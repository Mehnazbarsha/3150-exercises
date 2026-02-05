#ifndef __ISPRIMEFUNCTION_H
#define __ISPRIMEFUNCTION_H

#include <cmath>

bool isPrimeInteger(int pTest) {
    if (pTest <= 1) {
        return false;
    }
    
    if (pTest == 2) {
        return true;
    }
    
    if (pTest % 2 == 0) {
        return false;
    }
    
    int sqrtTest = static_cast<int>(std::sqrt(pTest));
    
    for (int i = 3; i <= sqrtTest; i += 2) {
        if (pTest % i == 0) {
            return false;
        }
    }
    
    return true;
}

#endif