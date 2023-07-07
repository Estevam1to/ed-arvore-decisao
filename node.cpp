/**
 * @authors Luis Estevam Rosa Chaves (536699), Gustavo Henrique Freitas de Sousa (535735)
 * @brief 
 * @date 2023-06-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef NODE_CPP
#define NODE_CPP

#include "node.h"

template<typename T>
Node<T>::Node(T val, Node<T> *l, Node<T> *r){
    value = val;
    left = l;
    right = r;
}

template<typename T>
T Node<T>::getValue(){
    return this->value;
}

template<typename T>
void Node<T>::setValue(T newValue){
    this->value = newValue;
}

template<typename T>
Node<T>* Node<T>::getLeft(){
    return this->left;
}

template<typename T>
void Node<T>::setLeft(Node<T>* newLeft){
    this->left = newLeft;
}

template<typename T>
Node<T>* Node<T>::getRight(){
    return this->right;
}

template<typename T>
void Node<T>::setRight(Node<T>* newRight){
    this->right = newRight;
}

#endif