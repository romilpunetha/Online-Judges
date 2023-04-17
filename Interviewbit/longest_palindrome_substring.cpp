string palin(string st, int i, int j) {
    int len = st.length() - 1;
    while (i >= 0 && j <= len && st[i] == st[j]) {
        i--;
        j++;
    }
    return st.substr(i + 1, j - i - 1);
}

string Solution::longestPalindrome(string A) {
    int len = A.length() - 1;
    int max = 0;
    string result = A.substr(0, 1);
    for (int i = 0; i <= len; i++) {
        string p1 = palin(A, i, i);
        if (p1.length() > result.length()) {
            result = p1;
        }
        string p2 = palin(A, i, i + 1);
        if (p2.length() > result.length()) {
            result = p2;
        }
    }
    return result;
}
