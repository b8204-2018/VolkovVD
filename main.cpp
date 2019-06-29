#include <iostream>
#include <stack>
#include <string.h>
#include <cstdlib>
#include "OPZ.h"
#include "OPZ.cpp"

int main() {
    Polska polska("((5+5)*(4-3))/2");
    cout << polska.getResult();
    return 0;
}