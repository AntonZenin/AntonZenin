#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"


void main(int argc, char** argv[])
{
    int n1, n2;
    double multt = 0;
    TVector v1, v2, s1, s2;
    char* infile, * outfile;
    if (argc < 3)
    {
        printf("Incorrect arguments!");
        return 1;
    }
    infile = argv[1];
    outfile = argv[2];
    fill(infile, &v1, &v2); 
    s1 = summ(&v1, &v2);
    s2 = diff(&v1, &v2);
    multt = mult(&v1, &v2);
    write(outfile, &s1, &s2, &multt);
    free(v1.x);
    free(v2.x);
    if (s1.x != NULL)
    {
        free(s1.x);
    }
    if (s2.x != NULL)
    {
        free(s2.x);
    }
    return;
}