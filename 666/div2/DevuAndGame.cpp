#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class DevuAndGame {
public:
    static const int max_size = 50;
    bool arrived[max_size];
    string canWin(vector<int> nextLevel) {
        
        //initialize cache
        for(int i=0;i< max_size;i++) {
            arrived[i] = false;
        }
        
        int p = 0;
        bool win = false;
        
        while(true) {
            if(arrived[p]) {
                break;
            }
            arrived[p] = true;
            
            if(nextLevel[p] == -1) {
                win = true;
                break;
            }
            
            p = nextLevel[p];
        }
        return win ? "Win" : "Lose";
    }

};