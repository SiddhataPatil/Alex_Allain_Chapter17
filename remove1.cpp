/*
 ==============================================================================================================================
 Name        : remove.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Copyright   : Copyright ©  Alex_Allain_Jumping_into_Cpp_Book. Question rights reserved.
 Question    : Remove an element from a binary tree Case 1: It has no children. Case 2: Has one Child Case 3: Has two children
 ==============================================================================================================================
 */
 
#include <iostream>
using namespace std;

struct node
{
    node* left;
    node* right;
    int data;
};


node* insert1 (node *tree, int new_data)
{
    if(tree == NULL)
    {
        node *new_tree = new node;
        new_tree->left=NULL;
        new_tree->right=NULL;
        new_tree->data=new_data;
        return new_tree;
    }
    if (new_data < tree->data)
    {
        tree->left = insert1(tree->left, new_data);
    }
    else
        tree->right = insert1(tree->right, new_data);
}

node* maximum(node* tree)
{
    if(tree==NULL) return NULL;
    if(tree->right==NULL) return tree;
    else return maximum(tree->right);
}

node* remove1(node* tree, int value)
{
    if(tree==NULL)
    {
        return NULL;
    }
    if(tree->data==value)
    {

        if ( tree->left == NULL )
        {
        node* right_subtree = tree->right;
        tree->data=0;
        delete tree;
        return right_subtree;
        }
        if ( tree->right == NULL )
        {
        node* left_subtree = tree->left;
        tree->data=0;
        delete tree;
        return left_subtree;
        }
        node* max_node = maximum( tree->left );
        max_node->left = tree->left;
        max_node->right = tree->right;
        tree->data=0;
        delete tree;
        return max_node;
    }
    else if (tree->data > value)
    {
         return remove1(tree->left,value);
    }
    else if (tree->data < value)
    {
         return remove1(tree->right,value);
    }
}

void print1(node* p1)
{
    cout<<"                          "<<p1->data<<endl;
    cout<<"      "<<p1->left->data;
    cout<<"                                      "<<p1->right->data<<endl;
    cout<<p1->left->left->data;
    cout<<"              "<<p1->left->right->data;
    cout<<"                 "<<p1->right->left->data;
    cout<<"                          "<<p1->right->right->data;
}



int main()
{
node* p = NULL;
node* p1;
p = insert1 (p, 10);
p = insert1 (p, 6);
p = insert1 (p, 5);
p = insert1 (p, 7);
p = insert1 (p, 14);
p = insert1 (p, 18);
p = insert1 (p, 11);
print1(p);
p1 = remove1(p,7);
cout<<endl;
print1(p);
system ("pause");
return 0;
}



