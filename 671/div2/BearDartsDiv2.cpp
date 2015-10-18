#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class BearDartsDiv2 {
public:
    long long count(vector <int> w) {
        
        int n_w = (int) w.size();
        long long answer = 0;
        for(int c = 2; c< n_w; c++) {
            for(int a=0;a<c-1;a++) {
                long long mulab = ((long long) w[a])*((long long) w[c-1]);
                if(mulab <= 1000000) {
                    ab[mulab] += (long long) 1;
                }
            }
            
            for(int d = c+1;d<n_w;d++) {
                if(w[d] % w[c] == 0) {
                    answer += ab[w[d] / w[c]];
                }
            }
        }
        return answer;
    }
    
private:
    
    long long ab[1000000+1]={};
};
