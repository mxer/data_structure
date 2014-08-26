#include <iostream>
#include <vector>
#include <deque>
using namespace std;
// ��Ϊ���Ǵ�������Ҫ�õ�������ʣ�����������ʹ��vector
typedef vector< deque<int> > LinQueue; 
#define DataType int
// nΪ������������mΪ�����������λ��dΪ����������Ͱ��һ��
DataType* RadixSort(DataType a[], int n, int m, const int d){
	int i,j,k,power=1;
	LinQueue tub(d);

	for(i=0;i<m;i++){
		if(i==0)
			power=1;
		else
			power=power*d;
		//
		for (j=0;j<n;j++)
		{
			//�����j�����ĵ�iλ
			k=a[j]/power%d;
			tub.at(k).push_back(a[j]);
		}
		k=0;
		for(j=0;j<d;j++){
			while(!tub[j].empty()){
				
				a[k]=tub.at(j).front();
				tub[j].pop_front();
				k++;
			}
		}

	}
	return a;

}
void display(DataType* a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"	";
	}
}


int main(){
	DataType a[]={8,64,2,20,34,54,23,54,14,98};
	DataType* aa=RadixSort(a,sizeof(a)/sizeof(int),2,10);
	display(a,sizeof(a)/sizeof(DataType));
}