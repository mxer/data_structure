/************************************************************************/
/* Prim����ԭ��	
1����ʼʱ������U={A},����V/U={B,C,D,E,F,G}��T={}��Ȼ��Ѱ��U�е���V/U�е���
���ӵ���СȨֵ�ıߣ�Ȼ�󽫵���뵽U��,��õ�ΪB����U={A,B},V/U={C,D,E,F,G}
T={(A,B)}
2,����ֱ��V/UΪNULL*/
/************************************************************************/

#ifndef PRIM
#define PRIM
#include "prim.h"
#endif

// ��ʱ����lowCost[v]�����˼���U�нڵ�u_i�뼯��V/U�нڵ�v_j�����б��е�ǰ������СȨֵ�ı�<u,v>
void prim(AdjMGraph G, MinSpanTree closeVertex[]){
	ItemType x;
	list<ItemType> temp=G.Vertices;
	int n=G.Vertices.size(),minCost;
	int *lowCost=new int[n];
	// �ڵ�0��Ϊ��ʼʱU�ĵ�
	for(int i=0;i<n;i++)
		lowCost[i]=G.edge[0][i];
	x=G.Vertices.front();
	G.Vertices.pop_front();
	closeVertex[0].vertex=x;
	lowCost[0]=-1;
	int k;
	
	for(int i=1;i<n;i++){
		minCost=MaxWeight;
		//Ѱ��U��V/U��,��ڵ�i�����ӵı�Ȩֵ��С�ĵ�
		for(int j=1;j<n;j++){
			if(lowCost[j]<minCost&&lowCost[j]>0){
				minCost=lowCost[j];
				k=j;
			}
		}
		//ȡ����k��Ԫ��
		list<ItemType>::iterator index=temp.begin();
		for(int ii=0;ii<k&&index!=temp.end();ii++,index++){

		}
		x=*index;
		G.Vertices.remove(*index);
		closeVertex[i].vertex=x;
		closeVertex[i].weight=minCost;
		lowCost[k]=-1;
		// ����lowCostΪ�ڵ�k������Ȩֵ����
		for(int i=1;i<n;i++){
			// �����ж��Ƿ�С��lowCost[i]��ԭ������֮ǰ�Ѿ�����U�ĵ���˴ε���������ӣ�֮ǰ�����Ѿ�����������-1�ˣ�����Ҫ�ų��������
			// �簴����ʵ���һ��U�е�ΪA�����ǵڶ�����B��A����ͬ����50������������Ϊ��U�е���V/U�е����СȨֵ��������ﲻ�ܿ��ǣ�B,A��
			// ����Ҫ����һ���ж�
			if(G.edge[k][i]<lowCost[i])
				lowCost[i]=G.edge[k][i];
		}

	}
}