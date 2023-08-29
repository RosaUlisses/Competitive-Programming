#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct graph {
    map<int, vector<int>> adjacency_list;
    
    graph() {
    }
};

void dfs(graph& g, map<int,int>& previous, int current, int last_visited) {
    if (previous.find(current) != previous.end()) return;
    previous.insert({current, last_visited});

    for (const auto& node : g.adjacency_list[current]) {
        dfs(g, previous, node, current); 
    }
}

map<int,int> top_sort(graph& g) {
    map<int,int> previous;
    int last_visited = 0;
    for (const auto&[value, _] : g.adjacency_list) {
        if (previous.find(value) == previous.end()) {
            dfs(g, previous, value, last_visited);
        } 
        last_visited = value;
    }

    return previous;
}

int main() {
    int number_of_students, number_of_good_students;
    cin >> number_of_students >> number_of_good_students;
    graph graph;
    for (int i = 0; i < number_of_good_students; ++i) {
       int count; 
       cin >> count;
       vector<int> subordinates(count);
        for (int j = 0; j < count; ++j) {
            cin >> subordinates[j];
        }
        graph.adjacency_list.insert({i + 1, subordinates}); 
    }

    for (int i = number_of_good_students + 1; i <= number_of_students; ++i) {
        graph.adjacency_list.insert({i, {}});
    }

    map<int,int> bosses = top_sort(graph);
    for (const auto& [_, boss] : bosses) {
       cout << boss << "\n"; 
    }
    
	return 0;
}
