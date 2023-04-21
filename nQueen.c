#include <stdio.h>
#include <stdbool.h>

int n;

bool isSafe(char board[n][n], int row, int col)
{
    int i, j;
    for (i = row, j = col; i >= 0, j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    for (i = row, j = col; i < 0, j >= 0; i++, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    for (j = col; j >= 0; j--)
    {
        if (board[row][j] == 'Q')
            return false;
    }
    return true;
}

bool nQueen(char board[n][n], int col)
{
    if (col >= n)
        return true;
    int row;
    for (row = 0; row < n; row++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 'Q';
            if (nQueen(board, col + 1))
                return true;
            board[row][col] = '_';
        }
    }
    return false;
}

int main()
{
    int row, col;
    printf("Enter the value of n : ");
    scanf("%d", &n);
    char board[n][n];
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < n; col++)
        {
            board[row][col] = '_';
        }
    }
    if (nQueen(board, 0) == false)
    {
        printf("Solution does not exist\n");
        return 0;
    }
    printf("Chess Board : \n");
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < n; col++)
        {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}