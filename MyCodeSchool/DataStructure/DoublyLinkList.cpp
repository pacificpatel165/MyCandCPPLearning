#include <iostream>
#include <new>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *CreateNewNode(int data)
{
    Node *newNode = new Node();
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = data;

    return newNode;
}

void PrintLinkList(Node *headPointer)
{
    cout << "Foward Direction : ";
    if(headPointer == NULL)
    {
        cout << "NULL" << endl;
        return;
    }
    while(headPointer != NULL)
    {
        cout << "[" << headPointer->data << "]-->";
        headPointer = headPointer->next;
    }
    cout << "NULL" << endl;
}

void PrintReverseLinkList(Node *headPointer)
{
    cout << "Backward Direction : ";
    if(headPointer == NULL)
    {
        cout << "NULL" << endl;
        return;
    }
    while(headPointer->next != NULL)
    {
        headPointer = headPointer->next;
    }
    while(headPointer != NULL)
    {
        cout << "[" << headPointer->data << "]-->";
        headPointer = headPointer->prev;
    }
    cout << "NULL" << endl;
}

void InsertNodeAtBegin(Node **pointerToHead, int data)
{
    Node *newNode = CreateNewNode(data);

    if(*pointerToHead == NULL)
    {
        *pointerToHead = newNode;
        return;
    }
    (*pointerToHead)->prev = newNode;
    newNode->next = *pointerToHead;
    *pointerToHead = newNode;
}

void InsertNodeAtPosition(Node **pointerToHead, int data, int position)
{
    // if position is first, add at begining
    if(position == 1)
    {
        InsertNodeAtBegin(pointerToHead, data);
        return;
    }

    Node *current = *pointerToHead;
    int currPosition = 0;
    // Travers the list till end
    while(current != NULL)
    {
        // Traverse till position - 2
        if(currPosition == position - 2)
        {
            // Insert the node at this location
            Node *newNode = CreateNewNode(data);

            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
            newNode->prev = current;

            break; 
        }
        // Continue the loop
        currPosition++;
        current = current->next;
    }
}

void DeleteFullLinkList(Node **pointerToHead)
{
    Node *temp = NULL;
    while(*pointerToHead != NULL)
    {
        temp = *pointerToHead;
        *pointerToHead = (*pointerToHead)->next;
        delete *pointerToHead;
    }
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
    }
    PrintLinkList(head);
    PrintReverseLinkList(head);
    cout << "==========================================" << endl;
    cout << "Insert node(7) @ 1" << endl;
    cout << "------------------------------------------" << endl;
    InsertNodeAtPosition(&head, 7, 1);
    PrintLinkList(head);
    PrintReverseLinkList(head);
    cout << "==========================================" << endl;
    cout << "Insert node(8) @ 4" << endl;
    cout << "------------------------------------------" << endl;
    InsertNodeAtPosition(&head, 8, 4);
    PrintLinkList(head);
    PrintReverseLinkList(head);
    cout << "==========================================" << endl;
    cout << "Delete entire link list" << endl;
    cout << "------------------------------------------" << endl;
    DeleteFullLinkList(&head);
    PrintLinkList(head); 
    PrintReverseLinkList(head);
    cout << "==========================================" << endl;
    return 0;
}
