#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class BearSortsDiv2 {
public:
    const static int N = 40;
    int t[N] = {0};

    int copiedSeq[N];
    int seq_size;
    int count = 0;
    double getProbability(vector<int> seq) {
        seq_size = (int) seq.size();
        for(int i = 0;i<seq_size;i++ ) {
            copiedSeq[i] = seq[i];
            t[i] = i+1;
        }
        mergeSort(0, seq_size);
        
        return 0  - log(pow(2, count));
        
    }
    
    void mergeSort(int left, int right) {
        if( left + 1 >= right) {
            return;
        }
        int mid = (left + right) /2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        vector<int> merged(0);
        int p1 = left;
        int p2 = mid;
        
        while((p1 < mid) || (p2 < right)) {
            if(p1 == mid) {
                merged.push_back(t[p2]);
                p2++;
            } else if(p2 == right) {
                merged.push_back(t[p1]);
                p1++;
            } else {
                if(less(t[p1], t[p2])) {
                    merged.push_back(t[p1]);
                    p1++;
                } else {
                    merged.push_back(t[p2]);
                    p2++;
                }
            }
        }
        
        for(int i = left;i<right;i++) {
            t[i] = merged[i-left];
        }
    }
    bool less(int a, int b) {
        for(int i = 0;i< seq_size;i++) {
            if(copiedSeq[i] == a) {
                count++;
                return true;
            
            } else if(copiedSeq[i] == b){
                count++;
                return false;
            }
        }
        // never
        return false;
    }
};
