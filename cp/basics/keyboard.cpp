#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int main() {
    string  keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    string shift_direction, text; 
    cin >> shift_direction >> text;
    string  original_text;

    for (auto c : text) {
        if (shift_direction == "R") {
            original_text.push_back(keyboard[keyboard.find(c) - 1]);
        } 
        else {
            original_text.push_back(keyboard[keyboard.find(c) + 1]);
        }
    }
    
    cout << original_text << "\n";
    
	return 0;
}
