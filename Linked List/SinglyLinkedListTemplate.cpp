#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
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
        cout << l.head -> data << "\t";
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

    a->data = x;
    a->next = NULL;

    return a;
}

void AddHead (List& l, Node* a)
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

void AddTail (List& l, Node* a)
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

void CreateNNode (List& l, int& n)
{
    CreateEmptyList (l);
    cout << "nhap n: ";
    cin >> n;
    int val;

    for (int i = 1; i <= n; i++)
    {
        cin >> val;
        AddHead (l, CreateNode(val));
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

void RemoveHead (List& l)
{
    if (l.head == NULL)
        return;

    Node* tmp = l.head;
    l.head = l.head->next;
    delete tmp;
}

void RemoveAfterQ (List& l, Node* q)
{
    if (q != NULL)
    {
        Node* tmp = q->next;
        q->next = tmp->next;

        if (tmp == l.tail)
            l.tail = q;

        delete (tmp);
    }
}

bool RemoveX (List& l, int x)
{
    Node* slow = NULL;
    Node* fast = l.head;

    while (fast != NULL && fast->data != x)
    {
        slow = fast;
        fast = fast->next;
    }

    if (fast == NULL) // x not found
        return 0;

    if (slow != NULL)
        RemoveAfterQ (l, slow);

    else
        RemoveHead (l);

    return 1;
}

//ascending
void BubbleSort (List& l) 
{
    int min = l.head->data;
    for (Node* i = l.head; i != NULL; i = i->next)
        for (Node* j = i->next; j != NULL; j = j->next)
            if (j->data < i->data)
            {
                swap (j->data, i->data);
            }
                
}

int main(){



    return 0;
}
