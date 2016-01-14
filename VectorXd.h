#pragma once

#include "stdafx.h"
#include <ostream>

namespace pma
{
	namespace math
	{


		/// @class mathematical vector with T (x,y,z).
		template <typename T,unsigned int dim> class VectorXd
		{
		private:
			T * m_data;
		public:
			/// A default constructor.
			/// @brief x and y and z are set with 0.0
			inline VectorXd(void)
			{
				m_data = new double[dim];
				for (int iPos = 0; iPos < dim; iPos++)
					m_data[iPos] = (T) 0.0;
			}

			/// A copy constructor.
			/// @param source the copy source
			inline VectorXd(const VectorXd<T, dim> & paramVector)
			{
				m_data = new double[dim];
				for (int iPos = 0; iPos < dim; iPos++)
					m_data[iPos] = (T) paramVector.m_data[iPos];
			}

			inline VectorXd(T data[dim])
			{
				m_data = new double[dim];
				for (int iPos = 0; iPos < dim; iPos++)
					m_data[iPos] = (T) data[iPos];
			}			

			inline ~VectorXd(void)
			{
				if (m_data != NULL)
				{
					delete [] m_data;
					m_data = NULL;
				}
			}

			/// A affection operator.
			/// @param p_source the affectation source
			/// @return the object with new value
			inline VectorXd<T,dim> & operator = (const VectorXd<T,dim> & paramVector)
			{
				if (m_data != NULL)
					delete[] m_data;

				m_data = new double[dim];

				for (int iPos = 0; iPos < dim; iPos++)
					m_data[iPos] = (T)paramVector.m_data[iPos];

				return (*this);
			}

			inline T& operator[] (unsigned int paramIndex) {
				return m_data[paramIndex];
			};

			inline const T& operator[] (unsigned int paramIndex) const
			{
				return m_data[paramIndex];
			};

			/// Compute the abslute vector 3d 
			/// @result the result vector abs(x,y,z) = (abs(x),abs(y),abs(z))
			inline VectorXd<T,dim> abs(void) const
			{
				T data[dim];

				for (int iPos = 0; iPos < dim; iPos++)
					data[iPos] = fabs(m_data[iPos]);

				return VectorXd<T, dim>(data);
			}

			/// Operator += increment vector with another vector
			/// @param vector to use for additional operation
			/// @result (xa,ya,za)+=(xb,yb,zb) => (xa+=xb,ya+=yb,za+=zb)
			inline VectorXd<T, dim> & operator += (const VectorXd<T, dim> & paramVector)
			{
				for (int iPos = 0; iPos < dim; iPos++)
					m_data[iPos] += paramVector.m_data[iPos];

				return (*this);
			}

			/// Operator + add vector with another vector
			/// @param vector to use for additional operation
			/// @result (xa,ya,za)+(xb,yb,zb) => (xa+xb,ya+yb,za+zb)
			inline VectorXd<T, dim> operator + (const VectorXd<T, dim> & paramVector) const
			{
				VectorXd<T, dim> result(*this);
				return (result += paramVector);
			}

			friend std::ostream & operator<< (std::ostream & paramOutput, const VectorXd<T,dim> & paramVector)
			{
				paramOutput << "(";
				for (int iPos = 0; iPos < dim; iPos++)
				{
					paramOutput << paramVector.m_data[iPos];
					if (iPos < dim-1)
						paramOutput << ";";
				}
				paramOutput << ")";
				return paramOutput;
			}
		};

	}
}

