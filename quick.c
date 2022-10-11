// The key process in quickSort is a partition().
// Element x of an array as the pivot, put x at its correct position ,
// put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x

#include<stdio.h>
#include<time.h>
int arr[100];
double t;

int partition(int arr[],int s,int e){
int pivot=arr[s];
int cnt=0;
for(int i=s+1;i<=e;i++){
    if(arr[i]<=pivot){
        cnt++;
    }
}
//place pivot at right position
int pivotIndex = s + cnt;
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[s];
    arr[s] = temp;

    //left and right wala part smbhal lete h 
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }

    }

    return pivotIndex;

}

void quickSort(int arr[],int s,int e){
    int pi;
    clock_t begin, end; 
    if(s>=e)return;
    //partitioon karenfe
    begin = clock();
    pi=partition(arr,s,e);

    //left part sort karo
    quickSort(arr,s,pi-1);
    //right wala part sort karo
    quickSort(arr,pi+1,e);
    end=clock();
    t=end-begin;
    printf("\nTime taken %f cpu1 cycle",(double)t/CLOCKS_PER_SEC);


}

int main(){
    int i,n;
    printf("Enter no of ele:");
    scanf("%d",&n);
    printf("Enter ele:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,n-1);
    for(int i=0; i<n; i++) 
    {
        printf("%d",arr[i]);
    } 
    return 0;


}