#include <iostream>
#include <string>
using namespace std;


//my answer
// int main(){
//     string current;
//     string result = "HE GOT AWAY!";
//     for(int i=0; i<5;i++){
//         cin >> current;
//         for(int j=0; j<current.length()-2; j++){
//             if(current[j] == 'F' && current[j+1] == 'B' && current[j+2] == 'I'){
//                 cout << i+1 << " ";
//                 result = "";
//             }
//         }
//     }
//     cout << result;
// }

//using .find()
int main(){
    string s;
    string result = "HE GOT AWAY!";
    for(int i=0; i<5; i++){
        cin >> s;
        //.find() returns 18446744073709551615(largest size_t value) which is equal to -1
        if(s.find("FBI") != -1){
            cout << i+1 << " ";
            result = "";
        }
    }
    cout << result;
}