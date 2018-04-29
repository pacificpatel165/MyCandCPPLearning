#include <iostream>
#include <new>

using namespace std;

struct Node
{
    int data;
    Node *link;
};

void InsertNodeAtBegin(Node **pointerToHead, int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->data = *pointerToHead;
    *pointerToHead = temp;
}

void DeleteLinkList(Node **pointerToHead)
{
    Node *temp = NULL;
    while(*pointerToHead != NULL)
    {
        temp = *pointerToHead;
        *pointerToHead = (*pointerToHead)->link;
        delete *pointerToHead;
    }
}

void PrintLinkList(Node *headPointer)
{
    while(headPointer != NULL)
    {
        cout << "[" << headPointer->data << "]-->";
        headPointer = headPointer->link;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;
    int numll = 0;
    int data = 0;

    cout << "How many numbers ?" << endl;
    cin >> numll;

    for(int i = 0; i < numll; i++)
    {
        cout << "Enter the number" << endl;
        cin >> data;
        InsertNodeAtBegin(&head, data);
        PrintLinkList(head);
    }
    DeleteLinkList(&head);
    PrintLinkList(head);
    
    return 0;
}
