#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "PyLongObject.h"

TEST_CASE("Default / value constructor") {
    PyLongObject a(0);
    CHECK(a.fitsInLongLong == true);
    CHECK(a.getSmallValue() == 0);

    PyLongObject b(42);
    CHECK(b.fitsInLongLong == true);
    CHECK(b.getSmallValue() == 42);

    PyLongObject c(-7);
    CHECK(c.fitsInLongLong == true);
    CHECK(c.getSmallValue() == -7);
}

TEST_CASE("Copy constructor produces independent copy") {
    PyLongObject original(100);
    PyLongObject copy(original);

    CHECK(copy.fitsInLongLong == true);
    CHECK(copy.getSmallValue() == 100);
    CHECK(original == copy);

    original = PyLongObject(999);
    CHECK(copy.getSmallValue() == 100);
}

TEST_CASE("Assignment operator") {
    PyLongObject a(55), b(0);
    b = a;
    CHECK(b.getSmallValue() == 55);
    CHECK(a == b);
}

TEST_CASE("Self-assignment is safe") {
    PyLongObject a(77);
    a = a;
    CHECK(a.getSmallValue() == 77);
}

TEST_CASE("Equality operator") {
    PyLongObject a(10), b(10), c(20);
    CHECK(a == b);
    CHECK(!(a == c));
}

TEST_CASE("Equality — same object") {
    PyLongObject a(42);
    CHECK(a == a);
}

TEST_CASE("getSmallValue") {
    PyLongObject a(123);
    CHECK(a.getSmallValue() == 123);
}

TEST_CASE("getDigitN") {
    PyLongObject a(BASE);
    CHECK(a.getDigitN(0) == 0);
    CHECK(a.getDigitN(1) == 1);
}

TEST_CASE("Addition — basic") {
    PyLongObject a(3), b(4);
    CHECK((a + b).getSmallValue() == 7);
}

TEST_CASE("Addition — zero identity") {
    PyLongObject a(0), b(42);
    CHECK((a + b).getSmallValue() == 42);
}

TEST_CASE("Addition — paper example") {
    PyLongObject x(380), y(2866);
    CHECK((x + y).getSmallValue() == 3246);
}

TEST_CASE("Addition — large values") {
    long long big = 4000000000LL;
    PyLongObject a(big), b(big);
    CHECK((a + b).getSmallValue() == big * 2);
}

TEST_CASE("Addition — commutativity") {
    PyLongObject a(123456), b(654321);
    CHECK((a + b) == (b + a));
}

TEST_CASE("Addition — associativity") {
    PyLongObject a(10), b(20), c(30);
    CHECK(((a + b) + c) == (a + (b + c)));
}

TEST_CASE("Addition — chained") {
    PyLongObject total(0);
    for (int i = 1; i <= 100; i++) total = total + PyLongObject(i);
    CHECK(total.getSmallValue() == 5050);
}