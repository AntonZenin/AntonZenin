#include <iostream>
#include <exception>
#include "Practice0.h"

TVector::TVector()
{
    this->n = 0;
    this->x = nullptr;
}

TVector::TVector(int n) //конструктор с параметром 
{
    this->n = n;
    this->x = new double(n);
}

TVector::TVector(const TVector& v)  //конструктор копирования 
{
    this->n = v.n;
    this->x = new double[this->n];
    for (int i = 0; i < this->n; i++)
    {
        this->x[i] = v.x[i];
    }
}

//TVector::~TVector()      //деструктор 
//{
//    delete[] this->x;
//}

TVector TVector::operator+(const TVector& v)
{
    if (this->n != v.n)
    {
        throw std::exception("Diff length");
    }
    TVector res(this->n);
    for (int i = 0; i < this->n; i++)
    {
        res.x[i] = this->x[i] + v.x[i];
    }
    return res;
}

TVector TVector::operator-(const TVector& v)
{
    if (this->n != v.n)
    {
        throw std::exception("Diff length");
    }
    TVector res(this->n);
    for (int i = 0; i < this->n; i++)
    {
        res.x[i] = this->x[i] - v.x[i];
    }
    return res;
}

TVector TVector::operator*(const TVector& v) 
{ 
    if (this->n != v.n)
    {
        throw std::exception("Diff length");
    }
    TVector res(this->n);
    for (int i = 0; i < this->n; i++) {
        res.x[i] = this->x[i] * v.x[i];
    }
    return res;
}

TVector& TVector::operator=(TVector& v)  
{
    if (this->n != v.n)
    {
        throw std::exception("Diff length");
    }
    this->n = v.n;

    for (int i = 0; i < this->n; i++) {
        this->x[i] = v.x[i];
    }
    return *this;
}

std::istream& operator>>(std::istream& in, TVector& v)
{
    std::cout << "Input n: ";
    in >> v.n;
    std::cout << "Input x: ";
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

std::ostream& operator<<(std::ostream& out, const TVector& v)
{
    out << "Vector: ";
    for (int i = 0; i < v.n; i++)
    {
        out << v.x[i] << " ";
    }
    return out;
}