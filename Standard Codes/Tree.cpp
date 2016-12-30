typedef struct Tree{
    typedef struct node{
        node *l, *r;
        int val;

        node(){
            l = r = NULL;
            val = -1;
        }
        node(int x){
            l = r = NULL;
            val = x;
        }
    }node;

    node *root;

    Tree(){
        root = NULL;
    }

    node* insert(node *rt, int x){
        if(!rt) rt = new node(x);
        else if(x <= rt->val) rt->l = insert(rt->l, x);
        else rt->r = insert(rt->r, x);
        return root = rt;
    }

    int get_h(node *rt){
        if(!rt) return 0;
        else{
            int l = get_h(rt->l);
            int r = get_h(rt->r);
            return max(l, r) + 1;
        }
    }

    void pre(node *rt){
        if(!rt) return;
        cout << rt -> val << endl;
        pre(rt->l);
        pre(rt->r);
    }

    void in(node *rt){
        if(!rt) return;
        in(rt->l);
        cout << rt->val << endl;
        in(rt->r);
    }

    void post(node *rt){
        if(!rt) return;
        post(rt->l);
        post(rt->r);
        cout << rt->val << endl;
    }

}Tree;
