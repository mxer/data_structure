#include <iostream>
#include "BiTree.h"
using namespace std;

int main(){
	Node* root,*p,*pp;
	Initiate(&root);
	p=InsertLeftNode(root,'A');
	p=InsertLeftNode(p,'B');
	p=InsertLeftNode(p,'D');
	p=InsertRightNode(p,'G');
	p=InsertRightNode(root->leftChild,'C');

	pp=p;
	InsertLeftNode(p,'E');
	InsertRightNode(pp,'F');

	PrintBiTree(root,0);
	cout<<"ǰ�����:";
	PreOrder(root->leftChild,Visit);
	cout<<endl;
	PreOrder_stack(root->leftChild,Visit);
 	cout<<endl;
	cout<<"���������";
	InOrder(root->leftChild,Visit);
	cout<<endl;
	InOrder_stack(root->leftChild,Visit);
	cout<<endl;
	cout<<"����������";
	PostOrder(root->leftChild,Visit);
	cout<<endl;
	PostOrder_stack(root->leftChild,Visit);
	cout<<endl;
	cout<<"��α���:";
	LevelOrder_deque(root->leftChild,Visit);

	Destroy(&root);

}