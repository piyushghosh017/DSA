#include<stdio.h>

int maxi(int a,int b){
    return (a>b)?a:b;
}
int main(){
    int i,j,n,k;
    int v[20][20],p[20],w[20];
    printf("Number of items: ");
    scanf("%d",&n);
    printf("Enter weight and profit");
    for(i=1;i<=n;i++){
        printf("weight and profit of %d :",i);
        scanf("%d%d",&w[i],&p[i]);
    }

    printf("Enter weight of knapsack:");
    scanf("%d",&k);

    for(i=0;i<=n;i++){
        v[i][0]=0;
    }
    for(i=0;i<=k;i++){
        v[0][i]=0;
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=k;j++){
            if(w[i]>j){
                v[i][j]=v[i-1][j];
            }
            else{
                v[i][j]=maxi(v[i-1][j],v[i-1][j-w[i]]+p[i]);
            }
        }
    }

    printf("\n DP table:");
    for(i=0;i<=n;i++){
        for(j=0;j<=k;j++){
            printf("%d\t",v[i][j]);
        }
        printf("\n");
    }

    printf("\n Profit is :%d",v[n][k]);
    j=k;
    printf("subset are :{");
    for(i=n;i>=1;i--){
        if(v[i][j]!=v[i-1][j]){
            printf("Items %d :",i);
            j=j-w[i];
        }
    }
    printf("}");


    return 0;
}