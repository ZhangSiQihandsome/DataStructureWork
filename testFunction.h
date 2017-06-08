//
// Created by zhangsiqi on 2017/6/8.
//

#ifndef DATASTRUCTUREWORK_TESTFUNCTION_H
#define DATASTRUCTUREWORK_TESTFUNCTION_H

void testIteratorSparseGraph();

#include <iostream>
#include <time.h>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"

void testIteratorDenseGraph() {
    int N = 20;
    int M = 100;
    srand(time(NULL));
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
}

void testIteratorSparseGraph() {
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
}

void testReadGraph() {

    string filename = "testG1.txt";
    SparseGraph g1(13, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename);
    g1.show();

    DenseGraph g2(13, false);
    ReadGraph<DenseGraph> readGraph2(g2, filename);
    g2.show();
}

#endif //DATASTRUCTUREWORK_TESTFUNCTION_H
