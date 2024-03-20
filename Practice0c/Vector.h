#ifndef FUNC

#define FUNC 

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	int n;
	double* x;
} TVector;

void alloc(TVector* v, int n);
void fill(TVector* v);
void sum_print(TVector* v);
void diff_print(TVector* v);

TVector sum(TVector* v1, TVector* v2);
TVector diff(TVector* v1, TVector* v2);
double mult(TVector* v1, TVector* v2);

#endif

