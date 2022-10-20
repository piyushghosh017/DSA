#include<stdio.h>
#include<time.h>

int arr[100];
int n;

void swap(int* a, int* b)
{
 
    int temp = *a;
 
    *a = *b;
 
    *b = temp;
}

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right =2*i+2;

    if(left < n && arr[left] > arr[largest]){
        largest=left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&arr[i], &arr[largest]);

        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){
    
    for (int i = n - 1; i >= 0; i--) {
        //step 1:
        swap(&arr[0], &arr[i]);
       // step 2:
        heapify(arr, i, 0);
    }
}

void main(){
    int choice;
    
    clock_t st,ed;
    do{
        printf("Enter no of elements:\n");
        scanf("%d",&n);
        printf("Enter the ele:\n");
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }

        st=clock();
        //heap creation
        for (int i = n / 2 - 1; i >= 0; i--)
                heapify(arr, n, i);

        //heap sort
        heapSort(arr,n);
        ed=clock();

        printf("Sorted array is: \n");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
        printf("\nTimetaken is %lf ",(double)(ed-st)/CLOCKS_PER_SEC);

        printf("\ndo u want to continue Press 1 else 0\n");
        scanf("%d",&choice);

    }while(choice);
    
}