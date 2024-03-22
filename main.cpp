/// File: main.cpp
/// This class provides the main menu for the swimming lessons booking system


#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <limits>
#include "Schedule.h"

using namespace std;

// Function prototypes of several helper methods used in the main menu
void displayProgramName(); // Function to display the program name
void displayMainMenu(); // Function to display the main menu
void displayInstructors(); // Function to display instructor options
void displayDaysOptions(); // Function to display day options
void displayTimeOptions(); // Function to display time options
int getMenu(); // Function to prompt the user a menu selection
int getInstructor(); // Function to prompt the user  instructor selection
int getDay(); // Function to prompt the user a day selection
int getTime(); // Function to prompt the user a time selection
void displayDetails(int instructor, int day, int time); // Function to display confirmation details
int confirmDetails(int instructor, int day, int time); // Function to prompt the user a confirmation
int confirmClearSchedule(); // Function to prompt the user a confirmation to clear all the schedule
void displayBookedTimeSlotMessage(); // Function to display an error message if the selected time slot is booked
void diaplayFreeTimeSlotMessage(); // Function to display an error message if the selected time slot is still available
void backToMainMenu(); // Function to clear the terminal screen
void displayContinueMessage(); // Function to prompt the user for any input to continue
void displayErrorMessage(); // Function to display an error message for invalid inputs

int main() {

    Schedule schedule;
    int menuOption;
    int instructorOption;
    int preferredDay;
    int preferredTime;
    int confirmation;

    do {
        displayMainMenu();
        menuOption = getMenu();
        switch (menuOption) {
        case (1):
            instructorOption = getInstructor();
            if (instructorOption == 0) {
                backToMainMenu();
                break;
            }
            preferredDay = getDay();
            if (preferredDay == 0) {
                backToMainMenu();
                break;
            }
            preferredTime = getTime();
            if (preferredTime == 0) {
                backToMainMenu();
                break;
            }
            if (schedule.getInstructorTimeSlot(instructorOption, preferredDay, preferredTime) == true) {
                displayBookedTimeSlotMessage();
                break;
            }
            confirmation = confirmDetails(instructorOption, preferredDay, preferredTime);
            if (confirmation == 2) {
                backToMainMenu();
                break;
            }
            schedule.bookSwimmingLesson(instructorOption, preferredDay, preferredTime);
            displayContinueMessage();
            break;
        case (2):
            instructorOption = getInstructor();
            if (instructorOption == 0) {
                backToMainMenu();
                break;
            }
            preferredDay = getDay();
            if (preferredDay == 0) {
                backToMainMenu();
                break;
            }
            preferredTime = getTime();
            if (preferredTime == 0) {
                backToMainMenu();
                break;
            }
            if (schedule.getInstructorTimeSlot(instructorOption, preferredDay, preferredTime) == false) {
                diaplayFreeTimeSlotMessage();
                break;
            }
            confirmation = confirmDetails(instructorOption, preferredDay, preferredTime);
            if (confirmation == 2) {
                backToMainMenu();
                break;
            }
            schedule.cancelSwimmingLesson(instructorOption, preferredDay, preferredTime);
            displayContinueMessage();
            break;
        case (3):
            instructorOption = getInstructor();
            if (instructorOption == 0) {
                backToMainMenu();
                break;
            }
            system("CLS");
            schedule.displayInstructorSchdule(instructorOption);
            displayContinueMessage();
            break;
        case (4):
            schedule.fillOverallSchedule();
            schedule.displayOverallSchedule();
            displayContinueMessage();
            break;
        case (5):
            confirmation = confirmClearSchedule();
            if (confirmation == 2) {
                backToMainMenu();
                break;
            }
            schedule.clearSchedule();
            displayContinueMessage();
            break;
        }
    } while (menuOption != 0);

    return 0;
}

/// \brief
/// Displays program name
void displayProgramName() {

    cout << "\t\t__________________________________________" << endl << endl;
    cout << "\t\t\tSWIMMING LESSONS BOOKING" << endl;
    cout << "\t\t__________________________________________" << endl << endl;
}

/// \brief
/// Displays main menu
void displayMainMenu() {

    displayProgramName();
    cout << endl;
    cout << "\t\t\t\tMAIN MENUS" << endl << endl;
    cout << "\t\t1) Book a swimming lesson" << endl;
    cout << "\t\t2) Cancel a swimming lesson" << endl;
    cout << "\t\t3) Display the current schedule of a swimming instructor" << endl;
    cout << "\t\t4) Display all time slots available for booking" << endl;
    cout << "\t\t5) Clear all the schedule" << endl << endl;
    cout << "\t\tPress 0 to exit the program" << endl << endl;
}

/// \brief
/// Displays instructors
void displayInstructors() {

    cout << endl;
    cout << "\tLIST OF SWIMMING INSTRUCTORS" << endl << endl;
    cout << "\t1) Jeff" << endl;
    cout << "\t2) Anna" << endl;
    cout << "\t3) Peter" << endl;
    cout << "\t4) Michael" << endl;
    cout << "\t5) Kerry" << endl << endl;
    cout << "\tPress 0 to go back the main menu." << endl << endl;
}

/// \brief
/// Displays day options
void displayDaysOptions() {

    cout << endl;
    cout << "\tDAYS OPTIONS" << endl << endl;
    cout << "\t1) Monday" << endl;
    cout << "\t2) Tuesday" << endl;
    cout << "\t3) Wednesday" << endl;
    cout << "\t4) Thursday" << endl;
    cout << "\t5) Friday" << endl << endl;
    cout << "\tPress 0 to go back the main menu." << endl << endl;

}

/// \brief
/// Displays time options
void displayTimeOptions() {

    cout << endl;
    cout << "\tTIME OPTIONS" << endl << endl;
    cout << "\t1) 9am  - 10am" << endl;
    cout << "\t2) 10am - 11am" << endl;
    cout << "\t3) 11am - 12am" << endl;
    cout << "\t4) 1pm  - 2pm" << endl;
    cout << "\t5) 2pm  - 3pm" << endl;
    cout << "\t6) 3pm  - 4pm" << endl;
    cout << "\t7) 4pm  - 5pm" << endl << endl;
    cout << "\tPress 0 to go back the main menu." << endl << endl;

}

/// \brief
/// Prompts the user a menu selection
///
/// \return int - a menu selected by user
int getMenu() {

    int menu;

    do {
        cout << "\t\tSelect a menu (options 1-5): ";
        cin >> menu;

        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << "\t\tSelect a menu (options 1-5): ";
            cin >> menu;
        }

        if (menu < 0 || menu > 5) {
            displayErrorMessage();
        }
    } while (menu < 0 || menu > 5);

    system("CLS");

    return menu;
}

/// \brief
/// Prompts the user an instructor selection
///
/// \return int - an instructor selected by user
int getInstructor() {

    int instructor;

    displayInstructors();

    do {
        cout << "\tSelect an instructor (options 1-5): ";
        cin >> instructor;

        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << "\tSelect an instructor (options 1-5): ";
            cin >> instructor;
        }

        if (instructor < 0 || instructor > 5) {
            displayErrorMessage();
        }
    } while (instructor < 0 || instructor > 5);

    return instructor;
}

/// \brief
/// Prompts the user a day selection
///
/// \return int - a day selected by user
int getDay() {

    int day;

    displayDaysOptions();

    do {
        cout << "\tEnter a day (options 1-5): ";
        cin >> day;

        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << "\tEnter a day (options 1-5): ";
            cin >> day;
        }

        if (day < 0 || day > 5) {
            displayErrorMessage();
        }
    } while (day < 0 || day > 5);

    return day;
}

/// \brief
/// Prompts the user a time selection
///
/// \return int - a time selected by user
int getTime() {

    int time;

    displayTimeOptions();

    do {
        cout << "\tEnter a lesson duration (options 1-7): ";
        cin >> time;

        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << "\tEnter a lesson duration (options 1-7): ";
            cin >> time;
        }

        if (time < 0 || time > 7) {
            displayErrorMessage();
        }
    } while (time < 0 || time > 7);

    return time;
}

/// \brief
/// Displays details for confirmation
///
/// \param instructor int - selected instructor
/// \param day int - preferred day
/// \param time int - preferred time
void displayDetails(int instructor, int day, int time) {

    const string INSTRUCTORS[] = {"Jeff", "Anna", "Peter", "Michael", "Kerry"};
    const string DAYS[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    const string TIMES[] = {"9am - 10am", "10am - 11am", "11am - 12am", "1pm - 2pm",
                      "2pm - 3pm", "3pm - 4pm", "4pm - 5pm"};

    cout << endl << "\tDETAILS CONFIRMATION" << endl << endl;
    cout << "\tInstructor: " << INSTRUCTORS[instructor-1] << endl;
    cout << "\tDay: " << DAYS[day-1] << endl;
    cout << "\tTime: " << TIMES[time-1] << endl;
}

/// \brief
/// prompts the user a confirmation for booking and cancellation
///
/// \param instructor int - selected instructor
/// \param day int - preferred day
/// \param time int - preferred time
/// \return int - user confirmation
int confirmDetails(int instructor, int day, int time) {

    int confirm;

    system("CLS");
    displayDetails(instructor, day, time);

    do {
        cout << endl << "\t1) Confirm" << endl;
        cout << "\t2) Cancel (back to the main menu)" << endl;
        cout << endl << "\tEnter an option: ";
        cin >> confirm;

        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << endl << "\t1) Confirm" << endl;
            cout << "\t2) Cancel (back to the main menu)" << endl;
            cout << endl << "\tEnter an option: ";
            cin >> confirm;
        }

        if (confirm < 1 || confirm > 2) {
            displayErrorMessage();
        }
    } while (confirm < 1 || confirm > 2);

    return confirm;
}

/// \brief
/// prompt the user a confirmation to clear all the schedules
///
/// \return int - user confirmation
int confirmClearSchedule() {

    int confirm;

    system("CLS");

    do {
        cout << endl << "\tWould you like to clear all the schedule?" << endl;
        cout << endl << "\t1) Confirm" << endl;
        cout << "\t2) Cancel (back to the main menu)" << endl;
        cout << endl << "\tEnter an option: ";
        cin >> confirm;

        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayErrorMessage();
            cout << endl << "\tWould you like to clear all the schedule?" << endl;
            cout << endl << "\t1) Confirm" << endl;
            cout << "\t2) Cancel (back to the main menu)" << endl;
            cout << endl << "\tEnter an option: ";
            cin >> confirm;
        }

        if (confirm < 1 || confirm > 2) {
            displayErrorMessage();
        }
    } while (confirm < 1 || confirm > 2);

    return confirm;
}

/// \brief
/// Displays a message if a particular time slot is already booked
void displayBookedTimeSlotMessage() {

    cout << endl << "\tThe selected time is unavailable." << endl;
    cout << "\tPlease change the day or time for your reservation." << endl << endl;
    cout << "\tPress any key to go back to the main menu..." << endl << endl;
    getch();
    backToMainMenu();
}

/// \brief
/// Displays a message if a particular time slot is still available
void diaplayFreeTimeSlotMessage() {

    cout << endl << "\tThe selected time is still available." << endl;
    cout << "\tPlease change the time for your cancellation." << endl << endl;
    cout << "\tPress any key to go back to the main menu..." << endl << endl;
    getch();
    backToMainMenu();
}

/// \brief
/// Clears the terminal
void backToMainMenu() {

    system("CLS");
}

/// \brief
/// Displays a continuity message and wait until user presses any key
void displayContinueMessage() {

    cout << endl << "\tPress any key to continue..." << endl << endl;
    getch();
    backToMainMenu();
}

/// \brief
/// Displays an error message for invalid input
void displayErrorMessage() {

    cout << endl << "\tERROR: Invalid Input." << endl << endl;
}

