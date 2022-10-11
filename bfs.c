#include<stdio.h>
#include<conio.h>
int a[10][10];

void distance(int v,int n){
    int queue[40],vis[20],dis[20],front,rear;
    int adjEle=0;
    for(int i=1;i<=n;i++){
        vis[i]=dis[i]=0;
    }
    front =rear=0;
    queue[rear++]=v;
    vis[v]=1;
    do{
        adjEle=queue[front++];
        for(int j=1;j<=n;j++){
            if(a[adjEle][j] && !vis[j]){
                dis[j]=dis[adjEle]+1;
                queue[rear++]=j;
			    vis[j]=1;
			    printf("\n\t the vertex %d to %d is of distance=%d\n",v,j,dis[j]);

            }
        }


    }while(front<rear);

}

int main(){
    int n;
    printf("enter no of vertices: \n");
    scanf("%d",&n);
    printf("Enter the adj matrix: \n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=1;i<=n;i++){
        printf("The starting vertex is %d \n",i);
        distance(i,n);
        printf("\t press enter for other source vertex\n");
        getch();
    }

    return 0;
}