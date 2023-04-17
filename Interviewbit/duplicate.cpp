int Solution::repeatedNumber(const vector<int> &A) {
    int p = 0;
    int l = A.size();
    int temp1 = 0, row = 0, flag = 0;
    int limit = sqrt(l - 1);
    int size = ceil(((l - (limit - 1)) * 1.0) / limit) + 1;   // number of ranges of size sqrt(n)
    vector<int> bucket1(size, 0);
    vector<int> bucket2(size, 0);
    if (l < 2)
        return 0;
    for (int i = 0; i < l; i++) {
        temp1 = A[i] / limit;   // if limit=3...for 1,2 =0, for 3,4,5 =1 , 6,7,8 =2 , so on...
        bucket1[temp1]++;       // counting size of different ranges
        if (bucket1[temp1] > limit) {
            row = temp1;   // storing bucket overflow,ie, the first bucket that overflows
            flag = 1;
            break;
        } else if (bucket1[0] == limit) {
            row = 0;
            flag = 1;
            break;
        }
    }
    if (flag != 1) {
        row = size - 1;
    }
    for (int j = 0; j < l; j++) {
        temp1 = A[j] / limit;
        if (temp1 == row)   // comparing if A[i] belongs to overflow bucket, ie, the bucket that contains the repeat element
        {
            p = A[j] % limit;   // hashing
            bucket2[p]++;

            if (bucket2[p] > 1)   // if collision occurs, return that particular element
            {
                return A[j];
            }
        }
    }
}
