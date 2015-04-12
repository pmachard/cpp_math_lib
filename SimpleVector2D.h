#pragma once

#include "math.h"

namespace prj {
namespace math {
	
/// @class mathematical vector with double (x,y).
class SimpleVector2D
{
private:
	/// The x component.
	double m_x;
	/// The y component.
	double m_y;
public:
	/// A default constructor.
	/// @brief x and y are set with 0.0
	inline SimpleVector2D(void) : m_x(0.0), m_y(0.0) {}
	
	/// A constructor with parameter.
	/// @param x value
	/// @param y value
	inline SimpleVector2D(const double & x, const double & y) : m_x(x), m_y(y) {}
	
	/// A copy constructor.
	/// @param source the copy source
	inline SimpleVector2D(const SimpleVector2D & source)
	{
		m_x = source.m_x;
		m_y = source.m_y;
	}
	
	/// A affection operator.
	/// @param p_source the affectation source
	/// @return the object with new value
	inline SimpleVector2D & operator = (const SimpleVector2D & source)
	{
		m_x = source.m_x;
		m_y = source.m_y;
		return (*this);
	}
	
	/// A field x accessor.
	/// @return x value
	inline const double & GetX(void) const  { return m_x; }
	/// Set the field x.
	/// @param value the value set to x
	inline void SetX(const double & value) { m_x = value; }
	
	/// A field y accessor.
	/// @return y value
	inline const double & GetY(void)const  { return m_y; }
	/// Set the field y.
	/// @param value the value set to y
	inline void SetY(const double & value) { m_y = value; }

	/// Compute the abslute vector 2d abs(x,y) = (abs(x),abs(y)). 
	/// @result the result vector 
	inline SimpleVector2D abs (void) const
	{
		return SimpleVector2D(fabs(m_x),fabs(m_y));
	}

	/// Operator += increment vector with another vector 
	/// @param vector to use for additional operation
	/// @result (xa,ya)+=(xb,yb) => (xa+=xb,ya+=yb)
	inline SimpleVector2D & operator += (const SimpleVector2D & source)
	{
		m_x += source.m_x;
		m_y += source.m_y;
		return (*this);
	}

	/// Operator + adds two vectors
	/// @param vector to use for additional operation
	/// @return (xa,ya)+(xb,yb) = (xa+xb,ya+yb)
	inline SimpleVector2D operator + (const SimpleVector2D & source) const
	{
		return SimpleVector2D(m_x + source.m_x,m_y + source.m_y);
	}

	/// Operator -= decrement vector with another vector 
	/// @param vector to use for sustraction operation
	/// @result (xa,ya)-=(xb,yb) => (xa-=xb,ya-=yb)
	inline SimpleVector2D & operator -= (const SimpleVector2D & source)
	{
		m_x -= source.m_x;
		m_y -= source.m_y;
		return (*this);
	}

	/// Operator + subb two vectors
	/// @param vector to use for sustraction operation
	/// @return (xa,ya)-(xb,yb) = (xa-xb,ya-yb)
	inline SimpleVector2D operator - (const SimpleVector2D & source) const
	{
		return SimpleVector2D(m_x - source.m_x,m_y - source.m_y);
	}

	/// Operator *= multiplication one vector and a double
	/// @param double to use for multiplication operation
	/// @return (x,y)*m => (x*=m,y*=m)
	inline SimpleVector2D & operator *= (const double & value)
	{
		m_x *= value;
		m_y *= value;
		return (*this);
	}
	
	/// Operator * multiplication one vector and a double
	/// @param double to use for multiplication operation
	/// @return (x,y)*m = (x*m,y*m)
	inline SimpleVector2D operator * (const double & value) const
	{
		return SimpleVector2D(m_x*value, m_y*value);
	}

	/// Operator /= disision one vector and a double
	/// @param double to use for division operation
	/// @return (x,y)/m => (x/=m,y/=m)
	inline SimpleVector2D & operator /= (const double & value)
	{
		if (value == 0.0)
			throw;
		m_x /= value;
		m_y /= value;
		return (*this);
	}
	
	/// Operator / disision one vector and a double
	/// @param double to use for disision operation
	/// @return (x,y)/m = (x/m,y/m)
	inline SimpleVector2D operator / (const double & value) const
	{
		if (value == 0.0)
			throw;
		return SimpleVector2D(m_x / value, m_y / value);
	}

	/// Operator * multiplication two vectors 
	/// @param SimpleVector2D to use for multiplication operation
	/// @return (xa,ya)*(xb,yb) = (xa*xb,ya*yb)
	inline SimpleVector2D operator * (const SimpleVector2D & source) const
	{
		return SimpleVector2D(m_x * source.m_x,m_y * source.m_y);
	}

	/// Operator * multiplication two vectors 
	/// @param SimpleVector2D to use for multiplication operation
	/// @return (xa,ya)*(xb,yb) = (xa*=xb,ya*=yb)
	inline SimpleVector2D & operator *= (const SimpleVector2D & source)
	{
		m_x *= source.m_x;
		m_y *= source.m_y;
		return (*this);
	}

	/// Operator ^ scalar product
	/// @param SimpleVector2D to use for scalar operation
	/// @return double (xa,ya)^(xb,yb) = (xa*yb) - (ya*xb)
	inline double operator ^ (const SimpleVector2D & source) const
	{
		return (m_x * source.m_y) - (m_y * source.m_x);
	}

	/// Operator equality check exact value
	/// @param SimpleVector2D to use for comparison
	/// @return double (xa,ya) == (xb,yb) = (xa == xb) and  (ya == yb)
	inline bool operator == (const SimpleVector2D & source)
	{
		return ((m_x == source.m_x) && (m_y == source.m_y));
	}

	/// Operator not equal check exact value
	/// @param SimpleVector2D to use for comparison
	/// @return double (xa,ya) != (xb,yb) = (xa != xb) or (ya != yb)
	inline bool operator != (const SimpleVector2D & source)
	{
		return !this->operator == (source);
	}
	
	inline double LengthSquared (void)
	{
		return m_x * m_x + m_y * m_y;
	}
};
}
}
