/*
 ==============================================================================================================================
 Name        : in_pre_post.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Copyright   : Copyright ©  Alex_Allain_Jumping_into_Cpp_Book. Question rights reserved.
 Question    : Find the maximum number in the binary tree
 ==============================================================================================================================
 */
 
 /*
 OUTPUT
 
 
                          10
      6                                      14
5              7                 11                          18
Inorder
5
6
7
10
11
14
18

Preorder
10
6
5
7
14
11
18

Postorder
5
7
6
11
18
14
10
 
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

void inorder(node *tree)
{
    if (tree!=NULL)
    {
        inorder(tree->left);
        cout<<tree->data<<endl;
        inorder(tree->right);
    }
}

void preorder (node*tree)
{
    if (tree!=NULL)
    {
        cout<<tree->data<<endl;
        preorder(tree->left);
        preorder(tree->right);
    }
}

void postorder (node*tree)
{
    if (tree!=NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        cout<<tree->data<<endl;
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
cout<<"\nInorder"<<endl;
inorder(p);
cout<<endl;
cout<<"Preorder"<<endl;
preorder(p);
cout<<endl;
cout<<"Postorder"<<endl;
postorder(p);
cout<<endl;
system ("pause");
return 0;
}
