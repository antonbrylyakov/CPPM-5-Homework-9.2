#pragma once
#include <iostream>
#include <cmath>
#include <stdexcept>

class Fraction
{
private:
	int numerator_;

	int denominator_;

	int getGcd(int v1, int v2);
public:
	Fraction(int numerator, int denominator);

	void shorten();

	int compare(const Fraction& other) const;

	bool operator == (const Fraction& other) const;

	bool operator != (const Fraction& other) const;

	bool operator >= (const Fraction& other) const;

	bool operator > (const Fraction& other) const;

	bool operator <= (const Fraction& other) const;

	bool operator < (const Fraction& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Fraction& f);

	Fraction operator + (const Fraction& other);

	Fraction operator - (const Fraction& other);

	Fraction operator * (const Fraction& other);

	Fraction operator / (const Fraction& other);

	Fraction operator-() const;

	Fraction operator++();

	Fraction operator++(int d);

	Fraction operator--();

	Fraction operator--(int d);
};


