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


void taylor() {
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
}

void crypto() {


    int method;
    cout<< "Input (1) to encrypt number:" << endl;
    cout<< "Input (2) to decrypt number:" << endl;
    cout<< "-------------------------------------:" << endl;
    cout<< "Please give a number between [1, 2]:" << endl;
    cin>>method;

    int input, n1,n2,n3,n4;

    switch(method){
        case 1:
            cout << "Enter a four digit integer: " << endl;
            cin >> input;

            // TO DO: Make it array, and do array map.

            n4 = input%10;
            input /= 10;
            n3 = input%10;
            input /= 10;
            n2 = input%10;
            input /= 10;
            n1 = input%10;
            input /=10;

            if (n1+7 > 9) {
                n1 = (n1+7)%10;
            } else {
                n1 = n1+7;
            }

            if (n2+7 > 9) {
                n2 = (n2+7)%10;
            } else {
                n2 = n2+7;
            }

            if (n3+7 > 9) {
                n3 = (n3+7)%10;
            } else {
                n3 = n3+7;
            }

            if (n4+7 > 9) {
                n4 = (n4+7)%10;
            } else {
                n4 = n4+7;
            }

            cout << "Encrypted value of your input: " << n3 << n4 << n1 << n2 << endl;

            break;
        case 2:
            cout << "Enter a four digit integer to decrypt: " << endl;
            cin >> input;

            n4 = input%10;
            input /= 10;
            n3 = input%10;
            input /= 10;
            n2 = input%10;
            input /= 10;
            n1 = input%10;
            input /=10;

            if (n1-7 < 1) {
                n1 = (n1-7)+10;
            } else {
                n1 = n1-7;
            }

            if (n2-7 < 1) {
                n2 = (n2-7)+10;
            } else {
                n2 = n2-7;
            }

            if (n3-7 < 1) {
                n3 = (n3-7)+10;
            } else {
                n3 = n3-7;
            }

            if (n4-7 < 1) {
                n4 = (n4-7)+10;
            } else {
                n4 = n4-7;
            }
            cout << "Decrypted value of your input: " << n3 << n4 << n1 << n2 << endl;
            break;
        default : //Optional
            cout << "I don't think we can serve that option";
    }
}

int main() {
    int selection;
    cout<< "Input (1) to calculate Taylor Series:" << endl;
    cout<< "Input (2) to run Cryptography Program:" << endl;
    cout<< "Input (3) to asteriks patterns:" << endl;
    cout<< "-------------------------------------:" << endl;
    cout<< "Please give a number between [1, 3]:" << endl;
    cin>>selection;

    switch(selection){
        case 1:
            taylor();
            break;
        case 2:
            crypto();
            break;

        case 3:
            // asteriks();
            break;
        default : //Optional
            cout << "I don't think we can serve that option";
    }


    return 0;
}