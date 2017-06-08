//
// Created by zhangsiqi on 2017/6/8.
//

#ifndef DATASTRUCTUREWORK_COMPONENT_H
#define DATASTRUCTUREWORK_COMPONENT_H

#include <iostream>
#include <cassert>

using namespace std;

template<typename Graph>
class Component {

private:
    Graph &G;
    bool *visited; // 记录每个节点的遍历情况
    int ccount; // 记录联通分量


    void dfs(int v) {
        visited[v] = true;

        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i])
                dfs(i);
        }
    }

public:
    Component(Graph &graph) : G(graph) {
        visited = new bool[G.V()];
        ccount = 0;
        for (int i = 0; i < G.V(); ++i) {
            visited[i] = false;
        }
        // 从第0个节点开始遍历
        for (int i = 0; i < G.V(); ++i) {
            // 如果当前节点没被访问过则进行一次深度遍历
            if (!visited[i]) {
                // 深度遍历完成之后如果所有节点全部被遍历则不会进入if语句中
                // 反之则没有被全部遍历完, 则进入第二个联通分量当中.
                dfs(i);
                ccount++;
            }
        }
    }

    ~Component() {
        delete[] visited;
    }

    int ccoutn() {
        return ccount;
    }
};

#endif //DATASTRUCTUREWORK_COMPONENT_H
