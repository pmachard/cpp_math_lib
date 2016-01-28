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
				for (int iPos = 0; iPos < dim1*dim2; iPos++)
					m_data[iPos] = (T) 0.0;
			};

			inline Matrix(T value)
			{
				m_data = new T[dim1*dim2];
				for (int iPos = 0; iPos < dim1*dim2; iPos++)
					m_data[iPos] = value;
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
		};

		template <typename T> class Matrix2x3 : public Matrix < T, 2, 3 >
		{
		public:
			inline Matrix2x3() : Matrix < T, 2, 3 >()
			{
			};

			inline Matrix2x3(T value) : Matrix < T, 2, 3 >(value)
			{
			};

			inline Matrix2x3(T * ptrValue) : Matrix < T, 2, 3 >(ptrValue)
			{
			};

			inline ~Matrix2x3()
			{
			};
		};
	}
}
