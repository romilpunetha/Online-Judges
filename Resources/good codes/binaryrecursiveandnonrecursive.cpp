#include <iostream>
using namespace std;
int binbin1(int);
void binbin2(int);

int main() {
    int T;
    cout << "enter the no of test cases" << endl;
    cin >> T;
    while (T--) {
        int a;
        cout << " \n enter the no" << endl;
        cin >> a;
        binbin1(a);
        binbin2(a);
        // cout<<"ans1 "<<z1<<endl;
        // cout<<"ans2 "<<z2<<endl;
    }
    return 0;
}
int binbin1(int a) {
    int z, A[100] = { 0 };
    int i = 0;
    cout << "ans1 ";
    while (a != 0) {
        A[i] = a % 2;
        a = a / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        cout << A[j];
    cout << endl;
}

void binbin2(int a) {
    if (a < 2)
        cout << a;
    else {
        binbin2(a / 2);
        cout << (a % 2);
    }
}
