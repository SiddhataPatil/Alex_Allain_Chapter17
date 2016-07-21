/*
 ==============================================================================================================================
 Name        : binary_tree.cpp.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Copyright   : Copyright ©  Alex_Allain_Jumping_into_Cpp_Book. Question rights reserved.
 Question    : Write a program to implement a simple binary tree
 // For checking for output, type a no, enter, type another no, enter, type l (for left) OR r (for right)
 ==============================================================================================================================
 */
#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

void disp(node * s)
{
	while (s->left->left!=NULL||s->right->right!=NULL)
{
	cout<<"				"<<s->data<<endl;
	cout<<"	"<<s->left->data<<"						"<<s->right->data<<endl;
	cout<<s->left->left->data<<"	     "<<s->left->right->data<<endl;
	cout<<"						"<<s->right->left->data<<"	    "<<s->right->right->data<<endl;
	cout<<endl;
	s=s->left;
}
}
int count=0;
node* temp=new node;
void get_new(node* s, int no1, int no2, int no3)
{char  tree='a';
count++;

if(count==1)
{
temp=s;
}
node* new_left = new node;
node* new_right = new node;

s->data=no1;
cout<<"Root Data"<<s->data<<endl;
cout<<"Root address" <<s<<endl;

s->left = new_left;
cout<<"Left address"<< s->left<<endl;

s->right = new_right;
cout<<"Right address"<< s->right<<endl;

new_left->left=NULL;
cout<<"New left address: "<<new_left->left<<endl;
new_left->data=no2;
cout<<"left data: "<<new_left->data<<endl;
new_right->right=NULL;
cout<<"New right address: "<<new_right->right<<endl;
new_right->data=no3;
cout<<"Right data: "<<new_right->data<<endl;

cin>>no2;
cin>>no3;
cin>>tree;

if(count==1&&tree=='l')
{
	get_new(s->left, new_left->data, no2, no3);
}
if(count==1&&tree=='r')
{
	get_new(s->right, new_right->data, no2, no3);
}
if(count==2&&tree=='l')
{
	get_new(temp->left, temp->left->data, no2, no3);
}
if(count==2&&tree=='r')
{
	get_new(temp->right, temp->right->data, no2, no3);
}
else return;
}


int main()
{
node* p = new node;
get_new(p,4,2,6);
disp(p);

system("pause");
return 0;
}
