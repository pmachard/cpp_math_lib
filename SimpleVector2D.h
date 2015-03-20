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
    
    inline SimpleVector2D operator + (const SimpleVector2D & p_source) const
    {
      return SimpleVector2D(p_source.GetX()+GetX(), p_source.GetY()+GetY());
    }
};
