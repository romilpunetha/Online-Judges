#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    int test;
    string exp;
    stack<char> operators;
    cin>>test;
    while(test--)
    {
        cin>>exp;
        string result="";
        int i=0;
        while(exp[i])
        {
            switch(exp[i])
            {
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                case '(':
                    {
                        operators.push(exp[i]);
                        break;
                    }
                case ')':{
                             while(operators.top()!='(')
                             {
                                 result=result+operators.top();
                                 operators.pop();
                             }
                             operators.pop();
                             break;
                         }
                default:{
                            result+=exp[i] ;
                        }
            }
            i++;
        }
        cout<<result<<endl;
        result.clear();
        exp.clear();
    }
    return 0;
}
