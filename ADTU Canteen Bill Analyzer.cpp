/* **Problem Title: ADTU Canteen Bill Analyzer
Story:

At Assam Down Town University (ADTU), the hostel canteen records the daily food expenses of each student.
Each row in a 2D array represents a student, and each column represents a day of the day week (from Monday to Friday).
The value bill[i][j] is the amount in ₹ spent by student i on day j.
You, as the Canteen Manager of ADTU, have been asked to analyze the weekly canteen records.

🧠 Your Tasks:

Given the 2D array bill, write a program to:

Print the total amount spent by each student in the week.

Find the day with the highest total collection.

Identify the student (or students) who spent the most overall.

Input Format:

The first line contains two integers:
n → number of students
m → number of days

The next n lines each contain m integers — the daily bill amounts.

📤 Output Format:

Print each student’s total weekly spending.

Print which day had the highest total collection.

Print which student(s) spent the most overall.
Input :
4 5
30 40 50 60 20
10 20 30 10 40
50 60 40 30 20
20 10 10 20 30

Output:

Student 1 total: ₹200  
Student 2 total: ₹110  
Student 3 total: ₹200  
Student 4 total: ₹90  

Highest collection on Day 2  
Highest spender: Student 1 and Student 3 */


#include <iostream>
using namespace std;

int main() {
    const int STUDENTS = 10;
    const int DAYS = 7;
    int A[STUDENTS][DAYS];

    cout << "Enter attendance (1 for Present, 0 for Absent):\n";
    for (int i = 0; i < STUDENTS; i++) {
        for (int j = 0; j < DAYS; j++) {
            cin >> A[i][j];
        }
    }

    int totalPresent[STUDENTS] = {0};
    int totalDay[DAYS] = {0};

    for (int i = 0; i < STUDENTS; i++) {
        for (int j = 0; j < DAYS; j++) {
            totalPresent[i] += A[i][j]; 
            totalDay[j] += A[i][j];     
        }
    }

    int highestStudent = 0;
    int highestDays = totalPresent[0];
    for (int i = 1; i < STUDENTS; i++) {
        if (totalPresent[i] > highestDays) {
            highestDays = totalPresent[i];
            highestStudent = i;
        }
    }

    int lowestDay = 0;
    int lowestCount = totalDay[0];
    for (int j = 1; j < DAYS; j++) {
        if (totalDay[j] < lowestCount) {
            lowestCount = totalDay[j];
            lowestDay = j;
        }
    }

    cout << "\nWeekly Attendance Summary\n";
    cout << "-------------------------\n\n";

    cout << "Total Present Days:\n";
    for (int i = 0; i < STUDENTS; i++) {
        cout << "Student " << i + 1 << ": " << totalPresent[i] << endl;
    }

    cout << "\nStudent with Highest Attendance: Student "
         << highestStudent + 1 << " (" << highestDays << " Days)" << endl;

    cout << "\nDay with Lowest Overall Attendance: Day "
         << lowestDay + 1 << endl;

    return 0;
}
