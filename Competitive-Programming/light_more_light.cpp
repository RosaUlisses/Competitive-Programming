#include <iostream>
#include <vector>
#include <string>

using namespace std;

string is_on(int nthest_bulb) {
    bool is_bulb_on = false;

    for (int i = 1; i <= nthest_bulb; ++i) {
        if (nthest_bulb % i == 0) {
            is_bulb_on = !is_bulb_on;
        }
    }

    return is_bulb_on ? "yes" : "no";
}

int main() {
    vector<string> output;
    while (true) {
        
        int bulb;
        cin >> bulb;
        if (bulb == 0) break;
        output.push_back(is_on(bulb)); 
    }

    for (string  value : output) {
        cout << value << "\n";
    }
    
    return 0;
}
