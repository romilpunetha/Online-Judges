#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> sieve(1000000, 1);
    sieve[0] = 0;
    sieve[1] = 0;
    for (long int i = 2; i < 1000000; i++) {
        if (sieve[i] == 1) {
            for (long int j = i * i; j < 1000000; j = j + i) {
                sieve[j] = 0;
            }
        }
    }
    vector<int> mobius(1000000, 1);
    for (long int i = 2; i < 1000000; i++) {
        if (sieve[i] == 1) {
            mobius[i] = -1;
            for (long int k = i * i, l = 1; k * l < 1000000; l++) {
                mobius[k * l] = 0;
            }
        } else if (mobius[i] == 1) {
        }
        for (int i = 0; i <= 50; i++) {
            cout << "i= " << i << " and mobius[i]= " << mobius[i] << endl;
        }

        return 0;
    }
