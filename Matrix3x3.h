#pragma once

namespace prj {
	namespace math {

		/// @class mathematical matrice 3*3
		template <typename T> class Matrix3x3
		{
		private:
			/// matriceData
			T m_Data[9];
			
			const unsigned int Cel1x1 = 0;
			const unsigned int Cel1x2 = 1;
			const unsigned int Cel1x3 = 3;
			const unsigned int Cel2x1 = 4;
			const unsigned int Cel2x2 = 5;
			const unsigned int Cel2x3 = 6;
			const unsigned int Cel3x1 = 7;
			const unsigned int Cel3x2 = 8;
			const unsigned int Cel3x3 = 9;
			
		public:
			/// A default constructor.
			/// @brief all data is create with default constructor
			inline Matrix3x3<T>(void)
			{
				Reset();
			}

			/// constructor with uniq value.
			/// @brief all data is create with the same value
			inline Matrix3x3<T>(T paramValue)
			{
				SetAllValue(paramValue);
			}

			/// constructor 
			/// @brief all data is create with a specific value
			inline Matrix3x3<T>(T pramValue1x1, T pramValue1x1, T pramValue1x1,
								T pramValue2x2, T pramValue2x2, T pramValue2x2, 
								T pramValue3x3, T pramValue3x3, T pramValue3x3 )
			{
				m_Data[Cel1x1] = pramValue0x0;	m_Data[Cel1x2] = pramValue1x0;	m_Data[Cel3x1] = pramValue2x0;
				m_Data[Cel2x1] = pramValue1x0;	m_Data[Cel2x2] = pramValue1x1;	m_Data[Cel3x2] = pramValue2x1;
				m_Data[Cel3x1] = pramValue2x0;	m_Data[Cel3x2] = pramValue1x2;	m_Data[Cel3x3] = pramValue2x2;
			}

			/// constructor 
			/// @brief all data is create with a specific value
			inline Matrix3x3<T>(const Matrix3x3<T> & paramSource)
			{
				m_Data[Cel1x1] = paramSource.m_Data[Cel1x1];	m_Data[Cel1x2] = paramSource.m_Data[Cel1x2];	m_Data[Cel1x3] = paramSource.m_Data[Cel1x3];
				m_Data[Cel2x1] = paramSource.m_Data[Cel2x1];	m_Data[Cel2x2] = paramSource.m_Data[Cel2x2];	m_Data[Cel2x3] = paramSource.m_Data[Cel2x3];
				m_Data[Cel3x1] = paramSource.m_Data[Cel3x1];	m_Data[Cel3x2] = paramSource.m_Data[Cel3x2];	m_Data[Cel3x3] = paramSource.m_Data[Cel3x3];
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

			inline T & operator() (unsigned int paramPosL, unsigned int paramPosC)
			{
				if (paramPosL >= 3 || paramPosC >= 3)
					throw std::logic_error("bad index");
				return m_Data[3 * paramPosL + paramPosC];
			}

			inline const T & operator() (unsigned int paramPosL, unsigned int paramPosC) const
			{
				if (paramPosL >= 3 || paramPosC >= 3)
					throw std::logic_error("bad index");
				return m_Data[3 * paramPosL + paramPosC];
			}

			inline void Reset()
			{
				m_Data[Cel1x1] = T();	m_Data[Cel1x2] = T();	m_Data[Cel1x3] = T();
				m_Data[Cel2x1] = T();	m_Data[Cel2x2] = T();	m_Data[Cel2x3] = T();
				m_Data[Cel3x1] = T();	m_Data[Cel3x3] = T();	m_Data[Cel3x3] = T();
			}
			
			void SetAllValue(T paramValue)
			{
				m_Data[Cel1x1] = pramValue;	m_Data[Cel1x2] = pramValue;	m_Data[Cel1x3] = pramValue;
				m_Data[Cel2x1] = pramValue;	m_Data[Cel2x2] = pramValue;	m_Data[Cel2x3] = pramValue;
				m_Data[Cel3x1] = pramValue;	m_Data[Cel3x2] = pramValue;	m_Data[Cel3x3] = pramValue;
			}
			
			inline void SetIdentity()
			{
				m_Data[Cel1x1] = T(1);	m_Data[Cel1x2] = T();	m_Data[Cel1x3] = T();
				m_Data[Cel2x1] = T();	m_Data[Cel2x2] = T(1);	m_Data[Cel2x3] = T();
				m_Data[Cel3x1] = T();	m_Data[Cel3x3] = T();	m_Data[Cel3x3] = T(1);
			}

			Matrix3x3<T> & operator+=(const Matrix3x3<T> & paramSource)
			{
				m_Data[Cel1x1] += paramSource.m_Data[Cel1x1];
				m_Data[Cel1x2] += paramSource.m_Data[Cel1x2];
				m_Data[Cel1x3] += paramSource.m_Data[Cel1x3];
				
				m_Data[Cel2x1] += paramSource.m_Data[Cel2x1];
				m_Data[Cel2x2] += paramSource.m_Data[Cel2x2];
				m_Data[Cel2x3] += paramSource.m_Data[Cel2x3];
				
				m_Data[Cel3x1] += paramSource.m_Data[Cel3x1];
				m_Data[Cel3x2] += paramSource.m_Data[Cel3x2];
				m_Data[Cel3x3] += paramSource.m_Data[Cel3x3];

				return (*this);
			}

			Matrix3x3<T> operator+(const Matrix3x3<T> & paramSource) const
			{
				return Matrix3x3<T>(m_Data[Cel1x1] + paramSource.m_Data[Cel1x1], 
					m_Data[Cel1x2] + paramSource.m_Data[Cel1x2], 
					m_Data[Cel1x3] + paramSource.m_Data[Cel1x3],
					
					m_Data[Cel2x1] + paramSource.m_Data[Cel2x1], 
					m_Data[Cel2x2] + paramSource.m_Data[Cel2x2], 
					m_Data[Cel2x3] + paramSource.m_Data[Cel2x3],
					
					m_Data[Cel3x1] + paramSource.m_Data[Cel3x1], 
					m_Data[Cel3x2] + paramSource.m_Data[Cel3x2], 
					m_Data[Cel3x3] + paramSource.m_Data[Cel3x3]);
			}

			Matrix3x3<T> & operator-=(const Matrix3x3<T> & paramSource)
			{
				m_Data[Cel1x1] -= paramSource.m_Data[Cel1x1];
				m_Data[Cel1x2] -= paramSource.m_Data[Cel1x2];
				m_Data[Cel1x3] -= paramSource.m_Data[Cel1x3];
				
				m_Data[Cel2x1] -= paramSource.m_Data[Cel2x1];
				m_Data[Cel2x2] -= paramSource.m_Data[Cel2x2];
				m_Data[Cel2x3] -= paramSource.m_Data[Cel2x3];
				
				m_Data[Cel3x1] -= paramSource.m_Data[Cel3x1];
				m_Data[Cel3x2] -= paramSource.m_Data[Cel3x2];
				m_Data[Cel3x3] -= paramSource.m_Data[Cel3x3];

				return (*this);
			}

			Matrix3x3<T> operator-(const Matrix3x3<T> & paramSource) const
			{
				return Matrix3x3<T>(m_Data[Cel1x1] - paramSource.m_Data[Cel1x1], 
					m_Data[Cel1x2] - paramSource.m_Data[Cel1x2], 
					m_Data[Cel1x3] - paramSource.m_Data[Cel1x3],
					
					m_Data[Cel2x1] - paramSource.m_Data[Cel2x1], 
					m_Data[Cel2x2] - paramSource.m_Data[Cel2x2], 
					m_Data[Cel2x3] - paramSource.m_Data[Cel2x3],
					
					m_Data[Cel3x1] - paramSource.m_Data[Cel3x1], 
					m_Data[Cel3x2] - paramSource.m_Data[Cel3x2], 
					m_Data[Cel3x3] - paramSource.m_Data[Cel3x3]);
			}
			
			Matrix3x3<T>  operator* (const Matrix3x3<T> & paramSource)
			{
				return Matrix3x3<T>(
				m_Data[0] * paramSource.m_Data[0] + m_Data[1] * paramSource.m_Data[3] + m_Data[2] * paramSource.m_Data[6],
				m_Data[0] * paramSource.m_Data[1] + m_Data[1] * paramSource.m_Data[4] + m_Data[2] * paramSource.m_Data[7],
				m_Data[0] * paramSource.m_Data[2] + m_Data[1] * paramSource.m_Data[5] + m_Data[2] * paramSource.m_Data[8],
				m_Data[3] * paramSource.m_Data[0] + m_Data[4] * paramSource.m_Data[3] + m_Data[5] * paramSource.m_Data[6],
				m_Data[3] * paramSource.m_Data[1] + m_Data[4] * paramSource.m_Data[4] + m_Data[5] * paramSource.m_Data[7],
				m_Data[3] * paramSource.m_Data[2] + m_Data[4] * paramSource.m_Data[5] + m_Data[5] * paramSource.m_Data[8],
				m_Data[6] * paramSource.m_Data[0] + m_Data[7] * paramSource.m_Data[3] + m_Data[8] * paramSource.m_Data[6],
				m_Data[6] * paramSource.m_Data[1] + m_Data[7] * paramSource.m_Data[4] + m_Data[8] * paramSource.m_Data[7],
				m_Data[6] * paramSource.m_Data[2] + m_Data[7] * paramSource.m_Data[5] + m_Data[8] * paramSource.m_Data[8])
			}
			
			Matrix3x3<T> Transpose(void) const
			{
				return Matrix3x3<T>(m_Data[Cel1x1], m_Data[Cel1x2], m_Data[Cel1x3],
					m_Data[Cel2x1], m_Data[Cel2x2], m_Data[Cel2x3],
					m_Data[Cel3x1], m_Data[Cel3x2], m_Data[Cel3x3])
			}
			
		};
	}
}
