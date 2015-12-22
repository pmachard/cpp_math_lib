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
	inline SimpleVector3D(const double & x, const double & y, const double & z) : m_x(x), m_y(y), m_z(z) {}
	
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
	inline void SetX(const double & value) { m_x = value; }
	
	/// A field y accessor.
	/// @return y value
	inline const double & GetY(void)const { return m_y; }
	/// Set the field y.
	/// @param value the value set to y
	inline void SetY(const double & value) { m_y = value; }
	
	/// A field z accessor.
	/// @return z value
	inline const double & GetZ(void)const { return m_z; }
	/// Set the field z.
	/// @param value the value set to z
	inline void SetZ(const double & value) { m_z = value; }
	
	/// Compute the abslute vector 3d 
	/// @result the result vector abs(x,y,z) = (abs(x),abs(y),abs(z))
	inline SimpleVector3D abs (void) const { return SimpleVector3D(fabs(m_x),fabs(m_y),fabs(m_z)); }
	
	/// Operator += increment vector with another vector
	/// @param vector to use for additional operation
	/// @result (xa,ya,za)+=(xb,yb,zb) => (xa+=xb,ya+=yb,za+=zb)
	inline SimpleVector3D & operator += (const SimpleVector3D & source)
	{
		m_x += source.m_x;
		m_y += source.m_y;
		m_z += source.m_z;
		return (*this);
	}
	
	/// Operator + add vector with another vector
	/// @param vector to use for additional operation
	/// @result (xa,ya,za)+(xb,yb,zb) => (xa+xb,ya+yb,za+zb)
	inline SimpleVector3D operator + (const SimpleVector3D & source) const { return SimpleVector3D(m_x + source.m_x, m_y + source.m_y, m_z + source.m_z); }
	
	/// Operator += decrement vector with another vector
	/// @param vector to use for sustration operation
	/// @result (xa,ya,za)-=(xb,yb,zb) => (xa-=xb,ya-=yb,za-=zb)
	inline SimpleVector3D & operator -= (const SimpleVector3D & source)
	{
		m_x -= source.m_x;
		m_y -= source.m_y;
		m_z -= source.m_z;
		return (*this);
	}
	
	/// Operator - sustraction vector with another vector
	/// @param vector to use to sustraction operation
	/// @result (xa,ya,za)-(xb,yb,zb) => (xa-xb,ya-yb,za-zb)
	inline SimpleVector3D operator - (const SimpleVector3D & source) const { return SimpleVector3D(m_x - source.m_x, m_y - source.m_y, m_z - source.m_z); }
	
	/// Operator *= multiplication vector with double value
	/// @param value to use to make the multiplication 
	/// @result (xa,ya,za)*=m => (xa*=m,ya*=m,za*=m)
	inline SimpleVector2D & operator *= (const double & value)
	{
		m_x *= value;
		m_y *= value;
		m_z *= value;
		return (*this);
	}
	
	/// Operator * multiplication vector with double value
	/// @param value to use to make the multiplication 
	/// @result (xa,ya,za)*m => (xa*m,ya*m,za*m)
	inline SimpleVector3D operator * (const double & value) const { return SimpleVector3D(m_x * value, m_y * value, m_z * value); }
	
	/// Operator /= division vector with double value
	/// @param value to use to make the division 
	/// @result (xa,ya,za)/=m => (xa/=m,ya/=m,za/=m)
	inline SimpleVector3D & operator /= (const double & value)
	{
		if (value == 0.0)
			throw;
		m_x /= value;
		m_y /= value;
		m_z /= value;
		return (*this);
	}
	
	/// Operator / division vector with double value
	/// @param value to use to make the division 
	/// @result (xa,ya,za)/=m => (xa/m,ya/m,za/m)
	inline SimpleVector3D operator / (const double & value) const
	{
		if (value == 0.0)
			throw;
		return SimpleVector3D(m_x / value, m_y / value, m_z / value);
	}
	
	/// Operator * multiplication with two vectors
	/// @param vector to use to make the multiplication 
	/// @result (xa,ya,za)*(xb,yb,zb) => (xa*xb,ya*yb,za*zb)
	inline SimpleVector3D operator * (const SimpleVector3D & source) const { return SimpleVector3D(m_x * source.m_x, m_y * source.m_y, m_z * source.m_z); }
	
	/// Operator *= multiplication with two vectors
	/// @param vector to use to make the multiplication 
	/// @result (xa,ya,za)*=(xb,yb,zb) => (xa*=xb,ya*=yb,za*=zb)
	inline SimpleVector3D & operator *= (const SimpleVector3D & source)
	{
		m_x *= source.m_x;
		m_y *= source.m_y;
		m_z *= source.m_y;
		return (*this);
	}
	
	/// Operator ^ scalar product
	/// @param vector to use for scalar operation
	/// @return double (xa,ya)^(xb,yb) = (xa*yb) - (ya*xb)
	inline double operator ^ (const SimpleVector3D & source) const { return (m_x * source.m_y) - (m_y * source.m_x); }
	
	/// Operator equality check exact value
	/// @param source to use for comparison
	/// @return double (xa,ya,za) == (xb,yb,zb) = (xa == xb) and (ya == yb) and (za == zb)
	inline bool operator == (const SimpleVector3D & source) { return ((m_x == source.m_x) && (m_y == source.m_y) && (m_z == source.m_z)); }

	/// Operator not equal check exact value
	/// @param source to use for comparison
	/// @return double (xa,ya,za) != (xb,yb,za) = (xa != xb) or (ya != yb) or (za != zb)		
	inline bool operator != (const SimpleVector3D & source)	{ return !this->operator == (source); }
	
	inline double LengthSquared (void) { return m_x * m_x + m_y * m_y + m_z * m_z; }
	
 	static SimpleVector3D Cross(const SimpleVector3D & vectorA, const SimpleVector3D & vectorB)
 	{
 		return SimpleVector3D (vectorA.m_y * vectorB.m_z - vectorA.m_z * vectorB.m_y,
 		vectorA.m_z * vectorB.m_x - vectorA.m_x * vectorB.m_z,
 		vectorA.m_x * vectorB.m_y - vectorA.m_y * vectorB.m_x);
 	}
 	
	/// Method to make a vector with specific coord handle
	/// @return double (x,y,z).MakeXYZ => (x,y,z)
	inline SimpleVector3D MakeXYZ(void) { return SimpleVector3D(m_x,m_y,m_z); } 	
	inline SimpleVector3D MakeXXX(void) { return SimpleVector3D(m_x,m_x,m_x); } 	
	inline SimpleVector3D MakeYYY(void) { return SimpleVector3D(m_y,m_y,m_y); } 	
	inline SimpleVector3D MakeYYY(void) { return SimpleVector3D(m_z,m_z,m_z); } 	
	inline SimpleVector3D MakeYZX(void) { return SimpleVector3D(m_y,m_z,m_x); } 	
	inline SimpleVector3D MakeZXY(void) { return SimpleVector3D(m_z,m_x,m_y); } 	
	inline SimpleVector3D MakeZYX(void) { return SimpleVector3D(m_z,m_y,m_x); } 
	
	inline SimpleVector2D MakeXY(void) { return SimpleVector2D(m_x,m_y); } 	
	inline SimpleVector2D MakeYX(void) { return SimpleVector2D(m_y,m_x); } 	
	inline SimpleVector2D MakeXZ(void) { return SimpleVector2D(m_x,m_z); } 	
	inline SimpleVector2D MakeZX(void) { return SimpleVector2D(m_z,m_x); } 	
	inline SimpleVector2D MakeYZ(void) { return SimpleVector2D(m_y,m_z); } 	
	inline SimpleVector2D MakeZY(void) { return SimpleVector2D(m_z,m_y); } 	
};
}
}
