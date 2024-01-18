#include <iostream>
#include <string>
using namespace std;

int findMinimumOperations(string s1, string s2, string s3) {
    if(!((s1[0] == s2[0]) && (s2[0] == s3[0]))) return -1;

    int i=0, j=0, k=0, count=0;
    while(true) {
        if((i < s1.size()) && (j < s2.size()) && (k < s3.size()) && (s1[i] == s2[j]) && (s2[j] == s3[k])) {
            i++;
            j++;
            k++;
        }
        else {
            count += s1.substr(i, s1.size()).size();
            count += s2.substr(j, s2.size()).size();
            count += s3.substr(k, s3.size()).size();
            break;
        }
    }

    return count;
}

int main() {
    // string s1 = "abc";
    // string s2 = "abb";
    // string s3 = "ab";
    // string s1 = "dac";
    // string s2 = "bac";
    // string s3 = "cac";
    string s1 = "abcccc";
    string s2 = "abb";
    string s3 = "af";
    // string s1 = "a";
    // string s2 = "a";
    // string s3 = "a";
    cout << findMinimumOperations(s1, s2, s3);
}