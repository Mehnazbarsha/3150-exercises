#ifndef PYLONGOBJECT_H
#define PYLONGOBJECT_H

#include <iostream>

using namespace std;

static const long long BASE = (1LL << 30);       
static const long long LLONG_FITS_MAX = (1LL << 62); 
struct PyLongObject {
    PyLongObject(long long _iValue = 0);
    PyLongObject(const PyLongObject &other);   
    ~PyLongObject();

    PyLongObject &operator=(const PyLongObject &other);

    PyLongObject operator+(const PyLongObject &other) const;

    bool operator==(const PyLongObject &other) const;

    int  getDigitN(int n) const;  
    long long getSmallValue() const;

    friend ostream &operator<<(ostream &os, const PyLongObject &p);

    int sign;         
    int numDigits;    
    bool fitsInLongLong;
    long long iValue;       
    unsigned int *digitsBase30; 

private:
    void  buildFromLongLong(long long val);
    void  copyFrom(const PyLongObject &other);
    void  freeDigits();
};

#endif
