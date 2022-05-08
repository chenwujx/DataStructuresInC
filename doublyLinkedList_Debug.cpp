#include <iostream>
#include <string>

using namespace std;

#include ".\include\linkedList.h"

int linkListDebug() {
    int sizeOfseqList, itmp;

    std::cout << "****************************************************" << endl;
    std::cout << "the structure of class <eleType>:" << endl;
    std::cout << "private:" << endl;
    std::cout << "      elemType *data;" << endl;
    std::cout << "      int curLength;" << endl;
    std::cout << "      int maxSize;" << endl;
    std::cout << "      void resize();" << endl;
    std::cout << "public:" << endl;
    std::cout << "      seqList(int initSize = 10);" << endl;
    std::cout << "      seqList(seqList & sl);" << endl;
    std::cout << "      ~seqList() { delete [] data; }" << endl;
    std::cout << "      void clear() { curLength = 0; }" << endl;
    std::cout << "      bool empty() const { return curLength == 0; }" << endl;
    std::cout << "      int size() const { return curLength; }" << endl;
    std::cout << "      void traverse() const;" << endl;
    std::cout << "      void inverse();" << endl;
    std::cout << "      void insert(int i, const elemType &value);" << endl;
    std::cout << "      void remove(int i);" << endl;
    std::cout << "      int search(const elemType &value) const;" << endl;
    std::cout << "      elemType visit(int i) const;" << endl;
    std::cout << "      bool Union(seqList<elemType> &B);" << endl;
    std::cout << "****************************************************" << endl;

    std::cout << "please enter the length of sequence queue :";
    std::cin >> sizeOfseqList;
    linkList<int> sL;
    std::cout << "please enter every data of " << sizeOfseqList << ":";
    for (int i = 0; i < sizeOfseqList; i++) {
        std::cin >> itmp;   
        sL.insert(i, itmp);     
    }

    std::cout << "the value of input data are:" << endl;
    for (int i = 0; i < sizeOfseqList; i++) {
        std::cout << sL.visit(i) << ", ";     
    }
    std::cout << endl;

    std::cout << "please the value of the element you want to find:";
    std::cin >> itmp;
    int i = sL.search(itmp);
    std::cout << "the element you wanted to find is in the satation of " << i << endl;


    return 0;
}

