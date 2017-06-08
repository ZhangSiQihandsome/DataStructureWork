#include <iostream>
#include <time.h>
#include "SparseGraph.h"
#include "DenseGraph.h"

using namespace std;

int main() {

    int N = 20;
    int M = 100;

    srand(time(NULL));

    // Sparse Graph
    cout << "Sparse Graph" << endl;
    SparseGraph g1(N, false);
    for (int i = 0; i < M; ++i) {
        int a = rand() % N; // 随机生成两个数
        int b = rand() % N;
        g1.addEdge(a, b); // 添加一条边
    }
    for (int j = 0; j < N; ++j) {
        cout << j << " : ";
        SparseGraph::adjIterator adj(g1, j);
        for (int w = adj.begin(); !adj.end(); w = adj.next()) {
            cout << w << " ";
        }
        cout << endl;
    }
    cout << "----------------------" << endl;

    // Dense Graph
    cout << "Dense Graph" << endl;
    DenseGraph g2(N, false);
    for (int i = 0; i < M; ++i) {
        int a = rand() % N; // 随机生成两个数
        int b = rand() % N;
        g2.addEdge(a, b); // 添加一条边
    }
    for (int j = 0; j < N; ++j) {
        cout << j << " : ";
        DenseGraph::adjIterator adj(g2, j);
        for (int w = adj.begin(); !adj.end(); w = adj.next()) {
            cout << w << " ";
        }
        cout << endl;
    }
    return 0;
}