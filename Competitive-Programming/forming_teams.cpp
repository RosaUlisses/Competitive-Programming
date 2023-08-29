#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>

using namespace std;

struct graph {
    map<int, set<int>> adjacency_list;

    void add_vertex(int vertex) {
        adjacency_list.insert({vertex, {}});
    }

    void add_edge(int v1, int v2) {
        adjacency_list.find(v1)->second.insert(v2);
        adjacency_list.find(v2)->second.insert(v1);
    }

    void remove_vertex(int vertex) {
        adjacency_list.erase(vertex);
        for (auto [_, adjacents]: adjacency_list) {
            if (adjacents.find(vertex) != adjacents.end()) {
                adjacents.erase(vertex);
            }
        }
    }
};

int wrong(graph enemies_graph, int number_of_players) {
    int number_of_without_enemies = number_of_players - enemies_graph.adjacency_list.size();
    set<int> first_bipartition;
    set<int> second_bipartition;

    vector<int> to_remove;

    for (auto [vertex, adjacents]: enemies_graph.adjacency_list) {
        bool remove_vertex = true;
        if (first_bipartition.find(vertex) == first_bipartition.end()) {
            bool allowed = true;
            for (int item: adjacents) {
                if (first_bipartition.find(item) != first_bipartition.end()) {
                    allowed = false;
                }
            }
            if (allowed) {
                first_bipartition.insert(vertex);
                remove_vertex = false;
            }
        }

        if (second_bipartition.find(vertex) == second_bipartition.end() &&
            first_bipartition.find(vertex) == first_bipartition.end()) {
            bool allowed = true;
            for (int item: adjacents) {
                if (second_bipartition.find(item) != second_bipartition.end()) {
                    allowed = false;
                }
            }
            if (allowed) {
                second_bipartition.insert(vertex);
                remove_vertex = false;
            }
        }
        if (remove_vertex) {
            to_remove.push_back(vertex);
        }

    }

    std::for_each(to_remove.begin(), to_remove.end(),
                  [&enemies_graph](int vertex) { enemies_graph.remove_vertex(vertex); });

    if ((enemies_graph.adjacency_list.size() + number_of_without_enemies) % 2 == 0) return number_of_players - (enemies_graph.adjacency_list.size() + number_of_without_enemies);
    return number_of_players - (enemies_graph.adjacency_list.size() + number_of_without_enemies) + 1;
}

void dfs(graph& graph, set<int>& visited, set<int>& first_bipartition, set<int>& second_bipartition, int current_vertex, int previous_vertex, vector<int>& to_delete) {
    visited.insert(current_vertex);
    if (previous_vertex == -1) {
        first_bipartition.insert(current_vertex);
        for (int vertex : graph.adjacency_list.find(current_vertex)->second) {
            if (visited.find(vertex) == visited.end()) {
                dfs(graph, visited, first_bipartition, second_bipartition, vertex, current_vertex, to_delete);
            }
        }
    }
    else if (first_bipartition.find(previous_vertex) != first_bipartition.end()) {
        bool allowed = true;
        for (int vertex : graph.adjacency_list.find(current_vertex)->second) {
            if (second_bipartition.find(vertex) != second_bipartition.end()) {
                allowed = false;
                break;
            } 
        }
        if (second_bipartition.find(current_vertex) == second_bipartition.end() && allowed) {
            second_bipartition.insert(current_vertex);
            for (int vertex : graph.adjacency_list.find(current_vertex)->second) {
                if (visited.find(vertex) == visited.end()) {
                    dfs(graph, visited, first_bipartition, second_bipartition, vertex, current_vertex, to_delete);
                }
            }
        } 
        else to_delete.push_back(current_vertex);
    }
    else if (second_bipartition.find(previous_vertex) != second_bipartition.end()) {
        bool allowed = true;
        for (int vertex : graph.adjacency_list.find(current_vertex)->second) {
            if (first_bipartition.find(vertex) != first_bipartition.end()) {
                allowed = false;
                break;
            }
        }
        if (first_bipartition.find(current_vertex) == first_bipartition.end() && allowed) {
            first_bipartition.insert(current_vertex);
            for (int vertex : graph.adjacency_list.find(current_vertex)->second) {
                if (visited.find(vertex) == visited.end()) {
                    dfs(graph, visited, first_bipartition, second_bipartition, vertex, current_vertex, to_delete);
                }
            }
        }
        else to_delete.push_back(current_vertex);
    }
}

int minimum_students_to_go_to_the_bench(graph graph, int number_of_players) {
    set<int> visited;
    set<int> first_bipartition;
    set<int> second_bipartition;
    vector<int> to_delete;
    
    int players_without_enemies = number_of_players - graph.adjacency_list.size();

    for (auto [vertex, adjacent] : graph.adjacency_list) {
        dfs(graph, visited, first_bipartition, second_bipartition, vertex, -1, to_delete);    
    }

    if ((graph.adjacency_list.size() - to_delete.size() + players_without_enemies) % 2 == 0) return to_delete.size();
    return to_delete.size() + 1;
}

int main() {
    int number_of_players, number_of_enemies;
    cin >> number_of_players >> number_of_enemies;
    graph g;

    for (int i = 0; i < number_of_enemies; ++i) {
        int player1, player2;
        cin >> player1 >> player2;
        g.add_vertex(player1);
        g.add_vertex(player2);
        g.add_edge(player1, player2);
    }

    cout << minimum_students_to_go_to_the_bench(g, number_of_players);

    return 0;
}
