//
// Created by zhangsiqi on 2017/6/9.
//

#ifndef DATASTRUCTUREWORK_KRUSKALMST_H
#define DATASTRUCTUREWORK_KRUSKALMST_H

#include <iostream>
#include <vector>
#include "MainHeap.h"
#include "UnionFind.h"
#include "Edge.h"

using namespace std;

template<typename Graph, typename Weight>
class KruskalMST {

private:
    vector<Edge<Weight>> mst;
    Weight mstWeight;

public:
    KruskalMST(Graph &graph) {

        MinHeap<Edge<Weight>> pq(graph.E()); // 首先创建一个最小堆
        for (int i = 0; i < graph.V(); ++i) {
            typename Graph::adjIterator adj(graph, i);
            for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
                if (e->v() < e->w())
                    pq.insert(*e); // 将取出的每一条边都存入最小堆
            }
        }
        UnionFind uf(graph.V());
        while (!pq.isEmpty() && mst.size() < graph.V() - 1) {  // 只要最小堆不为空
            Edge<Weight> e = pq.extractMin();  // 取出权值最小的一条边
            if (uf.isConnected(e.v(), e.w()))
                continue;
            mst.push_back(e);
            uf.unionElements(e.v(), e.w());
        }

        mstWeight = mst[0].wt();
        for (int i = 1; i < mst.size(); ++i)
            mstWeight += mst[i].wt();
    }

    ~KruskalMST() {}

    vector<Edge<Weight>> mstEdges() {
        return mst;
    }

    Weight result() {
        return mstWeight;
    }
};

#endif //DATASTRUCTUREWORK_KRUSKALMST_H
