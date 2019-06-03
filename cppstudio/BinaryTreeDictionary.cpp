//
//  BinaryTreeDictionary.cpp
//  cppstudio
//
//  Created by Иван Милаев on 03/06/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#include "BinaryTreeDictionary.hpp"

word:: word(std::string orig, std::string transl)
{
    original = orig;
    translation = transl;
}


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

void BTree::insert(word *wrd){
    if(root != NULL){
        insert(wrd, root);
    }else{
        root = new node();
        root->word = wrd;
        root->left = NULL;
        root->right = NULL;
    }
}

void BTree::insert(word *wrd, node *leaf)
{
    
    if(wrd->original < leaf->word->original)
    {
        if(leaf->left != NULL)
        {
            insert(wrd, leaf->left);
        }else
        {
            leaf->left = new node;
            leaf->left->word = wrd;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }else if(wrd->original >= leaf->word->original)
    {
        if(leaf->right != NULL)
        {
            insert(wrd, leaf->right);
        }else
        {
            leaf->right = new node;
            leaf->right->word = wrd;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }
    
}



std::string BTree::translate(std::string orig, node *leaf){
    if(leaf != NULL){
        if(orig == leaf->word->original){
            return leaf->word->translation;
        }
        if(orig < leaf->word->original){
            return translate(orig, leaf->left);
        }else{
            return translate(orig, leaf->right);
        }
    }else{
        return "no translation";
    }
}

std::string BTree::translate(std::string orig){
    return translate(orig, root);
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
        std:: cout << leaf->word->original << ":"<< leaf->word->translation <<",";
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
        std:: cout << leaf->word->original << ":"<< leaf->word->translation <<",";
    }
}

void BTree::preorder_print(){
    preorder_print(root);
    std:: cout << "\n";
}

void BTree::preorder_print(node *leaf){
    if(leaf != NULL){
        std:: cout << leaf->word->original << ":"<< leaf->word->translation <<",";
        inorder_print(leaf->left);
        inorder_print(leaf->right);
    }
}


