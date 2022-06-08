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

class Queun
{
public:
    Node *head;
    Node *tail;
    void CreateEmpty(Queun &s);
    bool isEmpty();
    void EnQueun(Queun &s, Node *p);
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

void Queun ::CreateEmpty(Queun &s)
{
    s.head = NULL;
    s.tail = NULL;
}

bool Queun ::isEmpty()
{
    if(head == NULL)
        return true;
    else return false;
}

void Queun ::EnQueun(Queun &s, Node *p)
{
    if(s.head == NULL)
    {
        s.head = p;
        s.tail = s.head;
    }
    else
    {
        s.tail->next = p;
        s.tail = p;
    }
}

int main()
{
    Queun s;
    s.CreateEmpty(s);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Node *p = Create(x);
        s.EnQueun(s, p);
    }

    for(Node *i = s.head; i != NULL; i = i->next)
    {
        cout << i->data << " ";
    }
    return 0;
}
