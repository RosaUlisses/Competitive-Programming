#include <iostream>

using namespace std;

bool is_there_a_polygon_with_this_angle(int angle) {
    // (180 * (n -2)) / n = angle
    int n = 180 - angle;
    return 360 % n == 0;
}

int main() {
    int number_of_inputs;
    cin >> number_of_inputs;

    for (int i = 0; i < number_of_inputs; ++i) {
        int angle;
        cin >> angle;
        is_there_a_polygon_with_this_angle(angle) ? cout << "YES\n" : cout << "NO\n"; 
    }
    
	return 0;
}
