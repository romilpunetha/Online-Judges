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

using namespace std;

int max(int a, int b) {
    return (a > b ? a : b);
}

int find(string arr[], int visited[][1000], int i, int j, int h, int w) {
    int result = 0;
    // cout<<"i = "<<i<<" and j = "<<j<<endl;
    if (i > 0) {
        if (j == 0) {
            if (!visited[i - 1][j] && arr[i - 1][j] - arr[i][j] == 1) {
                visited[i - 1][j] = 1;
                result = max(result, 1 + find(arr, visited, i - 1, j, h, w));
            }
            if (j + 1 < w && !visited[i - 1][j + 1] && arr[i - 1][j + 1] - arr[i][j] == 1) {
                visited[i - 1][j + 1] = 1;
                result = max(result, 1 + find(arr, visited, i - 1, j + 1, h, w));
            }
            if (j + 1 < w && !visited[i][j + 1] && arr[i][j + 1] - arr[i][j] == 1) {
                visited[i][j + 1] = 1;
                result = max(result, 1 + find(arr, visited, i, j + 1, h, w));
            }
            if (i + 1 < h && j + 1 < w && !visited[i + 1][j + 1] && arr[i + 1][j + 1] - arr[i][j] == 1) {
                visited[i + 1][j + 1] = 1;
                result = max(result, 1 + find(arr, visited, i + 1, j + 1, h, w));
            }
            if (i + 1 < h && !visited[i + 1][j] && arr[i + 1][j] - arr[i][j] == 1) {
                visited[i + 1][j] = 1;
                result = max(result, 1 + find(arr, visited, i + 1, j, h, w));
            }
            return max(result, 1);
        } else if (j > 0) {
            if (!visited[i - 1][j] && arr[i - 1][j] - arr[i][j] == 1) {
                visited[i - 1][j] = 1;
                result = max(result, 1 + find(arr, visited, i - 1, j, h, w));
            }
            if (j + 1 < w && !visited[i - 1][j + 1] && arr[i - 1][j + 1] - arr[i][j] == 1) {
                visited[i - 1][j + 1] = 1;
                result = max(result, 1 + find(arr, visited, i - 1, j + 1, h, w));
            }
            if (j + 1 < w && !visited[i][j + 1] && arr[i][j + 1] - arr[i][j] == 1) {
                visited[i][j + 1] = 1;
                result = max(result, 1 + find(arr, visited, i, j + 1, h, w));
            }
            if (j + 1 < w && i + 1 < h && !visited[i + 1][j + 1] && arr[i + 1][j + 1] - arr[i][j] == 1) {
                visited[i + 1][j + 1] = 1;
                result = max(result, 1 + find(arr, visited, i + 1, j + 1, h, w));
            }
            if (i + 1 < h && !visited[i + 1][j] && arr[i + 1][j] - arr[i][j] == 1) {
                visited[i + 1][j] = 1;
                result = max(result, 1 + find(arr, visited, i + 1, j, h, w));
            }
            if (i + 1 < h && !visited[i + 1][j - 1] && arr[i + 1][j - 1] - arr[i][j] == 1) {
                visited[i + 1][j - 1] = 1;
                result = max(result, 1 + find(arr, visited, i + 1, j - 1, h, w));
            }
            if (!visited[i][j - 1] && arr[i][j - 1] - arr[i][j] == 1) {
                visited[i][j - 1] = 1;
                result = max(result, 1 + find(arr, visited, i, j - 1, h, w));
            }
            if (!visited[i - 1][j - 1] && arr[i - 1][j - 1] - arr[i][j] == 1) {
                visited[i - 1][j - 1] = 1;
                result = max(result, 1 + find(arr, visited, i - 1, j - 1, h, w));
            }
            return max(result, 1);
        }
    } else if (i == 0) {
        if (j == 0) {
            if (i + 1 < h && j + 1 < w && !visited[i + 1][j + 1] && arr[i + 1][j + 1] - arr[i][j] == 1) {
                visited[i + 1][j + 1] = 1;
                result = max(result, 1 + find(arr, visited, i + 1, j + 1, h, w));
            }
            if (j + 1 < w && !visited[i][j + 1] && arr[i][j + 1] - arr[i][j] == 1) {
                visited[i][j + 1] = 1;
                result = max(result, 1 + find(arr, visited, i, j + 1, h, w));
            }
            if (i + 1 < h && !visited[i + 1][j] && arr[i + 1][j] - arr[i][j] == 1) {
                visited[i + 1][j] = 1;
                result = max(result, 1 + find(arr, visited, i + 1, j, h, w));
            }
            return max(result, 1);
        } else if (j > 0) {
            if (i + 1 < h && j + 1 < w && !visited[i + 1][j + 1] && arr[i + 1][j + 1] - arr[i][j] == 1) {
                visited[i + 1][j + 1] = 1;
                result = max(result, 1 + find(arr, visited, i + 1, j + 1, h, w));
            }
            if (j + 1 < w && !visited[i][j + 1] && arr[i][j + 1] - arr[i][j] == 1) {
                visited[i][j + 1] = 1;
                result = max(result, 1 + find(arr, visited, i, j + 1, h, w));
            }
            if (i + 1 < h && !visited[i + 1][j] && arr[i + 1][j] - arr[i][j] == 1) {
                visited[i + 1][j] = 1;
                result = max(result, 1 + find(arr, visited, i + 1, j, h, w));
            }
            if (i + 1 < h && !visited[i + 1][j - 1] && arr[i + 1][j - 1] - arr[i][j] == 1) {
                visited[i + 1][j - 1] = 1;
                result = max(result, 1 + find(arr, visited, i + 1, j - 1, h, w));
            }
            if (!visited[i][j - 1] && arr[i][j - 1] - arr[i][j] == 1) {
                visited[i][j - 1] = 1;
                result = max(result, 1 + find(arr, visited, i, j - 1, h, w));
            }
            return max(result, 1);
        }
    }
    return 0;
}

int main() {
    int h, w, c = 1;
    cin >> h >> w;
    long int result = 0;
    long int max = 0;
    int visited[1000][1000];
    while (h != 0 && w != 0) {
        string *arr = new string[1000];
        max = 0;
        result = 0;
        for (int i = 0; i < h; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {
                visited[i][j] = 0;
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (arr[i][j] == 'A') {
                    visited[i][j] = 1;
                    result = find(arr, visited, i, j, h, w);
                    if (max < result) {
                        max = result;
                    }
                }
            }
        }
        cout << "Case " << c++ << ": " << max << endl;
        max = 0;
        result = 0;
        delete[] arr;
        cin >> h >> w;
    }
    return 0;
}
