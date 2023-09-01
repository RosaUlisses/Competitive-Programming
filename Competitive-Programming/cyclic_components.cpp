#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef unordered_map<int, vector<int>> graph;

struct pair_hash {
    size_t  operator()(const pair<int,int>& p) const {
        auto h1 = hash<int>()(p.first);
        auto h2 = hash<int>()(p.second);
        return h1 ^ (h2 << 1);
    }
};

void set_degrees(graph& g, int vertex, set<int>& visited_vertexes, map<int,int>& degrees) {
    visited_vertexes.insert(vertex);
    
    for (auto adjacent : g[vertex]) {
        if (degrees.find(vertex) == degrees.end()) {
            degrees.insert({vertex, 1});
        }
        else degrees[vertex]++;

        if (visited_vertexes.find(adjacent) != visited_vertexes.end()) continue;
        set_degrees(g, adjacent, visited_vertexes, degrees); 
    }
}


int get_number_of_cyclical_components(graph g) {
    set<int> visited_vertexes;
    int number_of_cycles = 0;

    for(auto [vertex, _] : g) {
        if (visited_vertexes.find(vertex) != visited_vertexes.end()) continue;
        map<int,int> degrees;
        set_degrees(g, vertex, visited_vertexes, degrees);
        bool is_cyclic = true;
        for (auto [_, degree] : degrees) {
            if (degree != 2) is_cyclic = false; 
        }
        if (is_cyclic && degrees.size() > 2) {
            number_of_cycles++;
        }
        degrees.clear();
    }

    return number_of_cycles;
}


int main() {
    int number_of_vertexes, number_of_edges;
    cin >> number_of_vertexes >> number_of_edges;
    graph g;
    
    for (int i = 0; i < number_of_vertexes; i++) {
        g.insert({i + 1, {}});
    }

    for (int i = 0; i < number_of_edges; i++) {
        int first, second;
        cin >> first >> second;
        g[first].push_back(second);
        g[second].push_back(first);
    }
    
    cout << get_number_of_cyclical_components(g);

    return 0;    
}