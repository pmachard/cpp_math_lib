#pragma once

namespace prj {
	namespace math {

		/// @class mathematical vector with double (x,y,z).
		template <typename T> class Vector3D
		{
		private:
			/// The x component.
			T m_x;
			/// The y component.
			T m_y;
			/// The z component.
			T m_z;
		public:
			/// A default constructor.
			/// @brief x and y and z are set with 0.0
			inline Vector3D(void) : m_x((T)0.0), m_y((T)0.0), m_z((T)0.0) {}

			/// A constructor with parameter.
			/// @param x value
			/// @param y value	
			inline Vector3D(const T & x, const T & y, const T & z) : m_x(x), m_y(y), m_z(z) {}

			/// A copy constructor.
			/// @param source the copy source
			inline Vector3D(const Vector3D<T> & source)
			{
				m_x = source.m_x;
				m_y = source.m_y;
				m_z = source.m_z;
			}

			/// A affection operator.
			/// @param p_source the affectation source
			/// @return the object with new value
			inline Vector3D<T> & operator = (const Vector3D<T> & source)
			{
				m_x = source.m_x;
				m_y = source.m_y;
				m_z = source.m_z;
				return (*this);
			}

			/// A field x accessor.
			/// @return x value
			inline const T & GetX(void) const { return m_x; }
			/// Set the field x.
			/// @param value the value set to x
			inline void SetX(const T & value) { m_x = value; }

			/// A field y accessor.
			/// @return y value
			inline const T & GetY(void)const { return m_y; }
			/// Set the field y.
			/// @param value the value set to y
			inline void SetY(const T & value) { m_y = value; }

			/// A field z accessor.
			/// @return z value
			inline const T & GetZ(void)const { return m_z; }
			/// Set the field z.
			/// @param value the value set to z
			inline void SetZ(const T & value) { m_z = value; }

			/// Compute the abslute vector 3d 
			/// @result the result vector abs(x,y,z) = (abs(x),abs(y),abs(z))
			inline Vector3D<T> abs(void) const { return Vector3D<T>(abs(m_x), abs(m_y), abs(m_z)); }

			/// Operator += increment vector with another vector
			/// @param vector to use for additional operation
			/// @result (xa,ya,za)+=(xb,yb,zb) => (xa+=xb,ya+=yb,za+=zb)
			inline Vector3D<T> & operator += (const Vector3D<T> & source)
			{
				m_x += source.m_x;
				m_y += source.m_y;
				m_z += source.m_z;
				return (*this);
			}

			/// Operator + add vector with another vector
			/// @param vector to use for additional operation
			/// @result (xa,ya,za)+(xb,yb,zb) => (xa+xb,ya+yb,za+zb)
			inline Vector3D<T> operator + (const Vector3D<T> & source) const { return Vector3D<T>(m_x + source.m_x, m_y + source.m_y, m_z + source.m_z); }

			/// Operator += decrement vector with another vector
			/// @param vector to use for sustration operation
			/// @result (xa,ya,za)-=(xb,yb,zb) => (xa-=xb,ya-=yb,za-=zb)
			inline Vector3D<T> & operator -= (const Vector3D<T> & source)
			{
				m_x -= source.m_x;
				m_y -= source.m_y;
				m_z -= source.m_z;
				return (*this);
			}

			/// Operator - sustraction vector with another vector
			/// @param vector to use to sustraction operation
			/// @result (xa,ya,za)-(xb,yb,zb) => (xa-xb,ya-yb,za-zb)
			inline Vector3D<T> operator - (const Vector3D<T> & source) const { return Vector3D<T>(m_x - source.m_x, m_y - source.m_y, m_z - source.m_z); }

			/// Operator *= multiplication vector with double value
			/// @param value to use to make the multiplication 
			/// @result (xa,ya,za)*=m => (xa*=m,ya*=m,za*=m)
			inline Vector3D<T> & operator *= (const T & value)
			{
				m_x *= value;
				m_y *= value;
				m_z *= value;
				return (*this);
			}

			/// Operator * multiplication vector with double value
			/// @param value to use to make the multiplication 
			/// @result (xa,ya,za)*m => (xa*m,ya*m,za*m)
			inline Vector3D<T> operator * (const T & value) const { return Vector3D<T>(m_x * value, m_y * value, m_z * value); }

			/// Operator /= division vector with double value
			/// @param value to use to make the division 
			/// @result (xa,ya,za)/=m => (xa/=m,ya/=m,za/=m)
			inline Vector3D<T> & operator /= (const T & value)
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
			inline Vector3D<T> operator / (const T & value) const
			{
				if (value == 0.0)
					throw;
				return Vector3D<T>(m_x / value, m_y / value, m_z / value);
			}

			/// Operator * multiplication with two vectors
			/// @param vector to use to make the multiplication 
			/// @result (xa,ya,za)*(xb,yb,zb) => (xa*xb,ya*yb,za*zb)
			inline Vector3D<T> operator * (const Vector3D<T> & source) const { return Vector3D<T>(m_x * source.m_x, m_y * source.m_y, m_z * source.m_z); }

			/// Operator *= multiplication with two vectors
			/// @param vector to use to make the multiplication 
			/// @result (xa,ya,za)*=(xb,yb,zb) => (xa*=xb,ya*=yb,za*=zb)
			inline Vector3D<T> & operator *= (const Vector3D<T> & source)
			{
				m_x *= source.m_x;
				m_y *= source.m_y;
				m_z *= source.m_y;
				return (*this);
			}

			/// Operator ^ scalar product
			/// @param vector to use for scalar operation
			/// @return double (xa,ya)^(xb,yb) = (xa*yb) - (ya*xb)
			inline T operator ^ (const Vector3D<T> & source) const { return (m_x * source.m_y) - (m_y * source.m_x); }

			/// Operator equality check exact value
			/// @param source to use for comparison
			/// @return double (xa,ya,za) == (xb,yb,zb) = (xa == xb) and (ya == yb) and (za == zb)
			inline bool operator == (const Vector3D<T> & source) { return ((m_x == source.m_x) && (m_y == source.m_y) && (m_z == source.m_z)); }

			/// Operator not equal check exact value
			/// @param source to use for comparison
			/// @return double (xa,ya,za) != (xb,yb,za) = (xa != xb) or (ya != yb) or (za != zb)		
			inline bool operator != (const Vector3D<T> & source)	{ return !this->operator == (source); }

			inline T LengthSquared(void) { return m_x * m_x + m_y * m_y + m_z * m_z; }

			static Vector3D<T> Cross(const Vector3D<T> & vectorA, const Vector3D<T> & vectorB)
			{
				return Vector3D<T>(vectorA.m_y * vectorB.m_z - vectorA.m_z * vectorB.m_y,
					vectorA.m_z * vectorB.m_x - vectorA.m_x * vectorB.m_z,
					vectorA.m_x * vectorB.m_y - vectorA.m_y * vectorB.m_x);
			}

			/// Method to make a vector with specific coord handle
			/// @return double (x,y,z).MakeXYZ => (x,y,z)
			inline Vector3D<T> MakeXYZ(void) { return Vector3D<T>(m_x, m_y, m_z); }
			inline Vector3D<T> MakeXXX(void) { return Vector3D<T>(m_x, m_x, m_x); }
			inline Vector3D<T> MakeYYY(void) { return Vector3D<T>(m_y, m_y, m_y); }
			inline Vector3D<T> MakeYYY(void) { return Vector3D<T>(m_z, m_z, m_z); }
			inline Vector3D<T> MakeYZX(void) { return Vector3D<T>(m_y, m_z, m_x); }
			inline Vector3D<T> MakeZXY(void) { return Vector3D<T>(m_z, m_x, m_y); }
			inline Vector3D<T> MakeZYX(void) { return Vector3D<T>(m_z, m_y, m_x); }

			inline Vector2D<T> MakeXY(void) { return Vector2D<T>(m_x, m_y) }
			inline Vector2D<T> MakeYX(void) { return Vector2D<T>(m_y, m_x) }
			inline Vector2D<T> MakeXZ(void) { return Vector2D<T>(m_x, m_z) }
			inline Vector2D<T> MakeZX(void) { return Vector2D<T>(m_z, m_x) }
			inline Vector2D<T> MakeYZ(void) { return Vector2D<T>(m_y, m_z) }
			inline Vector2D<T> MakeZY(void) { return Vector2D<T>(m_z, m_y) }
		};
	}
}
