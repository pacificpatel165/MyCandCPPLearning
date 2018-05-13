// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 
#include <iostream>
#include <new>

using namespace std;

//Definition of Node for Binary search tree
struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

// Function to create a new Node in heap
BstNode* GetNewNode(int data)
{
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// To insert data in BST, returns address of root node 
BstNode* Insert(BstNode* head, int data)
{
    if(head == NULL) // empty tree
    {
        head = GetNewNode(data);
    }
    // if data to be inserted is lesser, insert in left subtree.
    else if(data <= head->data)
    {
        head->left = Insert(head->left, data);
    }
    // else, insert in right subtree.
    else
    {
        head->right = Insert(head->right, data);
    }
    return head;
}

//To search an element in BST, returns true if element is found
bool Search(BstNode* head, int data)
{
    if(head == NULL)
    {
        return false;
    }
    else if(data == head->data)
    {
        return true;
    }
    else if(data <= head->data)
    {
        Search(head->left, data);
    }
    else
    {
        Search(head->right, data);
    }
}


int main() 
{
    BstNode* root = NULL;  // Creating an empty tree
    /*Code to test the logic*/
    root = Insert(root,15); 
    root = Insert(root,10); 
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);
    // Ask user to enter a number.
    int number;
    cout<<"Enter number be searched\n";
    cin>>number;
    //If number is found, print "FOUND"
    if(Search(root,number) == true)
    {
        cout<<"Found\n";
    }
    else
    {
        cout<<"Not Found\n";
    }
    return 0;
}
