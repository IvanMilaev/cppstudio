//
//  DoublyLinkedList.cpp
//  cppstudio
//
//  Created by Иван Милаев on 01/06/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#include "DoublyLinkedList.hpp"
Node:: DoublyLinkedListNode(int val)
{
    value = val;
    next = NULL;
    prev = NULL;
}

DoublyLinkedList:: DoublyLinkedList()
{
    head = NULL;
    tail = NULL;
}

void DoublyLinkedList:: push_back(int value)
{
    Node *newItem = new Node(value);
    if(head == NULL)
    {
        head = newItem;
        tail = newItem;
    }else
    {
        newItem->prev = tail;
        tail->next = newItem;
        tail = newItem;
    }
}

void DoublyLinkedList:: push_front(int value)
{
    Node *newItem = new Node(value);
    if(head == NULL)
    {
        head = newItem;
        tail = newItem;
    }else
    {
        newItem->next = head;
        head->prev = newItem;
        head = newItem;
    }
}

void DoublyLinkedList:: delete_first()
{
    if(head == NULL) return;
    if(head == tail)
    {
        Node *tmp;
        tmp = head;
        head = NULL;
        tail = NULL;
        delete tmp;
        return;
    }else
    {
        Node *tmp;
        tmp = head;
        head = head->next;
        head->prev = NULL;
        delete tmp;
    }
}

void DoublyLinkedList:: delete_last()
{
    if(head == NULL) return;
    if(head == tail)
    {
        Node *tmp;
        tmp = head;
        head = NULL;
        tail = NULL;
        delete tmp;
        return;
    }else
    {
        Node *tmp;
        tmp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete tmp;
    }
}

void DoublyLinkedList:: display()
{
    display(head);
    std::cout << std::endl;
}
void DoublyLinkedList:: display(Node *node)
{
    if(node != NULL)
    {
        std::cout << node->value << ",";
        display(node->next);
    }else return;
}
