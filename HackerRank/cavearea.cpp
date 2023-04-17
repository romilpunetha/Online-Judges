#include <limits.h>
#include <string.h>

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
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int creep_x[] = { 0, 0, 0, 0, -2, -1, 1, 2, -1, -1, 1, 1 };
int creep_y[] = { -2, -1, 1, 2, 0, 0, 0, 0, -1, 1, -1, 1 };
int x[] = { 0, 0, 1, -1 };
int y[] = { 1, -1, 0, 0 };
bool valid(int i, int j, int row, int col) {
    return (i >= 0 && j >= 0 && i < row && j < col);
}

int max(int a, int b) {
    return a > b ? a : b;
}
vector<vector<bool> > vis;

void display(vector<vector<char> >& cave, int row, int col) {
    cout << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << cave[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int bfs(vector<vector<char> >& cave, vector<vector<bool> >& visited, int row, int col, int p, int q) {
    if (visited[p][q] || cave[p][q] == '#') {
        return 0;
    }
    // display(cave,row,col);
    int res = 1;
    visited[p][q] = true;
    queue<pair<int, int> > que;
    que.push(make_pair(p, q));
    while (!que.empty()) {
        pair<int, int> coord = que.front();
        que.pop();
        for (int k = 0; k < 4; k++) {
            int a = coord.first + x[k];
            int b = coord.second + y[k];
            if (valid(a, b, row, col) && !visited[a][b] && cave[a][b] != '#') {
                visited[a][b] = true;
                res++;
                que.push(make_pair(a, b));
            }
        }
    }
    return res;
}

int largest_cave(vector<vector<char> >& cave, vector<vector<bool> >& visited, int row, int col) {
    int res = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (!visited[i][j] && cave[i][j] != '#') {
                res = max(res, bfs(cave, visited, row, col, i, j));
            }
        }
    }
    return res;
}

void creeper(vector<vector<char> >& cave, vector<vector<bool> >& visited, int row, int col, int p, int q) {
    queue<pair<int, int> > que;
    visited[p][q] = true;
    que.push(make_pair(p, q));
    while (!que.empty()) {
        pair<int, int> coord = que.front();
        que.pop();
        cave[p][q] = '.';
        for (int i = 0; i < 12; i++) {
            int x = coord.first + creep_x[i];
            int y = coord.second + creep_y[i];
            if (valid(x, y, row, col)) {
                if (cave[x][y] == 'C' && !visited[x][y]) {
                    visited[x][y] = true;
                    que.push(make_pair(x, y));
                } else {
                    cave[x][y] = '.';
                }
            }
        }
    }
}

int cave_area(vector<vector<char> >& cave, vector<vector<bool> >& visited, queue<pair<int, int> >& que, int row, int col) {
    int flag = 0;
    int res = 0;
    while (!que.empty()) {
        flag = 1;
        pair<int, int> coord = que.front();
        que.pop();
        if (!visited[coord.first][coord.second]) {
            vector<vector<bool> >(row, vector<bool>(col, false)).swap(vis);
            vector<vector<char> > cave2 = cave;
            creeper(cave2, visited, row, col, coord.first, coord.second);
            int current = largest_cave(cave2, vis, row, col);
            res = max(res, current);
        }
    }
    if (flag == 0) {
        res = max(res, largest_cave(cave, vis, row, col));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int row, col;
    cin >> row >> col;
    vector<vector<bool> >(row, vector<bool>(col, false)).swap(vis);
    vector<vector<char> > cave(row, vector<char>(col));
    vector<vector<bool> > visited(row, vector<bool>(col, false));
    queue<pair<int, int> > que;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> cave[i][j];
            if (cave[i][j] == 'C') {
                que.push(make_pair(i, j));
            }
        }
    }
    cout << cave_area(cave, visited, que, row, col) << endl;
    return 0;
}
