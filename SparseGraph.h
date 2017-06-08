//
// Created by zhangsiqi on 2017/6/8.
//

#ifndef DATASTRUCTUREWORK_SPARSEGRAPH_H
#define DATASTRUCTUREWORK_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 稀疏图 -- 邻接表
class SparseGraph {

private:
    int n, m; // n: 图中的顶点数, m: 图中的边数
    bool directed; // true: 有向图, false: 无向图
    vector<vector<int>> g; // 邻接表

public:
    SparseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; ++i) {
            g.push_back(vector<int>());
        }
    }

    ~SparseGraph() {

    }

    // 返回图中的顶点个数
    int V() { return n; }

    // 返回图中的边数
    int E() { return m; }

    void addEdge(int v, int w) {

        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        if (hasEdge(v, w))
            return;

        g[v][w] = w;
        if (!directed) {
            g[w][v] = v;
        }
        m++;
    }

    bool hasEdge(int v, int w) {

        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        for (int a : g[v]) {
            if (a == w)
                return true;
        }
        return false;
    }
};


#endif //DATASTRUCTUREWORK_SPARSEGRAPH_H
