//
//  DoublyLinkedList.hpp
//  cppstudio
//
//  Created by Иван Милаев on 01/06/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp


#include <iostream>

typedef struct DoublyLinkedListNode
{
    int value;
    struct DoublyLinkedListNode *next;
    struct DoublyLinkedListNode *prev;
    DoublyLinkedListNode(int val);
} Node;

class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    
    void push_front(int value);
    void push_back(int value);
    void delete_first();
    void delete_last();
    void display();
    
    Node *head;
    Node *tail;
private:
    void display(Node *node);
   
};

#endif /* DoublyLinkedList_hpp */
