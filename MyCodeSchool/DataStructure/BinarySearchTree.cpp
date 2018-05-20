// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 
#include <iostream>
#include <new>
#include <queue>

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

int findMin(BstNode *root)
{
    if(root == NULL)
    {
        cout << "Tree is empty" << endl;
        return -1;
    }
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int findMinRecursive(BstNode *root)
{
    if(root == NULL)
    {
        cout << "Tree is empty" << endl;
        return -1;
    }
    if(root->left == NULL)
    {
        return root->data;
    }
    findMinRecursive(root->left);
}

int findMax(BstNode *root)
{
    if(root == NULL)
    {
        cout << "Tree is empty" << endl;
        return -1;
    }
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

/*
 * Height of a Node ==> Number of edges in longest path from the node to a leaf.
 * Height of tree ==> Height of root
 * Height of tree with 1 node = 0
 * Depth of a node ==> No. of edges in path from root to that node.
 */

int max(int left, int right)
{
    if(left >= right)
        return left;
    else
       return right ;
}

int findHeight(BstNode *root)
{
    if(root == NULL)
    {
        return -1; // Since we are calaculating no. of height as edges no node.
    }
    return (max(findHeight(root->left), findHeight(root->right)) + 1);
}

/*
 * Breadth-first ==> Level Order, Traverse the node on level, use queue machanism to traverse
 */

void PrintLevelOrder(BstNode *root)
{
    if(root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    queue<BstNode *> discoverNode;
    discoverNode.push(root);
    // While there is at least one discovered node
    while(!discoverNode.empty())
    {
        BstNode *visitedNode = discoverNode.front();
        cout << visitedNode->data << " ";
        // Push the childeren of visited node in queue
        if(visitedNode->left != NULL)
        {
            discoverNode.push(visitedNode->left);
        }
        if(visitedNode->right != NULL)
        {
            discoverNode.push(visitedNode->right);
        }
        // Now remove the discovered node from queue
        discoverNode.pop();
    }
}

/*
 * Depth-first ==> Traverse the node in 
 * PreOrder(Data, Left, Right), InOrder(Left, Data, Right) or PostOrder(Left, Right, Data)
 */

void PrintPreOrder(BstNode *root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PrintPreOrder(root->left);
    PrintPreOrder(root->right);
}

void PrintInOrder(BstNode *root)
{
    if(root == NULL)
    {
        return;
    }
    PrintInOrder(root->left);
    cout << root->data << " ";
    PrintInOrder(root->right);
}

void PrintPostOrder(BstNode *root)
{
    if(root == NULL)
    {
        return;
    }
    PrintPostOrder(root->left);
    PrintPostOrder(root->right);
    cout << root->data << " ";
}

// Chekc if a given binary tree is BST(Binary Search Tree)
bool IsSubTreeLesser(BstNode* root, int value)
{
    if(root == NULL)
    {
        return true;
    }
    if((root->data <= value) &&
        IsSubTreeLesser(root->left, value) &&
        IsSubTreeLesser(root->right, value))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsSubTreeGreater(BstNode* root, int value)
{
    if(root == NULL)
    {
        return true;
    }
    if((root->data > value) &&
        IsSubTreeGreater(root->left, value) &&
        IsSubTreeGreater(root->right, value))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsBinarySearchTree(BstNode* root)
{
    if(root == NULL)
    {
        return true;
    }
    if( IsSubTreeLesser(root->left, root->data) &&
        IsSubTreeGreater(root->right, root->data) &&
        IsBinarySearchTree(root->left) &&
        IsBinarySearchTree(root->right))
    {
        return true;
    }
    else
    {
        return false;
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
    //cin>>number;
    number = 12;
    //If number is found, print "FOUND"
    if(Search(root,number) == true)
    {
        cout<<"Found\n";
    }
    else
    {
        cout<<"Not Found\n";
    }
    cout << "Minimium number in tree " << findMin(root) << endl;
    cout << "Maximum number in tree " << findMax(root) << endl;
    cout << "Minimium number in tree(Recursive) " << findMinRecursive(root) << endl;
    cout << "Height of tree " << findHeight(root) << endl;
    cout << "Print Level Order of nodes [" ;
    PrintLevelOrder(root);
    cout << "]" << endl;
    cout << "Print Pre Order of nodes [" ;
    PrintPreOrder(root);
    cout << "]" << endl;
    cout << "Print In Order of nodes [" ;
    PrintInOrder(root);
    cout << "]" << endl;
    cout << "Print Post Order of nodes [" ;
    PrintPostOrder(root);
    cout << "]" << endl;
    cout << "Is tree BST(Binary Search Tree [" << IsBinarySearchTree(root) << "]" << endl;
    return 0;
}
