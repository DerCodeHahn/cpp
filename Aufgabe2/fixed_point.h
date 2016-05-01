#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <string>
#include <stdint.h>

class fixed_point{
public:
    fixed_point(float n=0.0f);
    fixed_point(int32_t n=0);
    fixed_point operator -() const;
    fixed_point& operator=(fixed_point const& rhs);
    fixed_point operator+(fixed_point rhs) const;
    fixed_point operator-(fixed_point rhs) const;
    fixed_point operator*(fixed_point rhs) const;
    fixed_point operator/(fixed_point rhs) const;
    fixed_point& operator+=(fixed_point const& rhs);
    fixed_point& operator-=(fixed_point const& rhs);
    fixed_point& operator*=(fixed_point const& rhs);
    fixed_point& operator/=(fixed_point const& rhs);
    bool operator<(fixed_point rhs) const;
    bool operator>(fixed_point rhs) const;
    bool operator==(fixed_point rhs) const;
    bool operator!=(fixed_point rhs) const;
    bool operator<=(fixed_point rhs) const;
    bool operator>=(fixed_point rhs) const;
    std::ostream& operator<< ( std::ostream& os )const;
    explicit operator float() const;
    explicit operator int() const;
//    operator int();
    fixed_point operator++(int rhs);
    fixed_point& operator++();
    fixed_point operator--(int rhs);
    fixed_point& operator--();
    friend fixed_point abs(fixed_point fp);
    std::string toString() const;
    int32_t getQ() const;
    friend fixed_point sin(fixed_point fp);
    friend fixed_point cos(fixed_point fp);
    friend fixed_point pow(fixed_point b, int16_t e);
    friend int factorial(int n);
private:
    int32_t mQ;
};

#endif // FIXED_POINT_H
