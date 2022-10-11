// the transitive closure of a given directed graph 
// DONE
#include<stdio.h>
int main(){
    int i,j,k,n;
    int a[10][10];
    printf("Enter no vertices:");
    scanf("%d",&n);

    printf("enter adj mat:");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("Transitive closure:");
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                a[i][j]=a[i][j] || (a[i][k] && a[k][j]);
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