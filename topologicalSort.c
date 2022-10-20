#include<stdio.h>
int s[10],cost[10][10],res[10];
int i,j,n,k=1;

void dfs(int u){
    s[u]=1;
    int i;
    for(i=1;i<=n;i++){
        if( cost[u][i]==1 && s[i]==0){
            dfs(i);
        }
    }
    res[k++]=u;
}

void main(){

    printf("Enter vertices:\n");
    scanf("%d",&n);

    printf("Enter adj matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        s[i]=0;
    }

    for(i=1;i<=n;i++){
        if(s[i]==0){
            dfs(i);
        }
    }
    printf("topological order is:\n");
    for(int i=n;i>=1;i--){
        printf("%d ",res[i]);
    }

}