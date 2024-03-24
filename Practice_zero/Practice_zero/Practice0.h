#ifndef FUNC 

#include <iostream> 
#include <fstream> 

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
    double operator*(const TVector&);
    const TVector& operator=(TVector& v);

    friend std::ofstream& operator<<(std::ofstream& out, TVector& v)
    {
        out << "Vector: "; 
        for (int i = 0; i < v.n; i++)
        {
            out << v.x[i] << " ";
        }
        out << std::endl;
        return out;
    }
    friend std::ifstream& operator>>(std::ifstream& in, TVector& v)
    {
        in >> v.n;
        if (v.x != nullptr)
        {
            delete[] v.x; 
        }
        v.x = new double[v.n];
        for (int i = 0; i < v.n; i++)
        {
            in >> v.x[i];
        }
        return in;
    }
};

std::istream& operator>>(std::istream& in, TVector& v);
std::ostream& operator<<(std::ostream& out, const TVector& v);

#endif 


