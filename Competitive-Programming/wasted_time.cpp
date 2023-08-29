#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

typedef pair<int,int> point;

double distance_between_points(point a, point b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

long double wasted_time_by_signature(vector<point>& points) {
    long double time = 0;
    for (int i = 0; i < points.size() - 1; ++i) {
       time += distance_between_points(points[i], points[i + 1]) / 50; 
    }
    return time;
}

int main() {
    int number_of_points, number_of_signatures;
    cin >> number_of_points >> number_of_signatures;
    vector<point> points(number_of_points);

    for (int i = 0; i < number_of_points; ++i) {
       cin >> points[i].first >> points[i].second; 
    }
    
    
    string total_time = to_string(wasted_time_by_signature(points) * number_of_signatures);
    cout << total_time;
    
	return 0;
}