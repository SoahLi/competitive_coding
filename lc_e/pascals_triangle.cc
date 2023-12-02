#include <iostream>
#include <vector>
using namespace std;

//Submission 1: PASSING
/*
 * Time complexity: O(n)
 * Space Complexity: O()
*/
vector<vector<int> > generate(int numRows) {
    vector<vector<int> > result;
    result.push_back(vector<int> {1});
    for(int i=1; i<numRows; i++){
        vector<int> levelValues {1};
        for(int j=1; j<result[i-1].size(); j++){
            levelValues.push_back(result[i-1][j-1] + result[i-1][j]);
        }
        levelValues.push_back(1);
        result.push_back(levelValues);
    }
    return result;
}

int main(){
    // vector<vector<int> > result = generate(5);
    vector<vector<int> > result = generate(1);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}