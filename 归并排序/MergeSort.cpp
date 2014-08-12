#include <iostream>
using namespace std;
#define DataType int


void display(DataType* a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"	";
	}
}
void Merge(DataType a[], int n, DataType swap[], int k){
	int m=0,u1,l2,i,j,u2;
	int l1=0;

	while(l1+k<n-1){
		l2=l1+k;//�ڶ������鿪ʼ
		u1=l2-1;//��һ�������β
		u2=(l2+k-1<=n-1)?l2+k-1:n-1;//�ڶ��������β

		for(i=l1,j=l2;i<=u1&&j<=u2;m++){
			if(a[i]<=a[j]){
				swap[m]=a[i];
				i++;
			}
			else{
				swap[m]=a[j];
				j++;
			}
		}
		//������2�Ѿ��鲢�꣬��������1��ʣ���Ԫ�طŵ�����swap��
		while(i<=u1){
			swap[m]=a[i];
			m++;
			i++;
		}
		//������1�Ѿ��鲢�꣬��������2��ʣ��Ԫ�طŵ�����swap
		while(j<=u2){
			swap[m]=a[j];
			m++;
			j++;
		}
		l1=u2+1;
	}
	for(i=l1;i<n;i++,m++)swap[m]=a[i];
}

void MergeSort(DataType a[], int n){
	int i,k=1;
	DataType *swap;
	swap=new DataType[n];
	while(k<n){
		Merge(a,n,swap,k);
		for(i=0;i<n;i++){
			a[i]=swap[i];
		}
		k=2*k;
	}
	delete [] swap;
}

int main(){
	DataType a[]={8,64,2,20,34,54,23,55,14,98};
	display(a,sizeof(a)/sizeof(DataType));
	MergeSort(a,sizeof(a)/sizeof(int));
	display(a,sizeof(a)/sizeof(DataType));
}