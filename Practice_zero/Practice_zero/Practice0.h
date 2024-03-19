#ifndef FUNC 

#include <iostream> 

#define FUNC

struct TVector
{
    int n;
    double* x;

    TVector();
    TVector(int n);
    TVector(const TVector&);
    //~TVector();

    TVector operator+(const TVector&);
    TVector operator-(const TVector&);
    TVector operator*(const TVector&);
    TVector& operator=(TVector& v);
};

std::istream& operator>>(std::istream& in, TVector& v);
std::ostream& operator<<(std::ostream& out, const TVector& v);

#endif 


