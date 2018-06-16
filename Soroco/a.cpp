#include<bits/stdc++.h>
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
#define Graph V<L<int> >
#define tr1(x)                cerr << #x << ": " << x << endl;
#define tr2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;



bool nu(char a){
    return (a >= '0' && a <= '9');
}

string find_phone_number(string t) {
    int l = t.length();
    int i = 0;
    int state = 0, len = 0, start = 0;
    while(i < l){
        switch(state){
            case 0:{
                       len = 0; start = 0;
                       if(t[i] == '(') start = i, state = 1, len++;
                       else if(nu(t[i])) start = i, state = 2, len++;
                       break;
                   }
            case 1:{
                       if(nu(t[i])) state = 2, len++;
                       else state = 0;
                       break;
                   }
            case 2:{
                       if(nu(t[i])) state = 3, len++;
                       else state = 0;
                       break;
                   }
            case 3:{
                       if(nu(t[i])) state = 4, len++;
                       else state = 0;
                       break;
                   }
            case 4:{
                       if(t[i] == ')') state = 5, len++;
                       else if(t[i] == '-') state = 7, len++;
                       else state = 0;
                       break;
                   }
            case 5:{
                       if(t[i] == ' ') state = 6, len++;
                       else state = 0;
                       break;
                   }
            case 6:{
                       if(nu(t[i])) state = 8, len++;
                       else state = 0;
                       break;
                   }
            case 7:{
                       if(nu(t[i])) state = 8, len++;
                       else state = 0;
                       break;
                   }
            case 8:{
                       if(nu(t[i])) state = 9, len++;
                       else state = 0;
                       break;
                   }
            case 9:{
                       if(nu(t[i])) state = 10, len++;
                       else state = 0;
                       break;
                   }
            case 10:{
                        if(t[i] == '-') state = 11, len++;
                        else state = 0;
                        break;
                    }
            case 11:{
                        if(nu(t[i])) state = 12, len++;
                        else state = 0;
                        break;
                    }
            case 12:{
                        if(nu(t[i])) state = 13, len++;
                        else state = 0;
                        break;
                    }
            case 13:{
                        if(nu(t[i])) state = 14, len++;
                        else state = 0;
                        break;
                    }
            case 14:{
                        if(nu(t[i])) state = 15, len++;
                        else state = 0;
                        break;
                    }
            case 15:{
                        cout << "in 15" << endl;
                        return t.substr(start, len);
                    }
        }
        tr2(state, t[i]);
        i++;
    }
    return "NONE";
}


int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s; cin >> s;
    s = s + 'm';
    cout << find_phone_number(s) << endl;
    return 0;
}

