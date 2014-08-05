#include <iostream>
#include <string>   
#include <stdio.h>   
using namespace std;   

#define MaxVertexNum 100   
#define INF 32767   
typedef struct  
{   
	char vertex[MaxVertexNum];   
	int edges[MaxVertexNum][MaxVertexNum];   
	int n,e;   
}MGraph;   

void CreateMGraph(MGraph &G)   
{   
	int i,j,k,p;   
	cout<<"�����붥�����ͱ���:";   
	cin>>G.n>>G.e;   
	cout<<"�����붥��Ԫ��:";   
	for (i=0;i<G.n;i++)   
	{   
		cin>>G.vertex[i];   
	}   
	for (i=0;i<G.n;i++)   
	{   
		for (j=0;j<G.n;j++)   
		{   
			G.edges[i][j]=INF;   
			if (i==j)   
			{   
				G.edges[i][j]=0;   
			}   
		}   
	}      
	for (k=0;k<G.e;k++)   
	{   
		cout<<"�������"<<k+1<<"����ͷ��β��ź���Ӧ��Ȩֵ:";   
		cin>>i>>j>>p;   
		G.edges[i][j]=p;   
	}   
}   
void Dispath(int A[][MaxVertexNum],int path[][MaxVertexNum],int n);

void Floyd(MGraph G)
{
	int A[MaxVertexNum][MaxVertexNum],path[MaxVertexNum][MaxVertexNum];
	int i,j,k;
	for (i=0;i<G.n;i++)
	{
		for (j=0;j<G.n;j++)
		{
			A[i][j]=G.edges[i][j];
			path[i][j]=-1;
		}
	}
	for (k=0;k<G.n;k++)
	{
		for (i=0;i<G.n;i++)
		{
			for (j=0;j<G.n;j++)
			{
				if (A[i][j]>A[i][k]+A[k][j])
				{
					A[i][j]=A[i][k]+A[k][j];
					path[i][j]=k;
				}
			}
		}
	}
	Dispath(A,path,G.n);
}

void Ppath(int path[][MaxVertexNum],int i,int j)
{
	int k;
	k=path[i][j];
	if (k==-1)
	{
		return;
	}
	Ppath(path,i,k);//path[i][j]��i��ʾ��vi��vj�����·���У�vj��ǰһ��������Ϊk����ˣ������õݹ�һ�ε�path=-1������ʼ��㣬�ɵݹ���������Ϳ���������·���������
	printf("%d,",k);
	Ppath(path,k,j);
}

void Dispath(int A[][MaxVertexNum],int path[][MaxVertexNum],int n)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (A[i][j]==INF)
			{
				if (i!=j)
				{
					printf("��%d��%dû��·��\n",i,j);
				}
			}
			else
			{
				printf("  ��%d��%d=>·������:%d·��:",i,j,A[i][j]);
				printf("%d,",i);
				Ppath(path,i,j);
				printf("%d\n",j);
			}
		}
	}
}

int main()
{
	//freopen("input2.txt", "r", stdin);
	MGraph G;
	CreateMGraph(G);
	Floyd(G);
	return 0;
}