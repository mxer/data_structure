#include <iostream>
using namespace std;

#define DataType int
/*�����Ѵ������±�i=(n-1)/2�������һ����Ҷ�ӽڵ�ĵ㣬������㿪ʼ����������
���£�������ɺ�i--��������һ�������ĸ��£�һ��ֱ��i=0,���ɴ���һ�������С����*/
void CreateHeap(DataType a[],int n, int h){
	int i,j,flag;
	DataType temp;

	i=h;
	j=2*i+1;
	temp=a[i];
	flag=0;
	while(j<n&&flag!=1){
		if(j<n-1&&a[j]<a[j+1])
			j++;
		if(temp>a[j])
			flag=1;
		else{
			a[i]=a[j];
			i=j;
			j=2*i+1;
		}
	}
	a[i]=temp;
}

void InitCreateHeap(DataType a[], int n){
	for(int i=(n-1)/2;i>=0;i--)
		CreateHeap(a,n,i);
}

void display(DataType* a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"	";
	}
}


DataType* HeapSort(DataType a[], int n){
	int i;
	DataType temp;
	InitCreateHeap(a,n);
	for(i=n-1;i>0;i--){
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		// ÿ��ȡ�����ֵ�󣬽��Ѹ���Ϊ����
		display(a,n);
		//����ȡ����һ���Ѷ�Ԫ�أ��������У������������Ԫ�ؽ�����
		//����֮��0��n-1���ƻ������ѽṹ�����Ǻ���Ȼ����Ҫ�ٴ���
		//��һ����Ҷ�ӽڵ�Ľڵ㿪ʼ�����������ѣ���Ϊ��ʱ��ֻ�Ƕ�
		//��Ԫ�ر�ȡ������������Ľ����ȫ���Ա��ֲ��䣬�ʣ�ֻ���
		//��һ�Σ�����ʱ����ʼ��Ϊ0����
		CreateHeap(a,i,0);
	}
	return a;
}


int main(){
	DataType a[]={8,64,2,20,34,54,23,54,14,98};
	DataType* aa= HeapSort(a,sizeof(a)/sizeof(int));
	display(aa,sizeof(a)/sizeof(DataType));
}