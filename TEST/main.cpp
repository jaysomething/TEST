// Take the Fraction class we wrote in the previous quiz (listed below) and add an overloaded operator<< and operator>> to it.

#include <iostream>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;
	
public:
	Fraction(int numerator=0, int denominator=1):
	m_numerator(numerator), m_denominator(denominator)
	{
		// We put reduce() in the constructor to ensure any new fractions we make get reduced!
		// Any fractions that are overwritten will need to be re-reduced
		reduce();
	}
	
	// We'll make gcd static so that it can be part of class Fraction without requiring an object of type Fraction to use
	static int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a % b);
	}
	
	void reduce()
	{
		if (m_numerator != 0 && m_denominator != 0)
		{
			int gcd = Fraction::gcd(m_numerator, m_denominator);
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}
	
	friend std::ostream& operator<< (std::ostream& out, const Fraction& f1);
	friend std::istream& operator>> (std::istream& in, Fraction& f1);
	
	friend Fraction operator*(const Fraction &f1, const Fraction &f2);
	friend Fraction operator*(const Fraction &f1, int value);
	friend Fraction operator*(int value, const Fraction &f1);
	
	void print()
	{
		std::cout << m_numerator << "/" << m_denominator << "\n";
	}
};

std::ostream& operator<< (std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

std::istream& operator>> (std::istream& in, Fraction& f1)
{
	char slash;
	in >> f1.m_numerator >> slash >> f1.m_denominator;
	return in;
}


// Learncpp's solution

/*
 std::istream& operator>>(std::istream &in, Fraction &f1)
 {
	 // Overwrite the values of f1
	 in >> f1.m_numerator;
  
	 // Ignore the '/' separator
	 in.ignore(std::numeric_limits<std::streamsize>::max(), '/');
  
	 in >> f1.m_denominator;
  
	 // Since we overwrite the existing f1, we need to reduce again
	 f1.reduce();
  
	 return in;
 }
 */



Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator*(const Fraction &f1, int value)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}

Fraction operator*(int value, const Fraction &f1)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}

int main()
{
	
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;
	
	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;
	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value
	
	return 0;
}

//Enter fraction 1: 2/3
//Enter fraction 2: 3/8
//2/3 * 3/8 is 1/4

