#include "logicfunctions.h"

// Compute xor
void exclusive(bool x, bool y, bool& ans){
    ans = x ^ y;
}

// Compute implication
void implies(bool x, bool y, bool& ans){
    if(x){
        if(y) ans = 1;
        else ans = 0;
    }
    else ans = 1;
}

// Compute equivalence
void equivalence(bool x, bool y, bool& ans){
    ans = ( x == y );
}