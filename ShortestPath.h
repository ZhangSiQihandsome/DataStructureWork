//
// Created by zhangsiqi on 2017/6/8.
//

#ifndef DATASTRUCTUREWORK_SHORTESTPATH_H
#define DATASTRUCTUREWORK_SHORTESTPATH_H

#include <iostream>
#include <cassert>
#include <c++/queue>
#include <c++/stack>

using namespace std;

template<typename Graph>
class ShortestPath {

private:
    Graph &G;
    int s;
    bool *visited;
    int *from;
    int *ord;

    void shortestPath(int s, int *ord, queue<int> &q) const {// 无向图最短路径算法
        q.push(s); // 将原点放入队列中
        visited[s] = true;  // 原点已被访问过
        ord[s] = 0; // 原点到原点的距离为0
        while (!q.empty()) {  // 只要队列不为空
            int v = q.front(); // 取出队列首
            q.pop();

            // 对取出的队列首进行所有的临边遍历
            typename Graph::adjIterator adj(G, v);
            for (int i = adj.begin(); !adj.end(); i = adj.next()) {
                // 队列首的临边没有遍历过
                if (!visited[i]) {
                    // 放入队列中
                    q.push(i);
                    // 节点设为已访问
                    visited[i] = true;
                    // 上一个节点是v
                    from[i] = v;
                    // 距离远点的距离是上一个节点到原点距离 + 1
                    ord[i] = ord[v] + 1;
                }
            }
        }
    }

public:

    ShortestPath(Graph &graph, int s) : G(graph) {
        assert(s >= 0 && s < G.V());
        visited = new bool[G.V()];
        from = new int[G.V()];
        int *ord = new int[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }
        this->s = s;

        queue<int> q;

        // 从构造函数中调用最短路径算法 (广度优先)
        shortestPath(s, ord, q);

    }

    ~ShortestPath() {
        delete[] visited;
        delete[] from;
        delete[] ord;
    }

    bool hasPath(int w) {
        assert(w >= 0 && w < G.V());
        return visited[w];
    }

    void path(int w, vector<int> &vec) {

        stack<int> s;

        int p = w;
        while (p != -1) {
            s.push(p);
            p = from[p];
        }

        vec.clear();
        while (!s.empty()) {
            vec.push_back((int) s.top());
            s.pop();
        }
    }

    void showPath(int w) {
        vector<int> vec;
        path(w, vec);
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i];
            if (i == vec.size() - 1)
                cout << endl;
            else
                cout << "-->";
        }
    }

    int length(int w) {
        assert(w >= 0 && w < G.V());
        return ord[w];
    }
};

#endif //DATASTRUCTUREWORK_SHORTESTPATH_H
