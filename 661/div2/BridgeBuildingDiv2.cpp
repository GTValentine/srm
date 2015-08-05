#include <iostream>
#include <vector>
#include <map>
#include<algorithm>
#include<cmath>
using namespace std;
class BridgeBuildingDiv2 {
    
public:
    int bridges[22][22];
    int size;
    int size_dbl;
    const int INF = 1000;
    int temp[22][22];
    int max = 1000;
    int minDiameter(vector<int> a, vector<int> b, int K) {
        size = (int) a.size() + 1;
        size_dbl = size << 1;
        
        for(int i=0;i< size_dbl;i++) {
            for(int j=0;j<size_dbl;j++) {
                bridges[i][j] = INF;
                if(i==j) {
                    bridges[i][j] = 0;
                }
            }
        }
        
        for(int i = 0; i< size-1;i++) {
            int aa = a[i];
            int bb = b[i];
            bridges[i][i+1] = bridges[i+1][i] = aa;
            bridges[i+size][i+1+size] = bridges[i+1+size][i+size] = bb;
        }
        int mask = 1 << size;
        for(int i = 0; i< mask; i++) {

            if(bitCount(i) != K) {
                continue;
            }
            cpy();
            
            int k = i;
            int c = 0;
            
            while(k > 0) {
                if(k % 2 == 1) {
                    temp[c][c+size] = temp[c+size][c] = 0;
                }
                c++;
                k = k >> 1;
            }
            
            for(int k =0;k<size_dbl;k++) {
                for(int i=0;i<size_dbl;i++) {
                    for(int j=0;j<size_dbl;j++) {
                        temp[i][j] = min(temp[i][j], temp[i][k] + temp[k][j]);
                    }
                }
            }
            
            int diameter = 0;
            
            for(int i =0; i< size_dbl;i++) {
                for(int j=i; j< size_dbl;j++) {
                    int v = temp[i][j];
                    if(diameter < v) {
                        diameter = v;
                    }
                }
            }
            
            max = max > diameter ? diameter : max;
        }
        
        return max;
    }
    void cpy() {
        for(int i = 0;i<size_dbl;i++) {
            for(int j =0;j<size_dbl;j++) {
                temp[i][j] = bridges[i][j];
            }
        }
    }
    int bitCount(int i) {
        int c = 0;
        while(i != 0) {
            if(i % 2 == 1) {
                c++;
            }
            i = i >> 1;
        }
        return c;
    }
};
