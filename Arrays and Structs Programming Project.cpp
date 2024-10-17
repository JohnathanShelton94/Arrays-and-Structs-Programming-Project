//This program rewrites the parallel arrays code using structs.


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

            // Define a struct to store each runner's data
struct Runner {
    string name;
    int miles[7]; // Array to store miles for 7 days
    int totalMiles;
    double avgMiles;
};

            // Function to calculate the total and average miles for each runner
void calculateMiles(Runner runners[], int size) {
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = 0; j < 7; j++) {
            sum += runners[i].miles[j];
        }
        runners[i].totalMiles = sum;
        runners[i].avgMiles = sum / 7.0;
    }
}

            // Function to display the results
void displayResults(Runner runners[], int size) {
    cout << left << setw(10) << "Name" << setw(8) << "Day 1" << setw(8) << "Day 2" << setw(8) << "Day 3"
        << setw(8) << "Day 4" << setw(8) << "Day 5" << setw(8) << "Day 6" << setw(8) << "Day 7"
        << setw(10) << "Total" << setw(10) << "Average" << endl;

    for (int i = 0; i < size; i++) {
        cout << left << setw(10) << runners[i].name;
        for (int j = 0; j < 7; j++) {
            cout << setw(8) << runners[i].miles[j];
        }
        cout << setw(10) << runners[i].totalMiles << setw(10) << runners[i].avgMiles << endl;
    }
}

int main() {
    const int numRunners = 5;           // Number of runners
    Runner runners[numRunners];             // Array of structs

                // Open the file for reading
    ifstream inputFile("runners.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

                // Read the data into the struct array
    for (int i = 0; i < numRunners; i++) {
        inputFile >> runners[i].name;
        for (int j = 0; j < 7; j++) {
            inputFile >> runners[i].miles[j];
        }
    }
    inputFile.close();

                // Calculate total and average miles for each runner
    calculateMiles(runners, numRunners);

                // Display the results
    displayResults(runners, numRunners);

    return 0;
}
