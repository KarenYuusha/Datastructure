#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int info;
    Node* next;
};

struct List
{
    Node* head;
    Node* tail;
};

void PrintList (List l)
{
    while (l.head != NULL)
    {
        cout << l.head -> info << "\t";
        l.head = l.head->next;
    }
    cout << endl;
}

void CreateEmptyList (List& l)
{
    l.head = NULL;
    l.tail = NULL;
}

Node* CreateNode (int x)
{
    Node* a = new Node;
    if (a == NULL)
        exit (1);

    a->info = x;
    a->next = NULL;

    return a;
}

void AddHead (List& l, Node *a)
{
    if (l.head == NULL)
    {
        l.head = a;
        l.tail = l.head;
    }
    else
    {
        a->next = l.head;
        l.head = a;
    }
}

void AddTail (List& l, Node *a)
{
    if (l.head == NULL) // list is empty
    {
        l.head = a;
        l.tail = a;
    }
    else
    {
        l.tail->next = a;
        l.tail = a;
    }
}

void CreateNNode (List &l, int &n)
{
    CreateEmptyList (l);
    cout << "nhap n: ";
    cin >> n;
    int val;
    for (int i = 1; i <= n; i++)
    {
        cin >> val;
        AddTail (l, CreateNode(val));
    }
}

void AddNodeAfterQ (List& l, Node* q, Node* p)
{
    if (q == l.tail)
        AddTail (l, p);
    else if (q != NULL)
    {
        p->next = q->next;
        q->next = p;
    }
    else
        AddHead (l, p);
}

void AddNodeBeforeQ (List& l, Node* q, Node* p)
{
    if (q == l.head)
        AddHead (l, p);
    else if (q != NULL)
    {
        Node* tmp = l.head;
        for (; tmp != NULL; tmp = tmp->next)
            if (tmp->next == q)
                break;
        tmp->next = p;
        p->next = q;
    }
    else
        AddTail (l, p);
}

int main(){

  

    return 0;
}
