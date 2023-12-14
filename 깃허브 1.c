#include <stdio.h>

int main(void)
{
  int score;
  printf("성적을 입력하시오!\n");
  scanf("%d", &score);

  if(score == 100 && score >= 90)
  {
    printf("A 입니다!\n");
  }
   else if(score <= 89 && score >= 80)
  {
    printf("B 입니다!\n");
  }
   else if(score <= 79 && score >= 70)
  {
    printf("C 입니다!\n");
  }
   else if(score == 69 && score >= 60)
  {
    printf("D 입니다!\n");
  }
    else
  {
    printf("F 입니다!\n");
    printf("더 노력하세요!\n");
  }
  return 0;
}
