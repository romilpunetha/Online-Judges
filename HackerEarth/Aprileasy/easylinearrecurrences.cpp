#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > vll;
typedef vector<ll> vl;
int mod = 1000000007;
unordered_map<int, int> mp;
vll mul(vll &a, vll &b, int ilim, int jlim, int klim) {
    vll res(ilim, vl(jlim, 0));
    for (int i = 0; i < ilim; i++) {
        for (int j = 0; j < jlim; j++) {
            for (int k = 0; k < klim; k++) {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    return res;
}

vll fastexp(vll arr, int q) {
    vll res(5, vl(5, 0));
    for (int i = 0; i < 5; i++) {
        res[i][i] = 1;
    }
    while (q) {
        if (q & 1) {
            res = mul(res, arr, 5, 5, 5);
        }
        arr = mul(arr, arr, 5, 5, 5);
        q >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> F(2), G(2);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f >> F[0] >> F[1] >> G[0] >> G[1];
    vll arr(5, vl(5, 0));
    vll FG(5, vl(1, 0));
    FG[0][0] = F[1];
    FG[1][0] = G[0];
    FG[2][0] = G[1];
    FG[3][0] = F[0];
    FG[4][0] = ((e * F[0] + f * G[0]) + (e * F[1] + f * G[1])) % mod;
    arr[0][0] = a;
    arr[0][1] = b;
    arr[1][2] = 1;
    arr[2][2] = c;
    arr[2][3] = d;
    arr[3][0] = 1;
    arr[4][0] = a * e;
    arr[4][1] = b * e;
    arr[4][2] = c * f;
    arr[4][3] = d * f;
    arr[4][4] = 1;
    int Q;
    cin >> Q;
    while (Q--) {
        int temp;
        cin >> temp;
        temp %= mod;
        if (temp == 0) {
            cout << (e * F[0] + f * G[0]) % mod << endl;
        } else if (temp == 1) {
            printf("%d\n", FG[4][0]);
        } else {
            if (mp.find(temp) == mp.end()) {
                vll arrnew = fastexp(arr, temp - 1);
                vll res = mul(arrnew, FG, 5, 1, 5);
                cout << res[4][0] << endl;
                mp[temp] = res[4][0];
            } else {
                printf("%d\n", mp[temp]);
            }
        }
    }
    return 0;
}
