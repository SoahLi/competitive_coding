#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
namespace std {
    template <>
    struct hash<std::pair<int, int>> {
        size_t operator()(const std::pair<int, int>& p) const {
            auto h1 = std::hash<int>{}(p.first);
            auto h2 = std::hash<int>{}(p.second);
            return h1 ^ h2;
        }
    };
}


//Submission 1: Wrong Answer
// void checkAdjSpace(vector<vector<char> >& grid, unordered_set<pair<int, int> >& dp, int i, int j){
//     if(dp.find(pair<int, int>(i, j)) != dp.end()) return;
//     if((i >= 0 && i < grid.size()) && (j >= 0 && j < grid[0].size())){
//         dp.insert(pair<int, int>(i, j));
//         if(grid[i][j] == '1'){
//             checkAdjSpace(grid, dp, i, j+1);
//             checkAdjSpace(grid, dp, i+1, j);
//         }
//     }
// }

// //This should only take O(n)
// int numIslands(vector<vector<char> >& grid){
//     //walk through map from left to right
//     //when "1" is found
//         //start checking the space directly to the right and beneath it
//         //add spaces with "1" to ds that accounts for this isalnd and its coordinates
//         //continue until no "1"'s are found
//     unordered_set<pair<int, int> > dp;
//     int height=grid.size(), width = grid[0].size();
//     int num_islands = 0;

//     for(int i=0; i<height; i++){
//         for(int j=0; j<width; j++){
//             if(dp.find(pair<int, int>(i, j)) != dp.end()) continue;
//             else if(grid[i][j] == '1'){
//                 num_islands++;
//                 checkAdjSpace(grid, dp, i, j+1);
//                 checkAdjSpace(grid, dp, i+1, j);
//             }
//             dp.insert(pair<int, int>(i, j));
//         }
//     }
//     return num_islands;
// }

//Submission 2: PASSING
/*
 Time Complexity: O(M*N)
 Space Complexity: O(M*N)
 Completed in: Past Time Limit
*/
void checkAdjSpace(vector<vector<char> >& grid, unordered_set<pair<int, int> >& dp, int i, int j){
    if(dp.find(pair<int, int>(i, j)) != dp.end()) return;
    dp.insert(pair<int, int>(i, j));
    if((i >= 0 && i < grid.size()) && (j >= 0 && j < grid[0].size())){
        if(grid[i][j] == '1'){
            checkAdjSpace(grid, dp, i, j+1);
            checkAdjSpace(grid, dp, i+1, j);
            checkAdjSpace(grid, dp, i-1, j);
            checkAdjSpace(grid, dp, i, j-1);
        }
    }
}


int numIslands(vector<vector<char> >& grid){
    //walk through map from left to right
    //when "1" is found
        //start checking the space directly to the right and beneath it
        //add spaces with "1" to ds that accounts for this isalnd and its coordinates
        //continue until no "1"'s are found
    unordered_set<pair<int, int> > dp;
    int height=grid.size(), width = grid[0].size();
    int num_islands = 0;

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            if(dp.find(pair<int, int>(i, j)) != dp.end()) continue;
            else if(grid[i][j] == '1'){
                num_islands++;
                checkAdjSpace(grid, dp, i, j+1);
                checkAdjSpace(grid, dp, i+1, j);
            }
            dp.insert(pair<int, int>(i, j));
        }
    }
    return num_islands;
}

int main(){
    // vector<vector<char>> map{
    //     {'1','1','1','1','0'},
    //     {'1','1','0','1','0'},
    //     {'1','1','0','0','0'},
    //     {'0','0','0','0','0'}
    // };

    // vector<vector<char> > map{
    //     {'1','1','0','0','0'},
    //     {'1','1','0','0','0'},
    //     {'0','0','1','0','0'},
    //     {'0','0','0','1','1'}
    // };

    vector<vector<char> > map{
        {'1', '1', '1'},
        {'0', '1', '0'},
        {'1', '1', '1'},
    };
    cout << numIslands(map);
}