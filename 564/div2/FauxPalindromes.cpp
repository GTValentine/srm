#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class FauxPalindromes {
    public:
    string classifyIt(string word) {
        
        if (isPalindrome(word)) {
            return "PALINDROME";
        }
        if(isPalindrome(toShort(word))) {
            return "FAUX";
        }
        return "NOT EVEN FAUX";
    }
    
    bool isPalindrome(string wd) {
        int len = (int) wd.length();
        int lenDiv2 = len / 2;
        int lenMin1 = len - 1;
        
        for(int i = 0; i< lenDiv2;i++) {
            if(wd[i] != wd[lenMin1 -i]) {
                return false;
            }
        }
        return true;
    }
    
    string toShort(string wd) {
        string rtn = "";
        int len = (int) wd.length();
        char cache = wd[0];
        for(int i = 0 ;i< len;i++) {
            if(cache == wd[i]) {
                continue;
            }
            rtn.push_back(cache);
            cache = wd[i];
        }
        rtn.push_back(cache);
        return rtn;
    }
};