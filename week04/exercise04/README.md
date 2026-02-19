# Exercise 04 - Python Style Integers

## Description
A `PyLongObject` mimics how CPython represents integers internally:
- Small integers are stored directly in a `long long`
- Large integers are stored as an array of base-2³⁰ digits

## What This Program Does
- Implements constructors including a copy constructor
- Implements a destructor with proper memory cleanup
- Implements base-2³⁰ addition digit-by-digit with carry
- Implements equality comparison
- Includes unit tests using doctest

## Files
- `PyLongObject.h`: struct declaration
- `PyLongObject.cpp`: struct definition and arithmetic
- `testPyLongObject.cpp`: unit tests

## Build and Run

Test program:
```bash
g++ -std=c++17 -Wall -Wextra testPyLongObject.cpp PyLongObject.cpp -o tests
./tests
```

## Tests Covered
- Default and value constructor
- Copy constructor produces independent copy
- Assignment operator
- Self-assignment safety
- Equality operator
- Self-comparison
- `getSmallValue` accessor
- `getDigitN` accessor
- Addition of basic values
- Addition with zero
- Addition matching the paper example (base-8 analogy)
- Addition of large values near long long boundary
- Commutativity
- Associativity
- Chained additions (1 + 2 + ... + 100 = 5050)
