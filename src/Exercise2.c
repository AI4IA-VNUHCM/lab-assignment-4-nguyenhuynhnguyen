/*
2.	Write a program to input an array of m x n.
Sort the odd column in increasing order and the
even column in decreasing order.
Ex:
___________________________________________________________________________________
| Input: 5 4 10 21 12 53 64 53 86 72 68 99 10 11 12 13 14 15 16 17 18 19 |
| The converted 2D array will be like this:                                        |
| 10 21 12 53                                                                      |
| 64 53 86 72                                                                      |
| 68 99 10 11                                                                      |
| 12 13 14 15                                                                      |
| 16 17 18 19                                                                      |
| Output:                                                                          |
| 68 13 86 11                                                                      |
| 64 17 18 15                                                                      |
| 16 21 14 19                                                                      |
| 12 53 12 53                                                                      |
| 10 99 10 72                                                                      |
|__________________________________________________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void Array2Dconverter(int arr[], int a[SIZE][SIZE], int m, int n)
{
  int row, column;
  int counter = 0;
  //Convert 1D array to 2D array
  for (row = 0; row <= (m - 1); row++)
  {
    for (column = 0; column <= (n - 1); column++)
    {
      a[row][column] = arr[counter];
      counter++;
    }
  }
}

void printArray(int a[SIZE][SIZE], int m, int n)
{
  int row, column;

  for (row = 0; row <= (m - 1); row++)
  {
    for (column = 0; column <= (n - 1); column++)
    {
      printf("%d ", a[row][column]);
    }
    printf("\n");
  }
}

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}
// ij
// 00 01 02 03
// 10 11 12 13
void Ex2(int arr[], int m, int n)
{
  int a[SIZE][SIZE];
  Array2Dconverter(arr, a, m, n);
  //Your codes here

  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      // printf("%d%d ", i, j);

      if (j % 2 == 0 || j == 0)
      {
        for (int i1 = 0; i1 < m; i1++)
        {
          for (int j1 = 0; j1 < n; j1++)
          {
            if (a[i1][j1] < a[i1 + 1][j1])
            {
              swap(&a[i1][j1], &a[i1 + 1][j1]);
            }
          }
        }
      }
      else
      {
        for (int i1 = 0; i1 < m; i1++)
        {
          for (int j1 = 0; j1 < n; j1++)
          {
            if (a[i1 - 1][j1] > a[i1][j1])
            {
              swap(&a[i1][j1], &a[i1 - 1][j1]);
            }
          }
        }
      }
    }
    // printf("\n");
  }

  printArray(a, m, n);
}

int main(int argc, char *argv[])
{
  //testing variable, applying it to your algorithm for auto-evaluating
  int row = atoi(argv[1]);
  int col = atoi(argv[2]);
  argc -= 3;
  int testcase[argc], i;
  for (i = 0; i < argc; i++)
  {
    testcase[i] = atoi(argv[i + 3]);
  }

  Ex2(testcase, row, col);

  return 0;
}
