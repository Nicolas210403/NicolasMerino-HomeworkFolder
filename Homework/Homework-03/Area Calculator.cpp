#include<iostream>
using namespace std;

int main() {
cout << "Which shape do you want to find an area for?" << endl;
cout << "Enter 1 for circle." << endl;
cout << "Enter 2 for rectangle." << endl;
cout << "Enter 3 for square." << endl;
cout << "Enter 4 for cylinder." << endl;
int shapeType;
cin >> shapeType;

double shapeHeight;
cout << "Enter the height of the shape in inches." << endl;
cin >> shapeHeight;
double shapeLength;
cout << "Enter the length of the shape in inches:" << endl;
cin >> shapeLength;
double shapeWidth;
cout << "Enter the width of the shape in inches." << endl;
cin >> shapeWidth;

constexpr double pi = 3.14159;
constexpr double twopi = (2 * pi);
double areaCylinder;
areaCylinder = (twopi * (shapeLength / 2) * shapeHeight) + (twopi * shapeLength);

if (shapeType == 1) {
    cout << "You have selected circle." << endl;
    cout << "The area of the circle is: " << pi * (shapeLength * shapeLength) << endl;
} else if (shapeType == 2) {
    cout << "You have selected rectangle." << endl;
    cout << "The area of the rectangle is: " << shapeLength * shapeWidth << endl;
} else if (shapeType == 3) {
    cout << "You have selected square." << endl;
    cout << "The area of the square is: " << shapeLength * shapeLength << endl;
} else if (shapeType == 4) {
    cout << "You have selected cylinder." << endl;
    cout << "The area of the cylinder is: " << areaCylinder << endl;
} else {
    cout << "Invalid shape selection." << endl;
}
return 0;
}