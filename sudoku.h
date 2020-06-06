#include <bits/stdc++.h>

#define unassigned 0
#define N 9
using namespace std;

class sudoku{
    private:
bool checkRow(int grid[N][N],int row,int num);
bool checkCol(int grid[N][N],int col,int num);
    bool checkBox(int grid[N][N],int boxStartRow,int boxStartCol,int num);
    void printer(int grid[N][N]);
    bool isSafe(int grid[N][N],int row,int col,int num);
    bool findUnsignedLocation(int grid[N][N],int &row,int &col);
    bool solveSudoku(int grid[N][N]);
    public:
          sudoku();
          
};
//for printing the output 
void sudoku::printer(int grid[N][N]){
    for(int row=0;row< N ; row++){
        for(int col=0;col<N; col++){
            cout<<grid[row][col]<<" ";
        }
        cout<<endl;
    }
}
//checking row 
bool sudoku::checkRow(int grid[N][N],int row,int num){
    for(int col=0;col < N ;col++){
        if(grid[row][col]==num){
            return true;
        }
    }
    return false;
}
//checking column
bool sudoku::checkCol(int grid[N][N],int col,int num){
    for(int row=0;row < N;row++){
        if(grid[row][col]==num){
            return true;
        }
    }
    return false;
}
bool sudoku::checkBox(int grid[N][N],int boxStartRow,int boxStartCol,int num){
    for(int row=0 ;row < 3;row++){
        for(int col=0;col < 3 ;col++){
            if(grid[row+boxStartRow][col+boxStartCol] == num){
                return true;
            }
        }
    }
    return false;
}
bool sudoku::findUnsignedLocation(int grid[N][N],int &row,int &col){
for(row=0; row<N; row++){
    for(col=0;col<N; col++){
        if(grid[row][col]==unassigned){
            return true;
        }
    }
}
return false;
}
bool sudoku::isSafe(int grid[N][N],int row,int col,int num){
    return  ((!checkRow(grid,row,num)) && (!checkCol(grid,col,num)) && (!checkBox(grid,row-row%3,col-col%3,num))); 
}
bool sudoku::solveSudoku(int grid[N][N]){
    int row,col;
    if(!findUnsignedLocation(grid,row,col)){
        return true;//success base case 
    }
    for(int num=1;num<=9;num++){
        if(isSafe(grid,row,col,num)){
            grid[row][col]=num;
        if(solveSudoku(grid)){
            return true;
        }
        grid[row][col]=unassigned; //this is wherre the backtracking takes place
        }
    }
    return false;
}
sudoku::sudoku(){
    int grid[N][N];
    for(int i=0;i<N ;i++){
for(int j=0;j<N;j++){
    cin>>grid[i][j];
}
    }
    if(solveSudoku(grid)==true){
        cout<<endl;
        printer(grid);
    }
    else{
        cout<<"No solution exists";
    }
}

