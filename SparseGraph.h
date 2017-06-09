//
// Created by zhangsiqi on 2017/6/8.
//

#ifndef DATASTRUCTUREWORK_SPARSEGRAPH_H
#define DATASTRUCTUREWORK_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;

// 稀疏图 -- 邻接表
template<typename Weight>
class SparseGraph {

private:
    int n, m; // n: 图中的顶点数, m: 图中的边数
    bool directed; // true: 有向图, false: 无向图
    vector<vector<Edge<Weight> *>> g; // 邻接表

public:
    SparseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; ++i) {
            g.push_back(vector<Edge<Weight> *>());
        }
    }

    ~SparseGraph() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < g[i].size(); j++)
                delete g[i][j];
    }

    // 返回图中的顶点个数
    int V() { return n; }

    // 返回图中的边数
    int E() { return m; }

    void addEdge(int v, int w, Weight weight) {

        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        // 不考虑平行边
        g[v].push_back(new Edge<Weight>(v, w, weight));
        if (v != w && !directed) {
            g[w].push_back(new Edge<Weight>(w, v, weight));
        }
        m++;
    }

    bool hasEdge(int v, int w) {

        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        for (Edge<Weight> a : g[v])
            if (a.other(v) == w)
                return true;
        return false;
    }

    // 打印出邻接表中的边
    void show() {
        for (int i = 0; i < n; ++i) {
            cout << "vertex " << i << ":\t";
            for (int j = 0; j < g[i].size(); ++j)
                cout << "( to:" << g[i][j]->w() << ",wt:"
                     << g[i][j]->wt() << ")   ";
            cout << endl;
        }
    }

    class adjIterator {

    private:
        SparseGraph &G; // 存儲傳入進來的圖
        int v;  // 存儲傳入進來的頂點
        int index; // 當前索引的位置
    public:
        adjIterator(SparseGraph &graph, int v) : G(graph) {
            this->v = v;
            this->index = -1;
        }

        Edge<Weight> *begin() {
            index = 0;
            if (G.g[v].size())
                return G.g[v][index];
            return NULL;
        }

        Edge<Weight> *next() {
            index++;
            if (index < G.g[v].size())
                return G.g[v][index];
            return NULL;
        }

        bool end() {
            return index >= G.g[v].size();
        }
    };

};


#endif //DATASTRUCTUREWORK_SPARSEGRAPH_H
