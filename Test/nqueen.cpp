#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<string> temp, int row, int col, int n) {
    // check if column had a queen before
    for (int i = 0; i < n; i++) {
        if (temp[i][col] == 'Q')
            return false;
    }

    // check forward diagonal
    int i = row, j = col;
    while (i >= 0 && j >= 0) {
        if (temp[i][j] == 'Q')
            return false;
        i--, j--;
    }

    // check backward diagonal
    i = row, j = col;
    while (i >= 0 && j >= 0) {
        if (temp[i][j] == 'Q')
            return false;
        i--, j++;
    }
    return true;
}

void util(vector<vector<string> >& res, vector<string> temp, int row, int n, int count) {
    if (count == n) {
        res.push_back(temp);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isValid(temp, row, col, n)) {
            temp[row][col] = 'Q';
            util(res, temp, row + 1, n, count + 1);
            temp[row][col] = '.';
        }
    }
}
vector<vector<string> > solveNQueens(int n) {
    string val = "";
    vector<vector<string> > res;
    for (int i = 0; i < n; i++)
        val += '.';

    vector<string> temp;
    for (int i = 0; i < n; i++) temp.push_back(val);

    util(res, temp, 0, n, 0);
    return res;
}
int main() {
    int n;
    cin >> n;
    vector<vector<string> > res;
    res = solveNQueens(n);
    cout << res.size() << endl;
    return 0;
}
