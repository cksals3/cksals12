#include <stdio.h>

int main(void)
{
  int score;
  printf("������ �Է��Ͻÿ�!\n");
  scanf("%d", &score);

  if(score == 100 && score >= 90)
  {
    printf("A �Դϴ�!\n");
  }
   else if(score <= 89 && score >= 80)
  {
    printf("B �Դϴ�!\n");
  }
   else if(score <= 79 && score >= 70)
  {
    printf("C �Դϴ�!\n");
  }
   else if(score == 69 && score >= 60)
  {
    printf("D �Դϴ�!\n");
  }
    else
  {
    printf("F �Դϴ�!\n");
    printf("�� ����ϼ���!\n");
  }
  return 0;
}
