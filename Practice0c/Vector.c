#include "Vector.h"

void alloc(TVector* v, int n)
{
	v->n = n;
	v->x = (double*)malloc(sizeof(double) * n);
}

void fill(TVector* v)
{
	int i = 0;
	printf("Input coordinates: ");
	for (; i < v->n; i++)
	{
		scanf("%lf", &(v->x[i]));
	}
}

void sum_print(TVector* v)
{
	int i = 0;
	printf("Vector sum: ");
	for (; i < v->n; i++)
	{
		printf("%.2lf ", v->x[i]);
	}
	printf("\n");
}

void diff_print(TVector* v)
{
	int i = 0;
	printf("Vector dif: ");
	for (; i < v->n; i++)
	{
		printf("%.2lf ", v->x[i]);
	}
	printf("\n");
}

TVector sum(TVector* v1, TVector* v2)
{
	TVector res;
	int i = 0;
	if (v1->n != v2->n)
	{
		printf("v1->n != v2->n");
		res.x = NULL;
		res.n = 0;
		return res;
	}
	alloc(&res, v1->n);
	for (; i < res.n; i++)
	{
		res.x[i] = v1->x[i] + v2->x[i];
	}
	return res;
}

TVector diff(TVector* v1, TVector* v2)
{
	TVector res;
	int i = 0;
	if (v1->n != v2->n)
	{
		printf("v1->n != v2->n");
		res.x = NULL;
		res.n = 0;
		return res;
	}
	alloc(&res, v1->n);
	for (; i < res.n; i++)
	{
		res.x[i] = v1->x[i] - v2->x[i];
	}
	return res;
}

double mult(TVector* v1, TVector* v2)
{
	int i = 0;
	double res = 0;
	if (v1->n != v2->n)
	{
		printf("v1->n != v2->n");
		return 0;
	}
	for (; i < v1->n; i++)
	{
		res = res + ((v1->x[i]) * (v2->x[i]));
	}
	return res;
}

void reading(const char* filename, TVector* v1, TVector* v2)
{
	int i = 0;
	FILE* f = fopen(filename, "r");
	if (f == NULL)
	{
		printf("File not found");
		abort();
	}
	fscanf(f, " %d ", &(v1->n));
	v1->x = (double*)malloc(v1->n * sizeof(double));
	for (; i < (v1->n); i++)
	{
		fscanf(f, " %lf ", &(v1->x[i]));
	}
	fscanf(f, "%d ", &(v2->n));
	v2->x = (double*)malloc(v2->n * sizeof(double));
	for (i = 0; i < (v2->n); i++)
	{
		fscanf(f, "%lf ", &(v2->x[i]));
	}
	fclose(f);
}

void writing(const char* filename, TVector* s, TVector* d, double mp)
{
	int i = 0;
	FILE* f = fopen(filename, "w+");
	if (f == NULL)
	{
		printf("File not found");
		abort();
	}
	fprintf(f, "Sum =");
	for (; i < s->n; i++)
	{
		fprintf(f, "%.2lf  ", (s->x[i]));
	}
	fprintf(f, "\nDiff =");
	for (i = 0; i < d->n; i++)
	{
		fprintf(f, "%.2lf  ", (d->x[i]));
	}
	fprintf(f, "\nScalar multiplication = %.3lf", mp);
	fclose(f);
}