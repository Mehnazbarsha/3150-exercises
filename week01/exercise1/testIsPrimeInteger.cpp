#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 

#include "../include/doctest.h" 
#include "isPrimeFunction.h"

TEST_CASE("Zero and one are not prime") {
    CHECK_FALSE(isPrimeInteger(0));
    CHECK_FALSE(isPrimeInteger(1));
}

TEST_CASE("Negative numbers are not prime") {
    CHECK_FALSE(isPrimeInteger(-5));
}

TEST_CASE("Two is prime") {
    CHECK(isPrimeInteger(2));
}

TEST_CASE("Small primes are detected correctly") {
    CHECK(isPrimeInteger(3));
    CHECK(isPrimeInteger(5));
    CHECK(isPrimeInteger(7));
    CHECK(isPrimeInteger(11));
}

TEST_CASE("Small composites are not prime") {
    CHECK_FALSE(isPrimeInteger(4));
    CHECK_FALSE(isPrimeInteger(6));
    CHECK_FALSE(isPrimeInteger(9));
}

TEST_CASE("Even numbers greater than 2 are not prime") {
    CHECK_FALSE(isPrimeInteger(100));
}

TEST_CASE("Larger primes are detected") {
    CHECK(isPrimeInteger(101));
    CHECK(isPrimeInteger(103));
}

TEST_CASE("Larger composites are not prime") {
    CHECK_FALSE(isPrimeInteger(102));
}

TEST_CASE("Perfect squares are not prime") {
    CHECK_FALSE(isPrimeInteger(121));
}

TEST_CASE("Very large prime is detected") {
    CHECK(isPrimeInteger(7919));
}