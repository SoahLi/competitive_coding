// #include <iostream>
// #include <set>
// #include <vector>
// using namespace std;


//first iteration: did not account for unsorted intervals
// int main(){
//     //traverse through list
//     //create new set
//     //while(first num of i+1th list <= 2nd num of ith list)
//         //pb(interval into set)
//     //pb(lowest and highest values from set)
//         //return result
//     //case 1
//     // vector<vector<int> > intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
//     //case 2
//     vector<vector<int> > intervals = {{1,4},{4,5}};

//     vector<vector<int> > result;
//     for(int i=0; i<intervals.size(); i++){
//         set<int> current_intervals;
//         current_intervals.insert(intervals[i][0]);
//         current_intervals.insert(intervals[i][1]);
//         while(i < intervals.size()-1 && intervals[i+1][0] <= intervals[i][1]){
//             cout << "inside" << '\n';
//             cout << intervals[i+1][0] << '\n';
//             cout << intervals[i+1][1] << '\n';
//             current_intervals.insert(intervals[i+1][0]);
//             current_intervals.insert(intervals[i+1][1]);
//             i++;
//         }
//         cout << "check 2" << '\n';
//         for(int s: current_intervals){
//             cout << s << '\n';
//         }
//         cout << endl << endl;
//         vector<int> interval {*(current_intervals.begin()), *(current_intervals.rbegin())};
//         for(int s: interval){
//             cout << s << '\n';
//         }
//         cout << endl << endl;
            // //this works?
            // vector<int> interval {*(current_intervals.begin()), *(current_intervals.rbegin())};
            // result.push_back(interval);
            // //this doesent?
            // // result.push_back(vector<int> (*(current_intervals.begin()), *(current_intervals.rbegin())));
//     }
//     cout << "check 3" << '\n';
//     for(vector<int> r: result){
//         cout << r[0] << " " <<r[1] << '\n';
//     }
// }

//second attempt: didn't account for largest num being the first interval
// #include <iostream>
// #include <set>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main(){
//     //traverse through list
//     //create new set
//     //while(first num of i+1th list <= 2nd num of ith list)
//         //pb(interval into set)
//     //pb(lowest and highest values from set)
//         //return result
//     //case 1
//     vector<vector<int> > intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
//     //case 2
//     // vector<vector<int> > intervals = {{1,4},{4,5}};
//     //case 3
//     // vector<vector<int> > intervals = {{1,4}, {0,0}};
//     // if(intervals.size() == 1) return intervals;
//     vector<pair<int, int> > p;
//     for(vector<int> interval: intervals){
//         p.push_back({interval[0], interval[1]});
//     }
//     sort(p.begin(), p.end());

//     vector<vector<int> > result;
//     for(int i=0; i<p.size(); i++){
//         set<int> current_intervals;
//         current_intervals.insert(p[i].first);
//         current_intervals.insert(p[i].second);
//         while(i < p.size()-1 && p[i+1].first <= p[i].second){
//             current_intervals.insert(p[i+1].first);
//             current_intervals.insert(p[i+1].second);
//             i++;
//         }
//         //this works?
//         vector<int> interval {*(current_intervals.begin()), *(current_intervals.rbegin())};
//         result.push_back(interval);
//         //this doesent?
//         // result.push_back(vector<int> (*(current_intervals.begin()), *(current_intervals.rbegin())));
//     }
//     for(vector<int> r: result){
//         cout << r[0] << " " <<r[1] << '\n';
//     }    
// }

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    //traverse through list
    //create new set
    //while(first num of i+1th list <= 2nd num of ith list)
        //pb(interval into set)
    //pb(lowest and highest values from set)
        //return result
    //case 1
    vector<vector<int> > intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    //case 2
    // vector<vector<int> > intervals = {{1,4},{4,5}};
    //case 3
    // vector<vector<int> > intervals = {{1,4}, {0,0}};
    //case 4
    // vector<vector<int> > intervals = {{1,10},{4,5},{6,7},{8,9}};
    // if(intervals.size() == 1) return intervals;
    vector<pair<int, int> > p;
    for(vector<int> interval: intervals){
        p.push_back({interval[0], interval[1]});
    }
    sort(p.begin(), p.end());

    vector<vector<int> > result;
    for(int i=0; i<p.size(); i++){
        set<int> current_intervals;
        current_intervals.insert(p[i].first);
        current_intervals.insert(p[i].second);
        while(i < p.size()-1 && p[i+1].first <= *(current_intervals.rbegin())){
            current_intervals.insert(p[i+1].first);
            current_intervals.insert(p[i+1].second);
            i++;
        }
        //this works?
        vector<int> interval {*(current_intervals.begin()), *(current_intervals.rbegin())};
        result.push_back(interval);
        //this doesent?
        // result.push_back(vector<int> (*(current_intervals.begin()), *(current_intervals.rbegin())));
    }
    for(vector<int> r: result){
        cout << r[0] << " " <<r[1] << '\n';
    }    
}




