// DONE
#include<stdio.h>
void main()
{
	int i,j,k,n,c[50][50];
	printf("\n enter the value of n & k\n");
	scanf("%d%d",&n,&k);
	for(i=0;i<=n;i++){
		for(j=0;j<=k;j++){
			c[i][j]=0;
		}
		
	}
    for(i=0;i<=n;i++){
	for(j=0;j<=k;j++){
        if(j==0 || j==i){
            c[i][j]=1;
        }
        else {
			if(j>i)break;
			else{
            c[i][j]=c[i-1][j-1]+c[i-1][j];

			}
        }
    }

    }
	
	 
	printf("\n the table for valuation is\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=k;j++)
		printf("\t%d",c[i][j]);
		printf("\n");
	}
	printf("\n\t the binomial coefficient of C(%d,%d) is %d\n",n,k,c[n][k]);
}
