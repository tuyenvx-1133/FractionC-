//
//  main.cpp
//  Baitap2_congHaiPhanSo
//
//  Created by TuyenVX on 12/20/17.
//  Copyright © 2017 TuyenVX. All rights reserved.
//

#include "Fraction.cpp"
#include <iostream>

using namespace std;


int main(int argc, const char * argv[]) {
    Fraction first = Fraction();
    Fraction second = Fraction();
    cout << "Nhap phan so thu nhat : " << endl;;
    cin >> first.numerator >> first.denominator;
    cout << "Nhap phan so thu hai : " << endl;
    cin >> second.numerator >> second.denominator;
    Fraction result = first * second;
    result.print();
    return 0;
}
