class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans  = 0;
        for(int i = 0; i < S.length(); i++){
            for(int j = 0; j < J.length(); j++){
                if(J[j] == S[i]){
                    ans ++;
                    break;
                }
            }
        }
        return ans;
    }
};
