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
    void Phan_tich_snt(Stack s);
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

void Stack ::Phan_tich_snt(Stack s)
{
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        while(n % i == 0)
        {
            Node *p = Create(i);
            s.Push(s, p);
            n /= i;
        }
    }

    for(Node *p = s.head; p != NULL; p = p->next)
    {
        if(p != s.tail)
            cout << p->data << " * ";
        else if(p == s.tail)
            cout << p->data;
    }
}

int main()
{
    Stack s;
    s.CreateEmpty(s);
    s.Phan_tich_snt(s);
    return 0;
}
