#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <string>
#include <stdint.h>

class Fixed_Point{
public:
    Fixed_Point(float n=0.0f);
    Fixed_Point(int32_t n=0);
    Fixed_Point& operator=(Fixed_Point const& rhs);
    Fixed_Point operator+(Fixed_Point rhs) const;
    Fixed_Point operator-(Fixed_Point rhs) const;
    Fixed_Point operator*(Fixed_Point rhs) const;
    Fixed_Point operator/(Fixed_Point rhs) const;
    bool operator<(Fixed_Point rhs) const;
    bool operator>(Fixed_Point rhs) const;
    bool operator==(Fixed_Point rhs) const;
    bool operator<=(Fixed_Point rhs) const;
    bool operator>=(Fixed_Point rhs) const;
    std::ostream& operator<< ( std::ostream& os )const;
    operator float();
//    operator int();
    Fixed_Point operator++();
    Fixed_Point& operator++(int rhs);
    Fixed_Point operator--();
    Fixed_Point& operator--(int rhs);
    friend Fixed_Point abs(Fixed_Point fp);
    std::string toString() const;
    int32_t getQ() const;
    friend Fixed_Point sin(Fixed_Point fp);
    friend Fixed_Point cos(Fixed_Point fp);
    friend Fixed_Point pow(Fixed_Point b, int16_t e);
    friend int factorial(int n);
private:
    int32_t mQ;
};

#endif // FIXED_POINT_H
