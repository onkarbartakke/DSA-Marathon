#include<iostream>
#define N 9
using namespace std;


bool issafe(int grid[N][N], int row, int col, int num);
bool Find_blank(int grid[N][N], int& row, int& col);
bool used_in_row(int grid[N][N], int row, int num);
bool used_in_col(int grid[N][N], int col, int num);
bool used_in_box(int grid[N][N], int boxrow, int boxcol, int num);

bool solve_sudoko(int grid[N][N])
{
    //count++;
    int row,col;

    if(!Find_blank(grid,row,col))
    return true;
    //cout<<"\n"<<row<<" "<<col;
    int num;
    for(num=1;num<=9;num++)
    {
        if(issafe(grid,row,col,num))
        {
            grid[row][col]=num;

            if(solve_sudoko(grid))
            return true;

            grid[row][col]=0;
        }
    }

    return false;
}

bool Find_blank(int grid[N][N], int& row, int& col)
{
    for(row=0;row<N;row++)
    {
        for(col=0;col<N;col++)
        {
            if(grid[row][col]==0)
            return true;
        }
    }

    return false;
}

bool issafe(int grid[N][N], int row, int col, int num)
{
    return ( !used_in_row(grid,row,num) && !used_in_col(grid,col,num) && !used_in_box(grid,row-row%3,col-col%3,num) && grid[row][col]==0);
}

bool used_in_row(int grid[N][N],int row, int num)
{
    for(int col=0;col<N;col++)
    {
        if(grid[row][col]==num)
        {
            //cout<<"\nRow used"<<" "<<num<<" "<<row<<" - "<<col;
            return true;
        }
       
    }
    return false;
}

bool used_in_col(int grid[N][N], int col, int num)
{
    for(int row=0;row<N;row++)
    {
        if(grid[row][col]==num)
        {
            //cout<<"\nCol used"<<" "<<num<<" "<<row<<" - "<<col;
            return true;
        }
    }
    return false;
}

bool used_in_box(int grid[N][N], int boxrow, int boxcol, int num)
{
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            if(grid[row+boxrow][col+boxcol]==num)
            {
                //cout<<"\nBox used"<<" "<<num<<" "<<row+boxrow<<" "<<col+boxcol;
                return true;
            }
        }
    }
    return false;
}

void print_grid(int grid[N][N])
{

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    int grid[N][N];
    int i,j;

    cout<<"Enter the Grid : \n\n";

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cin>>grid[i][j];
        }
    }

    if(solve_sudoko(grid)==true)
    {
        cout<<"\n\n";
        print_grid(grid);
    }
    else
    {
        cout<<"\nNO SOLUTION EXITS\n";
    }

   
}

/*  
   3, 0, 6, 5, 0, 8, 4, 0, 0 },
  { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
  { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
  { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
  { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
  { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
  { 0, 0, 5, 2, 0, 6, 3, 0, 0 }
                       */
                      
