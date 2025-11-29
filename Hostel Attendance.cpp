/* HOSTEL ATTENDANCE TRACKER 
Assam Down Town University maintains a strict hostel monitoring system to ensure student safety.
Every hostel student must mark attendance daily.
The warden keeps attendance for 7 days (Monday to Sunday) for 10 students.

The attendance is stored in a 2D array A[10][7], where:
A[i][j] = 1 → Student i was Present on Day j

A[i][j] = 0 → Student i was Absent on Day j

Here:

i = Student number (1 to 10)

j = Day number (1 to 7)

The warden wants a weekly summary of attendance.

Your Task: Write the algorithm or C program to do the following:
(a) Calculate and print the total number of days each student was present.

Total present days = sum of each row.

(b) Identify the student who has the highest attendance in the week.

If two students have the same highest attendance, print the one with the lower student number.

Find the day (1–7) on which overall hostel attendance was the lowest.

Total attendance on a day = sum of each column.
Input :
1 1 0 1 1 0 1
1 0 1 1 1 1 1
0 1 1 0 1 1 0
1 1 1 1 0 1 1
1 0 1 0 1 0 1
0 0 1 1 1 1 1
1 1 0 0 0 1 1
1 1 1 1 1 0 0
0 1 1 1 1 1 1
1 0 0 1 1 1 1

Output:
Weekly Attendance Summary
-------------------------

Total Present Days:
Student 1: 5
Student 2: 6
Student 3: 4
Student 4: 6
Student 5: 4
Student 6: 5
Student 7: 5
Student 8: 5
Student 9: 6
Student 10: 5

Student with Highest Attendance: Student 2 (6 Days)

Day with Lowest Overall Attendance: Day 2 */



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
