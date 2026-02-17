#include <iostream>
#include <string>
#include <cstdlib>


void createRandomMap(int &minX, int &maxX, int &minY, int &maxY) {
    minX = -(rand() % 11); 
    maxX = (rand() % 11);  
    minY = -(rand() % 11); 
    maxY = (rand() % 11);  
}

bool isPointValid(int x, int y, int minX, int maxX, int minY, int maxY) {
    if (x >= minX && x <= maxX && y >= minY && y <= maxY) {
        return true;
    } else {
        return false;
    }
}

int main() {
    
    srand(42); 

    std::string firstName;
    int userX, userY;
    int mXmin, mXmax, mYmin, mYmax; 

    std::cout << "Enter your first name: ";
    std::cin >> firstName;

    
    createRandomMap(mXmin, mXmax, mYmin, mYmax);

    std::cout << "\nHello, " << firstName << "!" << std::endl;
    std::cout << "Enter a point to check (x y): ";
    std::cin >> userX >> userY;

    
    if (isPointValid(userX, userY, mXmin, mXmax, mYmin, mYmax)) {
        std::cout << "Correct, the point (" << userX << ", " << userY << ") is inside the map." << std::endl;
    } else {
        std::cout << "The point (" << userX << ", " << userY << ") is outside the map." << std::endl;
    }

    std::cout << "\nThe map has the boundaries:" << std::endl;
    std::cout << "X: [" << mXmin << " to " << mXmax << "]" << std::endl;
    std::cout << "Y: [" << mYmin << " to " << mYmax << "]" << std::endl;

    return 0;
}