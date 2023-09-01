#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int rows, columns;
    map<char,int> colors = {{'C', 0}, {'M', 0}, {'Y', 0}, {'W', 0}, {'G', 0}, {'B', 0}}; 
    cin >> rows >> columns;

    for (int i = 0; i < rows * columns; ++i) {
       char color; 
       cin >> color;
       colors[color]++;
    }

    bool is_colored = any_of(colors.begin(), colors.end(), [](const auto& item) {
        if (item.first == 'C' || item.first == 'M' || item.first == 'Y') {
            if (item.second > 0) {
                return true;
            }
        }
        return false;
    });

    if (is_colored) {
        cout << "#Color";
    }
    
    else {
        cout << "#Black&White";
    }
    
	return 0;
}
