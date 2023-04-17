#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 2000000000
#define PI acos(-1.0)
#define inf INT_MAX
#define llu unsigned long long int
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define F first
#define si(n) scanf("%d", &n)
#define slli(n) scanf("%lld", &n);
#define ss(n) scanf("%s", n);
#define trace1(x) cerr << #x << " is " << x << endl;
#define trace2(x, y) cerr << #x << " is " << x << "  " << #y << " is " << y << endl;
using namespace std;
typedef long long int LL;
std::vector<pair<int, std::vector<int> > > adjList[510];
int dist[510];
queue<pair<int, pair<int, int> > > Q;
int main() {
    int N, M, u, v, c, K, S, D, test;
    si(test);
    for (int o = 1; o <= test; o++) {
        si(N);
        si(M);
        si(K);
        for (int i = 0; i < N + 4; i++)
            adjList[i].clear();
        for (int i = 1; i <= M; i++) {
            si(u);
            si(v);
            std::vector<int> costs;
            for (int o = 1; o <= 24; o++) {
                si(c);
                costs.pb(c);
            }
            adjList[u].pb(mp(v, costs));
            adjList[v].pb(mp(u, costs));
        }
        pair<int, pair<int, int> > curr;
        pair<int, std::vector<int> > record;
        std::vector<int> costs;
        int curr_node, dept_time, next_node;
        printf("Case #%d:", o);
        for (int i = 1; i <= K; i++) {
            si(D);
            si(S);
            for (int j = 0; j < N + 4; j++)
                dist[j] = 1e9;
            Q.push(mp(1, mp(0, (S % 24))));
            dist[1] = 0;
            while (!Q.empty()) {
                curr = Q.front();
                Q.pop();
                curr_node = curr.first;
                dept_time = (curr.second.second % 24);
                if (curr.second.first == dist[curr_node]) {
                    for (int i = 0; i < adjList[curr_node].size(); i++) {
                        next_node = adjList[curr_node][i].first;
                        costs = adjList[curr_node][i].second;
                        if (dist[next_node] > dist[curr_node] + costs[dept_time % 24]) {
                            dist[next_node] = dist[curr_node] + costs[dept_time % 24];
                            Q.push(mp(next_node, mp(dist[next_node], (dept_time + costs[(dept_time % 24)]) % 24)));
                        }
                    }
                }
            }
            if (dist[D] != 1e9)
                cout << " " << dist[D];
            else
                cout << " -1";
        }
        cout << endl;
    }
    return 0;
}
