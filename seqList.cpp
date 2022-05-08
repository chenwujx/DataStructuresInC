#include "..\include\seqList.h"

template <class elemType> seqList<elemType>::seqList(int initSize){
    if (initSize <= 0) throw badSize();
    maxSize = initSize;
    data = new elemType[maxSize];
    curLength = 0;
}

template <class elemType> seqList<elemType>::seqList(seqList & sl){
    maxSize = sl.maxSize;
    curLength = sl.curLength;
    data = new elemType[maxSize];
    for (int i = 0; i < curLength; ++i)
        data[i] = sl.data[i];
}

template <class elemType> void seqList<elemType>::traverse() const{
    if(empty()) 
        cout << "is empty" << endl;     // 空表，没有元素
    else {
        cout << "output element:\n";
        for (int i = 0; i < curLength; i++)     // 依次访问顺序表中的所有元素
            cout << data[i] << " ";
        cout << endl;
    }
}

template <class elemType> int seqList<elemType>::search(const elemType &value) const {
    for (int i = 0; i < curLength; i++)
        if (value == data[i]) return i;
    return -1;          // 查找失败返回-1
}

template <class elemType> void seqList<elemType>::insert(int i, const elemType &value) {
    if (i < 0 || i > curLength) throw outOfRange();     // 合法的插入范围为[0..curLength]
    if (curLength == maxSize) resize();                 // 表满，扩大数组容量
    for (int j = curLength; j < i; j--)
        data[j] = data[j - 1];      // 下标在[curLength-1..i]范围内的元素往后移动一步
    data[i] = value;        // 将值为value的元素放入位序为i的位置
    ++curLength;            // 表的实际长度增1
}

template <class elemType> void seqList<elemType>::remove(int i) {
    if (i < 0 || i > curLength - 1) throw outOfRange();
    if (curLength == maxSize) resize();
    for (int j = i; j < curLength - 1; j++)
        data[j] = data[j + 1];
    --curLength;
}

template <class elemType> void seqList<elemType>::inverse() {
    elemType tmp;
    for (int i = 0; i < curLength / 2; i++) {   // 控制交换的次数
        tmp = data[i];
        data[i] = data[curLength - i - 1];
        data[curLength - i - 1] = tmp;
    }
}

template <class elemType> void seqList<elemType>::resize() {
    elemType *p = data;
    maxSize *= 2;
    data = new elemType[maxSize];
    for (int i = 0; i < curLength; i++) 
        data[i] = p[i];
}

template <class elemType> elemType seqList<elemType>::visit(int i) const {
    if (i > curLength - 1) throw outOfRange();
    return data[i];
}

template <class elemType> bool seqList<elemType>::Union(seqList<elemType> &B) {
    int m, n, k, i, j;
    m = this->curLength;        // 当前对象为线性表A
    n = B.curLength;            // m，n分别为线性表A和B的长度
    k = m + n - 1;              // k为结果线性表的工作指针（下标）
    i = m - 1;                  // i，j分别为线性表A和B的工作指针（下标）
    j = n - 1;
    if (m + n > this->maxSize) { resize(); }    // 判断表A空间是否足够大，空间不够则扩大表空间
    while (i >= 0 && j >= 0)            // 合并顺序表，直到一个表为空
        if (data[i] >= B.data[j]) 
            data[k--] = data[i--];
        else
            data[k--] = B.data[j--];    // 默认当前对象，this指针可以省略    
    while(j >= 0)                   // 将表B中的剩余元素复制到表A中
        data[k--] = B.data[j--];
    curLength = m + n;              // 修改表A长度
    return true;
}
