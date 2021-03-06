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

    Node *takeinput()
    {
        int data;
        cin >> data;
        Node *head = NULL;
        Node *tail = NULL;

        while (data != -1)
        {
            Node *newnode = new Node(data);
            if (head == NULL)
            {
                head = newnode;
                tail = newnode;
            }
            else
            {
                tail->next = newnode;
                tail = tail->next;
            }
            cin >> data;
        }
    }
    return head;
};

int main()
{

    return 0;
}