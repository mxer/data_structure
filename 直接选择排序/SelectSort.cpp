#include <iostream>
using namespace std;
#define  DataType int

void display(DataType* a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"	";
	}
}
DataType* SelectSort(DataType a[],int n){
	// ����������ѡ��������Сֵ
	for(int i=0;i<n-1;i++){
		int min_index=i;
		
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min_index])
				min_index=j;
		}
		// ��min_index!=iʱ��������������һ����Ҳ�����±�Ϊi��������
		if(min_index!=i){
			int temp=a[i];
			a[i]=a[min_index];
			a[min_index]=temp;
		}
		display(a,n);
	}
	return a;
}




int main(){
	DataType a[]={8,64,2,20,34,54,23,54,14,98};
	DataType* aa= SelectSort(a,sizeof(a)/sizeof(int));
	display(aa,sizeof(a)/sizeof(DataType));
}