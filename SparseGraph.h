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

        g[v].push_back(w);
        if (v != w && !directed) {
            g[w].push_back(v);
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

    void show() {
        for (int i = 0; i < n; ++i) {
            cout << "vertex " << i << ":\t";
            for (int j = 0; j < g[i].size(); ++j)
                cout << g[i][j] << "   ";
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

        int begin() {
            index = 0;
            if (G.g[v].size())
                return G.g[v][index];
            return -1;
        }

        int next() {
            index++;
            if (index < G.g[v].size())
                return G.g[v][index];
            return -1;
        }

        bool end() {
            return index >= G.g[v].size();
        }
    };

};


#endif //DATASTRUCTUREWORK_SPARSEGRAPH_H
