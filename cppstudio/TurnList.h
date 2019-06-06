//
// Created by User on 31.05.2019.
//

#ifndef CPP_LABS_TURNLIST_H
#define CPP_LABS_TURNLIST_H

#include <string>
#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

class TurnNode{
public:
    TurnNode *getPrevNode() const;

    void setPrevNode(TurnNode *prevNode);

    TurnNode *getNextNode() const;

    void setNextNode(TurnNode *nextNode);

    int getData() const;

    void setData(int data);

    TurnNode(int data);

protected:
    TurnNode* prevNode;
    TurnNode* nextNode;
    int data;
};

class TurnList {
public:
    TurnList();

    void addNode(int data);

    void delNode(int index);

    string repr() const;

    int getLen() const;

    int* toArray() const;

    void sort();

    int find(int value) const ;

    friend ostream &operator<<(ostream &os, const TurnList &list);

    friend istream &operator>>(istream &is, TurnList &list);

protected:
    int len;
    TurnNode* currentNode;
    TurnNode* begin;
    TurnNode* end;
};



#endif //CPP_LABS_TURNLIST_H
