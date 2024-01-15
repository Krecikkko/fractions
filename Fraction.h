#ifndef C_FRACTIONS_FRACTION_H
#define C_FRACTIONS_FRACTION_H


#include <iostream>

class Fraction {
private:
    int nominator;
    int denominator;

    int nwd(int a, int b);
    int nww(int a, int b);
    void get_equal_denominator(Fraction* a, Fraction* b);
    void simplify();
public:
    Fraction();
    Fraction(int nominator, int denominator);

    void add(Fraction a, Fraction b);
    void subtract(Fraction a, Fraction b);
    void multiply(Fraction a, Fraction b);
    void divide(Fraction a, Fraction b);

    Fraction operator+(Fraction& other);
    Fraction operator-(Fraction& other);
    Fraction operator*(Fraction& other) const;
    Fraction operator/(Fraction& other) const;
    friend std::ostream &operator << (std::ostream &stream, Fraction c);
};


#endif //C_FRACTIONS_FRACTION_H
