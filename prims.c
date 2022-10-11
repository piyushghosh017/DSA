// Minimum Cost Spanning Tree of a given
//  undirected graph 

#include<stdio.h>
#include<stdbool.h>
int n;

void printMst(int parent[],int cost[n][n]){
    printf("MInimun cost is ");
    int sum=0,i;
    for(i=0;i<n;i++){
        sum+=cost[i][parent[i]];
    }
    printf("%d",sum);
}

int minKey(int key[],bool mstSet[]){
    printf("into minkey");
    int min=999,min_Idx;
    int v;
    for(v=0;v<n;v++){
        if(mstSet[v]==false && key[v]<min){
            min=key[v],min_Idx=v;
        }
    }
    return min_Idx;

}

int main(){
    int cost[10][10];
    int n,i,j;
    printf("enter no of node:");
    scanf("%d",&n);

    printf("adj matrix");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    int key[n],parent[n];
    bool mstSet[n];
    printf("init key mstset");
    for(i=0;i<n;i++){
        key[i]=999;
        mstSet[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    int count,u;
    printf("minkey fun");
    for(count=0;count<n-1;count++){
        u=minKey(key,mstSet);
        mstSet[u]=true;
    }

    printf("adj element of u");
    for(i=0;i<n;i++){
        if(cost[u][i] && mstSet[i]==false && cost[u][i]<key[i]){
            parent[i]=u;
            key[i]=cost[u][i];

        }
    }
    printf("adj element of u");
    printMst(parent,cost);
    return 0;

}