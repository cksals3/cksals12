#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    FILE* ctyfpr, * ctyfpw;

    int ctyw, ctyh, i, j;
    int num;
    char ctystr_temp[100];
    char ctyfname[50], ctyn_fname[50];
    unsigned char** ctyimg_in, ** ctyimg_ou;

    printf("���� ������ �̸� : ");
    scanf("%s", ctyfname);
    printf("���纻 ������ �̸� : ");
    scanf("%s", ctyn_fname);

    ctyfpr = fopen(ctyfname, "r");

    if (ctyfpr == NULL)
    {
        printf("���� ������ ���� ���߽��ϴ�.\n");
        exit(1);
    }

    ctyfpw = fopen(ctyn_fname, "w");

    if (ctyfpw == NULL)
    {
        printf("���纻 ������ ���� ���߽��ϴ�.\n");
        exit(1);
    }

    fgets(ctystr_temp, 100, ctyfpr);
    fputs(ctystr_temp, ctyfpw);
    fgets(ctystr_temp, 100, ctyfpr);
    fputs(ctystr_temp, ctyfpw);

    fscanf(ctyfpr, "%d", &ctyw);
    fscanf(ctyfpr, "%d", &ctyh);
    fprintf(ctyfpw, "%d %d\n", ctyw, ctyh);
    fscanf(ctyfpr, "%d", &i);
    fprintf(ctyfpw, "%d\n", i);

    ctyimg_in = (unsigned char**)malloc(ctyh * sizeof(unsigned char*));

    for (i = 0; i < ctyh; i++)
        ctyimg_in[i] = (unsigned char*)malloc(ctyw * sizeof(unsigned char));

    if (ctyimg_in == NULL)
    {
        printf("���� �̹����� ���� �޸� �Ҵ��� �����߽��ϴ�.\n");
        exit(1);
    }

    ctyimg_ou = (unsigned char**)malloc(ctyh * sizeof(unsigned char*));

    for (i = 0; i < ctyh; i++)
        ctyimg_ou[i] = (unsigned char*)malloc(ctyw * sizeof(unsigned char));

    if (ctyimg_ou == NULL)
    {
        printf("���纻 �̹����� ���� �޸� �Ҵ��� �����߽��ϴ�.\n");
        exit(1);
    }

    for (i = 0; i < ctyh; i++)
    {
        for (j = 0; j < ctyw; j++)
            fscanf(ctyfpr, "%d", &ctyimg_in[i][j]);
    }

    for (i = 0; i < ctyh; i++)
    {
        for (j = 0; j < ctyw; j++)
            ctyimg_ou[i][j] = ctyimg_in[i][j];
    }

    for (i = 0; i < ctyh; i++)
    {
        for (j = 0; j < ctyw; j++)
            fprintf(ctyfpw, "%d", ctyimg_ou[i][j]);
    }

    fclose(ctyfpr);
    fclose(ctyfpw);

    for (i = 0; i < ctyh; i++)
        free(ctyimg_in[i]);
        free(ctyimg_in);

    for (i = 0; i < ctyh; i++)
        free(ctyimg_ou[i]);
        free(ctyimg_ou);

    return 0;
}
