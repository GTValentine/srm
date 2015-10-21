#include <iostream>
#include <vector>
#include <map>
#include<algorithm>
#include<cmath>
using namespace std;
class PublicTransit {
public:
    int minimumLongestDistance(int R, int C) {
        int maxDistance=9999;
        for(int rs=0;rs<R;rs++) {
            for(int cs=0;cs<C;cs++) {
                
                for(int rg=0;rg<R;rg++) {
                    for(int cg=0;cg<C;cg++) {
                        
                        int ma = 0;
                        for(int trs=0;trs<R;trs++) {
                            for(int tcs=0;tcs<C;tcs++) {
                                
                                for(int trg=0;trg<R;trg++) {
                                    for(int tcg=0;tcg<C;tcg++) {
                                        int c = abs(trs-trg) + abs(tcs - tcg);
                                        
                                        int a = abs(trs-rs) + abs(tcs - cs) + abs(rg-trg) + abs(cg - tcg);
                                        
                                        int b = abs(trs -rg) + abs(tcs - cg) + abs(rs - trg) + abs(cs - tcg);
                                        
                                         ma = max(ma, min(c, min(a, b)));
                                        
                                    }
                                }
                            }
                        }
                        maxDistance = min(maxDistance, ma);
                    }
                }
                
            }
        }
        return maxDistance;
    }
};
