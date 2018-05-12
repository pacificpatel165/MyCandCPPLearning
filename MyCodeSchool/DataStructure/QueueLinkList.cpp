#include <iostream>
#include <new>

using namespace std;

struct Node 
{
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void EnQueue(int data)
{
    // Create new node
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;

    // Check is Queue is empty
    if(front == NULL && rear ==  NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void DeQueue()
{
    Node *temp = front;
    if(front == NULL)
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    // Check if single element available in queue
    if(front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        // Move to next Queue
        front = front->next;
    }
    delete temp;
}

int Front()
{
    if(front != NULL)
    {
        return front->data;
    }
    cout << "Queue is Empty" << endl;
}

void Print()
{
    Node *temp = front;
    while(temp != NULL)
    {
        cout << "[" << temp->data << "]-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    /* Drive code to test the implementation. */
    // Printing elements in Queue after each Enqueue or Dequeue 
    EnQueue(2); Print(); 
    EnQueue(4); Print();
    EnQueue(6); Print();
    DeQueue();  Print();
    EnQueue(8); Print();
    return 0;
}


