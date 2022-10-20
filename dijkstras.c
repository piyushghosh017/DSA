#include<stdio.h>

void main(){
    int n,cost[10][10],i,j,v,u,vis[10],dis[10],min;

    printf("enter no: vertices");
    scanf("%d",&n);

    printf("cost matrix");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }

    printf("enter no: source vertices");
    scanf("%d",&v);

    for(i=1;i<=n;i++){
        vis[i]=0;
        dis[i]=cost[v][i];
    }
    vis[v]=1;
    dis[v]=0;

    for(i=2;i<=n-1;i++){
        min=999;
        for(j=1;j<=n;j++){
            if(vis[j]==0 && dis[j]<min){
                min=dis[j];
                u=j;
            }
        }
        vis[u]=1;
        // relaxation
        for(j=1;j<=n;j++){
            if(vis[j]==0){
                if(dis[j]>(dis[u]+cost[u][j])){
                    dis[j]=(dis[u]+cost[u][j]);
                }
            }
        }
    
    }
    printf ("VERTEX\tDESTINATION\tCOST\n");
  for (i = 1; i <= n; i++)
    printf ("    %d\t    %d\t\t %d\n", v, i, dis[i]);
    getch();

}