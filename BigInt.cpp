#include <iostream>
#include "BigInt.h"
using namespace std;

BigInt::BigInt() {
  v.push_back('0');
}

BigInt::BigInt(int num) {
  while (num != 0) {
    v.push_back(num % 10 + '0');
    num /= 10;
  }
}

BigInt::BigInt(string str) {
  for (int i = 0; i < str.size(); i++) {
    v.push_back(str[i]);
  }
}

int BigInt::operator[](int index) const {
  if (index < 0 or index >= v.size()) {
    cerr << "Index out of range\n";
    return -1;
  }
  return v[index] - '0';
}

int BigInt::size() const {
  return v.size();
}

BigInt BigInt::operator+(BigInt other) {
  BigInt res;
  int n1 = v.size();
  int n2 = other.size();
  int nMax = max(n1, n2);
  res.v.clear();
  int carry = 0;
  for (int i = 0; i < nMax or carry != 0; ++i) {
      int digit1 = 0;
      int digit2 = 0;
      if (i < n1) {
          digit1 = v[i] - '0';
      }
      if (i < n2) {
          digit2 = other.v[i] - '0';
      }
      int sum = digit1 + digit2 + carry;
      carry = sum / 10;
      res.v.push_back((sum % 10) + '0');
  }
  return res;
}

BigInt BigInt::operator++() {
  *this = *this + 1;
  return *this;
}

BigInt BigInt::operator++(int) {
  ++(*this);
  return *this;
}

BigInt BigInt::operator*(BigInt other) {
  BigInt res(*this);
  BigInt num(*this);
  for (int i = 1; i < (other); i++) {
    res = res + num;
  }
  return res;
}

BigInt BigInt::half() {
  BigInt res(*this);
  int carry = 0;
  for (int i = res.size() - 1; i >= 0; i--) {
    int digit = res.v[i] - '0';
    int new_digit = carry * 10 + digit;
    carry = new_digit % 2;
    res.v[i] = (new_digit / 2) + '0';
  }
  while (res.size() > 1 and res.v.back() == '0') {
    res.v.pop_back();
  }
  return res;
}

bool BigInt::isOdd() {
  return v[0] % 2 != 0;
}

bool BigInt::isEven() {
  return v[0] % 2 == 0;
}

bool BigInt::operator==(BigInt other) {
  return v == other.v;
}

bool operator<(const BigInt &num1, const BigInt &num2) {
  int n1 = num1.size();
  int n2 = num2.size();
  if (n1 != n2) {
    return n1 < n2;
  }
  for (int i = n1 - 1; i >= 0; i--) {
    if (num1[i] != num2[i]) {
      return num1[i] < num2[i];
    }
  }
  return false;
}

ostream &operator<<(::ostream &os, const BigInt &num) {
  for (int i = num.size() - 1; i >= 0; --i) {
    os << num[i];
  }
  return os;
}