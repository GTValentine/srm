#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class CombiningSlimes {
public:
    int maxMascots(vector<int> a) {
        
        int mascots = 0;
        
        int last = a[0] + a[1];
        mascots = a[0] * a[1];
        for(int i=2;i<a.size();i++) {
            mascots += last *a[i];
            last += a[i];
        }
        
        return mascots;
    }
};