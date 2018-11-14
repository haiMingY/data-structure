#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <iostream>
#include "Node.h"

template <class T>
class LinkList
{
  private:
    int length;
    Node<T> *head;
    Node<T> *tail;

  public:
    LinkList();
    ~LinkList();
    bool isEmpty() const; //判断是否是空链表
};

template <class T>
LinkList<T>::LinkList() //构造函数
{
    length = 0;
};

template <class T>
LinkList<T>::~LinkList(){
    //析构函数

};
template <class T>
bool LinkList<T>::isEmpty() const {
    //判断是否是空链表

    return this->length == 0;

};

#endif // LINK_LIST_H