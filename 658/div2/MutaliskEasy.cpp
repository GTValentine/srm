
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class MutaliskEasy {
public:
    int minimalAttacks(vector<int> x) {
        int patterns[6][3] = {{1,3,9}, {3,9,1},{3,1,9},{9,3,1},{1,9,3},{9,1,3}};
        
        int answer=20;
        
        while(x.size() < 3) {
            x.push_back(0);
        }
        
        for(int a = 0;a<16;a++) {
            if(a > answer) {
                break;
            }
            for(int b =0;b<16;b++) {
                if(a+ b > answer) {
                    break;
                }
                for(int c = 0;c<16;c++) {
                    if(a+b + c > answer) {
                        break;
                    }
                    for(int d = 0;d<16;d++) {
                        if(a+ b + c + d > answer) {
                            break;
                        }
                        for(int e =0;e<16;e++) {
                            if(a+ b + c + d + e > answer) {
                                break;
                            }
                            vector<int> xx(x);
                            
                            for(int i = 0;i<3;i++) {
                                xx[i] -= a * patterns[0][i] + b * patterns[1][i] + c * patterns[2][i] + d * patterns[3][i] + e * patterns[4][i];
                                xx[i] = max(0, xx[i]);
                            }
                            
                            int aa = (xx[0] + 8)/9;
                            aa = max(aa,xx[1]);
                            aa = max(aa, (xx[2]+2)/3);
                            
                            answer = min(answer, a + b + c + d + e + aa);
                        }
                    }
                }
            }
        }
        return answer;
    }
};