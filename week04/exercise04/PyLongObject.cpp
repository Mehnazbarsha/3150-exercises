#include "PyLongObject.h"
#include <cstring>

void PyLongObject::freeDigits() {
    if (digitsBase30) {
        delete[] digitsBase30;
        digitsBase30 = nullptr;
    }
}

void PyLongObject::copyFrom(const PyLongObject &other) {
    sign = other.sign;
    numDigits = other.numDigits;
    fitsInLongLong = other.fitsInLongLong;
    iValue = other.iValue;
    if (!fitsInLongLong && other.digitsBase30 && numDigits > 0) {
        digitsBase30 = new unsigned int[numDigits];
        memcpy(digitsBase30, other.digitsBase30, numDigits * sizeof(unsigned int));
    } else {
        digitsBase30 = nullptr;
    }
}

PyLongObject::PyLongObject(long long _iValue)
    : sign(_iValue < 0 ? -1 : 1), numDigits(0), fitsInLongLong(true),
      iValue(_iValue), digitsBase30(nullptr) {}

PyLongObject::PyLongObject(const PyLongObject &other) : digitsBase30(nullptr) {
    copyFrom(other);
}

PyLongObject::~PyLongObject() {
    freeDigits();
}

PyLongObject &PyLongObject::operator=(const PyLongObject &other) {
    if (this != &other) {
        freeDigits();
        copyFrom(other);
    }
    return *this;
}

PyLongObject PyLongObject::operator+(const PyLongObject &other) const {
    auto getD = [](const PyLongObject &p, int i) -> long long {
        if (p.fitsInLongLong) {
            long long val = p.iValue < 0 ? -p.iValue : p.iValue;
            for (int k = 0; k < i; k++) val /= BASE;
            return val % BASE;
        }
        return i < p.numDigits ? (long long)p.digitsBase30[i] : 0LL;
    };

    auto numD = [](const PyLongObject &p) -> int {
        if (p.fitsInLongLong) {
            long long val = p.iValue < 0 ? -p.iValue : p.iValue;
            if (val == 0) return 1;
            int cnt = 0;
            while (val > 0) { val /= BASE; cnt++; }
            return cnt;
        }
        return p.numDigits;
    };

    int maxDig = max(numD(*this), numD(other)) + 1;
    unsigned int *res = new unsigned int[maxDig]();
    long long carry = 0;
    int actualDig = 0;

    for (int i = 0; i < maxDig; i++) {
        long long s = getD(*this, i) + getD(other, i) + carry;
        res[i] = (unsigned int)(s % BASE);
        carry = s / BASE;
        if (res[i] != 0) actualDig = i + 1;
    }
    if (actualDig == 0) actualDig = 1;

    bool overflow = false;
    long long val = 0;
    for (int i = actualDig - 1; i >= 0; i--) {
        if (val > (9223372036854775807LL - (long long)res[i]) / BASE) {
            overflow = true;
            break;
        }
        val = val * BASE + (long long)res[i];
    }

    PyLongObject result(0LL);
    if (!overflow) {
        result.iValue = val;
        delete[] res;
    } else {
        result.fitsInLongLong = false;
        result.numDigits = actualDig;
        result.digitsBase30 = res;
    }
    return result;
}

bool PyLongObject::operator==(const PyLongObject &other) const {
    if (this == &other) return true;
    if (sign != other.sign) return false;

    if (fitsInLongLong && other.fitsInLongLong)
        return iValue == other.iValue;

    if (!fitsInLongLong && !other.fitsInLongLong) {
        if (numDigits != other.numDigits) return false;
        for (int i = 0; i < numDigits; i++)
            if (digitsBase30[i] != other.digitsBase30[i]) return false;
        return true;
    }

    const PyLongObject *big = fitsInLongLong ? &other : this;
    const PyLongObject *small = fitsInLongLong ? this : &other;
    if (big->numDigits > 1) return false;
    long long bigVal = big->numDigits == 1 ? (long long)big->digitsBase30[0] : 0;
    return small->iValue == bigVal;
}

int PyLongObject::getDigitN(int n) const {
    if (fitsInLongLong) {
        long long val = iValue < 0 ? -iValue : iValue;
        for (int k = 0; k < n; k++) val /= BASE;
        return (int)(val % BASE);
    }
    if (n < 0 || n >= numDigits) return -1;
    return (int)digitsBase30[n];
}

long long PyLongObject::getSmallValue() const {
    return fitsInLongLong ? iValue : -1;
}

ostream &operator<<(ostream &os, const PyLongObject &p) {
    if (p.fitsInLongLong) {
        os << p.iValue;
    } else {
        os << "[base2^30 digits:";
        for (int i = p.numDigits - 1; i >= 0; i--)
            os << " " << p.digitsBase30[i];
        os << "]";
    }
    return os;
}