#include "fraction.h"
#include <iostream>
#include <cassert>

namespace cs_fraction {
	//ASK ABOUT THE VALUE OF "-x+y/z" ON WED. DOES IT EQUAL -x + y/z, OR IS IT -(x + y/z)? FIND OUT.
	Fraction::Fraction(int numer, int denom) {
		assert(denom != 0);
		this->numer = numer;
		this->denom = denom;
		(*this).simplify();
	}






	void Fraction::simplify() {
		// handle 0/x
		if (numer == 0) {
			denom = 1;
			return;
		}

		// handle signs of numerator & denominator
		if (denom < 0) {
			numer *= -1;
			denom *= -1;
		}

		// find gcf
		int gcf = 1;
		int greatest = denom;
		if (numer > denom) {
			greatest = numer;
		}
		if (numer % denom == 0) {
			gcf = denom;
		}
		for (int i = gcf; i <= denom / 2 + 1; i++) {
			if (denom % i == 0 && numer % i == 0) {
				gcf = i;
			}
		}

		// modify numerator & denominator
		numer /= gcf;
		denom /= gcf;
	}






	std::ostream& operator<< (std::ostream& out, const Fraction& frac) {
		if (frac.denom == 1) {
			std::cout << frac.numer;
		}
		else if (fabs(frac.numer) < frac.denom) {
			std::cout << frac.numer << '/' << frac.denom;
			}
		else {
			std::cout << frac.numer / frac.denom << '+' << frac.numer % frac.denom << '/' << frac.denom;
		}
		return out;
	}






	Fraction operator+(const Fraction& left, const Fraction& right) {
		int sumNumer = (left.numer * right.denom) + (right.numer * left.denom);
		int sumDenom = left.denom * right.denom;
		Fraction sum(sumNumer, sumDenom);
		return sum;
	}






	Fraction operator-(const Fraction& left, const Fraction& right) {
		int diffNumer = (left.numer * right.denom) - (right.numer * left.denom);
		int diffDenom = left.denom * right.denom;
		Fraction difference(diffNumer, diffDenom);
		return difference;
	}






	Fraction operator*(const Fraction& left, const Fraction& right) {
		int prodNumer = left.numer * right.numer;
		int prodDenom = left.denom * right.denom;
		Fraction product(prodNumer, prodDenom);
		return product;
	}






	Fraction operator/(const Fraction& left, const Fraction& right) {
		int quotNumer = left.numer * right.denom;
		int quotDenom = left.denom * right.numer;
		Fraction quotient(quotNumer, quotDenom);
		return quotient;
	}






	
}