vector<int> Solution::plusOne(vector<int> &A) {
    int n=A.size()-1;
    int sum=A[n]+1;
    A[n]=sum%10;
    int carry=sum/10;
    for(int i=n-1;i>=0;i--)
    {
        int sum=A[i]+carry;
        A[i]=sum%10;
        carry=sum/10;
    }
    vector<int> B;
    if(carry==1)
    {
        B.push_back(1);
        for(int i=0;i<A.size();i++)
            B.push_back(A[i]);
        return B;
    }
    else 
    {
        bool done=false;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]!=0)
                done=true;
            if(done)
                B.push_back(A[i]);
        }
        
    }
}

