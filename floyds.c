//  All Pair Shortest paths problem

// DONE

#include<stdio.h>
int mini(int a,int b){
    return (a<b)?a:b;
}
int main(){
    int i,j,k,n;
    int cost[10][10],a[10][10];
    printf("Enter no: vertices:");
    scanf("%d",&n);
    printf("Enter the cost adj matrix:");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }

for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            a[i][j]=cost[i][j];
        }
        
    }

    printf("Shortest path obtained:");
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                a[i][j]=mini(a[i][j] ,a[i][k] + a[k][j]);
            }
        }
    }

     for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("\t%d",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}













