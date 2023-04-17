#include <iostream>   //here important point is conversion of single element from char to integer
using namespace std;
int main() {
    int z = 0;
    char A[] = { "123" };
    for (int i = 0; i < 3; i++) {
        z = z * 10 + (A[i] - '0');
    }
    cout << "ans " << z << endl;
    cout << "z -10    " << z - 10 << endl;
    return 0;
}
