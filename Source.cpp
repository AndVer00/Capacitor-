#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <ctime>
#include <map>

using namespace std;

int main()
{
    double speed, cylinder_radius, distance, length, permittivity, voltage;
    const double q = -1.6e-19, m = 9.1e-31;

    cout << "Enter voltage between plates:" << endl;
    cin >> voltage;
    cout << "Enter outer cylinder radius:" << endl;
    cin >> cylinder_radius;
    cout << "Enter distance between plates:" << endl;
    cin >> distance;
    cout << "Enter condenser length:" << endl;
    cin >> length;
    cout << "Enter permittivity of capacitor material:" << endl;
    cin >> permittivity;
    cout << "Enter the speed of the electron at the initial moment:" << endl;
    cin >> speed;

    double speed_x = speed;
    double speed_y = 0;
    double acceleration = 0;
    double inner_radius = cylinder_radius - distance;
    double current_y = (cylinder_radius + inner_radius) / 2;
    double current_x = 0;
    

    while (current_x < length && inner_radius < current_y && current_y < cylinder_radius)
    {
        speed = sqrt(pow(speed_x, 2) + pow(speed_y, 2));

        cout << "Current statistics: " << endl;
        cout << "---Coordinate X: " << current_x << endl;
        cout << "---Coordinate Y: " << current_y - inner_radius << endl;
        cout << "---Current speed: " << speed << endl;
        cout << "---Current acceleration: " << acceleration << endl;
        cout << endl;

        acceleration = q * voltage / ((current_y * m * log(cylinder_radius / (cylinder_radius - distance))));
        speed_y += acceleration;
        current_y += speed_y;
        current_x += speed_x;
    }
    return 0;
}
