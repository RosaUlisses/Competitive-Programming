#include <iostream>
#include <vector>
#include <map>

/*
    Judge: Educational Dp Contest
    Problem: B-Frog2
    url: https://atcoder.jp/contests/dp/tasks/dp_b
 */

using namespace std;

int mod(int n) {
    return n < 0 ? n * -1 : n;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> path(n);
    map<int ,int> distances;

    for (int i = 0; i < n; ++i) {
        cin >> path[i];
        distances.insert({i, 0});
    }

    for (int i = path.size() - 2; i >= 0 ; --i) {
        int min_distance = mod(path[i] - path[i + 1]) + distances[i + 1];
        for (int j = 0; j < k && j + i + 1 < path.size(); ++j) {
            int distance = mod(path[i] - path[j + i + 1]) + distances[j + i + 1];
            if (distance < min_distance) {
                min_distance = distance;
            }
        } 
        distances[i] = min_distance;
    }

    cout << distances[0]; 
    
	return 0;
}
