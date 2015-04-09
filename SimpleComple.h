#pragma once
#include "math.h"
namespace prj {
namespace math {
class SimpleComplex
{
  private:
    double real, imag;
  public:
  complex(double re = 0, double im = 0);
  ~complex();
  double getReal();
  double getImag();
  void setReal(double re = 0);
  void setImag(double im = 0);
  complex operator+(const complex&) const;
  complex operator-(const complex&) const;
  complex operator*(const complex&) const;
  complex operator/(const complex&) const;
  complex& operator=(const double);
  complex& operator+=(const complex&);
  complex& operator-=(const complex&);
  complex& operator*=(const complex&);
  complex& operator/=(const complex&);
  bool operator==(const complex&) const;
  bool operator!=(const complex&) const;
  double modulus(const complex&);
  double coupling(const complex&);
  double argumentOfAComplexNumber();
  friend double fabs(complex &);
  friend ostream& operator<<(ostream&, const complex&);
  friend istream& operator>>(istream&, complex&);
  friend complex operator+(const double&, const complex&);
  friend complex operator-(const double&, const complex&);
  friend complex operator*(const double&, const complex&);
  friend complex operator/(const double&, const complex&);
  };
}
}
