//
//  main.cpp
//  cppstudio
//
//  Created by Иван Милаев on 31/05/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#include <iostream>
//#include "BinaryTree.hpp"
//#include "DoublyLinkedList.hpp"
#include "BinaryTreeDictionary.hpp"

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
    
//    DoublyLinkedList *list = new DoublyLinkedList();
//    list->push_front(2);
//    list->push_front(4);
//    list->push_back(3);
//    list->push_front(9);
//    list->push_back(8);
//
//    list->display();
//
//    list->delete_first();
//    list->display();
//    list->delete_last();
//    list->display();
    //std::cout << list->head->prev << std:: endl;
    
    BTree *tree = new BTree();
    word *pen = new word("ручка", "pen");
    word *table = new word("стол", "table");
    word *car = new word("машина", "car");
    word *gun = new word("ружье", "gun");
    word *bullet = new word("пуля", "bullet");
    word *sun = new word("солнце", "sun");
    word *sky = new word("небо", "sky");
    
    tree->insert(pen);
    tree->insert(table);
    tree->insert(car);
    tree->insert(gun);
    tree->insert(bullet);
    tree->insert(sun);
    tree->insert(sky);
    
    tree->inorder_print();
    
    std::cout << tree->translate("небо") << std::endl;
    std::cout << tree->translate("земля") << std::endl;
    return 0;
}
