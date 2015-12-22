#pragma once

namespace prj {
	namespace math {

		/// @class mathematical matrice 3*3
		template <typename T> class Matrix3x3
		{
		private:
			/// matriceData
			T m_Data[9];
		public:
			/// A default constructor.
			/// @brief all data is create with default constructor
			inline Matrix3x3<T>(void)
			{
				Reset();
			}

			/// constructor with uniq value.
			/// @brief all data is create with the same value
			inline Matrix3x3<T>(T pramValue)
			{
				m_Data[0] = pramValue;	m_Data[1] = pramValue;	m_Data[2] = pramValue;
				m_Data[3] = pramValue;	m_Data[4] = pramValue;	m_Data[5] = pramValue;
				m_Data[6] = pramValue;	m_Data[7] = pramValue;	m_Data[8] = pramValue;
			}

			/// constructor 
			/// @brief all data is create with a specific value
			inline Matrix3x3<T>(T pramValue0x0, T pramValue1x0, T pramValue2x0,
								T pramValue0x1, T pramValue1x1, T pramValue2x1, 
								T pramValue0x2, T pramValue1x2, T pramValue2x2 )
			{
				m_Data[0] = pramValue0x0;	m_Data[1] = pramValue1x0;	m_Data[2] = pramValue2x0;
				m_Data[3] = pramValue1x0;	m_Data[4] = pramValue1x1;	m_Data[5] = pramValue2x1;
				m_Data[6] = pramValue2x0;	m_Data[7] = pramValue1x2;	m_Data[8] = pramValue2x2;
			}

			/// constructor 
			/// @brief all data is create with a specific value
			inline Matrix3x3<T>(const Matrix3x3<T> & paramSource)
			{
				m_Data[0] = paramSource.m_Data[0];	m_Data[1] = paramSource.m_Data[1];	m_Data[2] = paramSource.m_Data[2];
				m_Data[3] = paramSource.m_Data[3];	m_Data[4] = paramSource.m_Data[4];	m_Data[5] = paramSource.m_Data[5];
				m_Data[6] = paramSource.m_Data[6];	m_Data[7] = paramSource.m_Data[7];	m_Data[8] = paramSource.m_Data[8];
			}
			inline T & operator[] (unsigned int paramPos)
			{
				if (paramPos >= 9)
					throw std::logic_error("bad index");
				return m_Data[paramPos];
			}

			inline const T & operator[] (unsigned int paramPos) const
			{
				if (paramPos >= 9)
					throw std::logic_error("bad index");
				return m_Data[paramPos];
			}

			inline T& operator() (unsigned int paramPosL, unsigned int paramPosC)
			{
				if (paramPosL >= 3 || paramPosC >= 3)
					throw std::logic_error("bad index");
				return m[3 * paramPosL + paramPosC];
			}

			inline const T & operator() (unsigned int paramPosL, unsigned int paramPosC) const
			{
				if (paramPosL >= 3 || paramPosC >= 3)
					throw std::logic_error("bad index");
				return m[3 * paramPosL + paramPosC];
			}

			inline void Reset()
			{
				m_Data[0] = T();	m_Data[1] = T();	m_Data[2] = T();
				m_Data[3] = T();	m_Data[4] = T();	m_Data[5] = T();
				m_Data[6] = T();	m_Data[7] = T();	m_Data[8] = T();
			}
			
			inline void SetIdentity()
			{
				m_Data[0] = T(1);	m_Data[1] = T();	m_Data[2] = T();
				m_Data[3] = T();	m_Data[4] = T(1);	m_Data[5] = T();
				m_Data[6] = T();	m_Data[7] = T();	m_Data[8] = T(1);
			}

			Matrix3x3<T> & operator+=(const Matrix3x3<T> & paramSource)
			{
				m_Data[0] += paramSource.m_Data[0];
				m_Data[1] += paramSource.m_Data[1];
				m_Data[2] += paramSource.m_Data[2];
				m_Data[3] += paramSource.m_Data[3];
				m_Data[4] += paramSource.m_Data[4];
				m_Data[5] += paramSource.m_Data[5];
				m_Data[6] += paramSource.m_Data[6];
				m_Data[7] += paramSource.m_Data[7];
				m_Data[8] += paramSource.m_Data[8];

				return (*this);
			}

			Matrix3x3<T> operator+(const Matrix3x3<T> & paramSource) const
			{
				return Matrix3x3<T>(m_Data[0] + paramSource.m_Data[0], m_Data[1] + paramSource.m_Data[1], m_Data[2] + paramSource.m_Data[2],
					m_Data[3] + paramSource.m_Data[3], m_Data[4] + paramSource.m_Data[4], m_Data[5] + paramSource.m_Data[5],
					m_Data[6] + paramSource.m_Data[6], m_Data[7] + paramSource.m_Data[7], m_Data[8] + paramSource.m_Data[8]);
			}

			Matrix3x3<T> & operator-=(const Matrix3x3<T> & paramSource)
			{
				m_Data[0] -= paramSource.m_Data[0];
				m_Data[1] -= paramSource.m_Data[1];
				m_Data[2] -= paramSource.m_Data[2];
				m_Data[3] -= paramSource.m_Data[3];
				m_Data[4] -= paramSource.m_Data[4];
				m_Data[5] -= paramSource.m_Data[5];
				m_Data[6] -= paramSource.m_Data[6];
				m_Data[7] -= paramSource.m_Data[7];
				m_Data[8] -= paramSource.m_Data[8];

				return (*this);
			}

			Matrix3x3<T> operator-(const Matrix3x3<T> & paramSource) const
			{
				return Matrix3x3<T>(m_Data[0] - paramSource.m_Data[0], m_Data[1] - paramSource.m_Data[1], m_Data[2] - paramSource.m_Data[2],
					m_Data[3] - paramSource.m_Data[3], m_Data[4] - paramSource.m_Data[4], m_Data[5] - paramSource.m_Data[5],
					m_Data[6] - paramSource.m_Data[6], m_Data[7] - paramSource.m_Data[7], m_Data[8] - paramSource.m_Data[8]);
			}
		};
	}
}
