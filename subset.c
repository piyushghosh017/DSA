#include<stdio.h>
int d,n,arr[10],set[10];
int count,flag=0;

void display(int c){
    int i;
    printf("{");
    for(i=0;i<count;i++){
        printf("%d",set[i]);
        printf("}\n");
    }
}

void subset(int sum,int i){
    if(sum==d){
        flag=1;
        display(count);
        return;

    }
    if(sum >d || i>=n){
        return;
    }
    else{
        set[count]=arr[i];
        count++;
        subset(sum+arr[i],i+1);
        count--;
        subset(sum,i+1);

    }
}

int main(){
    int i,j;
    printf("enter no: of elements \n");
    scanf("%d",&n);
   
    printf("enter set of elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("enter the sum:\n");
    scanf("%d",&d);

    printf("Subset sum are:\n");
    subset(0,0);
    if(flag==0)printf("no sol\n");
    return 0;
}