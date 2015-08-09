#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

class BearPlaysDiv2 {
public:
    struct triple {
        int mint;
        int maxt;
    };
    // 小さい値のcache
    const static int MAX_SIZE = 500;
    bool memo[MAX_SIZE][MAX_SIZE];
    int sum;
    queue<triple> que;
    const std::string POSSIBLE = std::string("possible");
    const std::string IMPOSSIBLE = std::string("impossible");
    
    string equalPiles(int A, int B, int C) {
        sum = A + B + C;
        
        if(sum % 3 != 0) {
            return IMPOSSIBLE;
        }
        initMemo();
        
        
        triple t;
        
        int ary[] = {A, B, C};
        srt(ary);
        t.mint = ary[0];
        t.maxt = ary[2];
        
        que.push(t);
        
        while(!que.empty()) {
            triple t = que.front();
            que.pop();
            if(t.maxt == t.mint) {
                return POSSIBLE;
            }
            if(memo[t.mint][t.maxt]) {
                continue;
            }
            memo[t.mint][t.maxt] = true;
            int mid = sum - t.mint - t.maxt;
            
            
            // a < b < c
            
            // -> a + a, b -a, c
            triple next1;
            ary[0] =t.mint *2;
            ary[1] = mid - t.mint;
            ary[2] = t.maxt;
            srt(ary);
            next1.maxt = ary[2];
            next1.mint = ary[0];
            que.push(next1);
            
            // -> a + a, b, c -a
            triple next2;
            ary[0] = t.mint *2;
            ary[1] = mid;
            ary[2] = t.maxt - t.mint;
            srt(ary);
            next2.maxt = ary[2];
            next2.mint = ary[0];
            que.push(next2);
            
            // -> a, b + b, c -b
            triple next3;
            ary[0] = t.mint;
            ary[1] = mid*2;
            ary[2] = t.maxt - mid;
            srt(ary);
            next3.maxt = ary[2];
            next3.mint = ary[0];
            que.push(next3);
        }
        // memo[][] = 1;
        return IMPOSSIBLE;
    }
    
    void srt(int* ary) {
        sort(ary, ary + 3);
    }
    void initMemo() {
        for(int i=0;i<MAX_SIZE;i++) {
            for(int j=0;j<MAX_SIZE;j++) {
                memo[i][j] = false;
            }
        }
    }
    
};
