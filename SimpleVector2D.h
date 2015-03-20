class SimpleVector2D
{
  private:
    double m_x;
    double m_y;
    
  public:
    inline SimpleVector2D(void) : m_x(0.0),m_y(0.0) {}
    
    inline SimpleVector2D(double p_x, double p_y) : m_x(p_x),m_y(p_y) {}
};
