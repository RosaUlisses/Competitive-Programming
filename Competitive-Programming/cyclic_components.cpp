#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

typedef map<int, vector<int>> graph;

void is_cycle(graph& g, int vertex, set<int>& visited_vertexes, unordered_set<pair<int,int>>& visited_edges, int first_vertex, bool& result) {
    if(vertex != first_vertex) {
        visited_vertexes.insert(vertex);
    }
     
    for(auto adjacent : g[vertex]) {
        if(visited_edges.find({adjacent, vertex}) != visited_edges.end()) continue; 
            
        visited_edges.insert({adjacent, vertex});
        if(adjacent == first_vertex) {
            if(visited_vertexes.find(first_vertex) == visited_vertexes.end()) {
                result && true;
                visited_vertexes.insert(first_vertex);
            }
            else {
                result && false;
            }
        }
        else {
            is_cycle(g, adjacent, visited_vertexes, visited_edges, first_vertex, result);
        }
    }
}


int get_number_of_cyclical_components(graph g) {
    set<int> visited_vertexes;
    unordered_set<pair<int,int>> visited_edges;
    int number_of_cycles = 0;

    for(auto vertex : g) {
        if(visited_vertexes.find(vertex.first) != visited_vertexes.end()) continue; 
        bool is_there_cycle = true;
        is_cycle(g, vertex.first, visited_vertexes, visited_edges, vertex.first, is_there_cycle);
        if(is_there_cycle) {
            number_of_cycles++;
        }
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