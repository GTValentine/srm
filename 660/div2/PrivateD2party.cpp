#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class PrivateD2party {
public:
    int static const R_MAX = 50;
    int reached[R_MAX];
    int* aa;
    int getsz(vector<int> a) {
        
        for(int i=0;i < R_MAX;i++) {
            reached[i] = -1;
        }
        
        int answer = (int) a.size();
        
        for(int i =0;i<a.size();i++) {
            if(findLoop(i, i, a)) {
                answer--;
            }
        }
        
        return answer;
    }
    
    bool findLoop(int start ,int goal, vector<int> a) {
        if(start == a[start]) {
            return false;
        }
        
        if(reached[start] != -1) {
            return goal == reached[start];
        }
        
        reached[start] = goal;
        
        return findLoop(a[start], goal, a);
    }
};