#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
class Hexspeak {
public:
    std::string decode(long long decimal_value) {
        std::stringstream ss;
        ss<< std::hex << decimal_value;
        std::string res ( ss.str() );
        
        std::string result = "";
        for(int i=0; i< res.length();i++) {
            char c = res.at(i);
            if(c == '2' || c=='3' || c=='4' || c== '5' || c== '6' || c=='7' || c=='8' || c== '9') {
                return "Error!";
            } else if(c == '1') {
                result.append("I");
            } else if (c == '0') {
                result.append("O");
            } else {
                result.append(std::string(1,c));
            }
        }
        std::transform(result.begin(), result.end(),result.begin(), ::toupper);
        return result;
    }
};