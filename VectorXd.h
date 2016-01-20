#pragma once

#include "stdafx.h"
#include <ostream>

namespace pma
{
	namespace math
	{
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

			inline T& operator[] (unsigned int paramIndex) {
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
		};

		template <typename T> class Vector2d : public VectorXd < T, 2 >
		{
		public :		
			inline Vector2d(T x, T y)
			{
				operator[](_X_) = x;
				operator[](_Y_) = y;
			}

			inline const T &  getX(void) const { return operator[](_X_); }
			inline const T & getY(void) const { return operator[](_Y_); }
			inline T &  getX(void) { return operator[](_X_); }
			inline T & getY(void) { return operator[](_Y_); }

		};

		template <typename T> class Vector3d : public VectorXd < T, 3 >
		{
		public:
			inline Vector3d(T x, T y, T z)
			{
				operator[](_X_) = x;
				operator[](_Y_) = y;
				operator[](_Z_) = z;
			}

			inline const T &  getX(void) const { return operator[](_X_); }
			inline const T & getY(void) const { return operator[](_Y_); }
			inline const T & getZ(void) const { return operator[](_Z_); }
			inline T &  getX(void) { return operator[](_X_); }
			inline T & getY(void) { return operator[](_Y_); }
			inline T & getZ(void) { return operator[](_Z_); }
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

			inline const T &  getX(void) const { return operator[](_X_); }
			inline const T & getY(void) const { return operator[](_Y_); }
			inline const T & getZ(void) const { return operator[](_Z_); }
			inline const T & getT(void) const { return operator[](_T_); }
			inline T &  getX(void) { return operator[](_X_); }
			inline T & getY(void) { return operator[](_Y_); }
			inline T & getZ(void) { return operator[](_Z_); }
			inline T & getT(void) { return operator[](_T_); }
		};

	}
}

