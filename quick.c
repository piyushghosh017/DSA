// The key process in quickSort is a partition().
// Element x of an array as the pivot, put x at its correct position ,
// put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x

#include<stdio.h>
#include<time.h>
int arr[100];

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
    if(s>=e)return;
    //partitioon karenfe
    pi=partition(arr,s,e);
    //left part sort karo
    quickSort(arr,s,pi-1);
    //right wala part sort karo
    quickSort(arr,pi+1,e);
   
}

int main(){
    int i,n,ch;
    clock_t st,ed;
    while(1){
        printf("\nMENU:\n1.wort case analysis\n2.best case analysis\nenter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("worst case :\n");
                printf("Enter no of ele:");
                scanf("%d",&n);
                printf("enter the elements :\n");
                for(int i=0;i<n;i++){
                    scanf("%d",&arr[i]);
                }
                printf("elemets are:\n");
                for(int i=0;i<n;i++){
                    printf("%d ",arr[i]);
                }
                st=clock();
                quickSort(arr,0,n-1);
                ed=clock();
                printf("\narray after sort:\n");
                for(int i=0;i<n;i++){
                    printf("%d ",arr[i]);
                }
                printf("\ntime taken is %lf secs",(double)(ed-st)/CLOCKS_PER_SEC);
                break;
            case 2:
                printf("worst case :\n");
                printf("RANDOM elements :\n");
                for(int i=0;i<n;i++){
                    arr[i]=rand()%100;
                }
                printf("array before sort:\n");
                for(int i=0;i<n;i++){
                    printf("%d ",arr[i]);
                }
                st=clock();
                quickSort(arr,0,n-1);
                ed=clock();

                printf("\narray after sort:\n");
                for(int i=0;i<n;i++){
                    printf("%d ",arr[i]);
                }
                printf("\ntime taken is %Lf secs",(double)(ed-st)/CLOCKS_PER_SEC);
                break;
            default:
                printf("invalid input..!\n");
                break;
        }
        
    }
   
    return 0;

}