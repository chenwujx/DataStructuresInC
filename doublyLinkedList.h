#include <iostream>
#include <exception>

using namespace std;

#include "LinearList.h"

#ifndef linkList_H_
#define linkList_H_ 

template <class elemType> struct Node {
    public:
        elemType data;      // 数据域
        Node *next;         // 指针域
        Node(const elemType value, Node *p = NULL) {    // 两个参数的构造函数
            data = value;
            next = p;
        }
        Node(Node *p = NULL) {      // 一个参数的构造函数
            next = p;
        }
};

template <class elemType> class linkList:public List<elemType> {    // elemType为单链表存储的元素类型
    private:
        struct Node {       // 结点类型
            public:
                elemType data;      // 结点的数据域
                Node *next;         // 结点的指针域
                Node(const elemType value, Node *p = NULL) {    // 两个参数的构造函数
                    data = value;
                    next = p;
                }
                Node(Node *p = NULL) {      // 一个参数的构造函数
                    next = p;
                }
        };
        Node *head;                     // 单链表的头指针
        Node *tail;                     // 单链表的尾指针
        int curLength;                  // 单链表的当前长度，牺牲空间换时间
        Node *getPositon(int i) const;  // 返回指向位序为i的结点的指针
    public:
        linkList();     // 构造函数
        ~linkList();    // 析构函数
        void clear();   // 将单链表清空，使之成为空表
        bool empty() const { return head->next == NULL; }   // 带头结点的单链表，判空
        int size() const ;   // 返回单链表的当前实际长度
        void insert(int i, const elemType &value);  // 在位序i处插入值为value的结点，表长增1
        void remove(int i);     // 删除位序i处的结点，表长减1
        int search(const elemType &value) const;    // 查找值为value的结点第一次出现的位序
        int prior(const elemType &value) const;     // 查找值为value的结点的前驱的位序
        elemType visit(int i) const;    // 访问位序为i的结点的值，0定位到首元结点
        void traverse() const;      // 遍历单链表
        void headCreate();          // “头插法”创建单链表
        void tailCreate();          // “尾插法”创建单链表
        void inverse();             // 逆置单链表
        linkList<elemType> * Union(linkList<elemType> *lb);
};

template <class elemType> linkList<elemType>::linkList() {
    head = tail = new Node();       // 创建带有头结点的空表
    curLength = 0;
}

template <class elemType> linkList<elemType>::~linkList() {
    clear();        // 清空单链表
    delete head;    // 释放头结点
}

template <class elemType> void linkList<elemType>::clear() {
    Node *p, *tmp;          // p为工作指针，指向首元结点
    p = head->next;         // 引入工作指针是为了防止随意修改头指针
    while (p != NULL) {     // 等效于 while(p)
        tmp = p;
        p = p->next;        // 指针后移
        delete tmp;
    }
    head->next = NULL;      // 头结点的指针域置空
    tail = head;            // 头尾指针均指向头结点
    curLength = 0;
}

// template <class elemType> int linkList<elemType>::size() const {
//    return curLength;       // 直接返回curLength
// }

template <class elemType> int linkList<elemType>::size() const {
    Node *p = head->next;   // 若类中没有数据成员curLength
    int count = 0;          // 则需要从头到尾遍历单链表
    while (p != NULL) {
        count ++;
        p = p->next;
    }
    return count;
}

template <class elemType> void linkList<elemType>::traverse() const {
    Node *p = head->next;       // 工作指针p指向首元结点
    cout << "traverse:";
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;            // 向后移动指针
    }
    cout << endl;
}

template <class elemType> typename linkList<elemType>
    ::Node* linkList<elemType>::getPositon(int i) const {
    if (i < -1 || i > curLength - 1) return NULL;
    Node *p = head;
    int count = 0;
    while (count <= i) {
        count ++;
        p = p->next;
    }
    return p;
}

template <class elemType> int linkList<elemType>::search(const elemType &value) const {
    Node *p = head->next;
    int count = 0;
    while (p != NULL && p->data != value) {
        count ++;
        p = p->next;
    }
    if (p == NULL) return -1;
    else return count;
}

template <class elemType> int linkList<elemType>::prior(const elemType &value) const {
    Node *p = head->next;
    Node *pre = NULL;
    int count = -1;
    while (p && p->data != value) {
        pre = p;
        p = p->next;
        count ++;
    }
    if (p == NULL) return -1;
    else return count;
}

template <class elemType> void linkList<elemType>::insert(int i, const elemType &value) {
    Node *p, *q;
    if (i < 0 || i > curLength) throw outOfRange();
    p = getPositon(i - 1);
    q = new Node(value, p->next);
    p->next = q;
    if (p == tail) tail = q;
    curLength ++;
}

template <class elemType> void linkList<elemType>::remove(int i) {
    Node *pre, *p;
    if (i < 0 || i > curLength) throw outOfRange();
    pre = getPositon(i - 1);
    p = pre->next;
    if (p == tail){
        tail = pre;
        pre->next = NULL;
        delete p;
    } 
    else {
        pre->next = p->next;
        delete p;
    }
    curLength --;
}

template <class elemType> void linkList<elemType>::headCreate() {
    Node *p;
    elemType value, flag;
    cout << "input elements, ended with:";
    cin >> flag;
    while (cin >> value, value != flag) {
        p = new Node(value, head->next);
        head->next = p;
        if (head == tail) tail = p;
        curLength ++;
    }
}

template <class elemType> void linkList<elemType>::tailCreate() {
    Node *p;
    elemType value, flag;
    cout << "input elements, ended with:";
    cin >> flag;
    while (cin >> value, value != flag) {
        p = new Node(value, NULL);
        tail->next = p;
        tail = p;
        curLength ++;
    }
}

template <class elemType> void linkList<elemType>::inverse() {
    Node *p, *tmp;
    p = head->next;
    head->next = NULL;
    if (p) tail = p;
    while(p) {
        tmp = p->next;
        p->next = head->next;
        head->next = p;
        p = tmp;
    }
}

template <class elemType> linkList<elemType> * linkList<elemType>::Union(linkList<elemType> *lb) {
    Node *pa, *pb, *pc;
    linkList<elemType> *lc = this;
}

template <class elemType> elemType linkList<elemType>::visit(int i) const {
//    if (i > curLength - 1) throw outOfRange();
    return head->data;
}
#endif // linkList_H_