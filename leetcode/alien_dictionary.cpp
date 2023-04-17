#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define der(c, x) ((c).find(x) != (c).end())
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define V vector
#define L list
#define P pair
#define MP map
#define ST set
#define UM unordered_map
#define MM multimap
#define UMM unordered_multimap
#define MST multiset
#define UST unordered_set
#define UMS unordered_multiset
#define PQ priority_queue
#define Pii P<int, int>
#define Pll P<long long, long long>
#define Graph V<L<int> >
#define all(a) (a).begin(), (a).end()
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
using namespace std;
template <typename A, typename B>
inline ostream &operator<<(ostream &os, const pair<A, B> &v) { return os << v.first << ' ' << v.second; }
template <typename A>
inline ostream &operator<<(ostream &os, const vector<A> &v) {
    auto it = v.begin();
    os << *it;
    for (++it; it != v.end();
         os << ' ' << *it++)
        ;
    return os;
}
void tr() { cout << endl; }
template <typename H, typename... T>
inline void tr(H head, T... tail) {
    cerr << head << ' ';
    tr(tail...);
}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

int get(char a) {
    return a - 'a';
}

bool isValid(string &s1, string &s2) {
    size_t found = s1.find(s2);
    return !(found == 0 && s1.size() > s2.size());
}

string alienOrder(vector<string> &words) {
    unordered_set<string> st;

    if (words.size() == 1) {
        set<char> st;
        for (auto &it : words[0]) st.insert(it);
        string s = "";
        for (auto &it : st) s += it;
        return s;
    }

    unordered_map<int, int> indegree;
    bool x[26][26];
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++) x[i][j] = false;

    for (int i = 0; i + 1 < words.size(); i++) {
        if (!isValid(words[i], words[i + 1])) return "";

        for (int j = 0; words[i][j]; j++)
            if (indegree.find(get(words[i][j])) == indegree.end()) indegree[get(words[i][j])] = 0;
        for (int j = 0; words[i + 1][j]; j++)
            if (indegree.find(get(words[i + 1][j])) == indegree.end()) indegree[get(words[i + 1][j])] = 0;

        for (int j = 0; words[i][j] && words[i + 1][j]; j++) {
            char a = words[i][j];
            char b = words[i + 1][j];

            string s1 = !j ? "" : words[i].substr(0, j);
            string s2 = !j ? "" : words[i + 1].substr(0, j);

            if (s1 != s2) break;
            if (!x[get(a)][get(b)] && a != b) {
                x[get(a)][get(b)] = 1;
                indegree[get(b)]++;
            }
        }
    }

    queue<int> q;
    vector<bool> visited(26, 0);
    string s = "";
    for (auto &it : indegree)
        if (!it.second) q.push(it.first);

    while (!q.empty()) {
        int t = q.front();
        q.pop();

        if (visited[t]) return "";
        visited[t] = true;

        s += ('a' + t);

        for (int i = 0; i < 26; i++) {
            if (t == i) continue;
            if (x[t][i]) {
                indegree[i]--;
                if (!indegree[i]) q.push(i);
            }
        }
    }
    return s.size() == indegree.size() ? s : "";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> words;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            words.push_back(s);
        }
        cout << alienOrder(words) << endl;
    }
}