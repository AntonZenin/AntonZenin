#ifndef FUNC

#define FUNC

typedef struct {
    int n;
    double* x;
}TVector;

void alloc(TVector* v, int n);
TVector summ(TVector* v1, TVector* v2);
TVector diff(TVector* v1, TVector* v2);
double mult(TVector* v1, TVector* v2);
void fill(const char* filename, TVector* v1, TVector* v2);
void print(TVector* v);
void write(const char* filename, TVector* sum, TVector* sub, double* mult);

#endif 

