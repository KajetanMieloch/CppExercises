#include <iostream>
#include <cmath>

class Fraction
{
    // or C++17's std::gcd
    constexpr int64_t gcd(int64_t a, int64_t b) { return b == 0 ? a : gcd(b, a % b); }
 
    int64_t n, d;
public:
    constexpr Fraction(int64_t n, int64_t d = 1) : n(n/gcd(n, d)), d(d/gcd(n, d)) {}
 
    constexpr int64_t num() const { return n; }
    constexpr int64_t den() const { return d; }
 
    constexpr Fraction& operator*=(const Fraction& rhs)
    {
        int64_t new_n = n * rhs.n / gcd(n * rhs.n, d * rhs.d);
        d = d * rhs.d / gcd(n * rhs.n, d * rhs.d);
        n = new_n;
        return *this;
    }
};
 
std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
   return out << f.num() << '/' << f.den();
}
 
constexpr bool operator==(const Fraction& lhs, const Fraction& rhs)
{
    return lhs.num() == rhs.num() && lhs.den() == rhs.den();
}
 
constexpr bool operator!=(const Fraction& lhs, const Fraction& rhs)
{
    return !(lhs == rhs);
}
 
constexpr Fraction operator*(Fraction lhs, const Fraction& rhs)
{
    return lhs *= rhs;
}

constexpr Fraction operator+(Fraction lhs, const Fraction& rhs)
{
    return Fraction(lhs.num() * rhs.den() + rhs.num() * lhs.den(), lhs.den() * rhs.den());
}

constexpr Fraction operator+=(Fraction& lhs, const Fraction& rhs)
{
    return lhs = lhs + rhs;
}

constexpr Fraction operator-(Fraction lhs, const Fraction& rhs)
{
    return Fraction(lhs.num() * rhs.den() - rhs.num() * lhs.den(), lhs.den() * rhs.den());
}

constexpr Fraction operator-=(Fraction& lhs, const Fraction& rhs)
{
    return lhs = lhs - rhs;
}

constexpr Fraction operator/(Fraction lhs, const Fraction& rhs)
{
    return Fraction(lhs.num()*rhs.den(), lhs.den()*rhs.num());
}

constexpr Fraction operator/=(Fraction lhs, const Fraction& rhs)
{
    return lhs = lhs/rhs;
}

double to_double(const Fraction& f)
{
    return static_cast<double>(f.num())/f.den();
}

constexpr Fraction sum1(int n)
{
    Fraction sum = Fraction{0,1};
    for (int i = 1; i <= n; i++)
    {
        sum += Fraction(1, i*(i+1));
    }
    return sum;
}

constexpr Fraction sum2(int n)
{
    Fraction sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + Fraction(pow(-1, i+1), i);
    }
    return sum;
}

constexpr Fraction sum3(int n)
{
    Fraction sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + Fraction(1, pow(2, i)*i);
    }
    return sum;
}
 
int main()
{
    std::cout << sum1(5) << std::endl;
    std::cout << sum2(5) << std::endl;
    std::cout << sum3(5) << std::endl;
}