#include <iostream>
#include <limits.h>
#include "BigInt.h" 
using namespace std;
struct ThreeNp1 {
    BigInt start;
    BigInt steps;
    BigInt max;
    BigInt odd;
    BigInt even;
};

void print(ThreeNp1 temp) {
    cout << "start:"<<temp.start<<endl;
    cout << "steps:"<<temp.steps<<endl;
    cout << "max:"<<temp.max<<endl;
    cout << "odds:"<<temp.odd<<endl;
    cout << "evens:"<<temp.even<<endl;
}

void findThreeNp1(BigInt n, ThreeNp1 & Np1, bool printSteps = false) { 
    if (printSteps) {
    cout << "->"<<'('<< n <<')'; 
    }
    if (Np1.max < n) {
    Np1.max = n;
    }

    if (n == BigInt(1)) { 
    return;
    }
    else if (n.isEven()) {
    Np1.even++;
    Np1.steps++;
    findThreeNp1(n.half(), Np1, printSteps);
    }
    else if (n.isOdd()) {
    ++Np1.odd;
    ++Np1.steps;
    BigInt tempN(n);
    findThreeNp1(tempN*BigInt(3)+BigInt(1), Np1, printSteps);
    }
    else {
    cout << "How did I get here?\n";
    return;
    }
}

int main() {
    BigInt MAX(INT_MAX);
    cout << "The largest integer is "<< MAX<<endl;
    cout << "Twice the largest integer is "<< MAX + MAX << endl;
    BigInt start(INT_MAX);
    bool printSteps = false;
    ThreeNp1 N = {start,0,0,0,0};
    findThreeNp1(start, N, printSteps);
    cout << endl; 
    print(N);
    return 0;
}