#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class OrderOfOperationsDiv2 {
public:
    typedef pair<int, int> P;
    
    int MAX = 1<< 22;
    int minTime(vector<string> s) {
        priority_queue<P, vector<P>, greater<P>> que;
        int n  = (int) s.size();
        int m  = (int) s[0].size();
        int bit_patterns = 1 << m;
        vector<int> time(bit_patterns, MAX);
        time[0] = 0;
        
        que.push(P(0, 0));
        
        while(!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;
            if(time[v] < p.first) {
                continue;
            }
            
            for(int i = 0; i < n;i++) {
                int target = toInt(s[i]);
                if(v == target) {
                    continue;
                }
                int destination = v | target;
                int edgeCost =time[v] + diffCost(v, destination);
                
                if(time[destination] == MAX || time[destination] > edgeCost) {
                    time[destination] = edgeCost;
                    que.push(P(time[destination], destination));
                }
            }
        }
        
        return time[goal(s)];
    }
    
    int goal(vector<string> s) {
        int g = 0;
        for(int i = 0; i<s.size();i++) {
            g = g | toInt(s[i]);
        }
        return g;
    }
    int diffCost(int small, int large) {
        int count =0;
        
        while(large !=0) {
            if(large % 2 == 1 && small % 2 == 0) {
                count++;
            }
            large = large >> 1;
            small = small >> 1;
        }
        return count * count;
    }
    int toInt(string s) {
        int n = 0;
        
        for(int i =0;i< s.size();i++) {
            n = n << 1;
            if(s[i] == '1') {
                n += 1;
            }

        }
        return n;
    }
};