#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class AnArray {
public:

    int solveProblem(vector <int> A, int K) {
        sort(A.begin(), A.end());
        
        int count =0;
        
        for(int q = (int)A.size()-2;q > 0;q--) {
            for(int p=0;p<q; p++) {
                
                int ar_d = gcd(A[p]*A[q], K);
                if(0 == K % ar_d) {
                    int ar = K/ar_d;
                    for(int i = q+1;i<A.size();i++) {
                        if(A[i] % ar ==0) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
    
    int gcd (int a, int b) {
        int c;
        while ( a != 0 ) {
            c = a; a = b%a;  b = c;
        }
        return b;
    }
};