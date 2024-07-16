#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <vector>
using namespace std;

class BigInt {
  private:
    vector<char> v;
  public:
    BigInt();
    BigInt(int);
    BigInt(string);
    int operator[](int) const;
    int size() const;
    BigInt operator+(BigInt);
    BigInt operator++( );
    BigInt operator++(int);
    BigInt operator*(BigInt);
    BigInt half();
    bool isOdd();
    bool isEven();
    bool operator==(BigInt);
    friend bool operator<(const BigInt&, const BigInt&);
    friend ostream& operator<<(ostream&, const BigInt&);
};

#endif