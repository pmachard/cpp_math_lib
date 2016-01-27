#pragma once

#include "stdafx.h"
#include <list>
#include <vector>
#include <ostream>

using namespace std;

namespace pma
{
	namespace math
	{
		const double ESPILON = 10e-10;

		const unsigned int _X_ = 0;
		const unsigned int _Y_ = 1;
		const unsigned int _Z_ = 2;
		const unsigned int _T_ = 3;

		/// @class mathematical vector with (T,dim) (d1,d2,...,dn).
		template <typename T, unsigned int dim> class VectorXd
		{
		private:
			T * m_data;
		public:
			/// A default constructor.
			/// @brief create the Tab with T time and dim value (set to 0.0)
			inline VectorXd(void)
			{
				m_data = new T[dim];
				for (int iPos = 0; iPos < dim; iPos++)
					m_data[iPos] = (T) 0.0;
			}

			/// A copy constructor.
			/// @param source the copy source
			inline VectorXd(const VectorXd<T, dim> & paramVector)
			{
				m_data = new double[dim];
				for (int iPos = 0; iPos < dim; iPos++)
					m_data[iPos] = (T)paramVector.m_data[iPos];
			}

			inline VectorXd(T data[dim])
			{
				m_data = new double[dim];
				for (int iPos = 0; iPos < dim; iPos++)
					m_data[iPos] = (T)data[iPos];
			}

			inline ~VectorXd(void)
			{
				if (m_data != NULL)
				{
					delete[] m_data;
					m_data = NULL;
				}
			}

			/// A affection operator.
			/// @param p_source the affectation source
			/// @return the object with new value
			inline VectorXd<T, dim> & operator = (const VectorXd<T, dim> & paramVector)
			{
				if (m_data != NULL)
					delete[] m_data;

				m_data = new double[dim];

				for (int iPos = 0; iPos < dim; iPos++)
					m_data[iPos] = (T)paramVector.m_data[iPos];

				return (*this);
			}

			inline T& operator[] (unsigned int paramIndex) 
			{
				if (paramIndex > dim - 1)
					throw range_error("VectorXd operator [] out of range access : ");

				return m_data[paramIndex];
			};

			inline const T& operator[] (unsigned int paramIndex) const
			{
				if (paramIndex > dim - 1)
					throw range_error("VectorXd operator [] out of range access : ");

				return m_data[paramIndex];
			};

			/// Compute the abslute vector 3d 
			/// @result the result vector abs(d1,d2,...,dn) = (abs(d1),abs(d2),...,abs(dn))
			inline VectorXd<T, dim> abs(void) const
			{
				T data[dim];

				for (int iPos = 0; iPos < dim; iPos++)
					data[iPos] = fabs(m_data[iPos]);

				return VectorXd<T, dim>(data);
			}

			/// Operator += increment vector with another vector
			/// @param vector to use for additional operation
			/// @result (d1,d2,...,dn)+=(e1,e2b,...,en) => (d1+=e1,d2+=e2,..,dn+=en)
			inline VectorXd<T, dim> & operator += (const VectorXd<T, dim> & paramVector)
			{
				for (int iPos = 0; iPos < dim; iPos++)
					m_data[iPos] += paramVector.m_data[iPos];

				return (*this);
			}

			/// Operator + add vector with another vector
			/// @param vector to use for additional operation
			/// @result (d1,d2,...,dn)+(e1,e2b,...,en) => (d1+e1,d2+e2,..,dn+en)
			inline VectorXd<T, dim> operator + (const VectorXd<T, dim> & paramVector) const
			{
				VectorXd<T, dim> result(*this);
				return (result += paramVector);
			}

			inline VectorXd<T, dim> & operator-(void)
			{
				for (int iPos = 0; iPos < dim; iPos++)
					m_data[iPos] = -m_data[iPos];

				return (*this);
			}


			/// Operator -= decrement vector with another vector
			/// @param vector to use for substraction operation
			/// @result (d1,d2,...,dn)-=(e1,e2b,...,en) => (d1-=e1,d2-=e2,..,dn-=en)
			inline VectorXd<T, dim> & operator -= (const VectorXd<T, dim> & paramVector)
			{
				for (int iPos = 0; iPos < dim; iPos++)
					m_data[iPos] -= paramVector.m_data[iPos];

				return (*this);
			}

			/// Operator - add vector with another vector
			/// @param vector to use for substraction operation
			/// @result (a1,a2,...,an) - (b1,b2,...,bn) => (a1 - b1,a2 - b2,...,an - bn)
			inline VectorXd<T, dim> operator - (const VectorXd<T, dim> & paramVector) const
			{
				VectorXd<T, dim> result(*this);
				return (result -= paramVector);
			}

			/// Operator *= multiplication vector with T paramValue
			/// @param paramValue to use to make the multiplication 
			/// @result (a1,a2,...,an) *= v => (a1 * v,a2 * v,...,an * v)
			inline VectorXd<T, dim> & operator *= (const T & paramValue)
			{
				for (int iPos = 0; iPos < dim; iPos++)
					m_data[iPos] *= paramValue;

				return (*this);
			}

			/// Operator * multiplication vector with T paramValue
			/// @param paramValue to use to make the multiplication 
			/// @result (a1,a2,...,an) * v => (a1 * v,a2 * v,...,an * v)
			inline VectorXd<T, dim> operator * (const T & paramValue) const
			{
				VectorXd<T, dim> result(*this);
				return (result *= paramValue);
			}

			/// Operator /= division vector with T paramValue
			/// @param paramValue to use to make the division 
			/// @result (xa,ya,za)/=paramValue => (xa/=paramValue,ya/=paramValue,za/=paramValue)
			inline VectorXd<T, dim> & operator /= (const T & paramValue)
			{
				if (paramValue == 0.0)
					throw;

				for (int iPos = 0; iPos < dim; iPos++)
					m_data[iPos] /= paramValue;

				return (*this);
			}

			/// Operator / division vector with T paramValue
			/// @param paramValue to use to make the division 
			/// @result (xa,ya,za)/=paramValue => (xa/paramValue,ya/paramValue,za/paramValue)
			inline VectorXd<T, dim> operator / (const T & paramValue) const
			{
				if (paramValue == 0.0)
					throw;

				VectorXd<T, dim> result(*this);
				return (result /= paramValue);
			}

			inline bool operator == (const VectorXd<T,dim> & paramVector)
			{
				for (int iPos = 0; iPos < dim; iPos++)
				{
					if (m_data[iPos] != paramVector.m_data[iPos])
						return false;
				}
				return true;
			}

			inline bool operator != (const VectorXd<T, dim> & paramVector)
			{
				return !this->operator==(paramVector);
			}

			inline T Min (void) const
			{
				T result = m_data[0];
				for (int iPos = 1; iPos < dim; iPos++)
				{
					if (result > m_data[iPos] )
						result = m_data[iPos];
				}
				return result;
			}

			inline T Max(void) const
			{
				T result = m_data[0];
				for (int iPos = 1; iPos < dim; iPos++)
				{
					if (result < m_data[iPos])
						result = m_data[iPos];
				}
				return result;
			}

			friend std::ostream & operator<< (std::ostream & paramOutput, const VectorXd<T, dim> & paramVector)
			{
				paramOutput << "(";
				for (int iPos = 0; iPos < dim; iPos++)
				{
					paramOutput << paramVector.m_data[iPos];
					if (iPos < dim - 1)
						paramOutput << ";";
				}
				paramOutput << ")";
				return paramOutput;
			}
		};

		template <typename T> class Vector1d : public VectorXd < T, 1 >
		{
		public:
			inline Vector1d(T x)
			{
				operator[](_X_) = x;
			}

			inline const T &  getX(void) const { return operator[](_X_); }
			inline T &  getX(void) { return operator[](_X_); }

			static Vector1d<T> Zero(void) { return Vector1d<T>((T)0.0); }
		};

		template <typename T> class Vector2d : public VectorXd < T, 2 >
		{
		public :		
			inline Vector2d(T x, T y)
			{
				operator[](_X_) = x;
				operator[](_Y_) = y;
			}

			inline Vector2d(const VectorXd < T, 2 > & source)
			{
				operator[](_X_) = source[_X_];
				operator[](_Y_) = source[_Y_];
			}

			static Vector2d<T> Zero(void) { return Vector2d<T>((T)0.0, (T)0.0); }
			static Vector2d<T> AxisX(void) { return Vector2d<T>((T)1.0, (T)0.0); }
			static Vector2d<T> AxisY(void) { return Vector2d<T>((T)0.0, (T)1.0); }

			inline void setX(const T & value) { operator[](_X_) = value; }
			inline void setY(const T & value) { operator[](_Y_) = value; }

			inline const T &  getX(void) const { return operator[](_X_); }
			inline const T & getY(void) const { return operator[](_Y_); }
			inline T &  getX(void) { return operator[](_X_); }
			inline T & getY(void) { return operator[](_Y_); }

			inline T getX2(void) const { return (operator[](_X_)*operator[](_X_)); }
			inline T getY2(void) const { return (operator[](_Y_)*operator[](_Y_)); }

			inline Vector2d<T> MakeXY(void) { return Vector2d<T>(getX(), getY()); }
			inline Vector2d<T> MakeYX(void) { return Vector2d<T>(getY(), getX()); }

			inline Vector1d<T> MakeX(void) { return Vector1d<T>(getX()); }
			inline Vector1d<T> MakeY(void) { return Vector1d<T>(getY()); }

			inline double operator * (const Vector2d<T> & vector) const
			{
				return (getX() * vector.getY()) - (getY() * vector.getX());
			}

			inline T SquaredLength(void) const
			{
				return getX2() + getY2();
			}

			inline T Length(void) const {
				return (T)sqrt(SquaredLength());
			};

			inline T Normalize(void)
			{
				T l = Length();

				if (l == (T) 0.0f)
					return (T) 0.0f;

				getX() /= l;
				getY() /= l;

				return l;
			};

			static inline Vector2d<T> Normalize(const Vector2d<T> & paramVector)
			{
				Vector2d<T> r(paramVector);
				r.Normalize();
				return r;			
			}

			static inline T Distance(const Vector2d<T> & paramVectorA, const Vector2d<T> & paramVectorB)
			{
				Vector2d<T> diff = paramVectorA - paramVectorB;
				return diff.Length();
			}

			inline bool IsNormalized()
			{						
				return fabs((T)(Length() - 1.0)) < ESPILON;
			}
		};

		template <typename T> class Vector3d : public VectorXd < T, 3 >
		{
		public:

			inline Vector3d(T x = (T) 0.0, T y = (T) 0.0, T z = (T) 0.0)
			{
				operator[](_X_) = x;
				operator[](_Y_) = y;
				operator[](_Z_) = z;
			}

			inline Vector3d(const VectorXd < T, 3 > & source)
			{
				operator[](_X_) = source[_X_];
				operator[](_Y_) = source[_Y_];
				operator[](_Z_) = source[_Z_];
			}

			static Vector3d<T> Zero(void) { return Vector3d<T>((T)0.0, (T)0.0, (T)0.0); }
			static Vector3d<T> AxisX(void) { return Vector3d<T>((T)1.0, (T)0.0, (T)0.0); }
			static Vector3d<T> AxisY(void) { return Vector3d<T>((T)0.0, (T)1.0, (T)0.0); }
			static Vector3d<T> AxisZ(void) { return Vector3d<T>((T)0.0, (T)0.0, (T)1.0); }

			inline void setX(const T & value) { operator[](_X_) = value; }
			inline void setY(const T & value) { operator[](_Y_) = value; }
			inline void setZ(const T & value) { operator[](_Z_) = value; }

			inline const T &  getX(void) const { return operator[](_X_); }
			inline const T & getY(void) const { return operator[](_Y_); }
			inline const T & getZ(void) const { return operator[](_Z_); }
			inline T &  getX(void) { return operator[](_X_); }
			inline T & getY(void) { return operator[](_Y_); }
			inline T & getZ(void) { return operator[](_Z_); }

			inline Vector3d<T> MakeXYZ(void) { return Vector3d<T>(getX(), getY(), getZ()); }
			inline Vector3d<T> MakeXZY(void) { return Vector3d<T>(getX(), getZ(), getY()); }
			inline Vector3d<T> MakeYXZ(void) { return Vector3d<T>(getY(), getX(), getZ()); }
			inline Vector3d<T> MakeYZX(void) { return Vector3d<T>(getY(), getZ(), getX()); }
			inline Vector3d<T> MakeZXY(void) { return Vector3d<T>(getZ(), getX(), getY()); }
			inline Vector3d<T> MakeZYX(void) { return Vector3d<T>(getZ(), getY(), getX()); }

			inline Vector2d<T> MakeXY(void) { return Vector2d<T>(getX(), getY()); }
			inline Vector2d<T> MakeXZ(void) { return Vector2d<T>(getX(), getZ()); }
			inline Vector2d<T> MakeYZ(void) { return Vector2d<T>(getY(), getZ()); }

			inline Vector1d<T> MakeX(void) { return Vector1d<T>(getX()); }
			inline Vector1d<T> MakeY(void) { return Vector1d<T>(getY()); }
			inline Vector1d<T> MakeZ(void) { return Vector1d<T>(getZ()); }

			static Vector3d<T> Cross(const Vector3d<T> & vectorA, const Vector3d<T> & vectorB)
			{
				return SimpleVector3D(vectorA.getY() * vectorB.getZ() - vectorA.getZ() * vectorB.getY(),
					vectorA.getZ() * vectorB.getX() - vectorA.getX() * vectorB.getZ(),
					vectorA.getX() * vectorB.getY() - vectorA.getY() * vectorB.getX());
			}

			/// Operator * scalar product
			/// @param vector to use for scalar operation
			/// @return T (xa,ya,za)^(xb,yb,zb) = (xa*xb) + (ya*yb) + (za*zb)
			inline T operator * (const Vector3d<T> & paramVector) const
			{
				return (getX() * paramVector.getX()) + (getY() * paramVector.getY()) + (getZ() * paramVector.getZ());
			}

			
			inline Vector3d<T> operator ^ (const Vector3d<T> & paramVector) const 
			{
				return Vector3d<T> (	
					((getY() * paramVector.getZ()) - (getZ() * paramVector.getY())),
					((getZ() * paramVector.getX()) - (getX() * paramVector.getZ())),
					((getX() * paramVector.getY()) - (getY() * paramVector.getX())));

			}

			inline T Dot(const Vector3d<T> & paramVectorA, const Vector3d<T> & paramVectorB) const
			{
				return (paramVectorA.getX() * paramVectorB.getX() + paramVectorA.getY() * paramVectorB.getY() + paramVectorA.getZ() * paramVectorB.getZ());
			}

			inline T SquaredLength() const
			{
				return (Dot(*this, *this));
			};

			inline T Length(void) const {
				return (T)sqrt(SquaredLength());
			};

			inline T Normalize(void)
			{
				T l = Length();

				if (l == (T) 0.0f)
					return (T) 0.0f;

				getX() /= l;
				getY() /= l;
				getZ() /= l;

				return l;
			};

			static inline Vector3d<T> Normalize(const Vector3d<T> & paramVector)
			{
				Vector3d<T> r(paramVector);
				r.Normalize();
				return r;
			}

			static inline T Distance(const Vector3d<T> & paramVectorA, const Vector3d<T> & paramVectorB)
			{

				Vector3d<T> diff = paramVectorA - paramVectorB;
				return diff.Length();
			}

			inline bool IsNormalized()
			{
				return fabs((T)(Length() - 1.0)) < ESPILON;
			}

			static inline list<Vector3d<T>> ToList(T * p, unsigned int s)
			{
				list<Vector3d<T>> result;
				for (int i = 0; i < s; i++, p+=3)
				{
					result.push_back(Vector3d<T>(p[0], p[1], p[2]));
				}
				return result;
			}

			static inline vector<Vector3d<T>> ToVector(T * p, unsigned int s)
			{
				vector<Vector3d<T>> result(s);
				for (int i = 0; i < s; i++, p += 3)
				{
					result.push_back(Vector3d<T>(p[0], p[1], p[2]));
				}
				return result;
			}

		};

		template <typename T> class Vector4d : public VectorXd < T, 4 >
		{
		public:
			inline Vector4d(T x, T y, T z, T t)
			{
				operator[](_X_) = x;
				operator[](_Y_) = y;
				operator[](_Z_) = z;
				operator[](_T_) = t;
			}

			inline void setX(const T & value) { operator[](_X_) = value; }
			inline void setY(const T & value) { operator[](_Y_) = value; }
			inline void setZ(const T & value) { operator[](_Z_) = value; }
			inline void setT(const T & value) { operator[](_T_) = value; }

			inline const T &  getX(void) const { return operator[](_X_); }
			inline const T & getY(void) const { return operator[](_Y_); }
			inline const T & getZ(void) const { return operator[](_Z_); }
			inline const T & getT(void) const { return operator[](_T_); }
			inline T &  getX(void) { return operator[](_X_); }
			inline T & getY(void) { return operator[](_Y_); }
			inline T & getZ(void) { return operator[](_Z_); }
			inline T & getT(void) { return operator[](_T_); }

			inline Vector4d<T> MakeXYZT(void) { return Vector3d<T>(getX(), getY(), getZ(), getT()); }

			inline Vector3d<T> MakeXYZ(void) { return Vector3d<T>(getX(), getY(), getZ()); }

			inline Vector2d<T> MakeXY(void) { return Vector2d<T>(getX(), getY()); }
			inline Vector2d<T> MakeXZ(void) { return Vector2d<T>(getX(), getZ()); }
			inline Vector2d<T> MakeYZ(void) { return Vector2d<T>(getY(), getZ()); }

			inline Vector1d<T> MakeX(void) { return Vector1d<T>(getX()); }
			inline Vector1d<T> MakeY(void) { return Vector1d<T>(getY()); }
			inline Vector1d<T> MakeZ(void) { return Vector1d<T>(getZ()); }
			inline Vector1d<T> MakeT(void) { return Vector1d<T>(getT()); }
		};
	}
}


