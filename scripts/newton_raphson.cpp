// LANGUAGE: C++
// ENV: vscode
// AUTHOR: nishant gupta
// GITHUB: https://github.com/nishant2253





#include <iostream>
#include <cmath>

double function(double x) {
    return x * x - 4;
}

double derivative(double x) {
    return 2 * x;
}

double newtonRaphson(double initialGuess, double tolerance, int maxIterations) {
    double x0 = initialGuess;
    for (int i = 0; i < maxIterations; i++) {
        double f = function(x0);
        double fPrime = derivative(x0);
        if (std::abs(f) < tolerance) {
            return x0;
        }
        x0 = x0 - f / fPrime;
    }
    return NAN;
}

int main() {
    double initialGuess = 3.0;
    double tolerance = 1e-6;
    int maxIterations = 100;

    double root = newtonRaphson(initialGuess, tolerance, maxIterations);

    if (!std::isnan(root)) {
        std::cout << "Approximate root: " << root << std::endl;
    }

    return 0;
}

