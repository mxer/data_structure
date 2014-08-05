#ifndef DIJKSTRA
#define DIJKSTRA
#include "Dijkstra.h"
#endif

void Dijkstra(AdjMGraph G, int v0, int distance[],int path[]){
	int n=G.Vertices.size();
	int *s=new int[n];
	int minDis,i,j,u;

	// ��ʼ����distance��ʼֵΪ���ʼ��v0�����ӵĵı�ֵ
	for (i=0;i<n;i++)
	{
		distance[i]=G.edge[v0][i];
		s[i]=0;
		if(i!=v0&&distance[i]<MaxWeight)
			path[i]=v0;
		else
			path[i]=-1;
	}
	// ��ǽ��v0�Ѿ��Ӽ���T���뵽����S��
	s[v0]=1;

	// �ڵ�ǰ��δ�ҵ����·���Ľ�㼯��ѡȡ������̾���Ľ��u
	for(i=1;i<n;i++){
		minDis=MaxWeight;
		// ��iʱ�ҵ���Ӧ����С����
		for(j=0;j<n;j++){
			if(s[j]==0&&distance[j]<minDis){
				u=j;
				minDis=distance[j];
			}
		}

		if(minDis==MaxWeight)return;
		// ���u��T���뵽S��
		s[u]=1;
		// �޸Ĵ�v0������������̾�������·��
		for(j=0;j<n;j++)
			if(s[j]==0&&G.edge[u][j]<MaxWeight&&distance[u]+G.edge[u][j]<distance[j]){
				distance[j]=distance[u]+G.edge[u][j];
				path[j]=u;
			}
	}
}