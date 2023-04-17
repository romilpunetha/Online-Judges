string Solution::convert(string A, int B) {
    vector<vector<char> > arr(B);
    int dir = 1;
    int p = 0;
    int l = A.length();
    for (int i = 0; i < l; i++) {
        arr[p].push_back(A[i]);
        if (p + dir >= 0 && p + dir < B) {
            p = p + dir;
        }
        if (p == 0) {
            dir = 1;
        }
        if (p == B - 1) {
            dir = -1;
        }
    }
    string res;
    for (int i = 0; i < B; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            res = res + arr[i][j];
        }
    }
    return res;
}
