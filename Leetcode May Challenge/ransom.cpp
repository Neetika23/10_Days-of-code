#include<bits/stdc++.h>
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = magazine.length();  
        char array[n + 1];
        strcpy(array, magazine.c_str()); 
         
        int countArray[26] = {0};        
        for(char c : array){            
            countArray[c-'a']++;
        }
         
        int m = ransomNote.length();  
        char array2[m + 1];
        strcpy(array2, ransomNote.c_str()); 
        for(char c : array2){   
            if(countArray[c-'a'] > 0){
                countArray[c-'a']--;
            }else {
                return false;
            }            
        }
        return true;
    }
};
