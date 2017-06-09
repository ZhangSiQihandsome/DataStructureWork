//
// Created by zhangsiqi on 2017/6/9.
//

#ifndef DATASTRUCTUREWORK_MAINHEAP_H
#define DATASTRUCTUREWORK_MAINHEAP_H

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;


template<typename Item>
class MinHeap {

private:
    Item *data;     // 用来存储数据
    int count;      // 已存储的数据数
    int capacity;   // 最大堆的容量

    void shiftUp(int k) {
        // 只要 k  没有到顶 且 k 小于父节点
        while (k > 1 && data[k / 2] > data[k]) {
            // 交换 k 和父节点
            swap(data[k / 2], data[k]);
            // 索引指向父节点
            k /= 2;
        }
    }

    void shiftDown(int k) {
        // 只要没有到最底 (叶子节点)
        while (2 * k <= count) {
            int j = 2 * k; // 取出左孩子索引
            if (j + 1 <= count && data[j + 1] < data[j]) j++; // 当右孩子存在且左孩子大于右孩子 j指向右孩子
            if (data[k] <= data[j]) break; // 现在j 指向孩子中较小的那个 如果 K 还要小则结束
            swap(data[k], data[j]); // 否则交换 k 和 偏小的孩子
            k = j; // 索引指向偏小的孩子
        }
    }

public:

    MinHeap(int capacity) {
        data = new Item[capacity + 1]; // 索引从1 开始
        count = 0;
        this->capacity = capacity;
    }

    // 传入一个数组的构造函数
    MinHeap(Item arr[], int n) {
        data = new Item[n + 1];
        capacity = n;


        for (int i = 0; i < n; i++)
            data[i + 1] = arr[i];
        count = n;

        // 从最后二叉树节点进行shiftDown  将最小的挑出来
        for (int i = count / 2; i >= 1; i--)
            shiftDown(i);
    }

    ~MinHeap() {
        delete[] data;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Item item) {
        assert(count + 1 <= capacity);
        data[count + 1] = item;
        shiftUp(count + 1);
        count++;
    }

    Item extractMin() {
        assert(count > 0);
        Item ret = data[1]; // 取出第一个数字
        swap(data[1], data[count]); // 交换第一个和最后一个
        count--;
        shiftDown(1); // 将第一个shiftDown下去
        return ret;
    }

    Item getMin() {
        assert(count > 0);
        return data[1];
    }

    void show() {
        cout << "| ";
        for (int i = 1; i <= count; i++)
            cout << data[i]->wt()/*<<","<<data[i]*/<< " | ";
        cout << endl;
    }
};

#endif //DATASTRUCTUREWORK_MAINHEAP_H
