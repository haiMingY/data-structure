#ifndef LIST_NODE_H //LIST_NODE_H
#define LIST_NODE_H

template <class T>
class Node
{
public:
  Node(T data)
  {
    this->data = data;
    this->next = nullptr;
  };
  Node<T> *next;
  T data;
};

#endif //LIST_NODE_H