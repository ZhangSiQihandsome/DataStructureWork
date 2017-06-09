#include <iostream>
#include "testFunction.h"

using namespace std;

int main() {

    // 有权图之前的测试函数
/*    // testIterator
//    testIteratorDenseGraph();
//    cout << "--------------" << endl;
//    testIteratorSparseGraph();

    // testReadGraph
//    testReadGraph();

    // testComponent
//    testComponent();

    //testPath
//    testPath();

    // testShortestPath
//    testShortestPath();*/

    // 有权图之后的测试函数 (添加 Edge.h)

    // test Weight Dense Graph
    testWeightGraph();

    return 0;
}