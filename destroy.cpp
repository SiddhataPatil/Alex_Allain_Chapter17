/*
 ==============================================================================================================================
 Name        : destroy.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Copyright   : Copyright ©  Alex_Allain_Jumping_into_Cpp_Book. Question rights reserved.
 Question    : Delete the binary tree
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
    cout<<"                          "<<p1->data<<endl;
    cout<<"      "<<p1->left->data;
    cout<<"                                      "<<p1->right->data<<endl;
    cout<<p1->left->left->data;
    cout<<"              "<<p1->left->right->data;
    cout<<"                 "<<p1->right->left->data;
    cout<<"                          "<<p1->right->right->data;


}

void destroy (node* p1)
{
    if (p1!=NULL)
    {
       destroy(p1->left);
       destroy(p1->right);
       cout<<"\n Deleting...."<<p1->data<<endl;
       delete p1;
    }
}

int main()
{
node* p = NULL;
node* p1;
p = insert1 (p, 10);
p1=p;
p = insert1 (p, 6);
p = insert1 (p, 5);
p = insert1 (p, 7);
p = insert1 (p, 14);
p = insert1 (p, 18);
p = insert1 (p, 11);
print1(p);
destroy(p);

system ("pause");
return 0;
}
