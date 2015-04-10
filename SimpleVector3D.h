#pragma once

namespace prj {
namespace math {
	
/// @class mathematical vector with double (x,y,z).
class SimpleVector3D
{
private:
	/// The x component.
	double m_x;
	/// The y component.
	double m_y;
	/// The z component.
	double m_z;
public:
	/// A default constructor.
	/// @brief x and y and z are set with 0.0
	inline SimpleVector3D(void) : m_x(0.0), m_y(0.0), m_z(0.0) {}

	/// A constructor with parameter.
	/// @param x value
	/// @param y value	
	inline SimpleVector3D(const double & x, const double & y, const double & z) : m_x(x), m_y(y), m_z(z) 
	{}
	
	/// A copy constructor.
	/// @param source the copy source
	inline SimpleVector3D(const SimpleVector3D & source)
	{
		m_x = source.m_x;
		m_y = source.m_y;
		m_z = source.m_z;
	}
	
	/// A affection operator.
	/// @param p_source the affectation source
	/// @return the object with new value
	inline SimpleVector3D & operator = (const SimpleVector3D & source)
	{
		m_x = source.m_x;
		m_y = source.m_y;
		m_z = source.m_z;
		return (*this);
	}
	
	/// A field x accessor.
	/// @return x value
	inline const double & GetX(void) const { return m_x; }
	/// Set the field x.
	/// @param value the value set to x
	inline void SetX(const double & p_value) { m_x = p_value; }
	
	/// A field y accessor.
	/// @return y value
	inline const double & GetY(void)const { return m_y; }
	/// Set the field y.
	/// @param value the value set to y
	inline void SetY(const double & p_value) { m_y = p_value; }
	
	/// A field z accessor.
	/// @return z value
	inline const double & GetZ(void)const { return m_z; }
	/// Set the field z.
	/// @param value the value set to z
	inline void SetZ(const double & p_value) { m_z = p_value; }
	

	/// Compute the abslute vector 3d 
	/// @result the result vector abs(x,y,z) = (abs(x),abs(y),abs(z))
	inline SimpleVector3D abs (void) const
	{
		return SimpleVector3D(fabs(m_x),fabs(m_y),fabs(m_z));
	}
	
	/// Operator += increment vector with another vector
	/// @param vector to use for additional operation
	/// @result (xa,ya,za)+=(xb,yb,zb) => (xa+=xb,ya+=yb,za+=zb)
	inline SimpleVector3D & operator += (const SimpleVector3D & p_source)
	{
		m_x += p_source.m_x;
		m_y += p_source.m_y;
		m_z += p_source.m_z;
		return (*this);
	}
	
	/// Operator + add vector with another vector
	/// @param vector to use for additional operation
	/// @result (xa,ya,za)+(xb,yb,zb) => (xa+xb,ya+yb,za+zb)
	inline SimpleVector3D operator + (const SimpleVector3D & p_source) const
	{
		return p_source + (*this);
	}
	
	/// Operator += decrement vector with another vector
	/// @param vector to use for sustration operation
	/// @result (xa,ya,za)-=(xb,yb,zb) => (xa-=xb,ya-=yb,za-=zb)
	inline SimpleVector3D & operator -= (const SimpleVector3D & p_source)
	{
		m_x -= p_source.m_x;
		m_y -= p_source.m_y;
		m_z -= p_source.m_z;
		return (*this);
	}
	
	/// Operator - sustraction vector with another vector
	/// @param vector to use for sustraction operation
	/// @result (xa,ya,za)-(xb,yb,zb) => (xa-xb,ya-yb,za-zb)
	inline SimpleVector3D operator - (const SimpleVector3D & p_source) const
	{
		return p_source - (*this);
	}
	
	inline SimpleVector2D & operator *= (const double & p_value)
	{
		m_x *= p_value;
		m_y *= p_value;
		m_z *= p_value;
		return (*this);
	}
	
	inline SimpleVector3D operator * (const double & p_value) const
	{
		return SimpleVector3D(m_x*p_value, m_y*p_value, m_z*p_value);
	}
	
	inline SimpleVector3D & operator /= (const double & p_value)
	{
		if (p_value == 0.0)
			throw;
		m_x /= p_value;
		m_y /= p_value;
		m_z /= p_value;
		return (*this);
	}
	
	inline SimpleVector3D operator / (const double & p_value) const
	{
		if (p_value == 0.0)
			throw;
		return SimpleVector3D(m_x / p_value, m_y / p_value, m_z / p_value);
	}
	
	inline SimpleVector3D operator * (const SimpleVector3D & p_source) const
	{
		return SimpleVector3D(*this)*p_source;
	}
	
	inline SimpleVector2D & operator *= (const SimpleVector2D & p_source)
	{
		m_x *= p_source.m_x;
		m_y *= p_source.m_y;
		m_z *= p_source.m_y;
		return (*this);
	}
	
	inline double operator ^ (const SimpleVector3D & p_source) const
	{
		return (m_x * p_source.m_y) - (m_y * p_source.m_x);
	}
	
	inline bool operator == (const SimpleVector3D & p_source)
	{
		return ((m_x == p_source.m_x) && (m_y == p_source.m_y) && (m_z == p_source.m_z));
	}
	
	inline bool operator != (const SimpleVector3D & p_source)
	{
		return !this->operator == (p_source);
	}
	
	inline double LengthSquared (void)
	{
		return m_x * m_x + m_y * m_y + m_z * m_z;
	}
	
 	static SimpleVector3D Cross(const SimpleVector3D & vectorA, const SimpleVector3D & vectorB)
 	{
 		return SimpleVector3D (vectorA.y * vectorB.z - vectorA.z * vectorB.y,
 		vectorA.z * vectorB.x - vectorA.x * vectorB.z,
 		vectorA.x * vectorB.y - vectorA.y * vectorB.x);			
 	}
}
}
