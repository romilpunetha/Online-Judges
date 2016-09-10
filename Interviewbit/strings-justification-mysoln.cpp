vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<string> result;
    int len=A.size();
    string str="";
    int i=0,j=0,k=0,l=0,flag=0,flag2=0,temp=0;
    while(i<len)
    {
        l=0;flag=0;temp=0;flag2=0;
        while(i<len && l+A[i].length()<=B)
        {
            if(l+A[i].length()<B)
            {
                l=l+A[i++].length()+1;
            }
            else
            {
                l=l+A[i++].length();
                flag=1;
            }
            if(i==len)
            {
                flag2=1;
            }
        }
        i--;
        if(flag==1)
        {
            l=l-(i-k);
        }
        else
        {
            l=l-(i-k)-1;
        }
        // cout<<"l= "<<l<<endl;
        if(flag2!=1)
        {
            int divi=B-l;
            for(j=k;j<i;j++)
            {
                str=str+A[j];
                int q=ceil((1.0*divi)/((i-k)-(temp)));
                temp++;
                for(int p=0;p<q;p++)
                {
                    str=str+' ';
                }
                divi=divi-q;
            }
            str=str+A[j];
            while(str.length()<B)
            {
                str+=' ';
            }
        }
        if(flag2==1)
        {
            while(k<i)
            {
                str=str+A[k++]+' ';
            }
            str=str+A[i];
            while(str.length()<B)
            {
                str+=' ';
            }
        }
        result.push_back(str);
        str.clear();
        k=++i;
    }
    return result;
}
