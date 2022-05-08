#include <iostream>
#include <exception>

using namespace std;

#include "LinearList.h"

#ifndef seqList_H_
#define seqList_H_ 

template <class elemType> class seqList:public List<elemType> {     // elemType为顺序表存储的元素类型
    private:
        elemType *data;         // 动态数组
        int curLength;          // 当前顺序表中存储的元素个数
        int maxSize;            // 顺序表的最大长度
        void resize();          // 表满时扩大表空间
    public:
        seqList(int initSize = 10);     // 构造函数
        seqList(seqList & sl);          // 拷贝构造函数
        ~seqList() { delete [] data; }  // 析构函数
        void clear() { curLength = 0; } // 清空表，只需置curLength为0
        bool empty() const { return curLength == 0; }   // 判空
        int size() const { return curLength; }      // 返回顺序表中当前存储元素的个数
        void traverse() const;          // 遍历顺序表
        void inverse();                 // 逆置顺序表
        void insert(int i, const elemType &value);  // 在位序i处插入值为value的元素，表长加1
        void remove(int i);             // 删除位序i处的元素，表长减1
        int search(const elemType &value) const;    // 查找值为value的元素第一次出现的位序
        elemType visit(int i) const;    // 访问位序为i的元素的值，“位序0”表示第一个元素
        bool Union(seqList<elemType> &B);
};


#endif // seqList_H_



