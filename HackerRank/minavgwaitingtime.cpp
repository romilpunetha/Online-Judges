#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i = 1;
    cin >> n;
    vector<pair<ll, ll> > arr(n);
    for (auto &it : arr) cin >> it.first >> it.second;
    sort(arr.begin(), arr.end());
    ll wtime = 0, finish = arr[0].first;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    pq.push({ arr[0].second, arr[0].first });
    while (!pq.empty() || i < n) {
        while (i < n && arr[i].first <= finish) pq.push({ arr[i].second, arr[i].first }), i++;
        if (pq.empty() && i < n) finish = arr[i].first, pq.push({ arr[i].second, arr[i].first }), i++;
        finish += pq.top().first;
        wtime += finish - pq.top().second;
        pq.pop();
    }
    cout << wtime / n << endl;
    return 0;
}
