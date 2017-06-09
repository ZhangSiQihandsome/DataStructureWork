//
// Created by zhangsiqi on 2017/6/9.
//

#ifndef DATASTRUCTUREWORK_LAZYPRIMMST_H
#define DATASTRUCTUREWORK_LAZYPRIMMST_H

#include <iostream>
#include "MainHeap.h"
#include "Edge.h"

using namespace std;

template<typename Graph, typename Weight>
class LazyPrimMST {

private:
    Graph &G;
    MinHeap<Edge<Weight>> pq;
    bool *marked; // 判断节点是否遍历
    vector<Edge<Weight>> mst; // 保存已选边
    Weight mstWeight; // 最小生成树最小的权值总和

    void visit(int v) {

        assert(!marked[v]); // 当前节点没有被访问过
        marked[v] = true;

        typename Graph::adjIterator adj(G, v);
        for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
            if (!marked[e->other(v)]) { // 如果边 e 的另一个节点没有被访问过
                pq.insert(*e); // 加* 取出指针下的值
            }
        }
    }

    void LazyPrim() {
        mst.clear();
        visit(0); // 寻找所有与 0 点相连接的端点并将边存入最小堆中
        while (!pq.isEmpty()) {
            Edge<Weight> e = pq.extractMin(); // 取出队列中权值最小的边
            if (marked[e.v()] == marked[e.w()])
                continue;  // 如果这条边两个端点, 都没被访问过, 或者都被访问过 则舍弃
            mst.push_back(e); // 否则符合条件 push 进最小生成树中
            if (!marked[e.v()]) // 然后对最小边的另一个未访问过得节点进行访问
                visit(e.v());
            else
                visit(e.w());
        }

        mstWeight = mst[0].wt();
        for (int i = 1; i < mst.size(); ++i)
            mstWeight += mst[i].wt();
    }

public:

    // 构造函数初始化, G为引用类型所以必须用构造列表初始化
    LazyPrimMST(Graph &graph) : G(graph), pq(MinHeap<Edge<Weight>>(graph.E())) {
        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); ++i)
            marked[i] = false;

        // 调用LazyPrim最小生成树算法
        LazyPrim();
    }

    ~LazyPrimMST() {
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges() {
        return mst;
    }

    Weight result() {
        return mstWeight;
    }
};

#endif //DATASTRUCTUREWORK_LAZYPRIMMST_H
