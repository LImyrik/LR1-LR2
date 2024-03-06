#include <iostream>
#include <iomanip>
#include <ios>
#include <vector>
#include <string>
using namespace std;

void printVector(vector<double>& numbers);

void calculateSumAndAverage(vector<double>& numbers) {
    float sum = 0;
    int size = numbers.size();

    for (int i = 0; i < size; i++)
        sum += numbers.at(i);

    numbers.push_back(sum);
    numbers.push_back(sum / size);
    printVector(numbers);
}

void multiplyBySmallest(vector<double>& numbers) {
    float min = numbers[0];

    for (int i = 0; i < numbers.size(); i++) {
        min = numbers[i];
    }
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] > 0) {
            numbers[i] *= min;
        }
    }
    printVector(numbers);
}

void printVector(vector<double>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << ' ';
    }
    cout << "\n";
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(3);

    int capacity = 0;
    int size = 0;
    cin >> size;
    capacity = size + 1;

    vector<double> numbers;
    numbers.resize(size);
    numbers.reserve(capacity);

    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    cout << numbers.size() << "\n";
    printVector(numbers);

    calculateSumAndAverage(numbers);

    multiplyBySmallest(numbers);

    while (true) {
        int choice;
        cin >> choice;

        if (choice == 0)
            break;

        if (choice == 1) {
            float x = 0;
            cin >> x;

            numbers.push_back(x);
            cout << "+: " << numbers.size() << '\n';
            printVector(numbers);

            calculateSumAndAverage(numbers);

            multiplyBySmallest(numbers);
        };
        if (choice == 2) {
            numbers.pop_back();
            cout << "-: " << numbers.size() << '\n';
            printVector(numbers);

            calculateSumAndAverage(numbers);

            multiplyBySmallest(numbers);
        };
    }
    return 0;
}
