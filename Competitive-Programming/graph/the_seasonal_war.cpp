#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;

struct point {
    int first;
    int second;

    point(int first, int second) {
        this->first = first;
        this->second = second;
    }
    
    bool operator==(const point& other) const {
        return first == other.first && second == other.second;
    }
};

struct pointHash {
    size_t operator()(const point& p) const
    {
        return hash<int>()(p.first) + hash<int>()(p.second);
    }
};
 

auto hash_function = [](const point &p) { return hash<int>()(p.first) + hash<int>()(p.second); };

vector<point> get_adjacent_points(point point) {
    return {{point.first + 1, point.second},
            {point.first,     point.second + 1},
            {point.first - 1, point.second},
            {point.first,     point.second - 1},
            {point.first + 1, point.second + 1},
            {point.first + 1, point.second - 1},
            {point.first - 1, point.second + 1},
            {point.first - 1, point.second - 1}};
}

bool is_out_of_bounds(point point, int dimension) {
    if (point.first < 0 || point.second < 0 || point.first >= dimension || point.second >= dimension) return true;
    return false;
}

void bfs(vector<vector<int>> &matrix, point start_point,
         unordered_set<point, pointHash> &visited_points) {
    auto adjacent_points = get_adjacent_points(start_point);
    visited_points.insert(start_point);
    stack<point> to_visit;
    for_each(adjacent_points.begin(), adjacent_points.end(), [&to_visit](point p) { to_visit.push(p); });

    while (!to_visit.empty()) {

        auto current = to_visit.top();
        to_visit.pop();

        auto p = visited_points.find(current);

        if (is_out_of_bounds(current, matrix.size()) || visited_points.find(current) != visited_points.end() ||
            matrix[current.first][current.second] == 0)
            continue;

        visited_points.insert(current);
        adjacent_points = get_adjacent_points(current);

        for_each(adjacent_points.begin(), adjacent_points.end(), [&to_visit](point p) { to_visit.push(p); });

    }
}

int get_number_of_war_eagles(vector<vector<int>> &matrix, stack<point> &eagle_points) {
    unordered_set<point, pointHash> visited_points;

    int eagle_wars_count = 0;

    while (!eagle_points.empty()) {
        
        point point = eagle_points.top();
        eagle_points.pop();
        
        if (visited_points.find(point) != visited_points.end()) continue;

        bfs(matrix, point, visited_points);
        eagle_wars_count++;
    }

    return eagle_wars_count;
}

int main() {
    int image_size;
    vector<int> output;
    int count = 1;
    while(cin >> image_size) {
        vector<vector<int>> matrix(image_size);
        stack<point> eagle_points;
        for (int i = 0; i < image_size; ++i) {
            string line;
            cin >> line;

            for (int j = 0; j < image_size; ++j) {
                if (line[j] == '1') {
                    matrix[i].push_back(1);
                    eagle_points.push({i, j});
                } else matrix[i].push_back(0);
            }

        }
        cout << "Image number " << count << " contains " << get_number_of_war_eagles(matrix, eagle_points) << " war eagles." << "\n";
        count++;
    }

    return 0;
}
