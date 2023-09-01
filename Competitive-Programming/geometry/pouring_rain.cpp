#include <iostream>
#include <math.h>

using namespace std;

const double PI = 2 * acos(0.0);

int main() {
    double diameter, initial_level_of_the_water, speed_of_dringking, growth_of_water;
    cin >> diameter >> initial_level_of_the_water >> speed_of_dringking >> growth_of_water;
    
    double radius = diameter / 2;
    double water_volume = (PI * pow(radius, 2)) * initial_level_of_the_water;
    double growth_water_volume = (PI * pow(radius, 2)) * growth_of_water;

    if (speed_of_dringking > growth_water_volume) {
        double time_to_empty_the_cup = water_volume / (speed_of_dringking - growth_water_volume);  
        cout << "YES\n" << time_to_empty_the_cup;
    }
    else cout << "NO\n"; 
    
	return 0;
}
