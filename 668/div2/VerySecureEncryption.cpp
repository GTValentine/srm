#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class VerySecureEncryption {
public:
    vector<int> _key;
    string encrypt(string message, vector<int> key, int K) {
        _key = key;
        string s = message;
        for(int i=0; i< K;i++) {
            s = shuffle(s);
        }
        return s;
    }
    
    string shuffle(string message) {
        char strs[10];
        
        for(int i=0;i<message.size();i++) {
            strs[_key[i]] = message[i];
        }
        return string(strs, message.size());
    }
};