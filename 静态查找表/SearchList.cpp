#include <iostream>
#include "SearchList.h"

using namespace std;

void CreateSearchList(Node *head, int length) {
	int n;
	Node* p=head;
	for (int i=0;i<length;i++)
	{
		cin>>n;
		p->data=n;
		Node* q=new Node;
		p->pNext=q;
		p=q;

	}
}

int SearchList(Node *head, DataType data){
	Node* p=head;
	int pos=0;
	while(p!=NULL){
		if(p->data==data){
			cout<<"Ԫ����������λ��Ϊ"<<pos<<endl;
			return 1;
		}
		pos++;
		p=p->pNext;
	}
	cout<<"Ԫ��û����������"<<endl;
	return -1;
}
int main(){
	cout<<"The SearchList length:"<<endl;
	int length;
	cin>>length;
	Node* head=new Node;
	CreateSearchList(head,length);
	SearchList(head,5);
}