#include <iostream>
#include <new>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *top = NULL;

// Insert the node at begining
void Push(int data)
{
    cout << "Push(" << data << ")"<< endl;
    Node *newNode = new Node();
    newNode->data = data;
    
    newNode->next = top;
    top = newNode;
}

// Delete the top node of link list and assgin to next node
void Pop()
{
    cout << "Pop()" << endl;
    if(top == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }
    Node *temp = top;
    top = top->next;
    delete temp;
}

// Check if it is empty
bool isEmpty()
{
    if(top == NULL)
    {
        cout << "List is Empty " << endl;
        return true;
    }
    cout << "List is not Empty " << endl;
    return false;
}

// Return the top value, and don't delete node
int Top()
{
    cout << "Top() --> " << top->data << endl;
    return top->data;
}

void ReverseStack()
{
    if(top == NULL)
    {
        return;
    }
    stack<Node *> S; // store the reference of node
    
    // Push all the element into stack
    Node *temp = top;
    while(temp != NULL)
    {
        S.push(temp);
        temp = temp->next;
    }

    // Pop the element and reverse it
    temp = S.top(); // Temp is at top
    top = temp; // Store the head to temp
    S.pop();
    while(!S.empty())
    {
        temp->next = S.top();
        S.pop();// delete the element
        temp = temp->next;
    }
    // Set the end node as NULL
    temp->next = NULL;
}

void Print()
{
    Node *current = top;
    while(current != NULL)
    {
        cout << "[" << current->data << "]-->";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void CheckBalancedParenthesis(string myString)
{
    // push the characters in stacks
    stack<char> expression;
    cout << "Parenthesis in string " << myString;

    for(int i = 0; i < myString.length(); i++)
    {
        if((myString[i] == '{') || (myString[i] == '[') || (myString[i] == '('))
        {
            expression.push(myString[i]);
            //cout << "Pushed " << expression.top() << endl; 
        }
        else if((myString[i] == '}') || (myString[i] == ']') || (myString[i] == ')'))
        {
            if(!expression.empty() && 
                (((expression.top() == '{') && (myString[i] == '}')) || 
                 ((expression.top() == '[') && (myString[i] == ']')) || 
                 ((expression.top() == '(') && (myString[i] == ')'))))
            {
                //cout << "Poped the stack " << myString[i] << endl;
                expression.pop();
            }
            else
            {
                cout << " -->[Not Matched]" << endl;
                return;
            }
        }
    }

    if(expression.empty())
    {
       cout << " -->[Matched]" << endl;
    } 
}



int main()
{
    // Create some stack
    isEmpty();
    Push(3);
    Push(6);
    Push(2);
    Top();
    Push(9);
    Print();
    Pop();
    Print();
    Push(7);
    isEmpty();
    Print();
    Top();
    Pop();
    Pop();
    Pop();
    isEmpty();
    Print();
    Pop();
    isEmpty();
    Print();
    Push(2);
    Push(4);
    Push(6);
    Push(8);
    Push(10);
    Print();
    cout << "Reverse the Stack" << endl;
    ReverseStack();
    Print();

    // Create stack of characters
    string myString = "[(a+b) * (c & d)]";
    CheckBalancedParenthesis(myString);
    myString = "[)a+b( * (c & d)]";
    CheckBalancedParenthesis(myString);
    return 0; 
}
