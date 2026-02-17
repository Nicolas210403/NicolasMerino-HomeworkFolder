#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

int getDaysInMonth(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year)) return 29;
        else return 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    return 31;
}

int main() {
    int year;
    string months[] = {"January", "February", "March", "April", "May", "June", 
                       "July", "August", "September", "October", "November", "December"};

    cout << "Enter a year (1900 or later): ";
    cin >> year;

    if (year < 1900) {
        cout << "Invalid year. Please enter a year starting from 1900." << endl;
    } else {
        long totalDays = 0;
        for (int y = 1900; y < year; y++) {
            if (isLeapYear(y)) totalDays += 366;
            else totalDays += 365;
        }

        int currentDay = (totalDays + 1) % 7;

        cout << "\nCALENDAR FOR " << year << endl;

        for (int m = 0; m < 12; m++) {
            int days = getDaysInMonth(m + 1, year);

            cout << "\n  ------------ " << months[m] << " ------------" << endl;
            cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

            for (int space = 0; space < currentDay; space++) {
                cout << setw(5) << " ";
            }

            for (int day = 1; day <= days; day++) {
                cout << setw(5) << day;
                currentDay++;
                
                if (currentDay > 6) {
                    currentDay = 0;
                    cout << endl;
                }
            }
            
            if (currentDay != 0) cout << endl;
        }
    }

    return 0;
}