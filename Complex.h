#pragma once

#include "math.h"

namespace prj {
namespace math {
class Complex
{
private:
      double m_real;
      double m_imag;
public:
  inline Complex(void) : m_real(0.0), m_imag(0.0)  {}
  inline Complex(double real, double imag) : m_real(real), m_imag(imag)  {}
  inline Complex(const Complex & source)
  {
    m_real = source.m_real;
    m_imag = source.m_imag;
  }

  inline Complex & operator=(const double & source)
  {
    m_real = source.m_real;
    m_imag = source.m_imag;
    return (*this);
  }
  
  inline const double & GetReal(void) const { return m_real;};
  inline const double & GetImag(void) const { return m_imag;};
  inline void SetReal(const double & value) { m_real = value;};
  inline void SetImag(const double & value) { m_imag = value;};

  inline Complex & operator+=(const Complex & source)
  {
    m_real += source.m_real;
    m_imag += source.m_imag;
    return (*this);
  }
  
  inline Complex operator+(const Complex & source) const
  {
    return Complex(m_real + source.m_real, m_imag + source.m_imag);
  }

  inline Complex & operator-=(const Complex & source)
  {
    m_real -= source.m_real;
    m_imag -= source.m_imag;
    return (*this);
  }
  
  inline Complex operator-(const Complex & source) const
  {
    return Complex(m_real - source.m_real, m_imag - source.m_imag);
  }

  inline Complex & operator*=(const Complex & source)
  {
    m_real *= source.m_real;
    m_imag *= source.m_imag;
    return (*this);
  }
  
  inline Complex operator*(const Complex & source) const
  {
    return Complex(m_real * source.m_real, m_imag * source.m_imag);
  }

  inline bool operator==(const Complex & source) const
  {
    return (m_real == source.m_real) && (m_imag == source.m_imag);
  }
  
  inline bool operator!=(const Complex & source) const;
  {
    return !(this->operator==(source));
  }
  };
}
}
