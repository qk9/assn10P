#ifndef FRACTION_H
#define FRACTION_H

#include <cassert>
#include <iostream>
namespace cs_fraction {
	class Fraction {
	public:
		Fraction(int numer = 0, int denom = 1);
		friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);
		friend Fraction operator+(const Fraction& left, const Fraction& right);
		friend Fraction operator-(const Fraction& left, const Fraction& right);
		friend Fraction operator*(const Fraction& left, const Fraction& right);
		friend Fraction operator/(const Fraction& left, const Fraction& right);
		friend bool operator==(const Fraction& left, const Fraction& right);
		friend bool operator!=(const Fraction& left, const Fraction& right);
		friend bool operator>(const Fraction& left, const Fraction& right);
	private:
		int numer;
		int denom;
		void simplify();
	};
}

#endif