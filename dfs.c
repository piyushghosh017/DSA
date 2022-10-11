#include<stdio.h>

void dfs(int n,int cost[10][10],int u,int v[10]){
    v[u]=1;
    for(int i=0;i<n;i++){
        if(cost[u][i]==1 && v[i]==0 ){
            dfs(n,cost,i,v);
        }
    }
}

int main(){
    int cost[10][10],v[10],flag,n;
    printf("Enter the no of nodes: \n");
    scanf("%d",&n);

    printf("enter adj matrix \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }

    int connected=0;
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            v[i]=0;
        }

        dfs(n,cost,j,v);

        flag=0;
        for(int i=0;i<n;i++){
            if(v[i]==0);
            flag=1;
        }
        if(flag==0)connected=1;

    }
    if(connected==1){
        printf("graph is connected \n");
    }else{
        printf("graph is not connected \n");
    }

    return 0;

}