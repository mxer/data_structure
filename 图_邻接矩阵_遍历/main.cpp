#include <iostream>
using namespace std;
//#include "AdjMGraph.h"
#include "CreateGraph.h"

int main(){
	AdjMGraph g1;
	ItemType a[]={1,2,3,4,5};
	RowColWeight row[]={{0,1,10},{0,4,20},{1,3,30},{2,1,40},{3,2,50}};

	CreateGraph(&g1,a,sizeof(a)/sizeof(ItemType),row,sizeof(row)/sizeof(RowColWeight));
	cout<<"���������������Ϊ��";
	DepthFirstSearch(g1,Visit);
	cout<<endl;
	cout<<"���������������Ϊ��";
	BroadFirstSearch(g1,Visit);
}