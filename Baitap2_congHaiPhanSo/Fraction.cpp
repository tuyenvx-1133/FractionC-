//
//  Fraction.cpp
//  Baitap2_congHaiPhanSo
//
//  Created by TuyenVX on 12/20/17.
//  Copyright © 2017 TuyenVX. All rights reserved.
//

#include "Fraction.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

struct Fraction {
    int numerator;
    int denominator;
    Fraction() {
        numerator = 0;
        denominator = 1;
    }
    Fraction(int numerator, int denominator) {
        if(denominator != 0) {
            this->numerator = numerator;
            this->denominator = denominator;
        } else {
            this->numerator = 0;
            this->denominator = 1;
        }
    }
    Fraction operator+(Fraction second) {
        Fraction first = *this;
        int numerator = first.numerator * second.denominator + first.denominator * second.numerator;
        int denominator = first.denominator * second.denominator;
        Fraction fraction = Fraction(numerator,denominator);
        fraction.reduce();
        return fraction;
    }
    Fraction operator-(Fraction second) {
        Fraction first = *this;
        int numerator = first.numerator * second.denominator - first.denominator * second.numerator;
        int denominator = first.denominator * second.denominator;
        Fraction fraction = Fraction(numerator,denominator);
        fraction.reduce();
        return fraction;
    }
    Fraction operator*(Fraction second) {
        Fraction first = *this;
        int numerator = first.numerator * second.numerator;
        int denominator = first.denominator * second.denominator;
        Fraction fraction = Fraction(numerator,denominator);
        fraction.reduce();
        return fraction;
    }
    Fraction operator/(Fraction second) {
        Fraction first = *this;
        int numerator = first.numerator * second.denominator;
        int denominator = first.denominator * second.numerator;
        Fraction fraction = Fraction(numerator,denominator);
        fraction.reduce();
        return fraction;
    }
    void reduce(){
        Fraction fraction = *this;
        int ucln = UCLN(fraction.numerator, fraction.denominator);
        fraction.numerator = fraction.numerator / ucln;
        fraction.denominator = fraction.denominator / ucln;
        *this = fraction;
    }
    int UCLN(int a, int b) {
        a = abs(a);
        b = abs(b);
        if (a==0 ||b==0)
            return a+b;
        while (a!=b)
        {
            if(a>b)
                a=a-b;
            else
                b=b-a;
        }
        return a;
    }
    void print() {
        Fraction self = *this;
        cout << self.numerator << "/" << self.denominator;
    }
};
