/*
 1c) Extra credit: the fraction 2/4 is the same as 1/2, but 2/4 is not reduced to the lowest terms. We can reduce any given fraction to lowest terms by finding the greatest common divisor (GCD) between the numerator and denominator, and then dividing both the numerator and denominator by the GCD.

 The following is a function to find the GCD:
 int gcd(int a, int b) {
     return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
 }
 Add this function to your class, and write a member function named reduce() that reduces your fraction. Make sure all fractions are properly reduced.
*/
#include <iostream>
 
class Fraction
{
public:
    Fraction(int numerator=0, int denominator=1) : m_numerator(numerator), m_denominator(denominator)
    { reduce(); }
    
    void print()
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
    
    // We'll make gcd static so that it can be part of class Fraction without requiring an object of type Fraction to use
    static int gcd(int a, int b)
    {
        return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
    }
    
    void reduce()
    {
        if ( m_numerator != 0 && m_denominator !=0)
        {
            int gcd = Fraction::gcd(m_numerator, m_denominator);
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }
    
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, int value);
    friend Fraction operator*(int value, const Fraction& f1);
    
private:
    int m_numerator;
    int m_denominator;
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator*(const Fraction& f1, int value)
{
    return Fraction(f1.m_numerator * value, f1.m_denominator);
}

Fraction operator*(int value, const Fraction& f1)
{
    return Fraction(f1.m_numerator * value, f1.m_denominator);
}

int main()
{
    Fraction f1(2, 5);
    f1.print();
    
    Fraction f2(3, 8);
    f2.print();
    
    Fraction f3 = f1 * f2;
    f3.print();
    
    Fraction f4 = f1 * 2;
    f4.print();
    
    Fraction f5 = 2 * f2;
    f5.print();
    
    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();
    
    Fraction f7(0, 6);
    f7.print();
    
    
    return 0;
}

/*
This should print:

2/5
3/8
3/20
4/5
3/4
1/4
0/6
 
 */
