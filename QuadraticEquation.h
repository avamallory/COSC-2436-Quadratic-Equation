#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H

class QuadraticEquation {
public:
     
  QuadraticEquation(double a, double b, double c);
  
  double getA() const;
  double getB() const;
  double getC() const;
  
  void setA(double a);
  void setB(double b);
  void setC(double c);
  
  void compute();
   
  private:
      double discriminant;
      double root1;        
      double root2;      
      double a;
      double b;
      double c;    
};

#endif


