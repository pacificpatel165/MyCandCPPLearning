#include <iostream>
#include <new>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void PrintLinkList(Node *headPointer)
{
    while(headPointer != NULL)
    {
        cout << "[" << headPointer->data << "]-->";
        headPointer = headPointer->next;
    }
    cout << "NULL" << endl;
}

void PrintLinkListRecursively(Node *headPointer)
{
    if(headPointer == NULL)
    {
        cout << "NULL" << endl;
        return;
    }
    cout << "[" << headPointer->data << "]-->";
    PrintLinkListRecursively(headPointer->next);
}

void PrintLinkListRecursivelyReverse(Node *headPointer)
{
    if(headPointer == NULL)
    {
        return;
    }
    PrintLinkListRecursivelyReverse(headPointer->next);
    cout << "[" << headPointer->data << "]-->";
}

void InsertNodeAtBegin(Node **pointerToHead, int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = *pointerToHead;
    *pointerToHead = temp;
}

void InsertNodeAtPosition(Node **pointerToHead, int data, int position)
{
    // if position is first, add at begining
    if(position == 1)
    {
        Node *temp = new Node();
        temp->data = data;
        temp->next = *pointerToHead;
        *pointerToHead = temp;
        return;
    }

    Node *current = *pointerToHead;
    int currPosition = 0;
    // Travers the list till end
    while(current != NULL)
    {
        if(currPosition == position - 2)
        {
            // Insert the node at this location
            Node *temp = new Node();
            temp->data = data;
            temp->next = current->next;
            current->next = temp;
            break; 
        }
        // Continue the loop
        currPosition++;
        current = current->next;
    }
}

void ReverseLinkList_Iterative(Node **pointerToHead)
{
    Node *prev = NULL;
    Node *curr = *pointerToHead;
    Node *future= NULL;

    while(curr != NULL)
    {
        future = curr->next;
        curr->next  = prev;
        prev = curr;
        curr = future;
    }
    *pointerToHead = prev;
}

void ReverseLinkList_Recursive(Node **pointerToHead)
{
    /* empty list */
    if(*pointerToHead == NULL)
    {
        return; 
    }

    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    Node *first = *pointerToHead;
    //cout << "Address of first --> " << first << " and first-->data  " << first->data << endl;
    Node *rest = first->next;

    if(rest == NULL)
    {
        return;
    }

    /* reverse the rest list and put the first element at the end */
    ReverseLinkList_Recursive(&(rest));
    // cout << "After recursion =====================================" << endl;
    // cout << "Address of first->next --> " << first->next << endl;
    /* Attach the rest next to first */
    first->next->next = first;
    // cout << "Address of first --> " << first << " and first-->data  " << first->data << endl;

    /* Diconnect from rest */
    first->next = NULL;

    /* fix the head pointer */
    *pointerToHead = rest;
    //cout << "Address of rest --> " << rest << " and rest-->data  " << rest->data << endl;
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

void DeleteNode(Node **pointerToHead, int position)
{
    Node *curr = *pointerToHead;

    // If it first node, simply delete it
    if(curr->next == NULL && position == 1)
    {
        delete curr;
        return;
    }

    Node *prev = *pointerToHead;
    int currPosition = 1;

    // Traverse the list till end
    while(curr->next != NULL)
    {
        if(position == 1)
        {
            *pointerToHead = curr->next;
            delete curr;
            break;
        }

        prev = curr;
        curr = curr->next;
        currPosition++;
        if(position == currPosition)
        {
            // delete the specific node
            prev->next = curr->next;
            delete curr;
            break;
        }
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
        PrintLinkList(head);
    }
    PrintLinkList(head);
    cout << "==========================================" << endl;
    cout << "Insert node(7) @ 1" << endl;
    cout << "------------------------------------------" << endl;
    InsertNodeAtPosition(&head, 7, 1);
    PrintLinkList(head);
    cout << "==========================================" << endl;
    cout << "Insert node(8) @ 4" << endl;
    cout << "------------------------------------------" << endl;
    InsertNodeAtPosition(&head, 8, 4);
    PrintLinkList(head);
    cout << "==========================================" << endl;
    cout << "Reverse the link list iteratively" << endl;
    cout << "------------------------------------------" << endl;
    ReverseLinkList_Iterative(&head);
    PrintLinkList(head);
    cout << "==========================================" << endl;
    cout << "Reverse the link list recursively" << endl;
    cout << "------------------------------------------" << endl;
    ReverseLinkList_Recursive(&head);
    PrintLinkList(head);
    cout << "==========================================" << endl;
    cout << "Print recursively" << endl;
    cout << "------------------------------------------" << endl;
    PrintLinkListRecursively(head);
    cout << "==========================================" << endl;
    cout << "Print recursively reverse" << endl;
    cout << "------------------------------------------" << endl;
    PrintLinkListRecursivelyReverse(head);
    cout << "NULL" << endl;
    cout << "==========================================" << endl;
    cout << "Delete node @ 1" << endl;
    cout << "------------------------------------------" << endl;
    DeleteNode(&head, 1);
    PrintLinkList(head);
    cout << "==========================================" << endl;
    cout << "Delete node @ 3" << endl;
    cout << "------------------------------------------" << endl;
    DeleteNode(&head, 3);
    PrintLinkList(head);
    cout << "==========================================" << endl;
    cout << "Delete entire link list" << endl;
    cout << "------------------------------------------" << endl;
    DeleteFullLinkList(&head);
    PrintLinkList(head); 
    cout << "==========================================" << endl;
    return 0;
}
