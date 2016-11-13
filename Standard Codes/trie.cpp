typedef struct trie{
    typedef struct node{
        node *arr[2];
        int cnt=0;
        node(){
            arr[0]=NULL;
            arr[1]=NULL;
        }
    }node;

    node *root;
    trie(){
        root=new node();
    }

    void insert(int num,int val){
        node *temp=root;
        while(num){
            if(temp->arr[(num&1)]==NULL) {
                temp->arr[(num&1)]=new node();
            }
            temp=temp->arr[(num&1)];
            num>>=1;
        }
        temp->cnt=val;
    }

    int query(int num){
        node *temp=root;
        ll res=0;
        while(num){
            if(temp->arr[(num&1)]==NULL) return 0;
            temp=temp->arr[(num&1)];
            num>>=1;
        }
        res=temp->cnt;
        return res;
    }
}trie;

