#ifndef TIMED_SHARED_PTR_HPP
#define TIMED_SHARED_PTR_HPP
#include <chrono>
#include <atomic>
#include <iostream>
#include <thread>

using namespace std;
using Clock = chrono::steady_clock;
template <typename T>
class TimedSharedPtr {
private:
    struct ControlBlock {
        T* ptr;
        atomic<int> ref_count;
        chrono::time_point<Clock> start_time;
        chrono::milliseconds duration;
        ControlBlock(T* p, int expiry_ms)
            : ptr(p),
              ref_count(1),
              start_time(Clock::now()),
              duration(chrono::milliseconds(expiry_ms)) {}
        bool expired() const {
            return Clock::now() - start_time >= duration;
        }
        ~ControlBlock() {
            delete ptr;
        }
    };

    ControlBlock* control;
    void release() {
        if (control && --control->ref_count == 0) {
            delete control;
        }
    }

public:
    TimedSharedPtr() : control(nullptr) {}
    TimedSharedPtr(T* raw_ptr, int expiry_ms = 100)
        : control(new ControlBlock(raw_ptr, expiry_ms)) {}
    TimedSharedPtr(const TimedSharedPtr& other) : control(other.control) {
        if (control)
            ++control->ref_count;
    }

    TimedSharedPtr& operator=(const TimedSharedPtr& other) {
        if (this != &other) {
            release();
            control = other.control;
            if (control)
                ++control->ref_count;
        }
        return *this;
    }

    ~TimedSharedPtr() {
        release();
    }

    T* get() const {
        if (control && !control->expired()) {
            return control->ptr;
        }
        return nullptr;
    }

    int use_count() const {
        return control ? control->ref_count.load() : 0;
    }
};
#endif