class Solution {
public:
     int findComplement(int n){ 
        int a = 0, temp=n;
        while( temp ) {
            temp = temp >> 1;
            a = a << 1;
            a = a | 1;
        }
        return ~n & a;
} 
};
