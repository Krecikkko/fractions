//
// Created by qubaq on 11.01.2024.
//

#include "Fraction.h"
#include <exception>


Fraction::Fraction() {
    nominator = 1;
    denominator = 1;
    simplify();
}

Fraction::Fraction(int nominator, int denominator) {
    if (denominator == 0) throw std::domain_error("The denominator cannot be 0.");
    this->nominator = nominator;
    this->denominator = denominator;
    this->simplify();
}

int Fraction::nwd(int a, int b) {
    if (a%b == 0) return b;
    return nwd(b, a%b);
}

int Fraction::nww(int a, int b) {
    return (a / nwd(a,b)) * b;
}

void Fraction::get_equal_denominator(Fraction* a, Fraction* b) {
    int nww_ = nww(a->denominator, b->denominator);
    a->nominator *= (nww_ / a->denominator);
    b->nominator *= (nww_ / b->denominator);
    a->denominator = nww_;
    b->denominator = nww_;
}

void Fraction::simplify() {
    int nwd_ = nwd(nominator, denominator);
    nominator = nominator / nwd_;
    denominator = denominator / nwd_;
    if (denominator < 0) {
        nominator *= -1;
        denominator *= -1;
    }
    if (nominator == 0) denominator = 1;
}

void Fraction::add(Fraction a, Fraction b) {
    if (a.denominator == b.denominator) {
        nominator = a.nominator + b.nominator;
        denominator = a.denominator;
    } else {
        get_equal_denominator(&a, &b);
        denominator = a.denominator;
        nominator = a.nominator + b.nominator;
    }
    simplify();
}

void Fraction::subtract(Fraction a, Fraction b) {
    if (a.denominator == b.denominator) {
        nominator = a.nominator - b.nominator;
        denominator = a.denominator;
    } else {
        get_equal_denominator(&a, &b);
        denominator = a.denominator;
        nominator = a.nominator - b.nominator;
    }
    simplify();
}

void Fraction::multiply(Fraction a, Fraction b) {
    nominator = a.nominator * b.nominator;
    denominator = a.denominator * b.denominator;
    simplify();
}

void Fraction::divide(Fraction a, Fraction b) {
    int temp = b.nominator;
    b.nominator = b.denominator;
    b.denominator = temp;
    multiply(a, b);
}

Fraction Fraction::operator+(Fraction& other) {
    Fraction result;
    if (denominator == other.denominator) {
        result.nominator = nominator + other.nominator;
        result.denominator = denominator;
    } else {
        get_equal_denominator(this, &other);
        result.denominator = denominator;
        result.nominator = nominator + other.nominator;
    }
    result.simplify();
    return result;
}

Fraction Fraction::operator-(Fraction &other) {
    Fraction result;
    if (denominator == other.denominator) {
        result.nominator = nominator - other.nominator;
        result.denominator = denominator;
    } else {
        get_equal_denominator(this, &other);
        result.denominator = denominator;
        result.nominator = nominator - other.nominator;
    }
    result.simplify();
    return result;
}

Fraction Fraction::operator*(Fraction &other) const {
    Fraction result;
    result.nominator = nominator * other.nominator;
    result.denominator = denominator * other.denominator;
    result.simplify();
    return result;
}

Fraction Fraction::operator/(Fraction &other) const {
    Fraction result;
    result.nominator = nominator * other.denominator;
    result.denominator = denominator * other.nominator;
    result.simplify();
    return result;
}

std::ostream &operator << (std::ostream &stream, Fraction const c) {
    if (c.nominator % c.denominator == 0) {
        stream << c.nominator;
    } else {
        stream << c.nominator << "/" << c.denominator;
    }
    return stream;
}
