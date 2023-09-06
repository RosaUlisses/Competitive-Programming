#include <iostream>
#include <vector>

using namespace std;

/*
    Judge: Neps Academy 
    Problem: Coast 
    url: https://neps.academy/exercise/329
 */

bool is_adjacent_to_water(int i, int j, vector<vector<char>>& matrix) {
    if ((i + 1 >= matrix.size() || i - 1 < 0 || j + 1 >= matrix[0].size() || j - 1 < 0)) {
        if (matrix[i][j] == '#') return true;
        return false;
    }
    if((matrix[i + 1][j] == '.' || matrix[i - 1][j] == '.' || matrix[i][j - 1] == '.' || matrix[i][j + 1] == '.') && matrix[i][j] == '#') return true; 
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix;

    for (int i = 0; i < n; ++i) {
        matrix.push_back({});
        for (int j = 0; j < m; ++j) {
            char value; 
            cin >> value;
            matrix[i].push_back(value);
        }
    }

    int number_of_coasts = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (is_adjacent_to_water(i, j, matrix)) {
                number_of_coasts++;
            } 
        } 
    }
    
    cout << number_of_coasts;
    
	return 0;
}
