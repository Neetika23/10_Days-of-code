vector<int> Solution::plusOne(vector<int> &A) {
    int n=A.size(),carry=0;
    vector<int>r;
    r.push_back((1+A[n-1])%10);
    carry=(1+A[n-1])/10;
    for(int i=n-2;i>=0;i--){
        r.push_back((carry+A[i])%10);
        carry=(carry+A[i])/10;
    }
    if(carry)
     r.push_back(carry);
    int x=r.size();
    for(int i=0;i<x/2;i++)
     swap(r[i],r[x-i-1]);
    while(r[0]==0){
       r.erase(r.begin());
    }
    return r;
}

