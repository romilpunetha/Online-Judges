#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<vector<int> > graph;
vector<int> degree;
vector<int> base;

bool myfun(int &a, int &b) {
    return degree[a] < degree[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    scanf("%d ", &test);
    while (test--) {
        int N;
        scanf("%d ", &N);
    }
    return 0;
}
