#include <iostream>
using namespace std;
int main() {
    int test = 0;
    cin >> test;
    long int sieve[1000000] = { 0 };
    long int m_n[100001];
    for (long int i = 2; i <= 1000000; i++) {
        sieve[i] = 1;
    }
    for (long int i = 2; i < 1000000; i++) {
        long int j = i;
        while (i * j <= 1000000) {
            if (sieve[j] == 1) {
                if (j % i == 0) {
                    sieve[j] = 0;
                }
            }
            j++
        }
    }
    while (test--) {
        long int m = 0, n = 0;
        cin >> m;
        cin >> n;
        for (long int i = 0; i <= 100001; i++) {
            m_n[i] = 0;
        }
        for (long int i = m; i <= n; i++) {
        }
    }
}
