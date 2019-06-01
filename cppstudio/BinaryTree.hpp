//
//  BinaryTree.hpp
//  cppstudio
//
//  Created by Иван Милаев on 31/05/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <iostream>
struct node{
    int value;
    node *left;
    node *right;
};

class BTree{
public:
    BTree();
    ~BTree();
    
    void insert(int key);
    node *search(int key);
    void destroy_tree();
    void inorder_print();
    void postorder_print();
    void preorder_print();
    void countBranchsNLevel_print(int &n);
    
private:
    void destroy_tree(node *leaf);
    void insert(int key, node *leaf);
    node *search(int key, node *leaf);
    void inorder_print(node *leaf);
    void postorder_print(node *leaf);
    void preorder_print(node *leaf);
    void countBranchsNLevel_print(int current_level,  int &count_nlevels, int &n, node *leaf);
    
    node *root;
};


#endif /* BinaryTree_hpp */
