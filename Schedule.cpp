/// File: Schedule.cpp
/// This class implements the functions for modeling swimming lesson schedules



#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include "Schedule.h"

using namespace std;

const string NAMES_OF_INSTUCTORS[] = {"Jeff", "Anna", "Peter", "Michael", "Kerry"};
const string ABBREVIATIONS[] = {"J", "A", "P", "M", "K"};
const string EMPTY_STRING = "";

/// Constructor of the Schedule class
Schedule::Schedule() {

    initialiseInstructorsAndSchedules();
    initialiseOverallSchedule();
}

/// Destructor of the Schedule class
Schedule::~Schedule() {

}

/// \brief
/// Helper method to initialise the arrays of instructor
/// and instructors' Schedules
void Schedule::initialiseInstructorsAndSchedules() {

    for (int i = 0; i < NUMBER_OF_INSTRUCTORS; i++) {
        for (int j = 0; j < TIME_SLOTS; j++) {
            for (int k = 0; k < WORKING_DAYS; k++) {
                _instructors[i][j][k] = false;
                _instructorSchedule[i][j][k] = EMPTY_STRING;
            }
        }
    }
}

/// \brief
/// Helper method to initialise the arrays of overall schedule
/// This method is also used when clearing the schedule
void Schedule::initialiseOverallSchedule() {

    for (int i = 0; i < TIME_SLOTS; i++) {
        for (int j = 0; j < WORKING_DAYS; j++) {
        _overallSchedule[i][j] = EMPTY_STRING;
        }
    }
}

/// \brief
/// Getter for an instructor's time slot
bool Schedule::getInstructorTimeSlot(int instructor, int day, int time) {

    return _instructors[instructor-1][time-1][day-1];
}

/// \brief
/// Books a swimming lesson for a member
///
/// \param instructor int - selected instructor
/// \param day int - preferred day
/// \param time int - preferred time
void Schedule::bookSwimmingLesson(int instructor, int day, int time) {

    _instructors[instructor-1][time-1][day-1] = true;
    _instructorSchedule[instructor-1][time-1][day-1] = "x";
}

/// \brief
/// Cancels a swimming lesson for a member
///
/// \param instructor int - selected instructor
/// \param day int - preferred day
/// \param time int - preferred time
void Schedule::cancelSwimmingLesson(int instructor, int day, int time) {

    _instructors[instructor-1][time-1][day-1] = false;
    _instructorSchedule[instructor-1][time-1][day-1] = EMPTY_STRING;
}

/// \brief
/// Displays an instructor's current schedule
///
/// \param instructor int - selected instructor
void Schedule::displayInstructorSchdule(int instructor) {

    string instructorName = NAMES_OF_INSTUCTORS[instructor-1];
    int timeSystem = 12;
    int time = 9;

    cout << endl;
    cout << setw(30) << instructorName << "'s Current Schedule" << endl << endl;
    cout << "\t____________________________________________________________" << endl << endl;
    cout << setw(14) << instructorName << setw(10) << "Monday" << setw(10) << "Tuesday"
         << setw(12) << "Wednesday" << setw(11) << "Thursday" << setw(9) << "Friday" << endl;
    cout << "\t____________________________________________________________" << endl << endl;

    for (int i = 0; i < TIME_SLOTS; i++) {
        if (time == timeSystem-1) {
            cout << setw(10) << (time % timeSystem) << "-" << ((time+1)) << setw(8);
        } else {
            if (time % timeSystem < timeSystem/2) {
                cout << setw(11) << (time % timeSystem) << "-" << ((time+1) % timeSystem) << setw(8);
            } else {
                cout << setw(10) << (time % timeSystem) << "-" << ((time+1) % timeSystem) << setw(8);
            }
        }
        for (int j = 0; j < WORKING_DAYS; j++) {
            if (j > 0) {
                cout << _instructorSchedule[instructor-1][i][j] << setw(11);
            } else {
                cout << _instructorSchedule[instructor-1][i][j] << setw(10);
            }
            if (j == WORKING_DAYS-1) {
                cout << endl;
            }
        }
        time++;
        if (time == 12) {
            time++;
        }
    }
    cout << "\t____________________________________________________________" << endl << endl;
}

/// \brief
/// Displays the overall schedule
void Schedule::displayOverallSchedule() {

    int timeSystem = 12;
    int time = 9;

    cout << endl;
    cout << setw(52) << "All Available Time Slots" << endl << endl;
    cout << "   __________________________________________________________________________" << endl << endl;
    cout << setw(18) << "Monday" << setw(15) << "Tuesday" << setw(15) << "Wednesday" << setw(14)
         << "Thursday" << setw(12) << "Friday" << endl;
    cout << "   __________________________________________________________________________" << endl << endl;

    for (int i = 0; i < TIME_SLOTS; i++) {
        if (time == timeSystem-1) {
            cout << setw(5) << (time % timeSystem) << "-" << ((time+1)) << setw(timeSystem);
        } else {
            if (time % timeSystem < timeSystem/2) {
                cout << setw(6) << (time % timeSystem) << "-" << ((time+1) % timeSystem) << setw(12);
            } else {
                cout << setw(5) << (time % timeSystem) << "-" << ((time+1) % timeSystem) << setw(12);
            }
        }
        for (int j = 0; j < WORKING_DAYS; j++) {
            cout << _overallSchedule[i][j] << setw(14);
            if (j == WORKING_DAYS-1) {
                cout << endl;
            }
        }
        time++;
        if (time == timeSystem) {
            time++;
        }
    }
    cout << "   __________________________________________________________________________" << endl << endl;
}

/// \brief
/// Clears the current schedule
void Schedule::clearSchedule() {

    initialiseInstructorsAndSchedules();
    initialiseOverallSchedule();
}

/// \brief
/// Models the overall schedule
void Schedule::fillOverallSchedule() {

    int **timeCount = getTimeCount();
    initialiseTimeCount(timeCount);

    initialiseOverallSchedule();

    string abbr = EMPTY_STRING;
    string slash = EMPTY_STRING;

    for (int i = 0; i < NUMBER_OF_INSTRUCTORS; i++) {
        abbr = ABBREVIATIONS[i];
        for (int j = 0; j < TIME_SLOTS; j++) {
            for (int k = 0; k < WORKING_DAYS; k++) {
				if (_instructors[i][j][k] == true) {
				    timeCount[j][k]++;
                    if (timeCount[j][k] == NUMBER_OF_INSTRUCTORS) {
                    _overallSchedule[j][k] += "    x    ";
                    }
					_overallSchedule[j][k] += EMPTY_STRING;
				} else if (_instructors[i][j][k] == false) {
					if (_overallSchedule[j][k] == EMPTY_STRING) {
					slash = EMPTY_STRING;
					} else {
					slash = "/";
					}
					_overallSchedule[j][k] += slash + abbr;
				}
            }
        }
    }

    delete[] timeCount;
}

/// \brief
/// Generates the timeCount parameter
/// Using for counting unavailable instructors in each time slot
///
/// \return int** - a pointer to a 2D array used for counting
///         unavailable instructors in each time slot
int** Schedule::getTimeCount() {

    int **timeCount = new int*[TIME_SLOTS];

    for (int i = 0; i < TIME_SLOTS; i++) {
        timeCount[i] = new int[WORKING_DAYS];
    }

    return timeCount;
}

/// \brief
/// Initialises the timeCount parameter
/// Using for counting unavailable instructors in each time slot
void Schedule::initialiseTimeCount(int **timeCount) {

    for (int i = 0; i < TIME_SLOTS; i++) {
        for (int j = 0; j < WORKING_DAYS; j++) {
            timeCount[i][j] = 0;
        }
    }
}
