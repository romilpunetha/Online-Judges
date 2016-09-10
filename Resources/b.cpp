#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<double, double> pii;
bool mycomp(pii one, pii two) {
    if(one.first == two.first) return one.second < two.second;
    return one.first < two.first;
}

int main() {
    int t, n, lineno, x1, x2;
    unsigned int i;
    double ki, bi, ans1, ans2;
    bool good;
    cin>>t;
    while(t--) {
        cin>>n>>x1>>x2;
        vector< pii > points;
        //vector<pii>(size,0).swap(points);
        for(lineno = 0; lineno<n; lineno++) {
            cin>>ki>>bi;
            points.push_back(make_pair(ki*x1 + bi, ki*x2 + bi));
        }
        sort(points.begin(), points.end(), mycomp);
        good=true;
        for(i=0; i<points.size()-1; i++)
            if(points[i].second > points[i+1].second)
                good=false, break;
        if(good) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
