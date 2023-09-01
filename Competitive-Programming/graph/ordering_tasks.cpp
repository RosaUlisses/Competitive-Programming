#include <iostream>
#include <vector>
#include <map>
#include <forward_list>
#include <set>
#include <stack>

using namespace std;

struct graph {
    map<int, vector<int>> adjacency_list;

    graph(int max_vertex) {
        for (int i = 1; i <= max_vertex; ++i) {
            adjacency_list.insert({i, {}});
        }
    }

    void add_edge(int source, int destination) {
        adjacency_list.find(source)->second.push_back(destination);
    }
};

void dfs(graph &graph, int node, set<int> &visited, forward_list<int> &order) {
    visited.insert(node);

    for (int neighbour: graph.adjacency_list.find(node)->second) {
        if (visited.find(neighbour) != visited.end()) continue;
        dfs(graph, neighbour, visited, order);
    }

    order.push_front(node);
}

forward_list<int> topological_sort(graph &graph) {
    set<int> visited;
    forward_list<int> top_sort_order;

    for (auto [node, _]: graph.adjacency_list) {
        if (visited.find(node) != visited.end()) continue;
        dfs(graph, node, visited, top_sort_order);
    }

    return top_sort_order;
}

int main() {
    int number_of_tasks, number_of_edges;
    while ((cin >> number_of_tasks >> number_of_edges, number_of_tasks == 0 && number_of_edges == 0)) {
        graph g(number_of_tasks);
        for (int i = 0; i < number_of_edges; ++i) {
            int source, destination;
            cin >> source >> destination;
            g.add_edge(source, destination);
        }
        forward_list<int> order = topological_sort(g);
        for (int value: order) {
            cout << value << " ";
        }
        cout << "\n";
    }

    return 0;
}
