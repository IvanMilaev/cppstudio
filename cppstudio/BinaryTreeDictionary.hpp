//
//  BinaryTreeDictionary.hpp
//  cppstudio
//
//  Created by Иван Милаев on 03/06/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#ifndef BinaryTreeDictionary_hpp
#define BinaryTreeDictionary_hpp

#include <iostream>

struct word {
    std::string original;
    std::string translation;
    word(std::string orig, std::string transl);
};

struct node{
    word *word;
    node *left;
    node *right;
};

class BTree{
public:
    BTree();
    ~BTree();
    
    void insert(word *wrd);
    std::string translate(std::string orig);
    void destroy_tree();
    void inorder_print();
    void postorder_print();
    void preorder_print();
    
    
private:
    void destroy_tree(node *leaf);
    void insert(word *wrd, node *leaf);
    std::string translate(std::string orig, node *leaf);
    void inorder_print(node *leaf);
    void postorder_print(node *leaf);
    void preorder_print(node *leaf);
    
    
    node *root;
};
#endif /* BinaryTreeDictionary_hpp */
