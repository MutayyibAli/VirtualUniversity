#include <iostream>
using namespace std;

int reverseInteger(int id);
int isPrime(int number);

int main()
{
    string studentId = "bc230416175";
    cout << "Student ID : " << studentId << endl;

    // Part 1.
    // Identify the study program by the first two characters of the student ID.
    string alphabeticPart = studentId.substr(0, 2); // substr() returns a substring of the given string.

    if (alphabeticPart == "bc" || alphabeticPart == "BC")
    {
        cout << "Program Name: Bachelors" << endl;
    }
    else if (alphabeticPart == "mc" || alphabeticPart == "MC")
    {
        cout << "Program Name: Masters" << endl;
    }
    else
    {
        cout << "Program Name: Unknown" << endl;
    }

    // Part 2.
    // Reverse the numerical part of the student ID and print the last two digits.
    int numericalPart = stoi(studentId.substr(2, 9)); // stoi() converts a string to an integer.
    int reversedID = reverseInteger(numericalPart);
    cout << "Last two digits of reversed ID: " << reversedID % 100 << endl;

    // Part 3.
    // Check if the last digit of the numerical part of the student ID is prime.
    int lastDigit = numericalPart % 10;
    if (isPrime(lastDigit))
    {
        cout << "Last digit of reversed ID is " << lastDigit << " which is a Prime number." << endl;
    }
    else
    {
        cout << "Last digit of reversed ID is " << lastDigit << " which is not a Prime number." << endl;
    }

    return 0;
}

// This function takes an integer and returns the reversed integer.
int reverseInteger(int id)
{
    int reversedID = 0;
    while (id > 0)
    {
        reversedID = reversedID * 10 + id % 10;
        id = id / 10;
    }
    return reversedID;
}

// This function takes an integer and returns 1 if the integer is prime, otherwise returns 0.
int isPrime(int number)
{
    if (number <= 1)
    {
        return 0;
    }
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }
    return 1;
}