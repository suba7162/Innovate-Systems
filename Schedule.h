/// File: Schedule.h
/// This class provides several functions for modeling swimming lesson schedules
/// Author: Thanat Chokwijitkul 9234900
/// Date: March, 2015

#include <string>

#ifndef SCHEDULE_H
#define SCHEDULE_H

#define WORKING_DAYS 5
#define TIME_SLOTS 7
#define NUMBER_OF_INSTRUCTORS 5

class Schedule {

    public:
        Schedule(); // Constructor
        ~Schedule(); // Destructor
        bool getInstructorTimeSlot(int instructor, int day, int time); // Function to return an instructor's time slot
        void bookSwimmingLesson(int instructor, int day, int time); // Function to book a swimming lesson
        void cancelSwimmingLesson(int instructor, int day, int time); // Function to cancel a swimming lesson
        void displayInstructorSchdule(int instructor); // Function to display an instructor's schedule
        void displayOverallSchedule(); // Function to display the overall schedule
        void clearSchedule(); // Function to clear all the schedules
        void fillOverallSchedule(); // Function to fill the overall schedule

    private:
        bool _instructors[NUMBER_OF_INSTRUCTORS][TIME_SLOTS][WORKING_DAYS]; // Boolean values of all the schedules
        std::string _instructorSchedule[NUMBER_OF_INSTRUCTORS][TIME_SLOTS][WORKING_DAYS]; // String values of each schedule
        std::string _overallSchedule[TIME_SLOTS][WORKING_DAYS]; // String values of the overall schedule

        // Helper methods
        void initialiseInstructorsAndSchedules(); // Function to initialise _instructors and _instructorSchedules
        void initialiseOverallSchedule(); // Function to initialise _overallSchedule
        int **getTimeCount(); // Function to create the timeCount pointer
        void initialiseTimeCount(int **timeCount); // Function to initialise timeCount

};

#endif // SCHEDULE_H
