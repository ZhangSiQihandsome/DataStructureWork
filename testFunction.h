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
#include "LazyPrimMST.h"
#include "PrimMST.h"
#include "KruskalMST.h"
#include "Dijkstra.h"
#include "BellmanFord.h"

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

// testWeightGraph
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

// test  Prim AND Kruskal MST
void testLazyPrimMST() {

    string filename = "testG3.txt";
    int V = 8;
    SparseGraph<double> g = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph(g, filename);

    // Test Lazy Prim MST
    cout << "Test Lazy Prim MST: " << endl;
    LazyPrimMST<SparseGraph<double>, double> lazyPrimMST(g);
    vector<Edge<double>> mst = lazyPrimMST.mstEdges();
    for (int i = 0; i < mst.size(); i++)
        cout << mst[i] << endl;
    cout << "The MST weight is: " << lazyPrimMST.result() << endl;
    cout << endl;

    // Test Prim MST
    cout << "Test Prim MST: " << endl;
    PrimMST<SparseGraph<double>, double> primMST(g);
    mst = primMST.mstEdges();
    for (int i = 0; i < mst.size(); ++i)
        cout << mst[i] << endl;
    cout << "The MST weight is: " << primMST.result() << endl;
    cout << endl;

    // Test Kruskal MST
    cout << "Test Kruskal MST: " << endl;
    KruskalMST<SparseGraph<double>, double> kruskalMST(g);
    mst = kruskalMST.mstEdges();
    for (int i = 0; i < mst.size(); ++i)
        cout << mst[i] << endl;
    cout << "Test MST Weight is: " << kruskalMST.result() << endl;

}


void testDijkstra() {

    string filename = "testG6.txt";
    int V = 16;

/*    string filename = "testG4.txt";
    int V = 5;*/
    SparseGraph<int> g = SparseGraph<int>(V, true); // 有向图
//    SparseGraph<int> g = SparseGraph<int>(V, false); // 无向图
    ReadGraph<SparseGraph<int>, int> readGraph(g, filename);
    cout << "Test Dijkstra: " << endl;
    Dijsktra<SparseGraph<int>, int> dij(g, 0);
    for (int i = 1; i < V; i++) {
        cout << "Shortest Path to " << i << " : " << dij.shortestPathTo(i) << endl;
        dij.showPath(i);
        cout << "---------" << endl;
    }
}

void testBellmanFord(){
    /*string filename = "testG5.txt";
    //string filename = "testG_negative_circle.txt";
    int V = 5;*/
    string filename = "testG6.txt";
    int V = 16;

    SparseGraph<int> g = SparseGraph<int>(V, true);
    ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

    cout<<"Test Bellman-Ford:"<<endl;
    BellmanFord<SparseGraph<int>, int> bellmanFord(g,0);
    if( bellmanFord.negativeCycle() )
        cout<<"The graph contain negative cycle!"<<endl;
    else
        for( int i = 1 ; i < V ; i ++ ){
            cout<<"Shortest Path to "<<i<<" : "<<bellmanFord.shortestPathTo(i)<<endl;
            bellmanFord.showPath(i);
            cout<<"----------"<<endl;
        }
}
#endif //DATASTRUCTUREWORK_TESTFUNCTION_H
