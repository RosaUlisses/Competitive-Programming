#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int a = -1, v = -1;
    
    int counter = 1;

    while(true) {
        cin >> a >> v;
        if (a == 0 && v == 0) break;
        map<int,vector<int>> adjacency_list;
        for (int i = 1; i <= a; ++i) {
            adjacency_list.insert({i, {}}); 
        }

        for (int i = 0; i < v; ++i) {
            int x, y; 
            cin >> x >> y;
            adjacency_list[x].push_back(y);
            adjacency_list[y].push_back(x);
        }
        
        int max_degree = -1;
        vector<int> airports;

        for (auto [airport, connections] : adjacency_list) {
            int degree = connections.size();
            if (degree > max_degree) {
                airports.clear();
                airports.push_back(airport);
                max_degree = degree;
            }
            else if (degree == max_degree) {
                airports.push_back(airport);
            }
        }

        cout << "Teste " << counter << "\n";
        for (auto value : airports) {
            cout << value << " "; 
        }
        cout << "\n";
        
        counter++;
    }
    
	return 0;
}
