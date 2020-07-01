// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int a = 1;
        int b = n;
        int mid = (a+(b-a)/2);
        while(a<b){
            if(isBadVersion(mid)){
                b = mid - 1;
            }
            else{
                a = mid + 1;
            }
            mid = (a+(b-a)/2);
        }
        return isBadVersion(a)?a:a+1;
    }
};
