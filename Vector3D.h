#pragma once

namespace prj {
	namespace math {

		/// @class mathematical vector with T (x,y,z).
		template <typename T> class Vector3D
		{
		private:
			T m_x;
			T m_y;
			T m_z;
		public:
			/// A default constructor.
			/// @brief x and y and z are set with 0.0
			inline Vector3D(void) : m_x(0.0), m_y(0.0), m_z(0.0) {}

			/// A constructor with parameter.
			/// @param x value
			/// @param y value	
			inline Vector3D(const T & paramX, const T & paramY, const T & paramZ) : m_x(paramX), m_y(paramY), m_z(paramZ) {}

			/// A copy constructor.
			/// @param source the copy source
			inline Vector3D(const Vector3D<T> & paramVector)
			{
				m_x = paramVector.m_x;
				m_y = paramVector.m_y;
				m_z = paramVector.m_z;
			}

			/// A affection operator.
			/// @param p_source the affectation source
			/// @return the object with new value
			inline Vector3D<T> & operator = (const Vector3D<T> & paramVector)
			{
				m_x = paramVector.m_x;
				m_y = paramVector.m_y;
				m_z = paramVector.m_z;
				return (*this);
			}

			inline T & GetX(void) { return m_x; }
			inline T & GetY(void) { return m_y; }
			inline T & GetZ(void) { return m_z; }
			inline const T & GetX(void) const { return m_x; }
			inline const T & GetY(void)const { return m_y; }
			inline const T & GetZ(void) const { return m_z; }
			inline void SetX(const T & paramX) { m_x = paramX; }
			inline void SetY(const T & paramY) { m_y = paramY; }
			inline void SetZ(const T & paramZ) { m_z = paramZ; }

			inline T& operator[] (unsigned int paramIndex) {
				if (paramIndex == 0)
					return GetX();
				if (paramIndex == 1)
					return GetY();
				return GetZ();
			};
			
			inline const T& operator[] (unsigned int paramIndex) const 
			{
				if (paramIndex == 0)
					return GetX();
				if (paramIndex == 1)
					return GetY();
				return GetZ();
			};		
			/// Compute the abslute vector 3d 
			/// @result the result vector abs(x,y,z) = (abs(x),abs(y),abs(z))
			inline Vector3D<T> abs(void) const 
			{ 
				return Vector3D<T>(abs(m_x), abs(m_y), abs(m_z)); 
			}

			/// Operator += increment vector with another vector
			/// @param vector to use for additional operation
			/// @result (xa,ya,za)+=(xb,yb,zb) => (xa+=xb,ya+=yb,za+=zb)
			inline Vector3D<T> & operator += (const Vector3D<T> & paramVector)
			{
				m_x += paramVector.m_x;
				m_y += paramVector.m_y;
				m_z += paramVector.m_z;
				return (*this);
			}

			/// Operator + add vector with another vector
			/// @param vector to use for additional operation
			/// @result (xa,ya,za)+(xb,yb,zb) => (xa+xb,ya+yb,za+zb)
			inline Vector3D<T> operator + (const Vector3D<T> & paramVector) const 
			{ 
				return Vector3D<T>(m_x + paramVector.m_x, m_y + paramVector.m_y, m_z + paramVector.m_z); 
			}

			/// Operator += decrement vector with another vector
			/// @param vector to use for sustration operation
			/// @result (xa,ya,za)-=(xb,yb,zb) => (xa-=xb,ya-=yb,za-=zb)
			inline Vector3D<T> & operator -= (const Vector3D<T> & paramVector)
			{
				m_x -= paramVector.m_x;
				m_y -= paramVector.m_y;
				m_z -= paramVector.m_z;
				return (*this);
			}

			/// Operator - sustraction vector with another vector
			/// @param vector to use to sustraction operation
			/// @result (xa,ya,za)-(xb,yb,zb) => (xa-xb,ya-yb,za-zb)
			inline Vector3D<T> operator - (const Vector3D<T> & paramVector) const 
			{ 
				return Vector3D<T>(m_x - paramVector.m_x, m_y - paramVector.m_y, m_z - paramVector.m_z); 
			}

			inline Vector3D<T> operator - (const Vector3D<T> & paramVector) const
			{
				return Vector3D<T>(-paramVector.m_x,-paramVector.m_y,-paramVector.m_z);
			}

			/// Operator *= multiplication vector with T paramValue
			/// @param paramValue to use to make the multiplication 
			/// @result (xa,ya,za)*=paramValue => (xa*=paramValue,ya*=paramValue,za*=paramValue)
			inline Vector3D<T> & operator *= (const T & paramValue)
			{
				m_x *= paramValue;
				m_y *= paramValue;
				m_z *= paramValue;
				return (*this);
			}

			/// Operator * multiplication vector with T paramValue
			/// @param paramValue to use to make the multiplication 
			/// @result (xa,ya,za)*paramValue => (xa*paramValue,ya*paramValue,za*paramValue)
			inline Vector3D<T> operator * (const T & paramValue) const 
			{ 
				return Vector3D<T>(m_x * paramValue, m_y * paramValue, m_z * paramValue); 
			}

			/// Operator /= division vector with T paramValue
			/// @param paramValue to use to make the division 
			/// @result (xa,ya,za)/=paramValue => (xa/=paramValue,ya/=paramValue,za/=paramValue)
			inline Vector3D<T> & operator /= (const T & paramValue)
			{
				if (paramValue == 0.0)
					throw;
				m_x /= paramValue;
				m_y /= paramValue;
				m_z /= paramValue;
				return (*this);
			}

			/// Operator / division vector with T paramValue
			/// @param paramValue to use to make the division 
			/// @result (xa,ya,za)/=paramValue => (xa/paramValue,ya/paramValue,za/paramValue)
			inline Vector3D<T> operator / (const T & paramValue) const
			{
				if (paramValue == 0.0)
					throw;
				return Vector3D<T>(m_x / paramValue, m_y / paramValue, m_z / paramValue);
			}

			/// Operator * multiplication with two vectors
			/// @param vector to use to make the multiplication 
			/// @result (xa,ya,za)*(xb,yb,zb) => (xa*xb,ya*yb,za*zb)
			inline Vector3D<T> operator * (const Vector3D<T> & paramVector) const 
			{ 
				return Vector3D<T>(m_x * paramVector.m_x, m_y * paramVector.m_y, m_z * paramVector.m_z); 
			}

			/// Operator *= multiplication with two vectors
			/// @param vector to use to make the multiplication 
			/// @result (xa,ya,za)*=(xb,yb,zb) => (xa*=xb,ya*=yb,za*=zb)
			inline Vector3D<T> & operator *= (const Vector3D<T> & paramVector)
			{
				m_x *= paramVector.m_x;
				m_y *= paramVector.m_y;
				m_z *= paramVector.m_y;
				return (*this);
			}

			/// Operator ^ scalar product
			/// @param vector to use for scalar operation
			/// @return T (xa,ya)^(xb,yb) = (xa*yb) - (ya*xb)
			inline T operator ^ (const Vector3D<T> & paramVector) const 
			{ 
				return (m_x * paramVector.m_y) - (m_y * paramVector.m_x); 
			}

			/// Operator equality check exact value
			/// @param source to use for comparison
			/// @return T (xa,ya,za) == (xb,yb,zb) = (xa == xb) and (ya == yb) and (za == zb)
			inline bool operator == (const Vector3D<T> & paramVector) 
			{ 
				return ((m_x == paramVector.m_x) && (m_y == paramVector.m_y) && (m_z == paramVector.m_z)); 
			}

			/// Operator not equal check exact value
			/// @param source to use for comparison
			/// @return T (xa,ya,za) != (xb,yb,za) = (xa != xb) or (ya != yb) or (za != zb)		
			inline bool operator != (const Vector3D<T> & paramVector)	
			{ 
				return !this->operator == (paramVector); 
			}

			inline T LengthSquared(void) 
			{ 
				return m_x * m_x + m_y * m_y + m_z * m_z; 
			}

			static Vector3D<T> Cross(const Vector3D<T> & paramVectorA, const Vector3D<T> & paramVectorB)
			{
				return Vector3D<T>(paramVectorA.m_y * paramVectorB.m_z - paramVectorA.m_z * paramVectorB.m_y,
					paramVectorA.m_z * paramVectorB.m_x - paramVectorA.m_x * paramVectorB.m_z,
					paramVectorA.m_x * paramVectorB.m_y - paramVectorA.m_y * paramVectorB.m_x);
			}

			/// Method to make a vector with specific coord handle
			/// @return T (x,y,z).MakeXYZ => (x,y,z)
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
			
			inline T Dot (const Vector3D<T> & paramVectorA, const Vector3D<T> & paramVectorB) 
			{
			      return (paramVectorA.GetX() * paramVectorB.GetX() + paramVectorA.GetY() * paramVectorB.GetY() + paramVectorA.GetZ() * paramVectorB.GetZ());
			}			
			
			inline T SquaredLength() const 
			{
			        return (Dot (*this, *this));
			};
			
			inline T Length(void) const {
			        return (T)sqrt (SquaredLength());
			};			
			
			inline T Normalize (void) 
			{
				T l = Length ();
				
				if (l == (T) 0.0f)
				  return (T) 0.0f;
				  
				m_X /= l;
				m_Y /= l;
				m_Z /= l;
				
				return l;
			};	
			
			inline Vector3D<T> Normalize (const Vector3D<T> & paramVector) 
			{
			    Vector3D<T> r (paramVector);
			    r.Normalize ();
			    return r;
			}
			
			inline T Distance (const Vector3D<T> & paramVectorA, const Vector3D<T> & paramVectorB) 
			{
			    return (paramVectorA-paramVectorB).Length ();
			}
			
			inline Vector3D<T> operator * (const T & paramValue, const Vector3D<T> & paramVector) 
			{
			   return (paramVector * paramValue);
			}			
			
			std::ostream & operator<< (std::ostream & paramOutput, const Vector3D<T> & paramVector) 
			{
			  paramOutput << "(" << paramVector.GetX() << ";" << paramVector.GetY() << ";" << paramVector.GetZ() << ")";
			  return paramOutput;
			}			
		};
		
		typedef Vector3D<float> Vector3Ddloat;
		typedef Vector3D<double> Vector3Ddouble;
		typedef Vector3D<int> Vector3Dint;		
	}
}
