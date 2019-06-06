//
//  CircularDoublyLinkedList.hpp
//  cppstudio
//
//  Created by Иван Милаев on 03/06/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#ifndef CircularDoublyLinkedList_hpp
#define CircularDoublyLinkedList_hpp

#include <iostream>

typedef struct CircularDoublyLinkedListNode
{
    int value;
    struct DoublyLinkedListNode *next;
    struct DoublyLinkedListNode *prev;
    CircularDoublyLinkedListNode(int val);
} Node;


class CircularDoublyLinkedList
{
public:
    CircularDoublyLinkedList();
    ~CircularDoublyLinkedList();
    
    void addNode(int value);
    void deleteNode();
    
    int getLen() const;
    
    int *toArray() const;
    
    void sortBulb();
    
    int find(int value) const ;
    
    void display();
    
protected:
    int len;
    Node *curr;
    Node *head;
    Node *tail;
private:
    void display(Node *node);
    
};


#endif /* CircularDoublyLinkedList_hpp */
