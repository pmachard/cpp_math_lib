class SimpleVector2D
{
  private:
    double m_x;
    double m_y;
    
  public:
    inline SimpleVector2D(void) : m_x(0.0),m_y(0.0) {}
    inline SimpleVector2D(double p_x, double p_y) : m_x(p_x),m_y(p_y) {}
    inline SimpleVector2D(const SimpleVector2D & p_source)
    {
      m_x = p_source.m_x;
      m_y = p_source.m_y;
    }
    
    inline double GetX(void) const  { return m_x; }
    inline double GetY(void)const  { return m_y; }
    inline void SetX(double p_value) { m_x = p_value; }
    inline void SetY(double p_value) { m_y = p_value; }
    
    inline SimpleVector2D & operator += (const SimpleVector2D & p_source) 
    {
      m_x += p_source.m_x;
      m_y += p_source.m_y;
      return (*this);
    }
    
    inline SimpleVector2D operator + (const SimpleVector2D & p_source) const
    {
      return p_source + (*this);
    }

    inline SimpleVector2D & operator -= (const SimpleVector2D & p_source) 
    {
      m_x -= p_source.m_x;
      m_y -= p_source.m_y;
      return (*this);
    }
    
    inline SimpleVector2D operator - (const SimpleVector2D & p_source) const
    {
      return p_source - (*this);
    }

SimpleVector2D operator * (const double & p_value) const
{
return SimpleVector2D(m_x*p_value,m_y*p_value);
}

SimpleVector2D & operator =* (const double & p_value)
{
m_x *= p_value;
m_y *= p_value;
return (*this)
}

SimpleVector2D operator / (const double & p_value) const
{
if (p_value == 0.0)
    throw new exception();
return SimpleVector2D(m_x/p_value,m_y/p_value);
}

SimpleVector2D & operator =/ (const double & p_value)
{
if (p_value == 0.0)
    throw new exception();
m_x /= p_value;
m_y /= p_value;
return (*this)
}
SimpleVector2D operator * (const SimpleVector2D & p_source) const
{
return SimpleVector2D(*this)*p_source;
}

SimpleVector2D & operator =* (SimpleVector2D & p_source)
{
m_x *= p_source.m_x;
m_y *= p_source.m_y;
return (*this)
}

double  operator ^ (SimpleVector2D & p_source) const
{
return (m_x * p_source.m_y )- (m_y * p_source.m_x);
}

bool operator == (const SimpleVector2D & p_source)
{
return ((m_x == p_source.m_x) && (m_y == p_source.m_y));
}

bool operator != (const SimpleVector2D & p_source)
{
return !this->operator(p_source);
}    
};
