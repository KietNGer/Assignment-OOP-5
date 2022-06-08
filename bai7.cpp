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
    void Binary(Stack s, int n);
    void Octal(Stack s, int n);
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

void Stack ::Binary(Stack s, int n)
{
    while(n > 0)
    {
        Node *p = Create(n%2);
        s.Push(s, p);
        n /= 2;
    }

    for(Node *p = s.head; p != NULL; p = p->next)
    {
        cout << p->data;
    }
}

void Stack ::Octal(Stack s, int n)
{
    while(n > 0)
    {
        Node *p = Create(n % 8);
        s.Push(s, p);
        n /= 8;
    }

    for(Node *p = s.head; p != NULL; p = p->next)
    {
        cout << p->data;
    }

}

int main()
{
    int n;
    cin >> n;
    int o = n;
    int h = n;
    Stack s;
    s.CreateEmpty(s);
    s.Binary(s, n);
    cout << endl;
    s.Octal(s, o);
    return 0;
}
