    #include <iostream>
    #include <vector>
     
    using namespace std;
     
    struct point {
        int x;
        int y;
        
        point() {
            x = 0;
            y = 0;
        }
    };
     
    int get_max_area(int x_size, int y_size, point dead_pixel) {
        dead_pixel.x++;
        dead_pixel.y++;
        int bigger_x = (x_size - dead_pixel.x) > (dead_pixel.x - 1) ? (x_size - dead_pixel.x) : (dead_pixel.x - 1);
        int bigger_y = (y_size - dead_pixel.y) > (dead_pixel.y - 1) ? (y_size - dead_pixel.y) : (dead_pixel.y - 1);
        
        int first = bigger_x * y_size;    
        int second = bigger_y * x_size;
        
        return first > second ? first : second;
    }
     
    int main() {
        int number_of_test_cases;
        cin >> number_of_test_cases;
        vector<int> output; 
     
        for (int i = 0; i < number_of_test_cases; ++i) {
            int x_size, y_size;
            point dead_pixel;
            cin >> x_size >> y_size >> dead_pixel.x >> dead_pixel.y;
            output.push_back(get_max_area(x_size, y_size, dead_pixel)); 
        }
        
        cout << "\n";
     
        for (int value : output) {
            cout << value << "\n"; 
        }
        
        return 0;
    }
