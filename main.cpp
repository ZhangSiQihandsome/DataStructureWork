#include <iostream>
#include "testFunction.h"

using namespace std;

int main() {
    testIteratorDenseGraph();
    cout << "--------------" << endl;
    testIteratorSparseGraph();
    return 0;
}