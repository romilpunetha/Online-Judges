typedef struct trie {
    typedef struct node {
        node *arr[2];
        int cnt = 0;
        node() {
            arr[0] = NULL;
            arr[1] = NULL;
        }
    } node;

    node *root;
    trie() {
        root = new node();
    }

    void insert(int num, int val) {
        node *temp = root;
        while (num) {
            if (temp->arr[(num & 1)] == NULL) {
                temp->arr[(num & 1)] = new node();
            }
            temp = temp->arr[(num & 1)];
            num >>= 1;
        }
        temp->cnt = val;
    }

    int query(int num) {
        node *temp = root;
        ll res = 0;
        while (num) {
            if (temp->arr[(num & 1)] == NULL) return 0;
            temp = temp->arr[(num & 1)];
            num >>= 1;
        }
        res = temp->cnt;
        return res;
    }
} trie;

int mx = (2e5 + 10) * 40, t = 0;
vector<vector<int> > arr(mx, vector<int>(2, -1));
vector<int> cnt(mx, 0);

void insert(int num) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        if (arr[p][num >> i & 1] == -1) arr[p][num >> i & 1] = ++t;
        p = arr[p][num >> i & 1], cnt[p]++;
    }
}

void erase(int num) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        p = arr[p][num >> i & 1];
        cnt[p]--;
    }
}

int query(int num) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        if (arr[p][(num >> i & 1) ^ 1] != -1 && cnt[arr[p][(num >> i & 1) ^ 1]])
            res += (1 << i), p = arr[p][(num >> i & 1) ^ 1];
        else
            p = arr[p][num >> i & 1];
    }
    return res;
}
