//
//  main.cpp
//  cppstudio
//
//  Created by Иван Милаев on 31/05/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#include <iostream>
//#include "BinaryTree.hpp"
#include "DoublyLinkedList.hpp"


int main(int argc, const char * argv[]) {
    
    
    //btree tree;
//    BTree *tree = new BTree();
//
//    tree->insert(10);
//    tree->insert(6);
//    tree->insert(14);
//    tree->insert(5);
//    tree->insert(8);
//    tree->insert(11);
//    tree->insert(18);
//    tree->insert(21);
//    tree->insert(17);
//    tree->insert(16);
//    tree->insert(23);
//
//    tree->preorder_print();
//    tree->inorder_print();
//    tree->postorder_print();
//
//    int n = 5;
//    tree->countBranchsNLevel_print(n);
//
//    delete tree;
    DoublyLinkedList *list = new DoublyLinkedList();
    list->push_front(2);
    list->push_front(4);
    list->push_back(3);
    list->push_front(9);
    list->push_back(8);
    
    list->display();
    
    list->delete_first();
    list->display();
    list->delete_last();
    list->display();
    //std::cout << list->head->prev << std:: endl;
    
    //cin.get();
    return 0;
}
