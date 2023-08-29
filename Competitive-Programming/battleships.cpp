#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<pair<int, int>> get_adjacent_cells(pair<int, int> cell) {
    return {
            {cell.first + 1, cell.second},
            {cell.first - 1, cell.second},
            {cell.first, cell.second + 1},
            {cell.first, cell.second - 1},
    };
}

void bfs(vector<vector<char>> &grid, pair<int,int> cell, set<pair<int, int>> &visited) {
    for (auto adjacent : get_adjacent_cells(cell)) {
        if (adjacent.first >= grid.size() || adjacent.first < 0 || adjacent.second >= grid.size() || adjacent.second < 0 || grid[adjacent.first][adjacent.second] == '.') continue;
        if (visited.find(adjacent) != visited.end()) continue; 
        visited.insert(adjacent);
        bfs(grid, adjacent, visited);
    }
}

int get_the_number_of_battleships(vector<vector<char>> &grid, vector<pair<int, int>> &ship_positions) {
    int count = 0;
    set<pair<int, int>> visited;
    for (auto position : ship_positions) {
        if (visited.find(position) == visited.end()) {
            bfs(grid, position, visited);
            count++;
        } 
    }
    
    return count;
}

int main() {
    int number_of_tests; 
    cin >> number_of_tests;
    vector<int> outputs(number_of_tests);

    for (int i = 0; i < number_of_tests; ++i) {
       int grid_size; 
       cin >> grid_size;
       vector<vector<char>> grid(grid_size); 
       vector<pair<int,int>> ship_positions;
        for (int j = 0; j < grid_size; ++j) {
            string line;
            cin >> line;
            for (int k = 0; k < line.size(); ++k) {
               grid[j].push_back(line[k]);
                if (line[k] == 'x') ship_positions.push_back({j, k});
            }
        }
        outputs[i] = get_the_number_of_battleships(grid, ship_positions);
    }

    for (int i = 0; i < outputs.size(); ++i) {
        cout << "Case " << i + 1 << ": " << outputs[i] << "\n";
    }

    return 0;
}
