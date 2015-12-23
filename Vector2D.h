#pragma once

#include "stdafx.h"

namespace prj {
	namespace math {

		/// @class mathematical vector with T (x,y).
		template <typename T> class Vector2D
		{
		private:
			T m_x;
			T m_y;
		public:
			/// A default constructor.
			/// @brief x and y are set with 0.0
			inline Vector2D(void) : m_x(0.0), m_y(0.0) {}

			/// A constructor with parameter.
			/// @param paramX value for X
			/// @param paramY value for Y
			inline Vector2D(T paramX, T paramY) : m_x(paramX), m_y(paramY) {}

			/// A copy constructor.
			/// @param paramVector the copy source
			inline Vector2D(const Vector2D<T> & paramVector)
			{
				m_x = paramVector.m_x;
				m_y = paramVector.m_y;
			}

			/// A affection operator.
			/// @param paramVector the affectation source
			/// @return the object with new value
			inline Vector2D<T> & operator = (const Vector2D<T> & paramVector)
			{
				m_x = paramVector.m_x;
				m_y = paramVector.m_y;
				return (*this);
			}

			inline const T & GetX(void) const  { return m_x; }
			inline T & GetX(void)  { return m_x; }
			inline void SetX(T paramX) { m_x = paramX; }

			inline const T & GetY(void)const  { return m_y; }
			inline T & GetY(void)  { return m_y; }
			inline void SetY(T paramY) { m_y = paramY; }
		
			inline T& operator[] (unsigned int paramIndex) {
				if (paramIndex == 0)
					return GetX();
				return GetY();
			};
			
			inline const T& operator[] (unsigned int paramIndex) const 
			{
				if (paramIndex == 0)
					return GetX();
				return GetY();
			};			

			/// Compute the abslute vector 2d abs(x,y) = (abs(x),abs(y)). 
			/// @result the result vector 
			inline Vector2D<T> abs(void) const
			{
				return Vector2D<T>(abs(m_x), fabs(m_y));
			}

			/// Operator += increment vector with another vector 
			/// @param vector to use for additional operation
			/// @result (xa,ya)+=(xb,yb) => (xa+=xb,ya+=yb)
			inline Vector2D & operator += (const Vector2D<T> & paramVector)
			{
				m_x += paramVector.m_x;
				m_y += paramVector.m_y;
				return (*this);
			}

			/// Operator + adds two vectors
			/// @param vector to use for additional operation
			/// @return (xa,ya)+(xb,yb) = (xa+xb,ya+yb)
			inline Vector2D<T> operator + (const Vector2D<T> & paramVector) const
			{
				return Vector2D<T>(m_x + paramVector.m_x, m_y + paramVector.m_y);
			}

			/// Operator -= decrement vector with another vector 
			/// @param vector to use for sustraction operation
			/// @result (xa,ya)-=(xb,yb) => (xa-=xb,ya-=yb)
			inline Vector2D<T> & operator -= (const Vector2D<T> & paramVector)
			{
				m_x -= paramVector.m_x;
				m_y -= paramVector.m_y;
				return (*this);
			}

			/// Operator - subb two vectors
			/// @param vector to use for sustraction operation
			/// @return (xa,ya)-(xb,yb) = (xa-xb,ya-yb)
			inline Vector2D<T> operator - (const Vector2D<T> & paramVector) const
			{
				return Vector2D<T>(m_x - paramVector.m_x, m_y - paramVector.m_y);
			}
			
			/// Operator - 
			/// @return (-x,-y)
			inline Vector2D<T> operator - (void) const
			{
				return Vector2D<T>(-m_x, -m_y);
			}

			/// Operator *= multiplication one vector and a T
			/// @param T to use for multiplication operation
			/// @return (x,y)*m => (x*=m,y*=m)
			inline Vector2D<T> & operator *= (T paramValue)
			{
				m_x *= paramValue;
				m_y *= paramValue;
				return (*this);
			}

			/// Operator * multiplication one vector and a T
			/// @param T to use for multiplication operation
			/// @return (x,y)*m = (x*m,y*m)
			inline Vector2D<T> operator * (T paramValue) const
			{
				return Vector2D<T>(m_x*paramValue, m_y*paramValue);
			}

			/// Operator /= disision one vector and T Value
			/// @param T to use for division operation
			/// @return (x,y)/m => (x/=m,y/=m)
			inline Vector2D<T> & operator /= (T paramValue)
			{
				if (paramValue == (T)0)
					throw;
				m_x /= paramValue;
				m_y /= paramValue;
				return (*this);
			}
			
			/// Operator /= disision one vector and a other vector
			/// @paramVector vector used for division operation
			/// @return (x,y)/m => (x/=m,y/=m)
			inline Vector2D<T> & operator /= (T paramVector)
			{
				if ((paramValue.GetX() == (T)0) || (paramValue.GetY() == (T)0))
					throw;
				m_x /= paramValue.GetX();
				m_y /= paramValue.GetY();
				return (*this);
			}

			/// Operator / disision one vector and a T
			/// @param T to use for disision operation
			/// @return (x,y)/m = (x/m,y/m)
			inline Vector2D<T> operator / (T paramValue) const
			{
				if (paramValue == (T)0)
					throw;
				return Vector2D<T>(m_x / paramValue, m_y / paramValue);
			}

			/// Operator * multiplication two vectors 
			/// @param Vector2D to use for multiplication operation
			/// @return (xa,ya)*(xb,yb) = (xa*xb,ya*yb)
			inline Vector2D<T> operator * (const Vector2D<T> & paramVector) const
			{
				return Vector2D<T>(m_x * paramVector.m_x, m_y * paramVector.m_y);
			}

			/// Operator * multiplication two vectors 
			/// @param Vector2D to use for multiplication operation
			/// @return (xa,ya)*(xb,yb) = (xa*=xb,ya*=yb)
			inline Vector2D<T> & operator *= (const Vector2D<T> & paramVector)
			{
				m_x *= paramVector.m_x;
				m_y *= paramVector.m_y;
				return (*this);
			}

			/// Operator ^ scalar product
			/// @param Vector2D to use for scalar operation
			/// @return T (xa,ya)^(xb,yb) = (xa*yb) - (ya*xb)
			inline T operator ^ (const Vector2D<T> & paramVector) const
			{
				return (m_x * paramVector.m_y) - (m_y * paramVector.m_x);
			}

			/// Operator equality check exact value
			/// @param Vector2D to use for comparison
			/// @return T (xa,ya) == (xb,yb) = (xa == xb) and  (ya == yb)
			inline bool operator == (const Vector2D<T> & paramVector)
			{
				return ((m_x == paramVector.m_x) && (m_y == paramVector.m_y));
			}

			/// Operator not equal check exact value
			/// @param Vector2D to use for comparison
			/// @return T (xa,ya) != (xb,yb) = (xa != xb) or (ya != yb)
			inline bool operator != (const Vector2D<T> & paramVector)
			{
				return !this->operator == (paramVector);
			}

			inline T LengthSquared(void)
			{
				return m_x * m_x + m_y * m_y;
			}

			inline Vector2D<T> MakeXY(void) { return Vector2D<T>(m_x, m_y);}
			inline Vector2D<T> MakeXX(void) { return Vector2D<T>(m_x, m_x);}
			inline Vector2D<T> MakeYX(void)	{ return Vector2D<T>(m_y, m_x); }
			inline Vector2D<T> MakeYY(void)	{ return Vector2D<T>(m_y, m_y); }
			
			inline T Dot (const Vector2D<T> & paramVectorA, const Vector2D<T> & paramVectorB) {
			      return (paramVectorA.GetX() * paramVectorB.GetX() + paramVectorA.GetY() * paramVectorB.GetY());
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
				
				return l;
			};			
			
			inline Vector2D<T> Normalize (const Vector2D<T> & paramVector) 
			{
			    Vector2D<T> r (paramVector);
			    r.Normalize ();
			    return r;
			}			
			
			inline T Distance (const Vector2D<T> & paramVectorA, const Vector2D<T> & paramVectorB) 
			{
			    return (paramVectorA-paramVectorB).Length ();
			}
			
			inline Vector2D<T> operator * (const T & paramValue, const Vector2D<T> & paramVector) 
			{
			   return (paramVector * paramValue);
			}			
			
			std::ostream & operator<< (std::ostream & paramOutput, const Vector2D<T> & paramVector) {
			  paramOutput << "(" << paramVector.GetX() << ";" << paramVector.GetY() << ")";
			  return paramOutput;
			}			
		};
		
		typedef Vector2D<float> Vector2Ddloat;
		typedef Vector2D<double> Vector2Ddouble;
		typedef Vector2D<int> Vector2Dint;		
	}
}
