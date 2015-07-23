#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstddef>
class Flee {
public:
    double maximalSafetyLevel(std::vector<int> x, std::vector<int> y) {
        double ans = std::numeric_limits<double>::max();
        
        for (int i =0;i<x.size();i++) {
            int xx = x.at(i);
            int yy = y.at(i);
            long a = xx * xx + yy * yy;
            ans = ans > a ? a : ans;
        }
        double an = std::sqrt(ans);
        return an;
    }
};