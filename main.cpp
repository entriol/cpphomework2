#include <iostream>
#include <cmath>

using namespace std;

// I used long int's, long doubles. Otherwise, result is going to be out of range.
long int factorial(long int n) {
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

double calculate (int base) {
    int exponent = 1;
    long double	 result = 1;
    while (result > 0.000001) {
        exponent++;
        result = pow(base, exponent)/factorial(exponent);
    }
    // This one, calculated biggest x^n/n! just less than 1e-6

    // From here, I'm calculating x^0/0!+x^1/1!+x^2/2!+...+x^n/n!
    long double numerator = 1;
    long double denominator = 1;

    long double total = (numerator / denominator);
    for (int i = 1; i <= exponent -1; ++i) { // I subtracted -1 from exponent to make last item bigger than 1e-6, but not less than.
        numerator *= base; // x^i
        denominator *= i; // i!
        total += (numerator / denominator);
    }

    return total;
}

int main() {
    bool valid= false; // A value to keep validity flag for user input.
    double input = -1;

    while (!valid) {
        cout << "Enter a number: " << endl;
        cin >> input;

        if (input <= 10 && input >= -10) {
            valid = true;
            cout << "Result: " << calculate(input) << endl;
        } else {
            valid = false;
            cout << "Please provide a number between [10, -10]!!!" << endl;
        }
    }

    std::cout << "Calculated :)" << std::endl;
    return 0;
}