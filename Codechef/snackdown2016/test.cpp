int maxProduct(int A[], int n) {
    int n = A.size();
    int r = A[0];
    for (int i = 1, imax = r, imin = r; i < n; i++) {
        if (A[i] < 0)
            swap(imax, imin);
        imax = max(A[i], imax * A[i]);
        imin = min(A[i], imin * A[i]);
        r = max(r, imax);
    }
    return r;
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

                                                                                                                        int
                                                                                                                        Solution::maxProduct(const vector<int> &A) {
    int len = A.size();
    int m = INT_MIN;
    int mi = INT_MAX;
    int has_p = 0, has_n = 0;
    for (int i = 0; i < len; i++) {
        m = max(m, A[i]);
        mi = min(mi, A[i]);
        if (A[i] > 0)
            has_p = 1;
        if (i + 1 < len && A[i] < 0 && A[i + 1] < 0)
            has_n = 1;
    }
    if (m == 0 && mi == 0)
        return 0;
    int res = 1, prevneg = 1, prevpos = 1;
    for (int i = 0; i < len; i++) {
        if (A[i] == 0) {
            prevpos = 1, prevneg = 1;
        } else if (A[i] > 0) {
            prevpos = prevpos * A[i];
            prevneg = min(prevneg * A[i], 1);
        } else {
            int temp = prevpos;
            prevpos = max(prevneg * A[i], 1);
            prevneg = temp * A[i];
        }
        res = max(res, prevpos);
    }
    if (has_n || has_p)
        return max(res, m);
    else
        return m;
}
