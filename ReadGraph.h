//
// Created by zhangsiqi on 2017/6/8.
//

#ifndef DATASTRUCTUREWORK_READGRAPH_H
#define DATASTRUCTUREWORK_READGRAPH_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

template<typename Graph>
class ReadGraph {

public:
    ReadGraph(Graph &graph, const string &filename) {
        ifstream file(filename); // 加載文件
        string line; // 讀取一行的字符串
        int V, E;  // 讀取其中的頂點數和邊數

        assert(file.is_open());  // 判斷文件是否打開成功
        assert(getline(file, line));
        // 獲取其中第一行的頂點數和邊數
        stringstream ss(line);
        ss >> V >> E;

        // 判斷頂點數是否相同
        assert(V == graph.V());
        for (int i = 0; i < E; ++i) {
            assert(getline(file, line));
            stringstream ss(line);
            int a, b;
            ss >> a >> b;
            assert(a >= 0 && a < V);
            assert(b >= 0 && b < V);
            graph.addEdge(a, b);
        }
    }
};


#endif //DATASTRUCTUREWORK_READGRAPH_H
