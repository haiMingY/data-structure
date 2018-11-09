#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <iostream>
#include "Node.h"

template <class T>
class LinkList
{
    friend class Node<T>;

  public:
    LinkList();
    ~LinkList();
    void push(const T &data);      //添加元素
    void printData() const;        //输出所有内容
    void deleteNode(const T data); //删除指定的数据
    void deleteByPos(int pos);     //删除指定位置的数据
  private:
    Node<T> *head;
};

template <class T>
LinkList<T>::LinkList(){

};
template <class T>
LinkList<T>::~LinkList()
{
    Node<T> *curr = head;
    Node<T> *temp;
    while (curr != nullptr)
    {
        temp = curr->next;
        delete curr;
        curr = temp;
    }
    head = nullptr;
    std::cout << "----析构函数" << std::endl;
};
template <class T>
void LinkList<T>::push(const T &data)
{

    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *node = new Node<T>(data);
        node->next = head;
        head = node;
    }
};
template <class T>
void LinkList<T>::deleteNode(const T data) //删除指定项
{
    Node<T> *curr = head;
    Node<T> *prev;
    if (curr != nullptr && curr->data == data)
    {
        prev = curr;
        curr = curr->next;
        delete prev;
        return;
    }
    while (curr != nullptr && curr->data != data)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr)
    {
        return;
    }

    prev->next = curr->next;
    delete curr;
};
template <class T>
void LinkList<T>::deleteByPos(int pos)
{
    if (pos < 0 || head == nullptr)
    {
        return;
    }
    Node<T> *curr = head;
    if (pos == 0)
    {
        head = head->next;
        delete curr;
        return;
    }

    for (int i = 0; curr != nullptr && i < pos - 1; i++)
    {
        /* code */
        curr = curr->next;
    }
    if (curr == nullptr || curr->next == nullptr)
    {
        return;
    }
    Node<T> *next = curr->next->next;
    delete curr->next;
    curr->next = next;
};
template <class T>
void LinkList<T>::printData() const
{
    Node<T> *curr = head;
    while (curr != nullptr)
    {
        std::cout << " data is:" << curr->data << std::endl;
        curr = curr->next;
    }
}

#endif //LINK_LIST_H