#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int **pBingo = (int **) malloc(sizeof(int *) * 3);
  for (int i = 0; i < 3; i++)
  {
    pBingo[i] = (int *) malloc(sizeof(int) * 3);
  }

  int **pBingoMat = (int **) malloc(sizeof(int *) * 3);
  for (int i = 0; i < 3; i++)
  {
    pBingoMat[i] = (int *) malloc(sizeof(int) * 3);
  }


  for (int i = 0; i < 3; i++)
  {
    char *pRow = (char *) malloc(sizeof(char) * 20);
    fgets(pRow, 20, stdin);
    // printf(pRow);

    int pos = 0;
    for (int j = 0; j < 3; j++)
    {
      int val = 0;
      while ('0' <= pRow[pos] && pRow[pos] <= '9')
      {
        // printf("%d", pRow[pos]-'0');
        val = val * 10 + pRow[pos] - '0';
        pos ++;
      }
      pBingo[i][j] = val;
      pos ++;
    }
    // printf("%d, %d, %d", pBingo[i][0], pBingo[i][1], pBingo[i][2]);
    free(pRow);
  }

  // printf("Input N");
  char pN[3];
  fgets(pN, 3, stdin);

  int N = 0;
  {
    int pos = 0;
    while ('0' <= pN[pos] && pN[pos] <= '9')
    {
      N = N * 10 + pN[pos] - '0';
      pos ++;
    }
  }

  int *pB = (int *) malloc(sizeof(int) * N);
  {
    int pos = 0;
    char buf[4];
    for (int i = 0; i < N; i++)
    {
      fgets(buf, 4, stdin);

      int val = 0;
      pos = 0;
      while('0' <= buf[pos] && buf[pos] <= '9')
      {
        val = val * 10 + buf[pos] - '0';
        pos++;
      }
      pB[i] = val;
      // printf("%d\n", pB[i]);

      for (int i = 0; i < 3; i++)
      {
        for (int j = 0; j < 3; j++)
        {
          pBingoMat[i][j] = (1 == pBingoMat[i][j] || pBingo[i][j] == val) ? 1 : 0;
        } 
      }
    }
  }

  // for (int i = 0; i < 3; i++)
  // {
  //   for (int j = 0; j < 3; j++)
  //   {
  //     printf("%d, ", pBingo[i][j]);
  //   } 
  //   printf("\n");
  // }

  // for (int i = 0; i < 3; i++)
  // {
  //   for (int j = 0; j < 3; j++)
  //   {
  //     printf("%d, ", pBingoMat[i][j]);
  //   } 
  //   printf("\n");
  // }



  for (int i = 0; i < 3; i++)
  {
    int sum = 0;
    for (int j = 0; j < 3; j++)
    {
      sum += pBingoMat[i][j];
    }
    if (3 == sum)
    {
      printf("Yes");
      return 0;
    }
    // printf("%d\n",sum);
  }

  for (int i = 0; i < 3; i++)
  {
    int sum = 0;
    for (int j = 0; j < 3; j++)
    {
      sum += pBingoMat[j][i];
    }
    if (3 == sum)
    {
      printf("Yes");
      return 0;
    }
  }

  {
    int sum = 0;
    for (int j = 0; j < 3; j++)
    {
      sum += pBingoMat[j][j];
    }
    if (3 == sum)
    {
      printf("Yes");
      return 0;
    }
  }

  {
    int sum = 0;
    for (int j = 0; j < 3; j++)
    {
      sum += pBingoMat[2-j][2-j];
    }
    if (3 == sum)
    {
      printf("Yes");
      return 0;
    }
  }

  printf("No");
  return 0;
}