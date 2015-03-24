#pragma once
namespace prj {
namespace math {
	class SimpleVector3D
	{
		private:
			double m_x;
			double m_y;
			double m_z;
		public:
			inline SimpleVector3D(void) : m_x(0.0), m_y(0.0), m_z(0.0) {}
			inline SimpleVector3D(double p_x, double p_y, double p_z) : m_x(p_x), m_y(p_y), m_z(p_z) {}
			inline SimpleVector3D(const SimpleVector2D & p_source)
			{
				m_x = p_source.m_x;
				m_y = p_source.m_y;
				m_z = p_source.m_z;
			}
			
			inline double GetX(void) const { return m_x; }
			inline double GetY(void)const { return m_y; }
			inline double GetZ(void)const { return m_z; }
			inline void SetX(double p_value) { m_x = p_value; }
			inline void SetY(double p_value) { m_y = p_value; }
			inline void SetZ(double p_value) { m_z = p_value; }
			
			inline SimpleVector3D & operator += (const SimpleVector3D & p_source)
			{
				m_x += p_source.m_x;
				m_y += p_source.m_y;
				m_z += p_source.m_z;
				return (*this);
			}
			
			inline SimpleVector3D operator + (const SimpleVector3D & p_source) const
			{
				return p_source + (*this);
			}
			
			inline SimpleVector3D & operator -= (const SimpleVector3D & p_source)
			{
				m_x -= p_source.m_x;
				m_y -= p_source.m_y;
				m_z -= p_source.m_z;
				return (*this);
			}
			
			inline SimpleVector3D operator - (const SimpleVector3D & p_source) const
			{
				return p_source - (*this);
			}
			
			SimpleVector3D operator * (const double & p_value) const
			{
				return SimpleVector3D(m_x*p_value, m_y*p_value, m_z*p_value);
			}
			
			SimpleVector2D & operator *= (const double & p_value)
			{
				m_x *= p_value;
				m_y *= p_value;
				m_z *= p_value;
				return (*this);
			}
			
			SimpleVector3D operator / (const double & p_value) const
			{
				if (p_value == 0.0)
					throw;
				return SimpleVector3D(m_x / p_value, m_y / p_value, m_z / p_value);
			}
			
			SimpleVector3D & operator /= (const double & p_value)
			{
				if (p_value == 0.0)
					throw;
				m_x /= p_value;
				m_y /= p_value;
				m_z /= p_value;
				return (*this);
			}
			
			SimpleVector3D operator * (const SimpleVector3D & p_source) const
			{
				return SimpleVector3D(*this)*p_source;
			}
			
			SimpleVector2D & operator *= (SimpleVector2D & p_source)
			{
				m_x *= p_source.m_x;
				m_y *= p_source.m_y;
				m_z *= p_source.m_y;
				return (*this);
			}
			double operator ^ (SimpleVector3D & p_source) const
			{
				return (m_x * p_source.m_y) - (m_y * p_source.m_x);
			}
			bool operator == (const SimpleVector3D & p_source)
			{
				return ((m_x == p_source.m_x) && (m_y == p_source.m_y) && (m_z == p_source.m_z));
			}
			
			bool operator != (const SimpleVector3D & p_source)
			{
				return !this->operator == (p_source);
			}
			
			double LengthSquared (void)
			{
				return m_x * m_x + m_y * m_y + m_z * m_z;
			}
		
	};
}
}
