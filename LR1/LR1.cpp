#include <iostream>
#include <iomanip>
#include <ios>
#include <vector>
#include <string>

void printVector(std::vector<double>& numbers);

void calculateSumAndAverage(std::vector<double>& numbers) {
    float sum = 0;
    int size = numbers.size();

    for (int i = 0; i < size; i++)
        sum += numbers.at(i);

    numbers.push_back(sum);
    numbers.push_back(sum / size);
    printVector(numbers);
}

void multiplyBySmallest(std::vector<double>& numbers) {
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

void printVector(std::vector<double>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << ' ';
    }
    std::cout << "\n";
}

int main() {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(3);

    int capacity = 0;
    int size = 0;
    std::cin >> size;
    capacity = size + 1;

    std::vector<double> numbers;
    numbers.resize(size);
    numbers.reserve(capacity);

    for (int i = 0; i < size; i++) {
        std::cin >> numbers[i];
    }

    std::cout << numbers.size() << "\n";
    printVector(numbers);

    calculateSumAndAverage(numbers);

    multiplyBySmallest(numbers);

    while (true) {
        int choice;
        std::cin >> choice;

        if (choice == 0)
            break;

        if (choice == 1) {
            float x = 0;
            std::cin >> x;

            numbers.push_back(x);
            std::cout << "+: " << numbers.size() << '\n';
            printVector(numbers);

            calculateSumAndAverage(numbers);

            multiplyBySmallest(numbers);
        };
        if (choice == 2) {
            numbers.pop_back();
            std::cout << "-: " << numbers.size() << '\n';
            printVector(numbers);

            calculateSumAndAverage(numbers);

            multiplyBySmallest(numbers);
        };
    }
    return 0;
}
