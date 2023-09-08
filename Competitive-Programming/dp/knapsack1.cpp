#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n, w;
    cin >> n >> w;
    
    vector<pair<int,int64_t >> array;

    for (int i = 0; i < n; ++i) {
        int weight;
        int64_t value;
        cin >> weight >> value; 
        array.push_back({weight, value});
    }
    
    vector<vector<int64_t>> matrix(n + 1);
    for (auto & i : matrix) {
        for (int j = 0; j < w + 1; ++j) {
            i.push_back(0);
        }       
    }
    
    for (int i = 1; i < matrix.size(); ++i) {
        int weight = array[i - 1].first;
        int64_t value = array[i - 1].second; 
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (j >= weight) {
                matrix[i][j] = value;
            }
            if (j - weight >= 0) {
                matrix[i][j] += matrix[i - 1][j - weight];
            }
            if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) {
                matrix[i][j] = matrix[i - 1][j];
            }
        } 
    }

    cout << matrix[n][w]; 
    
	return 0;
}
