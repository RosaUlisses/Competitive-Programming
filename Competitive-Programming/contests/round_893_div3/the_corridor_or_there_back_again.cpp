#include <iostream>
#include <map>
#include <vector>

using namespace std;


int main() {
    int nt;
    cin >> nt;
    
    vector<int> results;

    for (int i = 0; i < nt; ++i) {
        map<int,int> traps;
        int num_traps;
        cin >> num_traps;
        for (int j = 0; j < num_traps; ++j) {
            int position, time; 
            cin >> position >> time;
            if (traps.find(position) != traps.end()) {
                if (traps[position] > time) {
                    traps[position] = time;
                }
            }
            traps.insert({position, time});
        }

        vector<int> max_reachables;
        for (auto trap : traps) {
            if (trap.second % 2 == 0) {
                max_reachables.push_back(trap.first + (trap.second / 2 - 1));
            }
            else {
                max_reachables.push_back(trap.first + ((trap.second - 1) / 2));
            }
        }
        
        int min_val = max_reachables[0];
        for (int j = 1; j < max_reachables.size(); ++j) {
            min_val = min_val < max_reachables[j] ? min_val : max_reachables[j];  
        }
        
        cout << min_val << "\n";
    } 
    
	return 0;
}
