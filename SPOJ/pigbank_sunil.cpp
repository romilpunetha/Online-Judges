#include <limits.h>

#include <iostream>
using namespace std;

struct C {
    int p;
    int w;
};
int main() {
    int T;
    cin >> T;
    while (T--) {
        int E, F, N;
        cin >> E >> F;
        cin >> N;
        C c[N];
        long long int M[F - E + 1];
        for (int i = 0; i < (F - E + 1); i++) M[i] = LLONG_MAX;
        for (int i = 0; i < N; i++) {
            cin >> c[i].p >> c[i].w;
            if (c[i].w < (F - E + 1)) M[c[i].w] = c[i].p;
        }
        for (int i = 0; i < (F - E + 1); i++) {
            if (M[i] == LLONG_MAX) continue;   // ignore
            for (int j = 0; j < N; j++) {
                if ((i + c[j].w) < (F - E + 1) && (M[i] + c[j].p) < M[i + c[j].w])
                    M[i + c[j].w] = M[i] + c[j].p;
            }
        }
        if (!(F - E))
            cout << "The minimum amount of money in the piggy-bank is 0.\n";
        else if (M[F - E] == LLONG_MAX)
            cout << "This is impossible.\n";
        else
            cout << "The minimum amount of money in the piggy-bank is " << M[F - E] << ".\n";
    }
    return 0;
}
