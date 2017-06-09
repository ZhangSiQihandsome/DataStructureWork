//
// Created by zhangsiqi on 2017/6/8.
//

#ifndef DATASTRUCTUREWORK_TESTFUNCTION_H
#define DATASTRUCTUREWORK_TESTFUNCTION_H

#include <iostream>
#include <time.h>
#include <iomanip>
#include "ShortestPath.h"
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"

// 有权图之前的测试函数

/*
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

void testComponent() {
    void testIteratorSparseGraph();
    // TestG1.txt
    string filename1 = "testG1.txt";
    SparseGraph g1 = SparseGraph(13, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename1);
    Component<SparseGraph> component1(g1);
    cout << "TestG1.txt Component Count: " << component1.ccoutn() << endl;
    cout << endl;

    // TestG2.txt
    string filename2 = "testG2.txt";
    SparseGraph g2 = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph2(g2, filename2);
    Component<SparseGraph> component2(g2);
    cout << "TestG2.txt, Component Count: " << component2.ccoutn() << endl;
    cout << endl;
}

void testPath() {
    string filename = "testG2.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();
    cout << endl;

    // 原点是 0
    Path<SparseGraph> dfs(g, 0);
    cout << "DFS: " << endl;
    for (int i = 0; i < 7; ++i) {
        dfs.showPath(i); // 展示原点到 5 的路径
    }

}

void testShortestPath() {
    string filename = "testG2.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();
    cout << endl;

    Path<SparseGraph> dfs(g, 0);
    cout << "DFS: ";
    dfs.showPath(6);

    ShortestPath<SparseGraph> bfs(g, 0);
    cout << "BFS: " << endl;
    for (int i = 0; i < 7; ++i) {
        bfs.showPath(i);
    }

}*/

// 有权图之后的测试函数 (添加 Edge.h)
void testWeightGraph() {
    string filename = "testG3.txt";
    int V = 8;
    cout << fixed << setprecision(2); // 设置输出的小数后两位

    // Test Weight Dense Graph
    DenseGraph<double> g1 = DenseGraph<double>(V, false);
    ReadGraph<DenseGraph<double>, double> readGraph1(g1, filename);
    g1.show();
    cout << endl;

    // Test Weight Sparse Graph
    SparseGraph<double> g2 = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph2(g2, filename);
    g2.show();
    cout << endl;
}

#endif //DATASTRUCTUREWORK_TESTFUNCTION_H
