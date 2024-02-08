#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Submission 1 PASSING
/*
 * Time complexity: O(m*n)
 * Space complexity: O(m*n)
*/
// void setZeroes(vector<vector<int> > &matrix){
//     //find which indexes are zeros
//     //set entire row to zero
//     //set indexes of other rows to zero
//     vector<int> zeroIndexes;
//     bool thereIsAZero = false;
//     for(int i=0; i<matrix.size(); i++){
//         for(int j=0; j<matrix[0].size(); j++){
//             if(matrix[i][j] == 0){
//                 zeroIndexes.push_back(j);
//                 thereIsAZero = true;
//             }
//         }
//         if(thereIsAZero){
//             fill_n(matrix[i].begin(), matrix[i].size(), 0);
//         }
//         thereIsAZero = false;
//     }
//     for(int i=0; i<matrix.size(); i++){
//         for(int j: zeroIndexes){
//             matrix[i][j] = 0;
//         }
//     }
// }

// int main(){
//     vector<vector<int> > m = {{1,1,1},{1,0,1},{1,1,1}};
//     // vector<vector<int> > m = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
//     // vector<vector<int> > m = {{0}};
//     setZeroes(m);
//     for(int i=0; i<m.size(); i++){
//         for(int j=0; j<m[i].size(); j++){
//             cout << m[i][j];
//         }
//         cout << endl;
//     }
    
// }


//Submission 2 PASSING
/*
 * Time complexity: O(m*n^2)
 * Space complexity: O(m*n)
*/
void setZeroes(vector<vector<int> > &matrix){
    //find which indexes are zeros
    //set entire row to zero
    //set indexes of other rows to zero
    vector<pair<int, int> > zeroIndexes;
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            if(matrix[i][j] == 0) zeroIndexes.push_back(pair<int, int>(i, j));
        }
    }

    //fill horizontally
    for(pair<int, int> p: zeroIndexes){
            fill_n(matrix[p.first].begin(), matrix[p.first].size(), 0);
    }

    //fill vertically
    for(int i=0; i<matrix.size(); i++){
        for(pair<int, int> p: zeroIndexes){
            matrix[i][p.second] = 0;
        }
    }
}

int main(){
    // vector<vector<int> > m = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int> > m = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    // vector<vector<int> > m = {{0}};
    setZeroes(m);
    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m[i].size(); j++){
            cout << m[i][j];
        }
        cout << endl;
    }
    
}
