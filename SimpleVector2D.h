#pragma once

#include "math.h"

namespace prj {
namespace math {
class SimpleVector2D
{
private:
	double m_x;
	double m_y;
public:
	inline SimpleVector2D(void) : m_x(0.0), m_y(0.0) {}
	inline SimpleVector2D(const double & p_x, const double & p_y) : m_x(p_x), m_y(p_y) {}
	inline SimpleVector2D(const SimpleVector2D & p_source)
	{
		m_x = p_source.m_x;
		m_y = p_source.m_y;
	}
	
	inline SimpleVector2D & operator = (const SimpleVector2D & p_source)
	{
		m_x = p_source.m_x;
		m_y = p_source.m_y;
		return (*this);
	}
	
	inline const double & GetX(void) const  { return m_x; }
	inline const double & GetY(void)const  { return m_y; }
	inline void SetX(const double & p_value) { m_x = p_value; }
	inline void SetY(const double & p_value) { m_y = p_value; }

	inline SimpleVector2D abs (void) const
	{
		return SimpleVector2D(fabs(m_x),fabs(m_y));
	}

	inline SimpleVector2D & operator += (const SimpleVector2D & p_source)
	{
		m_x += p_source.m_x;
		m_y += p_source.m_y;
		return (*this);
	}

	inline SimpleVector2D operator + (const SimpleVector2D & p_source) const
	{
		return SimpleVector2D(m_x + p_source.m_x,m_y + p_source.m_y);
	}

	inline SimpleVector2D & operator -= (const SimpleVector2D & p_source)
	{
		m_x -= p_source.m_x;
		m_y -= p_source.m_y;
		return (*this);
	}

	inline SimpleVector2D operator - (const SimpleVector2D & p_source) const
	{
		return SimpleVector2D(m_x - p_source.m_x,m_y - p_source.m_y);
	}

	inline SimpleVector2D operator * (const double & p_value) const
	{
		return SimpleVector2D(m_x*p_value, m_y*p_value);
	}

	inline SimpleVector2D & operator *= (const double & p_value)
	{
		m_x *= p_value;
		m_y *= p_value;
		return (*this);
	}

	inline SimpleVector2D operator / (const double & p_value) const
	{
		if (p_value == 0.0)
			throw;
		return SimpleVector2D(m_x / p_value, m_y / p_value);
	}

	inline SimpleVector2D & operator /= (const double & p_value)
	{
		if (p_value == 0.0)
			throw;
		m_x /= p_value;
		m_y /= p_value;
		return (*this);
	}

	inline SimpleVector2D operator * (const SimpleVector2D & p_source) const
	{
		return SimpleVector2D(m_x * p_source.m_x,m_y * p_source.m_y);
	}

	inline SimpleVector2D & operator *= (const SimpleVector2D & p_source)
	{
		m_x *= p_source.m_x;
		m_y *= p_source.m_y;
		return (*this);
	}

	inline double  operator ^ (const SimpleVector2D & p_source) const
	{
		return (m_x * p_source.m_y) - (m_y * p_source.m_x);
	}

	inline bool operator == (const SimpleVector2D & p_source)
	{
		return ((m_x == p_source.m_x) && (m_y == p_source.m_y));
	}

	inline bool operator != (const SimpleVector2D & p_source)
	{
		return !this->operator == (p_source);
	}
	
	inline double LengthSquared (void)
	{
		return m_x * m_x + m_y * m_y;
	}
};
}
}
