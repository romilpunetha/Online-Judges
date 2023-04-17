#include <bits/stdc++.h>
#define tr1(x) cerr << #x << ":\t" << x << endl
#define tr2(x, y) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int mod = 1e9 + 7;
struct matrix {
    ll rows, cols;
    vector<vector<ll> > mat;
    matrix() {
        ;
    }

    matrix(int x, int y = 0, int iden = 0) {
        rows = x;
        cols = y;
        if (y == 0) cols = rows;
        mat = vector<vector<ll> >(rows, vector<ll>(cols, 0));
        if (iden)
            for (int i = 0; i < rows; i++) mat[i][i] = 1;
    }

    void out() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cout << mat[i][j] << " ";
        cout << endl;
    }

    ll rowsum(int x) {
        ll ans = 0;
        for (int i = 0; i < cols; i++) {
            ans += mat[x][i];
            if (ans >= mod) ans -= mod;
        }
        return ans;
    }

    ll colsum(int x) {
        ll ans = 0;
        for (int i = 0; i < rows; i++) {
            ans += mat[i][x];
            if (ans >= mod) ans -= mod;
        }
        return ans;
    }
};

matrix operator*(const matrix &a, const matrix &b) {
    int p = a.rows, q = a.cols, r = b.cols;
    matrix c = matrix(p, r);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            ll &val = c.mat[i][j];
            val = 0;
            for (int k = 0; k < q; k++) {
                val += (a.mat[i][k] * 1LL * b.mat[k][j]) % mod;
                if (val >= mod) val -= mod;
            }
        }
    }
    return c;
}
matrix operator*(ll a, const matrix &b) {
    matrix c = matrix(b.rows, b.cols);
    int p = b.rows, q = b.cols;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            ll &val = c.mat[i][j];
            val = a * b.mat[i][j];
            val %= mod;
        }
    }
    return c;
}

matrix operator+(const matrix &a, const matrix &b) {
    int p = a.rows, q = a.cols;
    matrix c = matrix(p, q);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            ll &val = c.mat[i][j];
            val = (a.mat[i][j] + b.mat[i][j]);
            if (val >= mod) val -= mod;
        }
    }
    return c;
}

matrix operator-(const matrix &a, const matrix &b) {
    int p = a.rows, q = a.cols;
    matrix c = matrix(p, q);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            ll &val = c.mat[i][j];
            val = (a.mat[i][j] - b.mat[i][j]);
            if (val >= mod) val -= mod;
            if (val < 0) val += mod;
        }
    }
    return c;
}

matrix operator%(const matrix &M, int MOD) {
    matrix temp(M.rows, M.cols);
    for (int i = 0; i < M.rows; i++)
        for (int j = 0; j < M.cols; j++)
            temp.mat[i][j] = M.mat[i][j] % MOD;
    return temp;
}

matrix expo(matrix a, ll b) {
    matrix res = matrix(a.rows, a.rows, 1);
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
