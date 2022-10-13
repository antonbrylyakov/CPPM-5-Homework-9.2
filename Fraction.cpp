#include "Fraction.h"


// Алгоритм евклида для нахождения НОД
int Fraction::getGcd(int v1, int v2)
{
	auto a = std::abs(v1);
	auto b = std::abs(v2);

	if (a == 0 || b == 0)
	{
		return 1;
	}
	auto large = a > b ? a : b;
	auto small = a > b ? b : a;
	do
	{
		auto r = large % small;
		if (r == 0)
		{
			return small;
		}

		large = small;
		small = r;
	} while (true);
}

Fraction::Fraction(int numerator, int denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Знаменатель не должен быть равен нулю");
	}

	numerator_ = numerator;
	denominator_ = denominator;
}

void Fraction::shorten()
{
	auto gcd = getGcd(numerator_, denominator_);
	numerator_ = numerator_ / gcd;
	denominator_ = denominator_ / gcd;
}

int Fraction::compare(const Fraction& other) const
{
	int currentN = numerator_;
	int otherN = other.numerator_;
	if (denominator_ != other.denominator_)
	{
		currentN = currentN * other.denominator_;
		otherN = otherN * denominator_;
	}

	return currentN > otherN ? 1 : (currentN == otherN ? 0 : -1);
}

bool Fraction::operator == (const Fraction& other) const
{
	return compare(other) == 0;
}

bool Fraction::operator != (const Fraction& other) const
{
	return compare(other) != 0;
}

bool Fraction::operator >= (const Fraction& other) const
{
	return compare(other) >= 0;
}

bool Fraction::operator > (const Fraction& other) const
{
	return compare(other) > 0;
}

bool Fraction::operator <= (const Fraction& other) const
{
	return compare(other) <= 0;
}

bool Fraction::operator < (const Fraction& other) const
{
	return compare(other) < 0;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
	os << f.numerator_;
	if (f.denominator_ != 1)
	{
		os << '/' << f.denominator_;
	}
	return os;
}

Fraction Fraction::operator + (const Fraction& other)
{
	Fraction f(other.numerator_ * denominator_ + numerator_ * other.denominator_, denominator_ * other.denominator_);
	f.shorten();
	return f;
}

Fraction Fraction::operator - (const Fraction& other)
{
	Fraction f(-other.numerator_ * denominator_ + numerator_ * other.denominator_, denominator_ * other.denominator_);
	f.shorten();
	return f;
}

Fraction Fraction::operator * (const Fraction& other)
{
	Fraction f(other.numerator_ * numerator_, denominator_ * other.denominator_);
	f.shorten();
	return f;
}

Fraction Fraction::operator / (const Fraction& other)
{
	if (other.numerator_ == 0 || other.denominator_ == 0)
	{
		throw std::runtime_error("Деление на ноль.");
	}

	Fraction f(numerator_ * other.denominator_, denominator_ * other.numerator_);
	f.shorten();
	return f;
}

Fraction Fraction::operator-() const
{
	Fraction f(-numerator_, denominator_);
	return f;
}

Fraction Fraction::operator++()
{
	numerator_ = numerator_ + denominator_;
	shorten();
	return *this;
}

Fraction Fraction::operator++(int d)
{
	Fraction f(numerator_, denominator_);
	numerator_ = numerator_ + denominator_;
	shorten();
	return f;
}

Fraction Fraction::operator--()
{
	numerator_ = numerator_ - denominator_;
	shorten();
	return *this;
}

Fraction Fraction::operator--(int d)
{
	Fraction f(numerator_, denominator_);
	numerator_ = numerator_ - denominator_;
	shorten();
	return f;
}