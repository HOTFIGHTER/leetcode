//
// Created by xmly on 2020/1/23.
//
/**Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front
before implementing one. However, here is a list of characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.
 */

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

bool scanUnsignedInteger(char **s) {
    while (**s == ' ') {
        ++(*s);
    }
    const char *before = *s;
    while (**s >= '0' && **s <= '9') {
        //函数中指针指向的值作用域大于函数作用域，指针本身作用域是函数级别的
        ++(*s);
    }
    if ((**s != NULL) && (**s != '.') && (**s != 'e') && (**s != 'E')&& (**s != ' ')) {
        return false;
    }
    return *s > before;
}


bool scanInteger(char **s) {
    if (**s == '-' || **s == '+') {
        ++(*s);
        while (**s == ' ') {
            return false;
        }
    }
    return scanUnsignedInteger(s);
}

class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) {
            return false;
        }
        //s.erase(remove(s.begin(), s.end(), ' '), s.end());
        char *c = const_cast<char *>(s.c_str());
        bool number = scanInteger(&c);
        if (*c == '.') {
            ++c;
            bool isNotBlank = true;
            while (*c == ' ') {
                ++c;
                isNotBlank = false;
            }
            number = scanUnsignedInteger(&c) ? isNotBlank : false || number;
        }
        if (*c == 'e' || *c == 'E') {
            ++c;
            while (*c == ' ') {
                ++c;
                number = false;
            }
            number = scanInteger(&c) && number;
        }
        while (*c == ' ') {
            ++c;
        }
        return number && *c == '\0';
    }
};

int main() {
    string s = ". 1";
    Solution solution;
    cout << solution.isNumber(s);
}