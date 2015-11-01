#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class ProblemSetsEasy {
public:
    int maxSets(int E, int EM, int M, int MH, int H) {
        
        int problems = 0;
        
        for(long long step = 63LL; step > 0LL;step--) {
            long long inc = 1<<step;
            
            if(isOk(problems + inc, E, EM, M, MH, H)) {
                problems += inc;
            }
        }
        return problems;
    }
private:
    bool isOk(long long over, int E, int EM, int M, int MH, int H) {
        EM -= over - E;
        MH -= over - H;
        
        if(EM < 0 || MH < 0) {
            return false;
        }
        
        return M + EM + MH >= over;
    }
};