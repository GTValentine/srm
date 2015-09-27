#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class IsItASquare {
public:
    string isSquare(vector<int> x, vector<int> y) {
        
        if(issqr(x[0], y[0], x[1], y[1], x[2], y[2], x[3], y[3]) ||
        issqr(x[0], y[0], x[2], y[2], x[1], y[1], x[3], y[3]) ||
           issqr(x[0], y[0], x[3], y[3], x[1], y[1], x[2], y[2])) {
            return "It's a square";
        }
        return "Not a square";
    }
    
    
    bool issqr(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        if((x2 - x1) * (x4 - x3) + (y2 - y1) * (y4 - y3) == 0) {
            if((x2-x1) * (x2 - x1) + (y2 -y1) * (y2 - y1) == (x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3)) {
                return true;
            }
        }
        return false;
    }
};