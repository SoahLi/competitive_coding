

#include <iostream>
#include <vector>
using namespace std;
 
void calcSubset(vector<int>& A, vector<vector<int> >& res,
                vector<int>& subset, int index)
{
    // Add the current subset to the result list

    cout << "new iteration, index is equal to " << index << ". pushing ";
    for(int j=0; j< subset.size(); j++){
        cout << subset[j] << " ";
    }
    cout << "to result" << '\n';
    res.push_back(subset);
 
    // Generate subsets by recursively including and
    // excluding elements
    for (int i = index; i < A.size(); i++) {
        cout << "current iteration of index " << index << " is " << i << '\n';
        // Include the current element in the subset
        subset.push_back(A[i]);
        cout <<"pushing back " << A[i] << " subset is now equal to ";
        for(int j=0; j< subset.size(); j++){
            cout << subset[j] << " ";
        }
        cout << '\n';
        // Recursively generate subsets with the current
        // element included
        calcSubset(A, res, subset, i + 1);
 
        // Exclude the current element from the subset
        // (backtracking)

        subset.pop_back();
        cout << "result after being popped is ";
        for(int j=0; j< subset.size(); j++){
            cout << subset[j] << " ";
        }
        cout << '\n';
    }
    cout << "returning" << '\n';
}
 
vector<vector<int> > subsets(vector<int>& A)
{
    vector<int> subset;
    vector<vector<int> > res;
    int index = 0;
    calcSubset(A, res, subset, index);
    return res;
}
 
// Driver code
int main()
{
    vector<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    vector<vector<int> > res = subsets(array);
 
    // Print the generated subsets
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
 
    return 0;
}