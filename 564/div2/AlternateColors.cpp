#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class AlternateColors {
    public:
	string getColor(long long r, long long g, long long b, long long k) {
        long long min3 = min(min(r, g), b);
        if(k <= 3 * min3) {
            int divBy3 = k % 3;
            if(divBy3 == 1) {
                return "RED";
            } else if (divBy3 == 2) {
                return "GREEN";
            } else {
                return "BLUE";
            }
        }
        long long r2 = r - min3;
        long long g2 = g - min3;
        long long b2 = b - min3;
        long long k2 = k - min3;
        long long ary[] ={r2, g2, b2};
        sort(ary, ary+3);
        long long s = ary[1];
        long long l = ary[2];
        
      
        if(k2 <= 2 * s) {
            int mod2 = k2 % 2;
            if(mod2 == 0) {
                if(r2 == 0 || g2 == 0) {
                    return "BLUE";
                } else {
                    return "GREEN";
                }
            } else {
                if(g2 == 1 || b2 == 1) {
                    return "RED";
                } else {
                    return "GREEN";
                }
            }
        }
        
        if(l == r2) {
            return "RED";
        } else if (l == g2) {
            return "GREEN";
        } else {
            return "BLUE";
        }


    }
};
