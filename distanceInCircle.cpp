#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1416;

double distance(double x1, double x2, double y1, double y2);
double radius(double x1, double x2, double y1, double y2);
double circumference(double r);
double area(double r);

double distance(double x1, double x2, double y1, double y2) {
    double s = sqrt(((x2-x1)*(x2-x1)) +((y2-y1)*(y2-y1)));
    return s;
}

double radius(double x1, double x2, double y1, double y2) {
    double r = distance(x1, x2, y1, y2);
    return r;
}

double circumference(double r) {
    double c = 2 * PI * r;
    return c;
}

double area(double r) {
    double a = PI * r * r;
    return a;
}

int main() {
    double a, b, x, y; //x1, y1,  x2, y2
    char comma;

    cout << "Enter the center of the circle (a, b): ";
    cin >> a >> comma >> b;
    cout << "Enter the point (x, y): ";
    cin >> x >> comma >> y;

    cout << "This circle has: " << endl;

    double result1 = radius(a, x, b, y);
    cout << "Radius\t\t= " << result1 << " unit";

    double result2 = circumference(result1);
    cout << "\nCircumference\t= " << result2 << " unit";

    double result3 = area(result1);
    cout << "\nArea\t\t= " << result3 << " square unit";

    return 0;
}
