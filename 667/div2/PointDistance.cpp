#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class PointDistance {
public:
    vector<int> findPoint(int x1, int y1, int x2, int y2) {
        vector<int> ans;
        
        if(x2 >= x1) {
            ans.push_back(100);
            ans.push_back(y2);
            return ans;
        }
        ans.push_back(-100);
        ans.push_back(y2);
        return ans;
    }
};

