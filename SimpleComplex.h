#pragma once

#include "math.h"

namespace prj {
namespace math {
class SimpleComplex
{
private:
      double m_real;
      double m_imag;
public:
  inline SimpleComplex(void) : m_real(0.0), m_imag(0.0)  {}
  inline SimpleComplex(double real, double imag) : m_real(real), m_imag(imag)  {}
  inline SimpleComplex(const double & source)
  {
    m_real = source.m_real;
    m_imag = source.m_imag;
  }

  inline SimpleComplex & operator=(const double & source)
  {
    m_real = source.m_real;
    m_imag = source.m_imag;
    return (*this);
  }
  
  inline const double & GetReal(void) const { return m_real;};
  inline const double & GetImag(void) const { return m_imag;};
  inline void SetReal(const double & value) { m_real = value;};
  inline void SetImag(const double & value) { m_imag = value;};

  inline SimpleComplex & operator+=(const SimpleComplex & source)
  {
    m_real += source.m_real;
    m_imag += source.m_imag;
    return (*this);
  }
  
  inline SimpleComplex operator+(const SimpleComplex & source) const
  {
    return SimpleComplex(m_real + source.m_real, m_imag + source.m_imag);
  }

  inline SimpleComplex & operator-=(const SimpleComplex & source)
  {
    m_real -= source.m_real;
    m_imag -= source.m_imag;
    return (*this);
  }
  
  inline SimpleComplex operator-(const SimpleComplex & source) const
  {
    return SimpleComplex(m_real - source.m_real, m_imag - source.m_imag);
  }

  inline SimpleComplex & operator*=(const SimpleComplex & source)
  {
    m_real *= source.m_real;
    m_imag *= source.m_imag;
    return (*this);
  }
  
  inline SimpleComplex operator*(const SimpleComplex & source) const
  {
    return SimpleComplex(m_real * source.m_real, m_imag * source.m_imag);
  }

  inline bool operator==(const SimpleComplex & source) const
  {
    return (m_real == source.m_real) && (m_imag == source.m_imag);
  }
  inline bool operator!=(const SimpleComplex & source) const;
  {
    return !(this->operator==(source));
  }
  };
}
}
