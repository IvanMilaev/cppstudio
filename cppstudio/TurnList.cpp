//
// Created by User on 31.05.2019.
//

#include "TurnList.h"

TurnNode *TurnNode::getPrevNode() const {
    return prevNode;
}

void TurnNode::setPrevNode(TurnNode *prevNode) {
    TurnNode::prevNode = prevNode;
}

TurnNode *TurnNode::getNextNode() const {
    return nextNode;
}

void TurnNode::setNextNode(TurnNode *nextNode) {
    TurnNode::nextNode = nextNode;
}

int TurnNode::getData() const {
    return data;
}

void TurnNode::setData(int data) {
    TurnNode::data = data;
}

TurnNode::TurnNode(int data) : data(data) {
    prevNode = nullptr;
    nextNode = nullptr;
}


TurnList::TurnList() {
    this->len = 0;
    currentNode = nullptr;
    begin = nullptr;
    end = nullptr;
}

void TurnList::addNode(int data) {
    TurnNode* newNode = new TurnNode(data);
    if (begin == nullptr){
        begin = newNode;
        end = newNode;
        currentNode = newNode;
    } else {
        begin->setPrevNode(newNode);
        end->setNextNode(newNode);

        end = newNode;
        len++;
    }
    newNode->setNextNode(begin);
    newNode->setPrevNode(end);
}

string TurnList::repr() const {
    string rez = "Turn List[";
    TurnNode* tmpNode = begin;
    for (int i=0;i<=len;i++){
        rez += to_string(tmpNode->getData());
        tmpNode = tmpNode->getNextNode();
        if (i!=len){
            rez += ", ";
        }
    }
    rez += "]";
    return rez;
}

void TurnList::delNode(int index) {
    assert(index<len && "Wrong index");
    TurnNode* tmpNode = begin;
    for (int i=0;i<=len;i++){
        tmpNode = tmpNode->getNextNode();
    }
    tmpNode->setPrevNode(tmpNode->getNextNode());
    tmpNode->setNextNode(tmpNode->getPrevNode());
    if (tmpNode==begin){
        begin = tmpNode->getNextNode();
    }
    if (tmpNode==end){
        end = tmpNode->getPrevNode();
    }
    len--;
    delete(tmpNode);
}

int *TurnList::toArray() const {
    int* newArray = new int[len];
    TurnNode* tmpNode = begin;
    for (int i=0;i<=len;i++){
        newArray[i] = tmpNode->getData();
        tmpNode = tmpNode->getNextNode();
    }
    return newArray;

}

int TurnList::getLen() const {
    return len+1;
}

void TurnList::sort() {
    for (int j=0;j<=len;j++) {
        TurnNode* tmpNode = begin;
        int swapBuf = 0;
        for (int i = 0; i < len; i++) {
            if (tmpNode->getNextNode()->getData() > tmpNode->getData()) {
                swapBuf = tmpNode->getNextNode()->getData();
                tmpNode->getNextNode()->setData(tmpNode->getData());
                tmpNode->setData(swapBuf);
            }
            tmpNode = tmpNode->getNextNode();
        }

    }


}

int TurnList::find(int value) const {
    int index = -1;
    TurnNode* tmpNode = begin;
    for (int i=0;i<=len;i++){
        if (value == tmpNode->getData()) {
            index = i;
            break;
        }
        tmpNode = tmpNode->getNextNode();
    }
    assert(index!=-1 && "Can't find value");
    return index;
}

ostream &operator<<(ostream &os, const TurnList &list) {
    os<<list.repr();
    return os;
}

istream &operator>>(istream &is, TurnList &list){
    int fileLen;
    is>>fileLen;
    int tmp;
    for (int i=0; i<fileLen; i++){
        is>>tmp;
        list.addNode(tmp);
    }
    return is;
}