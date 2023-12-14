#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fpr, *fpw;
    int w, h, i, j;
    int num;
    char str_temp[100];
    char fname[50], n_fname[50];
    unsigned char **img_in, **img_ou; // 변수명 수정

    printf("원본 파일의 이름 : ");
    scanf("%s", fname);
    printf("복사본 파일의 이름 : ");
    scanf("%s", n_fname);

    fpr = fopen(fname, "r");
    if (fpr == NULL)
    {
        printf("원본 파일을 열지 못했습니다.\n");
        exit(1);
    }
    fpw = fopen(n_fname, "w");
    if (fpw == NULL)
    {
        printf("복사본 파일을 열지 못했습니다.\n");
        exit(1);
    }

    fgets(str_temp, 100, fpr);
    fputs(str_temp, fpw);

    fgets(str_temp, 100, fpr);
    fputs(str_temp, fpw);

    fscanf(fpr, "%d", &w);
    fscanf(fpr, "%d", &h);
    fprintf(fpw, "%d %d\n", w, h);

    fscanf(fpr, "%d", &num);
    fprintf(fpw, "%d\n", num);

    img_in = (unsigned char **)malloc(h * sizeof(unsigned char *));
    for (i = 0; i < h; i++)
        img_in[i] = (unsigned char *)malloc(w * sizeof(unsigned char));
    if (img_in == NULL)
    {
        printf("원본 이미지의 동적 메모리 할당을 실패했습니다.\n");
        exit(1);
    }

    img_ou = (unsigned char **)malloc(h * sizeof(unsigned char *));
    for (i = 0; i < h; i++)
        img_ou[i] = (unsigned char *)malloc(w * sizeof(unsigned char));
    if (img_ou == NULL)
    {
        printf("복사본 이미지의 동적 메모리 할당을 실패했습니다.\n");
        exit(1);
    }

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
            fscanf(fpr, "%d", &img_in[i][j]);
    }

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
            img_ou[i][j] = img_in[i][j];
    }

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
            fprintf(fpw, "%d ", img_ou[i][j]);
        fprintf(fpw, "\n");
    }

    fclose(fpr);
    fclose(fpw);

    for (i = 0; i < h; i++)
        free(img_in[i]);
    free(img_in);

    for (i = 0; i < h; i++)
        free(img_ou[i]);
    free(img_ou);

    return 0;
}
