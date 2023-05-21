#include <stdio.h>
#include <stdbool.h>

int N;

void display(int board[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
            {
                printf("_ ");
            }
            else
            {
                printf("Q ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }
    for (i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
}

int nQueen(int board[N][N], int row)
{
    if (row == N)
    {
        display(board);
        return 1;
    }
    int res = 0;
    int col;
    for (col = 0; col < N; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;
            res += nQueen(board, row + 1);
            board[row][col] = 0;
        }
    }
    return res;
}

int main()
{
    int i, j;
    printf("Enter the value of N : ");
    scanf("%d", &N);
    int board[N][N];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }
    if (nQueen(board, 0) == 0)
    {
        printf("No Possible Solution\n");
    }
    return 0;
}