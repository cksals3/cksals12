#include <stdio.h>

int main(void)
{
  int i, j, k=10;

  for(i=1; i<=4; i++)
    {
      for(j=5; j>i; j--)
        printf("%3d", k--);
      printf("\n");
    }
  return 0;
}
