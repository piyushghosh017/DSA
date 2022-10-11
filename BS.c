#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX 2000
int LS(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int BS(int array[],int first,int last,int middle,int search){

  while (first <= last) {
    if (array[middle] < search)
      first = middle + 1;
    else if (array[middle] == search) {
      return 1;
      break;
    }
    else
      last = middle - 1;

    middle = (first + last)/2;
  }
  return -1;
}

int main()
{
  int c, first, last, middle, n, search, arr[100];

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%d", &arr[c]);

  printf("Enter value to find\n");
  scanf("%d", &search);
    
    int op;
  while(1)
  {
    printf("\n.....MENU.....\n 1.Binary Search\n 2.Linear Search\n 3.Exit\n");
    printf("\nEnter your choice\n");
    scanf("%d",&op);

  switch(op)
  {
    case 1:
    first = 0;
    last = n - 1;
    middle = (first+last)/2;
    
    int pos=BS(arr,first,last,middle,search);
    if(pos==-1)
	       printf("\n\n Unsuccessful search");
	else{
        printf("\n Element %d is found at position %d",search,pos+1);
	    // printf("\n Time taken is %lf CPU1 cycles\n",(end-begin)/CLK_TCK);
	    break;
    }
    case 2:
        //  begin=clock();
	      pos=LS(arr,n,search);
	    //   end=clock();
	     if(pos==-1)
		 printf("\n\n Unsuccessful search");
	     else{
            printf("\n Element %d is found at position %d",search,pos+1);
	        // printf("\n Time taken is %lf CPU cycles\n",(end-begin)/CLK_TCK);
	        break;
         }
		
    default:printf("\nInvalid choice entered\n");
	    exit(0);

	       
  }
  }
  

  return 0;
}