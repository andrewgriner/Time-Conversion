/*
Andrew Griner
6/12/2023
This is a time clock that converts military time to 12 hour AM/PM system
*/
#include <iostream>
#include <string>

using namespace std;

// Function to input the time from the user
void input_time(int& hour, int& minute) {
    string time;
    cout << "Enter 24-hour time in the format HH:MM: \n";
    cin >> time;
    size_t colonIndex = time.find(":");
    if (colonIndex != string::npos) {
        hour = stoi(time.substr(0, colonIndex));  // Extract the hour component and convert it to an integer
        minute = stoi(time.substr(colonIndex + 1));  // Extract the minute component and convert it to an integer
    }
    else {
        hour = -1;  // Invalid hour
        minute = -1;  // Invalid minute
    }
}

// Function to convert the time from 24-hour format to 12-hour format
void convert_time(int hour, int minute, int& converted_hour, char& am_pm) {
    if (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59) {  // Check if the hour and minute values are within valid ranges
        if (hour == 0) {
            converted_hour = 12;  // Convert 0 hour to 12-hour format
            am_pm = 'A';  // Set the AM indicator
        }
        else if (hour < 12) {
            converted_hour = hour;  // Keep hours before 12 as is
            am_pm = 'A';  // Set the AM indicator
        }
        else if (hour == 12) {
            converted_hour = 12;  // Keep 12 hour as is
            am_pm = 'P';  // Set the PM indicator
        }
        else {
            converted_hour = hour - 12;  // Convert hours greater than 12 to 12-hour format
            am_pm = 'P';  // Set the PM indicator
        }
    }
    else {
        converted_hour = -1;  // Invalid converted hour
        am_pm = ' ';  // Invalid AM/PM indicator
    }
}

// Function to output the converted time
void output_time(int hour, int minute, int converted_hour, char am_pm) {
    if (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59 && converted_hour >= 0) {  // Check if the input time and converted time are valid
        cout << "Time in 12-hour format:" << endl;
        cout << converted_hour << ":" << minute << " ";
        if (am_pm == 'A') {
            cout << "AM" << endl;
        }
        else {
            cout << "PM" << endl;
        }
    }
    else {
        cout << "Invalid time format." << endl;  // Display an error message for invalid time format
    }
}

int main() {
    int hour, minute, converted_hour;
    char am_pm;
    char choice = 'y';

    while (tolower(choice) == 'y') {
        input_time(hour, minute);  // Get the input time from the user
        convert_time(hour, minute, converted_hour, am_pm);  // Convert the time to 12-hour format
        output_time(hour, minute, converted_hour, am_pm);  // Output the converted time

        cout << "Enter Y or y to continue, anything else quits: " << endl;
        cin >> choice;  // Prompt for continuation
    }

    return 0;
}
