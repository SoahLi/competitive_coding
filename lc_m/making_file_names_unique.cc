#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

//Submission 1: time limit exceeded
//Problem: using unordered set instead of map

// vector<string> getFolderNames(vector<string>& names) {
//     vector<string> result;
//     unordered_set<string> m;
//     int k = 0;


//     for(string name : names) {
//         if(m.find(name) != m.end()) {
//             k = 0;
//             string current = name;
//             while(m.find(current) != m.end()) {
//                 current = name;
//                 k++;
//                 current = current + "(" + to_string(k) + ")";
//             }
//             result.push_back(current);
//             m.insert(current);
//         }
//         else {
//             result.push_back(name);
//             m.insert(name);
//         }
//     }
    

//     return result;
// }

vector<string> getFolderNames(vector<string>& names) {
    vector<string> result;
    unordered_map<string, int> m;


   for(int i=0; i<names.size(); i++) {
        // for(auto& p : m) {
        //     cout << "key : " << p.first << " value : " << p.second << " ";
        // }
        // cout << endl;
        if(m.find(names[i]) != m.end()) {
            int k = m[names[i]];
            string current;
            do {
                current = names[i] + "(" + to_string(k) + ")";
                m[names[i]]++;
                k++;

            }   while(m.find(current) != m.end());
            m[current]++;
            result.push_back(current);
        }
        else {
            m[names[i]]++;
            result.push_back(names[i]);
        }
    }
    

    return result;
}

int main() {
    // vector<string> names = {"pes","fifa","gta","pes(2019)"};
    // vector<string> names = {"gta","gta(1)","gta","avalon"};
    // vector<string> names = {"onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"};
    vector<string> names = {"wano","wano","wano","wano"};
    vector<string> output = getFolderNames(names);
    for(string folder : output) {
        cout << folder << " ";
    }
}

