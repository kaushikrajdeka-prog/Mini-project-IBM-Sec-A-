/*Question 1: The Mathematician’s Number Challenge

Problem Story:
Riya, a young mathematician, loves playing with numbers. One day, she picks a number and wants to check two things:

Whether the number is prime or not.

Whether it is even or odd.
She wants your help to write a program that tells her both answers.
Task:
Write a program that takes an integer as input and:

Checks if it is a prime number or not.

Checks whether it is even or odd.

Input Format:
The first line contains one integer — the number to check.

Output Format:
Print two lines:
First line: "Prime Number" or "Not Prime"
Second line: "Even Number" or "Odd Number"


Example 1:
Input: 7
Output:
Prime Number
Odd Number

Example 2:
Input: 10
Output:
Not Prime
Even Number*/

#include <iostream>
using namespace std;

int main()
{
    int num;

    cout << "Enter your number :";
    cin >> num;

    if (num <= 1)
    {
        cout << num << " is Not a Prime number." << endl;
    }
    else
    {
        int i;
        for (i = 2; i <= num / 2; i++)
        {
            if (num % i == 0)
            {
                cout << num << " is Not a Prime number." << endl;
                break;
            }
        }

        if (i > num / 2)
        {
            cout << num << " is a Prime number." << endl;
        }
    }

    if (num % 2 == 0)
        cout << "Even number" << endl;
    else
        cout << "Odd number" << endl;

    return 0;
}
