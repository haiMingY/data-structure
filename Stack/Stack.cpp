#include <iostream>
using namespace std;

// Array Stack

#define MAX 1000
class Stack
{
  private:
    int top;

  public:
    int a[MAX];
    Stack() : top(-1){};

    bool push(int x);
    int pop();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top >= MAX - 1)
    {
        cout << "Stack Overflow" << endl;

        return false;
    }
    else
    {
        a[++top] = x;
        cout << "Stack pushed" << endl;
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << " empty" << endl;
        return 0;
    }

    return a[top--];
}

bool Stack::isEmpty()
{
    return top < 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    Stack s;

    for (int i = 1; i < 100; i++)
    {
        /* code */
        s.push(i);
    }

    cout << s.isEmpty() << endl;

    while (!s.isEmpty())
    {
        /* code */
        cout << s.pop() << endl;
    }

    return 0;
}
