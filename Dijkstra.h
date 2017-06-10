//
// Created by zhangsiqi on 2017/6/10.
//

#ifndef DATASTRUCTUREWORK_DIJKSTRA_H
#define DATASTRUCTUREWORK_DIJKSTRA_H

#include <iostream>
#include <vector>
#include <stack>
#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

template<typename Graph, typename Weight>
class Dijsktra {

private:
    Graph &G;
    int s;
    Weight *distTo; // 存放源点到个个顶点的最短距离
    bool *marked;  // 存储节点的状态
    vector<Edge<Weight> *> from; // 存放个个顶点的最短路径边

    void doDijkstra(int s, IndexMinHeap<Weight> &ipq) const {// Dijkstra
        distTo[s] = Weight();  // 到原点的距离设为初始值
        marked[s] = true;     // 原点已被访问过
        ipq.insert(s, distTo[s]); // 插入原点和到原点的距离
        while (!ipq.isEmpty()) {

            int v = ipq.extractMinIndex(); // 每一次取出距离最小的点 ,在第一次中取出原点

            // disTo[v] 就是s 到 v 的最短距离
            marked[v] = true;  // 在第一次中再次将原点设为访问过

            typename Graph::adjIterator adj(G, v);  // 遍历所有与原点相邻的边
            for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
                int w = e->other(v);  // 找到相邻边的另一个点
                if (!marked[w]) {    // 如果另一点未被访问过
                    if (from[w] == NULL || distTo[v] + e->wt() < distTo[w]) {  // 如果没有边到达这一点, 或者新到的这条边权值总和小于之前的一条边
                        distTo[w] = distTo[v] + e->wt();   // 更新到这一点的距离
                        from[w] = e;                     // 更新到这一点的边
                        if (ipq.contain(w)) {            // 如果这一点距离被改了就 change
                            ipq.change(w, distTo[w]);
                        } else {                         // 这一点是新遍历的就是 insert
                            ipq.insert(w, distTo[w]);
                        }
                    }
                }
            }
        }
    }

public:

    Dijsktra(Graph &graph, int s) : G(graph) {
        this->s = s;
        distTo = new Weight[G.V()];
        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            distTo[i] = Weight();
            marked[i] = false;
            from.push_back(NULL);
        }
        IndexMinHeap<Weight> ipq(G.V());

        // Dijkstra
        doDijkstra(s, ipq);

    }

    ~Dijsktra() {
        delete[] distTo;
        delete[] marked;
    }

    Weight shortestPathTo(int w) {
        return distTo[w];
    }

    bool hasPathTo(int w) {
        return marked[w];
    }

    void shortestPath(int w, vector<Edge<Weight>> &vec) {

        stack<Edge<Weight> *> s;

        Edge<Weight> *p = from[w];
        while ( p->v() != this->s) {  // 没有到原点
            s.push(p);
            p = from[p->v()];
        }

        vec.clear();
        while (!s.empty()) {
            p = s.top();
            vec.push_back(*p);
            s.pop();
        }
    }

    void showPath(int w) {

        assert(w >= 0 && w < G.V());

        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        cout << s << "-->";
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i].v() << "-->";
            if (i == vec.size() - 1)
                cout << vec[i].w() << endl;
        }
    }

};

#endif //DATASTRUCTUREWORK_DIJKSTRA_H
