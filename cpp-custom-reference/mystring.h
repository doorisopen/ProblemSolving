#ifndef mystring_H
#define mystring_H

#include <vector>
#include <string>
#include <sstream>
using namespace std;
/** 
 * ## Todo
 * [x] trim
 * [x] split
 * [x] replaceFirst
 * [x] replaceAll
 * [x] toUpperCase
 * [x] toLowerCase
 *
 * ## Others Refer
 * https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
 * 
 * @author doorisopen
 * @date 2020-08-12
 */

string _trim(string str) {
    int startCut = 0, endCut = 0;
    for (int i = 0; i < str.length(); i++) {
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            startCut = i;
            break;
        }
    }
    for (int i = str.length()-1; i >= startCut; i--) {
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            endCut = i;
            break;
        }
    }
    endCut-= startCut - 1;
    return str.substr(startCut, endCut);
}

vector<string> _split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
    while (getline(ss, temp, delimiter)) {
        internal.push_back(temp);
    }
    return internal;
}

string _replaceFirst(string str, string target, string replacement) {
    int targetIndexOf = str.find_first_of(target);
    if(str.substr(targetIndexOf,target.length()) != target) {
        return str;
    } else {
        return str.substr(0, targetIndexOf) + replacement + str.substr(targetIndexOf+target.length());
    }
}

string _replaceAll(string str, string target, string replacement) {
    string result = str;
    string::size_type pos = 0;
    string::size_type offset = 0;
    while ((pos = result.find(target, offset)) != string::npos) {
        result.replace(result.begin() + pos, result.begin() + pos + target.length(), replacement);
        offset = pos + target.length();
    }
    return result;
}

string _toUpperCase(string str) {
    for (int i = 0; i < str.length(); i++) {
        if(str[i] >= 97 && str[i] <= 122) {
            str[i] -= 32;
        }
    }
    return str;
}

string _toLowerCase(string str) {
    for (int i = 0; i < str.length(); i++) {
        if(str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
    }
    return str;
}

#endif