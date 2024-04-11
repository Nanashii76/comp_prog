#include <bits/stdc++.h>
using namespace std;

double convertToRadian(int angle) {
    return (angle*M_PI) / 180;
}

pair<double,double> rotate_points(double a, double b, int angle) {

    pair<double,double> newPoints;

    double radian = convertToRadian(angle);
    double new_a, new_b;
    // new a' will be equal to (a*cos(angle)-b*sin(angle))
    new_a = a*cos(radian)-b*sin(radian);
    new_b = b*cos(radian)+a*sin(radian);

    // new b' will be equal to (b*cos(angle)+b*sin(angle))
    newPoints.first = new_a;
    newPoints.second = new_b;

    return newPoints;

}


int main(){

    double a,b;
    int ang;
    cin >> a >> b >> ang;
    pair<double,double> points = rotate_points(a,b,ang);

    cout << fixed << setprecision(20) << points.first << " " << points.second << endl;
    
    return 0;

}