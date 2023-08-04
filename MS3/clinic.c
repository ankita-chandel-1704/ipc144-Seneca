/*
*****************************************************************************
                        Assignment 1 - Milestone 3
Full Name : Ankita Chandel
Student ID#: 161317219
Email : achandel1@myseneca.ca
Section : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"
//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////
// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}
// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ",
            patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}
// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");
    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}
// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);
    displayFormattedPhone(patient->phone.number);
    printf(" (%s)\n", patient->phone.description);
}
//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////
// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu (hub) for application
void menuMain(struct ClinicData* data)
{
    int selection;
    do
    {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}
// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;
    do
    {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}
// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;
    do
    {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ",
            patient->patientNumber, patient->name);
        displayFormattedPhone(patient->phone.number);
        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }
    } while (selection);
}
// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;
    do
    {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data); // ToDo: You will need to create this function !
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data); // ToDo: You will need to create this function !
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient); // ToDo: You will need to create this function !
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient); // ToDo: You will need to create this function !
            suspend();
            break;
        }
    } while (selection);
}
// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------
// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    if (patient)
    {
        int maa;
        displayPatientTableHeader();
        for (maa = 0; maa < max; maa++)
        {
            if (patient[maa].patientNumber != 0)
            {
                displayPatientData(&patient[maa], fmt);
            }
        }
        putchar('\n');
    }
    else
    {
        printf("*** No records found ***\n\n");
    }
}
// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max)
{
    int selection = 0;
    do
    {
        printf("Search Options\n==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 1:
            searchPatientByPatientNumber(patient, max);
            suspend();
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            suspend();
            break;
        }
    } while (selection);
}
// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max)
{
    int maa;
    int width = 0;
    int counter = 0;
    for (maa = 0; maa < max; maa++)
    {
        if (patient[maa].patientNumber != 0)
        {
            width++;
        }
    }
    if (max > width)
    {
        for (maa = 0; maa < width; maa++)
        {
            if (patient[maa].patientNumber == 0)
            {
                counter = maa;
                break;
            }
        }
        patient[counter].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[counter]);
        printf("*** New patient record added ***\n");
    }
    else
    {
        printf("ERROR: Patient listing is FULL!\n");
    }
    putchar('\n');
}
// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max)
{
    int num = 0;
    int counter = 0;
    printf("Enter the patient number: ");
    scanf(" %d", &num);
    clearInputBuffer();
    putchar('\n');
    counter= findPatientIndexByPatientNum(num, patient, max);
    if (counter != -1)
    {
        menuPatientEdit(&patient[counter]);
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}
// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max)
{
    int num = 0;
    char option[30] = { '\0' };
    int counter = 0;
    printf("Enter the patient number: ");
    scanf(" %d", &num);
    clearInputBuffer();
    putchar('\n');
    counter = findPatientIndexByPatientNum(num, patient, max);
    if (counter != -1)
    {
        displayPatientData(&patient[counter], FMT_FORM);
        putchar('\n');
        printf("Are you sure you want to remove this patient record? (y/n): ");
        do
        {
            scanf(" %s", option);
            clearInputBuffer();
            if (strcmp(option, "y") == 0)
            {
                strcpy(patient[counter].name, "\0");
                patient[counter].patientNumber = 0;
                strcpy(patient[counter].phone.description, "\0");
                strcpy(patient[counter].phone.number, "\0");
                printf("Patient record has been removed!\n\n");
            }
            else
            {
                printf("ERROR: Character must be one of [yn]: ");
            }
        } while (strcmp(option, "y") != 0);
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// View ALL scheduled appointments
void viewAllAppointments(struct ClinicData* data)
{
    int a = 0, b = 0;
    int quantity = 0;
    //Calculate the size of the appoiment array
    quantity = calculateSizeOfAppointmentsArray(data->appointments, data->maxAppointments);
    //Sorting the appointment
    sortingAppoint(data->appointments, quantity);
    if (data)
    {
        displayScheduleTableHeader(&data->appointments->date, IS_ALL);
        for (a= 0; a < data->maxAppointments; a++)
        {
            for (b= 0; b < data->maxPatient; b++)
            {
                if (data->appointments[a].patientNumber == data->patients[b].patientNumber)
                {
                    displayScheduleData(&data->patients[b], &data->appointments[a], IS_ALL);
                    break;
                }
            }
        }
        putchar('\n');
    }
    else
    {
        printf("*** No records found ***\n\n");
    }
}
// View appointment schedule for the user input date
void viewAppointmentSchedule(struct ClinicData* data)
{
    int a, b;
    int quantity = 0;
    struct Date userInput = { '\0' };
    //Prompt user to enter date and validate them
    checkLeapYear(&userInput);
    putchar('\n');
    //Calculate the size of the appoinment array
    quantity = calculateSizeOfAppointmentsArray(data->appointments, data->maxAppointments);
    displayScheduleTableHeader(&userInput, NOT_ALL);
    for (a = 0; a < quantity; a++)
    {
        //Find the exact date
        if (userInput.year == data->appointments[a].date.year &&
            userInput.month == data->appointments[a].date.month && userInput.day == data->appointments[a].date.day)
        {
            for (b = 0; b < quantity; b++)
            {
                if (data->appointments[a].patientNumber == data->patients[b].patientNumber)
                {
                    displayScheduleData(&data->patients[b], &data->appointments[a], NOT_ALL);
                }
            }
        }
    }
    putchar('\n');
}
// Add an appointment record to the appointment array
void addAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatient)
{
    int a;
    int quantity = 0;
    int f = 1;
    //Calculate the size of the array
    quantity = calculateSizeOfAppointmentsArray(appointments, maxAppointments);
    //Execute if there is available element
    if (maxAppointments > quantity)
    {
        printf("Patient Number: ");
        scanf(" %d", &appointments[quantity].patientNumber);
        clearInputBuffer();
        //Check if there is patient with provied patient number
        if (findPatientIndexByPatientNum(appointments[quantity].patientNumber,
            patients, maxPatient) != -1)
        {
            do
            {
                int duplicate = 0;
                checkLeapYear(&appointments[quantity].date);
                do
                {
                    printf("Hour (0-23)  : ");
                    appointments[quantity].time.hour = inputIntRange(0, 23);
                    printf("Minute (0-59): ");
                    appointments[quantity].time.min = inputIntRange(0, 59);
                    //Check if there is any appoinment with the same time and date
                    for (a = 0; a < quantity; a++)
                    {
                        if (appointments[quantity].date.year ==
                            appointments[a].date.year &&
                            appointments[quantity].date.month ==
                            appointments[a].date.month &&
                            appointments[quantity].date.day ==
                            appointments[a].date.day &&
                            appointments[quantity].time.hour ==
                            appointments[a].time.hour &&
                            appointments[quantity].time.min ==
                            appointments[a].time.min)
                        {
                            printf("\nERROR: Appointment timeslot is not available!\n\n");
                            duplicate = 1;
                        }
                    }
                    //Execute if there is no duplicate
                    if (duplicate == 0)
                    {
                        if (appointments[quantity].time.hour >= START_HOUR && appointments[quantity].time.hour <= END_HOUR)
                        {
                            if (appointments[quantity].time.min >=
                                START_MIN &&
                                appointments[quantity].time.min <= END_MIN)
                            {
                                printf("\n*** Appointment scheduled! ***\n\n");
                                f = 0;
                                break;
                            }
                            else
                            {
                                printf("ERROR: Time must be between 10:00 and 14:00 in %d minute intervals.\n\n", MINUTE_INTERVAL);
                            }
                        }
                        else
                        {
                            printf("ERROR: Time must be between 10:00 and 14:00 in %d minute intervals.\n\n", MINUTE_INTERVAL);
                        }
                    }
                } while (duplicate == 0);
            } while (f == 1);
        }
        else
        {
            printf("\nERROR: Patient record not found!\n\n");
        }
    }
}
// Remove an appointment record from the appointment array
void removeAppointment(struct Appointment* appointments, int maxAppointments,
    struct Patient* patients, int maxPatient)
{
    int counter;
    char option;
    int a;
    struct Appointment removeAppm = { 0 };
    int quantity = 0;
    //Calculate the size of the appoinment array
    quantity = calculateSizeOfAppointmentsArray(appointments, maxAppointments);
    //Sorting appointments
    sortingAppoint(appointments, quantity);
    printf("Patient Number: ");
    scanf(" %d", &removeAppm.patientNumber);
    clearInputBuffer();
    counter = findPatientIndexByPatientNum(removeAppm.patientNumber, patients,
        maxPatient);
    if (counter != -1)
    {
        checkLeapYear(&removeAppm.date);
        putchar('\n');
        displayPatientData(&patients[counter], FMT_FORM);
        printf("Are you sure you want to remove this appointment (y,n): ");
        scanf(" %c", &option);
        clearInputBuffer();
        if (option == 'y')
        {
            //Find the index of the appointment in array by date
            for (a = 0; a < maxAppointments; a++)
            {
                if (removeAppm.patientNumber ==
                    appointments[a].patientNumber &&
                    removeAppm.date.day == appointments[a].date.day &&
                    removeAppm.date.month == appointments[a].date.month && removeAppm.date.year == appointments[a].date.year)
                {
                    counter = a;
                    break;
                }
            }
            //Removing the appointment
            appointments[counter].patientNumber = 0;
            appointments[counter].date.day = 0;
            appointments[counter].date.month = 0;
            appointments[counter].date.year = 0;
            appointments[counter].time.hour = 0;
            appointments[counter].time.min = 0;
            printf("\nAppointment record has been removed!\n\n");
        }
        else
        {
            printf("Operation aborted.\n\n");
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}
//Calculate the size of the appointments array
int calculateSizeOfAppointmentsArray(const struct Appointment* appointments, int
    maxAppointment)
{
    int quantity = 0;
    int a;
    for (a = 0; a < maxAppointment; a++)
    {
        if (appointments[a].date.day != 0)
        {
            quantity++;
        }
    }
    return quantity;
}
//Check Leap Year
void checkLeapYear(struct Date* userInput)
{
    printf("Year        : ");
    scanf(" %d", &userInput->year);
    clearInputBuffer();
    printf("Month (1-12): ");
    userInput->month = inputIntRange(0, 12);
    switch (userInput->month)
    {
    case 1:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(0, 31);
        break;
    case 2:
        //Check if entered year input is a leap year
        if (userInput->year % 400 == 0 || userInput->year % 100 == 0 ||
            userInput->year % 4 == 0)
        {
            printf("Day (1-29)  : ");
            userInput->day = inputIntRange(1, 29);
        }
        else
        {
            printf("Day (1-28)  : ");
            userInput->day = inputIntRange(1, 28);
        }
        break;
    case 3:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    case 4:
        printf("Day (1-30)  : ");
        userInput->day = inputIntRange(1, 30);
        break;
    case 5:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    case 6:
        printf("Day (1-30)  : ");
        userInput->day = inputIntRange(1, 30);
        break;
    case 7:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    case 8:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    case 9:
        printf("Day (1-30)  : ");
        userInput->day = inputIntRange(1, 30);
        break;
    case 10:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    case 11:
        printf("Day (1-30)  : ");
        userInput->day = inputIntRange(1, 30);
        break;
    case 12:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    default:
        inputIntRange(1, 12);
        break;
    }
}
//Selection Sort
void sortingAppoint(struct Appointment* appointments, int size)
{
    int a, b;
    struct Appointment temp;
    for (a = size - 1; a > 0; a--)
    {
        for (b = 0; b < a; b++)
        {
            //Sorting by year
            if (appointments[b].date.year > appointments[b + 1].date.year)
            {
                temp = appointments[b];
                appointments[b] = appointments[b + 1];
                appointments[b + 1] = temp;
            }
            //Sorting by day
            else if (appointments[b].date.year == appointments[b +
                1]
                .date.year &&
                appointments[b].date.day > appointments[b + 1].date.day)
            {
                temp = appointments[b];
                appointments[b] = appointments[b + 1];
                appointments[b + 1] = temp;
            }
            //Sorting by hour
            else if (appointments[b].date.year == appointments[b +
                1]
                .date.year &&
                appointments[b].date.day == appointments[b + 1].date.day &&
                appointments[b].time.hour > appointments[b + 1].time.hour)
            {
                temp = appointments[b];
                appointments[b] = appointments[b + 1];
                appointments[b + 1] = temp;
            }
            //Sorting by min
            else if (appointments[b].date.year == appointments[b +
                1]
                .date.year &&
                appointments[b].date.day == appointments[b + 1].date.day &&
                appointments[b].time.hour == appointments[b + 1].time.hour &&
                appointments[b].time.min > appointments[b + 1].time.min)
            {
                temp = appointments[b];
                appointments[b] = appointments[b + 1];
                appointments[b + 1] = temp;
            }
        }
    }
}
//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////
// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int number;
    int index;
    printf("Search by patient number: ");
    scanf(" %d", &number);
    clearInputBuffer();
    putchar('\n');
    index = findPatientIndexByPatientNum(number, patient, max);
    if (index != -1)
    {
        displayPatientData(&patient[index], FMT_FORM);
        putchar('\n');
    }
    else
    {
        printf("*** No records found ***\n\n");
    }
}
// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    char phoneNumber[PHONE_LEN + 1] = { '\0' };
    int result;
    int a;
    int found = 0;
    printf("Search by phone number: ");
    scanf(" %[^\n]", phoneNumber);
    clearInputBuffer();
    putchar('\n');
    displayPatientTableHeader();
    for (a = 0; a < max; a++)
    {
        result = strcmp(patient[a].phone.number, phoneNumber);
        if (result == 0)
        {
            displayPatientData(&patient[a], FMT_TABLE);
            found++;
        }
    }
    if (!found)
    {
        putchar('\n');
        printf("*** No records found ***\n");
    }
    putchar('\n');
}
// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max)
{
    int a;
    int biggestNum = patient[0].patientNumber;
    for (a = 1; a < max; a++)
    {
        if (biggestNum < patient[a].patientNumber)
        {
            biggestNum = patient[a].patientNumber;
        }
    }
    return biggestNum + 1;
}
// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max)
{
    int a;
    for (a = 0; a < max; a++)
    {
        if (patientNumber == patient[a].patientNumber)
        {
            return a;
        }
    }
    return -1;
}
//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////
// Get user input for a new patient record
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    do
    {
        scanf(" %[^\n]", patient->name);
        clearInputBuffer();
        if (strlen(patient->name) > NAME_LEN)
        {
            printf("ERROR: String length must be no more than 15 chars: ");
        }
    } while (strlen(patient->name) > NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);
}
// Get user input for phone contact information
void inputPhoneData(struct Phone* phone)
{
    int selection;
    char phoneNum[15] = { '\0' };
    printf("Phone Information\n-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    selection = inputIntRange(1, 4);
    putchar('\n');
    switch (selection)
    {
    case 1:
        strcpy(phone->description, "CELL");
        break;
    case 2:
        strcpy(phone->description, "HOME");
        break;
    case 3:
        strcpy(phone->description, "WORK");
        break;
    case 4:
        strcpy(phone->description, "TBD");
        break;
    }
    if (selection != 4)
    {
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        do
        {
            scanf(" %[^\n]", phoneNum);
            clearInputBuffer();
            if (strlen(phoneNum) != PHONE_LEN)
            {
                printf("Invalid 10-digit number! Number: ");
            }
            else
            {
                strcpy(phone->number, phoneNum);
            }
        } while (strlen(phoneNum) != PHONE_LEN);
        putchar('\n');
    }
    else
    {
        strcpy(phone->number, "\0");
    }
}
//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////
// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    FILE* fp = fopen(datafile, "r");
    int a = 0;
    int records = 0;
    if (fp != NULL)
    {
        for (a = 0; a < max; a++)
        {
            //Check if the records are not empty and count the records
            if (fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]",
                &patients[a].patientNumber, patients[a].name, patients[a].phone.description,
                patients[a].phone.number) > 0)
            {
                records++;
            }
        }
        fclose(fp);
    }
    return records;
}
// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char* datafile, struct Appointment appoints[], int
    max)
{
    FILE* fp = fopen(datafile, "r");
    int a = 0;
    int records = 0;
    if (fp != NULL)
    {
        for (a = 0; a < max; a++)
        {
            //Check if the records are not empty and count the records
            if (fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[a].patientNumber,
                &appoints[a].date.year, &appoints[a].date.month, &appoints[a].date.day,
                &appoints[a].time.hour, &appoints[a].time.min) > 0)
            {
                records++;
            }
        }
        fclose(fp);
    }
    return records;
}