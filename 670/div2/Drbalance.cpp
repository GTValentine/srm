#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Drbalance {
public:
    int lesscng(string s, int k) {
        string ss = s;
        int ans = 0;
        
        while(count(ss) > k) {
            ss = flip(ss);
            ans++;
        }
        return ans;
    }
    
    int count(string s) {
        int count = 0;
        for(int i =0; i<s.size();i++) {
            int p = 0;
            for(int j=0;j<=i;j++) {
                if(s[j] == '+') {
                    p++;
                } else {
                    p--;
                }
            }
            if(p <0) {
                count++;
            }
        }
        return count;
    }
    
    string flip(string s) {
        for(int i = 0;i<s.size();i++) {
            if(s[i] == '-') {
                s[i] = '+';
                break;
            }
        }
        return string(s);
    }
};