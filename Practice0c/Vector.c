#include "Vector.h"
#include <stdlib.h>
#include <stdio.h>


void alloc(TVector* v, int n)
{
    v->n = n;
    v->x = (double*)malloc(sizeof(double) * n);
}

TVector summ(TVector* v1, TVector* v2)
{
    TVector sum;
    int i = 0;
    if (v1->n != v2->n)
    {
        printf("ERROR!");
        sum.x = NULL;
        sum.n = 0;
        return sum;
    }
    alloc(&sum, v1->n);
    for (i = 0; i < sum.n; i++)
    {
        sum.x[i] = v1->x[i] + v2->x[i];
    }
    return sum;
}

void fill(const char* filename, TVector* v1, TVector* v2)
{
    int i = 0;
    FILE* f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("We didn't find file");
        abort();
    }
    fscanf(f, "%d", &(v1->n));
    v1->x = (double*)malloc(v1->n * sizeof(double));
    for (; i < (v1->n); i++)
    {
        fscanf(f, "%lf", &(v1->x[i]));
    }
    fscanf(f, "%d", &(v2->n));
    v2->x = (double*)malloc(v2->n * sizeof(double));
    for (i = 0; i < (v2->n); i++)
    {
        fscanf(f, "%lf", &(v2->x[i]));
    }
    fclose(f);
}

void write(const char* filename, TVector* sum, TVector* sub, double* mult)
{
    int i = 0;
    FILE* f = fopen(filename, "w+");
    if (f == NULL)
    {
        printf("We didn't find file");
        abort();
    }
    fprintf(f, "Summ is ");
    for (; i < sum->n; i++)
    {
        fprintf(f, "%lf ", sum->x[i]);
    }
    fprintf(f, "\nDiff is ");
    for (i = 0; i < sub->n; i++)
    {
        fprintf(f, "%lf ", sub->x[i]);
    }
    fprintf(f, "\nMult is %lf\n", *mult);
    fclose(f);
}

void print(TVector* v)
{
    int i = 0;
    for (i = 0; i < v->n; i++)
    {
        printf("%lf ", v->x[i]);
    }
    printf("\n");
}

TVector diff(TVector* v1, TVector* v2)
{
    TVector dif;
    int i = 0;
    if (v1->n != v2->n)
    {
        printf("ERROR!");
        dif.x = NULL;
        dif.n = 0;
        return dif;
    }
    alloc(&dif, v1->n);
    for (i = 0; i < dif.n; i++)
    {
        dif.x[i] = v1->x[i] - v2->x[i];
    }
    return dif;
}

double mult(TVector* v1, TVector* v2)
{
    double mult = 0;
    int i = 0;
    if (v1->n != v2->n)
    {
        printf("ERROR!");
        mult = 0;
        return mult;
    }
    for (i = 0; i < v1->n; i++)
    {
        mult += v1->x[i] * v2->x[i];
    }
    return mult;
}
