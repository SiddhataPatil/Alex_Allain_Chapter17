/*
 ==============================================================================================================================
 Name        : insert.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Copyright   : Copyright ©  Alex_Allain_Jumping_into_Cpp_Book. Question rights reserved.
 Question    : Insert a number at root, left and right child in binary tree
 ==============================================================================================================================
 */
 
#include <iostream>
using namespace std;

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

void print1(node* p1)
{
    cout<<"         "<<p1->data<<endl;
    cout<<p1->left->data;
    cout<<"                 "<<p1->right->data<<endl;
}

int main()
{
node* p = NULL;
p = insert1 (p, 5);
p = insert1 (p, 3);
p = insert1 (p, 7);
print1(p);
system ("pause");
return 0;
}
