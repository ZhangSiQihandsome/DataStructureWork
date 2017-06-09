//
// Created by zhangsiqi on 2017/6/8.
//

#ifndef DATASTRUCTUREWORK_DENSEGRAPH_H
#define DATASTRUCTUREWORK_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;

// 稠密图 -- 邻接矩阵
template<typename Weight>
class DenseGraph {

private:
    int n, m; // n: 顶点数, m: 边数
    bool directed;  // 用来设置图为有向图还是无向图 true:有向图 false: 无向图
    // 邻接矩阵用二维vector 数组表示 邻接矩阵中存放bool型变量表示是否有边
    vector<vector<Edge<Weight> *>> g;
public:
    DenseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; ++i) {
            g.push_back(vector<Edge<Weight> *>(n, NULL));
        }
    }

    ~DenseGraph() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j] != NULL)
                    delete g[i][j];
    }

    // 返回图中的顶点数
    int V() { return n; }

    // 返回图中的边数
    int E() { return m; }

    void addEdge(int v, int w, Weight weight) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        // 返回true 代表已经有边了  直接结束函数
        if (hasEdge(v, w)) {
            delete g[v][w];
            if (!directed)
                delete g[w][v];
            m--;
        }

        g[v][w] = new Edge<Weight>(v, w, weight);
        if (!directed) {
            g[w][v] = new Edge<Weight>(w, v, weight);;
        }
        m++;  // 边数++
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return g[v][w] != NULL;
    }

    // 打印出邻接矩阵中的边
    void show() {
        for (int i = 0; i < n; ++i) {
            cout << "vertex " << i << ":\t";
            for (int j = 0; j < g[i].size(); ++j)
                if (g[i][j])
                    cout << g[i][j]->wt() << "   ";
                else
                    cout << "NULL   ";
            cout << endl;
        }
    }

    class adjIterator {

    private:
        DenseGraph &G;
        int v;
        int index;

    public:
        adjIterator(DenseGraph &g, int v) : G(g) {
            this->v = v;
            this->index = -1;
        }

        Edge<Weight> *begin() {
            index = -1;
            return next();
        }

        Edge<Weight> *next() {
            // index 先加1 然后遍历小于总顶点数的次数
            for (index += 1; index < G.V(); index++)
                // 如果其中一个顶点为true 则返回顶点索引
                if (G.g[v][index])
                    return G.g[v][index];
            return NULL;
        }

        bool end() {
            return index >= G.V();
        }
    };
};


#endif //DATASTRUCTUREWORK_DENSEGRAPH_H
