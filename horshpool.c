// Horspool algorithm for String Matching
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
    int tab[128];
    char t[100],p[25];
    int n,i,k,j,m,flag=0;
    printf("enter the text\n");
    gets(t);
    n=strlen(t);
    printf("enter the pattern:\n");
    gets(p);
    m=strlen(p);
    for(i=0;i<128;i++){
        tab[i]=m;
    }
    for(j=0;j<m-1;j++)
		tab[p[j]]=m-1-j;

    i=m-1;
    while(i<=n-1){
        k=0;
        while( (k<=m-1) && (p[m-1-k]==t[i=k]) ){
            k++;
        }
        if(k==m){
            printf("the position of pattern is %d\n",i-m+2);
            flag=1;
            break;
        }else{
            i=i+tab[t[i]];
        }
    }
    if(!flag){
        printf("Pattern is not found in the given text \n");
    }
		

}