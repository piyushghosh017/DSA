//program to solve the n queen problem 
//grid[][] is represent the 2-d array with value(0 and 1) for grid[i][j]=1 means queen i are placed at j column.
//we can take any number of queen , for this time we take the atmost 10 queen (grid[10][10]).
#include<stdio.h>
#include<stdbool.h>
int grid[10][10];

//print the solution
void print(int n) {
    for (int i = 0;i < n; i++) {
        for (int j = 0;j < n; j++) {
            
                printf("%d",grid[i][j]);
            
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

//function for check the position is safe or not
//row is indicates the queen no. and col represents the possible positions
bool isSafe(int col, int row, int n) {
  //check for same column
    for (int i = 0; i < row; i++) {
        if (grid[i][col]) {
            return false;
        }
    }
    //check for upper left diagonal
    for (int i = row,j = col;i >= 0 && j >= 0; i--,j--) {
        if (grid[i][j]) {
            return false;
        }
    }
    //check for upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; j++, i--) {
        if (grid[i][j]) {
            return false;
        }
    }
    return true;
}

//function to find the position for each queen
//row is indicates the queen no. and col represents the possible positions
bool solve (int n, int row) {
    if (n == row) {
        print(n);
        return true;
    }
    //variable res is use for possible backtracking 
    bool res = false;
    for (int i = 0;i <n;i++) {
        if (isSafe(i, row, n)) {
            grid[row][i] = 1;
            //recursive call solve(n, row+1) for next queen (row+1)
            res = solve(n, row+1) || res;//if res ==false then backtracking will occur 
            //by assigning the grid[row][i] = 0
            
            grid[row][i] = 0;
        }
    }
    return res;
}

int main()
{
  
        int n;
        printf("Enter the number of queen \n");
        scanf("%d",&n);
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                grid[i][j] = 0;
            }
        }
        bool res = solve(n, 0);
        if(res == false) {
            printf( "-1 \n"); //if there is no possible solution
        } else {
            printf("\n");
        }
  return 0;
}