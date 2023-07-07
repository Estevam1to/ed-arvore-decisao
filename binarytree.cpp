#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

#include <iostream>
#include "binarytree.h"
using namespace std;

template<typename T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template<typename T>
BinaryTree<T>::BinaryTree(T value) {
    root = new Node<T>(value, nullptr, nullptr);
}

template<typename T>
BinaryTree<T>::BinaryTree(T value, BinaryTree<T>& l, BinaryTree<T>& r) {
    root = new Node<T>(value, l.getRoot(), r.getRoot());
    //As duas árvores ficarão vazias, pois os nós raizes delas serão filhas da árvore criada
    l.setRoot(nullptr);
    r.setRoot(nullptr);
}

template<typename T>
Node<T>* BinaryTree<T>::getRoot(){
    return root;
}
    
template<typename T>
void BinaryTree<T>::setRoot(Node<T>* newRoot){
    root = newRoot;
}

//Implementei uma função recursiva para liberar os nós de forma recursiva
template<typename T>
void clear_rec(Node<T> *node) {
    if(node != nullptr) {
        clear_rec(node->getLeft());
        clear_rec(node->getRight());
        delete node;
    }
}


template<typename T>
void BinaryTree<T>::clear() {
    clear_rec(root);
    root = nullptr;
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
    clear();
}

template<typename T>
bool BinaryTree<T>::is_empty() {
    return root == nullptr;
}

template<typename T>
void print_values_rec(Node<T> *node) {
    if(node != nullptr) {
        cout << node->getValue() << " ";
        print_values_rec(node->getLeft());
        print_values_rec(node->getRight());
    }
}

template<typename T>
void BinaryTree<T>::print_values() {
    print_values_rec(root);
    cout << endl;
}

template<typename T>
bool BinaryTree<T>::is_leaf() {
    return !is_empty() && root->getLeft() == nullptr && root->getRight() == nullptr;
}

template<typename T>
bool contains_rec(Node<T> *node, T value) {
    if(node == nullptr) 
        return false; // subárvore vazia
    else 
        return node->getValue() == value ||
               contains_rec(node->getLeft(), value) ||
               contains_rec(node->getRight(), value);
}

template<typename T>
bool BinaryTree<T>::contains(T value) {
    return contains_rec(root, value);
}

#endif