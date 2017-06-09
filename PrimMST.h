//
// Created by zhangsiqi on 2017/6/9.
//

#ifndef DATASTRUCTUREWORK_PRIMMST_H
#define DATASTRUCTUREWORK_PRIMMST_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

template<typename Graph, typename Weight>
class PrimMST {

private:
    Graph &G;
    IndexMinHeap<Weight> ipq; // 存储和每个节点相邻的权值
    vector<Edge<Weight> *> edgeTo; // 存储和每个节点相邻的节点的横切边
    bool *marked;
    vector<Edge<Weight>> mst;
    Weight mstWeight;

    void visit(int v) {

        assert(!marked[v]); // 当前节点没有被访问过
        marked[v] = true;

        typename Graph::adjIterator adj(G, v); // 遍历与当前节点所有相邻的边
        for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
            int w = e->other(v); // 边相邻的节点
            if (!marked[w]) {    // 当另一个节点没有被访问过
                if (!edgeTo[w]) {  // 如果横切边中不存在连接w的边
                    ipq.insert(w, e->wt()); // 将变得权值存放进最小索引堆
                    edgeTo[w] = e; // 将边放入横切边中
                } else if (e->wt() < edgeTo[w]->wt()) {
                    edgeTo[w] = e;
                    ipq.change(w, e->wt());
                }
            }
        }
    }

public:
    PrimMST(Graph &graph) : G(graph), ipq(IndexMinHeap<double>(graph.V())) {

        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            marked[i] = false;
            edgeTo.push_back(NULL);
        }

        mst.clear();
        // Prim
        visit(0);
        while (!ipq.isEmpty()) {
            int v = ipq.extractMinIndex(); // 取出最小的哼切边的索引
            assert(edgeTo[v]);
            mst.push_back(*edgeTo[v]); // 因为存放的都是指针 所以用* 取出值
            visit(v);
        }

        mstWeight = mst[0].wt();
        for (int i = 1; i < mst.size(); ++i)
            mstWeight += mst[i].wt();
    }

    ~PrimMST() {
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges() {
        return mst;
    }

    Weight result() {
        return mstWeight;
    }

};

#endif //DATASTRUCTUREWORK_PRIMMST_H
