#include <iostream>
#include <vector>
#include <cmath>

class Rand {
public:
    Rand(const std::vector<double>& values) : values_(values) {}

    double calculateMean() {
        double sum = 0.0;
        for (const auto& value : values_) {
            sum += value;
        }
        return sum / values_.size();
    }

    double calculateVariance() {
        double mean = calculateMean();
        double sum = 0.0;
        for (const auto& value : values_) {
            sum += (value - mean) * (value - mean);
        }
        return sum / values_.size();
    }

    double monteCarloIntegration(double (*f)(double), double a, double b, int n) {
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            double x = a + (b - a) * i / (n - 1);
            sum += f(x) * (b - a) / n;
        }
        return sum;
    }

private:
    std::vector<double> values_;
};

double functionToMonteCarlo(double x) {
    // ����� ����� ���������� ���� ������� f(x)
    return x * x;
}

int main() {
    const double M_PI = 3.14;

    // ������ ����������� �������
    int size;
    std::cin >> size;

    // ������ ��������� ������� �������� ���������
    std::vector<double> argumentValues(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> argumentValues[i];
    }

    // ������ ��������� ������� �������� �������
    std::vector<double> functionValues(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> functionValues[i];
    }

    // �������� ������� ������ Rand ��� �������� ���������
    Rand argumentRand(argumentValues);

    // ���������� ��������������� �������� � ��������� ��� �������� ���������
    double argumentMean = argumentRand.calculateMean();
    double argumentVariance = argumentRand.calculateVariance();

    // �������� ������� ������ Rand ��� �������� �������
    Rand functionRand(functionValues);

    // ���������� ��������������� �������� � ��������� ��� �������� �������
    double functionMean = functionRand.calculateMean();
    double functionVariance = functionRand.calculateVariance();

    std::cout << "input= argument ";
    for (int i = 0; i < size; ++i) {
        std::cout << argumentValues[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "function ";
    for (int i = 0; i < size; ++i) {
        std::cout << functionValues[i] << " ";
    }
    std::cout << std::endl;

    // ����� �����������
    std::cout << "MO X= " << argumentMean << " Disp X= " << sqrt(argumentVariance) << std::endl;
    std::cout << "MO Y= " << functionMean << " Disp Y= " << sqrt(functionVariance) << std::endl;

    // ���������� ��������� ������� �����-�����
    double integral = argumentRand.monteCarloIntegration(functionToMonteCarlo, 0.0, M_PI, size);
    std::cout << "MonteKarlo= " << integral << std::endl;

    return 0;
}
