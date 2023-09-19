#include <iostream>

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
    return Fraction{lhs.num(), lhs.den()} = Fraction(lhs.num() * rhs.den() + rhs.num() * lhs.den(), lhs.den() * rhs.den());
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
 
int main()
{
    constexpr Fraction f1{3, 8}, f2{1, 2}, f3{0, 1};
    std::cout<<(f3 * f2)<<std::endl;
    std::cout<<(f1 += f3) <<std::endl;
    std::cout<<to_double(f1)<<std::endl;
}