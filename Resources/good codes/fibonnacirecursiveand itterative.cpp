#include <iostream>
using namespace std;
int fibon1(int);
int fibon2(int);
int main() {
    int a, z1, z2;
    a = 10;
    z1 = fibon1(a);
    z2 = fibon2(a);
    cout << "ans1 " << z1 << endl;
    cout << "ans2 " << z2 << endl;
    return 0;
}

int fibon1(int a) {
    int first = 0, second = 1, sum = 0;
    for (int i = 1; i <= a; i++) {
        sum = first + second;
        second = first;
        first = sum;
    }
    return sum;
}

int fibon2(int a) {
    if (a == 0) {
        return 0;
    } else if (a == 1) {
        return 1;
    } else {
        return (fibon2(a - 1) + fibon2(a - 2));
    }
}
