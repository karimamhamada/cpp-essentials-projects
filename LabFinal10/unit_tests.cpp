#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "TimedSharedPtr.hpp"
#include <thread>
#include <chrono>

TEST_CASE("Bbasic construction and dereferencing") {
    TimedSharedPtr<int> p(new int(10), 100);
    CHECK(p.get() != nullptr);
    CHECK(*p.get() == 10);
    CHECK(p.use_count() == 1);
}
TEST_CASE("Copy/reference count") {
    TimedSharedPtr<int> p(new int(20), 100);
    TimedSharedPtr<int> q = p;
    CHECK(p.use_count() == 2);
    CHECK(q.use_count() == 2);
    CHECK(*q.get() == 20);
}
TEST_CASE("Expiry check") {
    TimedSharedPtr<int> p(new int(30), 50);
    std::this_thread::sleep_for(std::chrono::milliseconds(60));
    CHECK(p.get() == nullptr);
}