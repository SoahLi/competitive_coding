#include <iostream>
#include <string>
using namespace std;

int main() {
    string date;
    getline(cin, date);
    if(date == "OCT 31"){
        cout << "yup";
    }   else {
        cout << "nope";
    }
}