#include<iostream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
public:
    Node *head;
    Node *tail;
    void CreateEmpty(Stack &s);
    bool isEmpty();
    void Push(Stack &s, Node *p);
    int Top();
    int Pop(Stack s, int x);
};

Node *Create(int x)
{
    Node *p = new Node;
    if(p == NULL)
        exit(1);
    p->data = x;
    p->next = NULL;
    return p;
}

void Stack ::CreateEmpty(Stack &s)
{
    s.head = NULL;
    s.tail = NULL;
}

bool Stack ::isEmpty()
{
    if(head == NULL)
        return true;
    else return false;
}

void Stack ::Push(Stack &s, Node *p)
{
    if(s.head == NULL)
    {
        s.head = p;
        s.tail = s.head;
    }
    else
    {
        p->next = s.head;
        s.head = p;
    }
}

int main()
{
    Stack s;
    s.CreateEmpty(s);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Node *p = Create(x);
        s.Push(s, p);
    }

    for(Node *i = s.head; i != NULL; i = i->next)
    {
        cout << i->data << " ";
    }
    return 0;
}
