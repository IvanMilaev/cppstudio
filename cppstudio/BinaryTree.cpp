//
//  BinaryTree.cpp
//  cppstudio
//
//  Created by Иван Милаев on 31/05/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#include "BinaryTree.hpp"
#include <iostream>
BTree::BTree()
{
    root = NULL;
}

BTree::~BTree(){
    destroy_tree();
}

void BTree::destroy_tree(node *leaf)
{
    if(leaf != NULL)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void BTree::insert(int key, node *leaf)
{
    
    if(key < leaf->value)
    {
        if(leaf->left != NULL)
        {
            insert(key, leaf->left);
        }else
        {
            leaf->left = new node;
            leaf->left->value = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }else if(key >= leaf->value)
    {
        if(leaf->right != NULL)
        {
            insert(key, leaf->right);
        }else
        {
            leaf->right = new node;
            leaf->right->value = key;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }
    
}

void BTree::insert(int key){
    if(root != NULL){
        insert(key, root);
    }else{
        root = new node;
        root->value = key;
        root->left = NULL;
        root->right = NULL;
    }
}

node *BTree::search(int key, node *leaf){
    if(leaf != NULL){
        if(key == leaf->value){
            return leaf;
        }
        if(key < leaf->value){
            return search(key, leaf->left);
        }else{
            return search(key, leaf->right);
        }
    }else{
        return NULL;
    }
}

node *BTree::search(int key){
    return search(key, root);
}

void BTree::destroy_tree(){
    destroy_tree(root);
}

void BTree::inorder_print(){
    inorder_print(root);
    std:: cout << "\n";
}

void BTree::inorder_print(node *leaf){
    if(leaf != NULL){
        inorder_print(leaf->left);
        std:: cout << leaf->value << ",";
        inorder_print(leaf->right);
    }
}

void BTree::postorder_print(){
    postorder_print(root);
    std:: cout << "\n";
}

void BTree::postorder_print(node *leaf){
    if(leaf != NULL){
        inorder_print(leaf->left);
        inorder_print(leaf->right);
        std:: cout << leaf->value << ",";
    }
}

void BTree::preorder_print(){
    preorder_print(root);
    std:: cout << "\n";
}

void BTree::preorder_print(node *leaf){
    if(leaf != NULL){
        std:: cout << leaf->value << ",";
        inorder_print(leaf->left);
        inorder_print(leaf->right);
    }
}

void BTree:: countBranchsNLevel_print(int &n)
{
    int current_level = 0;
    int count_nlevels = 0;
    countBranchsNLevel_print(current_level, count_nlevels, n, root);
    std:: cout<< count_nlevels << "\n";
}


void BTree:: countBranchsNLevel_print(int current_level, int &count_nlevels, int &n, node *leaf)
{
    if(leaf != NULL){
        if(++current_level == n) count_nlevels++;
        if(leaf->left != NULL)  countBranchsNLevel_print(current_level, count_nlevels, n, leaf->left);
        if(leaf->left != NULL)  countBranchsNLevel_print(current_level, count_nlevels, n, leaf->right);
    }


}


