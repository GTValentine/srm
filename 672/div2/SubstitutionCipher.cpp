#include <iostream>
#include <vector>
#include <map>
#include<algorithm>
#include<cmath>
using namespace std;

class SubstitutionCipher {
public:
    string decode(string a, string b, string y) {
        char table[26] = {};
        
        for(int i=0;i<a.size();i++) {
            int ii = (int) b[i]- (int) 'A';
            table[ii] = a[i];
        }

        int one = -1;
        for(int i=0;i<26;i++) {
            if(isupper(table[i])) {
                continue;
            }
            if(one == -1) {
                one = i;
                continue;
            }
            one = -1;
            break;
        }
        
        if(one != -1) {
            bool alphabets[26] = {};
            
            for(int i =0;i<26;i++) {
                alphabets[table[i] - 'A'] = true;
            }
            for(int i=0;i<26;i++) {
                if(!alphabets[i]) {
                    table[one] = i+'A';
                    break;
                }
            }
        }
        string answer;
        for(int i =0;i<y.size();i++) {
        
            if(isupper(table[y[i] - 'A'])) {
                answer.push_back(table[y[i]-'A']);
            } else {
                cout << y[i];
                cout << y[i] - 'A';
                cout << table[y[i] - 'A'];
                return "";
            }

        }
        return answer;
    }
    
};