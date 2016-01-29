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
		template <typename T, unsigned int dim1, unsigned int dim2>class Matrix
		{
		private:
			T * m_data;
		public:
			inline Matrix()
			{
				m_data = new T[dim1*dim2];
				setAll((T)0.0);
			};

			inline Matrix(T value)
			{
				m_data = new T[dim1*dim2];
				setAll(value);
			};

			inline Matrix(T * ptrValue)
			{
				m_data = new T[dim1*dim2];
				for (int iPos = 0; iPos < dim1*dim2; iPos++)
				{
					m_data[iPos] = *ptrValue;
					ptrValue++;
				}
			};

			inline Matrix(const Matrix<T, dim1, dim2> & mat)
			{
				m_data = new T[dim1*dim2];
				for (int iPos = 0; iPos < dim1*dim2; iPos++)
				{
					m_data[iPos] = mat.m_data[iPos];
				}
			};

			virtual inline ~Matrix()
			{
			};

			inline const T & get(unsigned int iPos1, unsigned int iPos2) const
			{
				return m_data[iPos1 * dim2 + iPos2];
			}

			inline void set(unsigned int iPos1, unsigned int iPos2, const T & value)
			{
				m_data[iPos1 * dim2 + iPos2] = value;
			}

			inline void setAll(const T & value)
			{
				for (int iPos = 0; iPos < dim1*dim2; iPos++)
				{
					m_data[iPos] = value;
				}
			}

			inline void setDiagonal(const T & value)
			{
				for (int iPos = 0; iPos < dim1 && iPos < dim2; iPos++)
				{
					set(iPos, iPos,value);
				}
			}		

			inline void setIdentity()
			{
				setAll((T)0.0);
				setDiagonal((T)1.0);
			}
			
			Matrix<T, dim1, dim2> operator+(const Matrix<T, dim1, dim2> & mat) const
			{
				Matrix<T, dim1, dim2> result(*this);
				return (result += mat);
			}

			Matrix<T, dim1, dim2> & operator+=(const Matrix<T, dim1, dim2> & mat)
			{
				for (int iPos = 0; iPos < dim1*dim2; iPos++)
				{
					m_data[iPos] += mat.m_data[iPos];
				}
				return (*this);
			}

			Matrix<T, dim1, dim2> operator-(const Matrix<T, dim1, dim2> & mat) const
			{
				Matrix<T, dim1, dim2> result(*this);
				return (result -= mat);
			}

			Matrix<T, dim1, dim2> & operator-=(const Matrix<T, dim1, dim2> & mat)
			{
				for (int iPos = 0; iPos < dim1*dim2; iPos++)
				{
					m_data[iPos] -= mat.m_data[iPos];
				}
				return (*this);
			}

			Matrix<T, dim1, dim2> & operator=(const Matrix<T, dim1, dim2> & mat)
			{
				for (int iPos = 0; iPos < dim1*dim2; iPos++)
				{
					m_data[iPos] = mat.m_data[iPos];
				}
				return (*this);
			}

			friend std::ostream & operator<< (std::ostream & paramOutput, const Matrix<T, dim1, dim2> & paramMatrix)
			{
				paramOutput << "(";
				for (int iPos1 = 0; iPos1 < dim1; iPos1++)
				{
					paramOutput << "(";
					for (int iPos2 = 0; iPos2 < dim2; iPos2++)
					{
						paramOutput << paramMatrix.m_data[iPos1 * dim1 + iPos2];
						if (iPos2 < dim2 - 1)
							paramOutput << ";";
					}
					paramOutput << ")";
				}
				paramOutput << ")";
				return paramOutput;
			}

		};

		template <typename T> class Matrix2x3 : public Matrix < T, 2, 3 >
		{
		public:
			inline Matrix2x3() : Matrix < T, 2, 3 >() {};
			inline Matrix2x3(T value) : Matrix < T, 2, 3 >(value) {};
			inline Matrix2x3(T * ptrValue) : Matrix < T, 2, 3 >(ptrValue) {};
			inline ~Matrix2x3() {};
		};

		template <typename T> class Matrix3x3 : public Matrix < T, 3, 3 >
		{
		public:
			inline Matrix3x3() : Matrix < T, 3, 3 >() {};
			inline Matrix3x3(T value) : Matrix < T, 3, 3 >(value) {};
			inline Matrix3x3(T * ptrValue) : Matrix < T, 3, 3 >(ptrValue) {};
			inline ~Matrix3x3() {};
		};

	}
}
