#include <iostream>
using namespace std;

void doubleDigits(int id);
int sumOfDoubleDigits(int id);

int main()
{
    string studentId = "BC123456789";

    // stoi() converts a string to an integer and substr() returns a substring of the given string.
    int numericalId = stoi(studentId.substr(2, 9));

    cout << "The given student ID is " << studentId << endl;
    cout << "Given Student ID digits part is " << numericalId << endl;

    doubleDigits(numericalId);

    int sum = sumOfDoubleDigits(numericalId);
    cout << "Sum of Separated Digits: " << sum << endl;

    return 0;
}

// This function takes an integer id and prints the separated digits of the id after doubling them.
void doubleDigits(int id)
{
    int digit = 0;
    while (id > 0)
    {
        digit = id % 10;
        cout << "Separated digits doubled : " << digit * 2 << endl;
        id = id / 10;
    }
}

// This function takes an integer id and returns the sum of the separated digits after doubling them.
int sumOfDoubleDigits(int id)
{
    int sum = 0;
    int digit = 0;
    while (id > 0)
    {
        digit = id % 10;
        sum += digit * 2;
        id = id / 10;
    }
    return sum;
}