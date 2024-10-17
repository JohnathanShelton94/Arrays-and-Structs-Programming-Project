// This program uses parallel arrays to analyze data from the text file.



#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

            // Function to calculate the total and average miles for each runner
void calculateMiles(int miles[5][7], int totalMiles[], double avgMiles[]) {
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 7; j++) {
            sum += miles[i][j];
        }
        totalMiles[i] = sum;
        avgMiles[i] = sum / 7.0;
    }
}

            // Function to display the results
void displayResults(string names[], int miles[5][7], int totalMiles[], double avgMiles[]) {
    cout << left << setw(10) << "Name" << setw(8) << "Day 1" << setw(8) << "Day 2" << setw(8) << "Day 3"
        << setw(8) << "Day 4" << setw(8) << "Day 5" << setw(8) << "Day 6" << setw(8) << "Day 7"
        << setw(10) << "Total" << setw(10) << "Average" << endl;

    for (int i = 0; i < 5; i++) {
        cout << left << setw(10) << names[i];
        for (int j = 0; j < 7; j++) {
            cout << setw(8) << miles[i][j];
        }
        cout << setw(10) << totalMiles[i] << setw(10) << avgMiles[i] << endl;
    }
}

int main() {
    string names[5];
    int miles[5][7];
    int totalMiles[5];
    double avgMiles[5];

                // Reading the data from the file
    ifstream inputFile("runners.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        inputFile >> names[i];
        for (int j = 0; j < 7; j++) {
            inputFile >> miles[i][j];
        }
    }
    inputFile.close();

                // Calculate total and average miles
    calculateMiles(miles, totalMiles, avgMiles);

                // Display the results
    displayResults(names, miles, totalMiles, avgMiles);

    return 0;
}
