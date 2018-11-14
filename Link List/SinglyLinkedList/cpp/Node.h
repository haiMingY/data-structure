#ifndef LIST_NODE_H
#define LIST_NODE_H

template <class T>

class Node
{
  public:
    Node(/* args */) = default;
    Node(T data) : data(data), next(nullptr){};
    /* data */
    Node<T> *next;
    T data;
};

#endif //LIST_NODE_H