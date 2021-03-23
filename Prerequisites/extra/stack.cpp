#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack
{
private:
    Node<T> *head;
    int size;
    pubic : Stack()
    {
        head = NULL;
        size = 0;
    }
    void push(T data)
    {
        Node<T> *newnode = new Node<T>(data);
        newnode->next = head;
        head = newnode;
        size++;
    }

    T top()
    {
        if (size == 0)
        {
            return 0;
        }
        return head->data;
    }

    T pop()
    {
        if (size == 0)
        {
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head->next;
        delete head;
        head = temp;
        size--;
        return ans;
    }
};
