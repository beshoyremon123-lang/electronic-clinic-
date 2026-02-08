#include <bits/stdc++.h>
using namespace std;
struct personal_patients
{
    string name;
    int age;
    long long id;
    string diagnosis;
    string medicine;
    string treatment;
    string doctor;
};
struct appointments
{
    long long id;
    string date;
    string time;
};
void ADDPATIENTS(personal_patients person[] , int &count)
{
     cout << "================================================================" << endl;
    cout << "Enter patient's name : ";
    getline(cin , person[count].name);
    cout << "Enter patient's age : ";
    cin >> person[count].age;
    cout << "Enter patient's id : ";
    cin >> person[count].id;
    cin.ignore(numeric_limits<streamsize>::max() , '\n');
    cout << "Enter patient's diagnosis : ";
    getline(cin , person[count].diagnosis);
    cout << "Enter patient's medicine : ";
    getline(cin , person[count].medicine);
    cout << "Enter patient's time for treatment : ";
    getline(cin , person[count].treatment);
    cout << "Enter doctor name : ";
    getline(cin , person[count].doctor);
    count++;
    cout << "\n" << "\n";
    cout << "\tTHE PATIENT HAS BEEN ADDED SUCCESSFULLY\n";
    cout << "================================================================" << endl;
};
void DISPLAYPATIENTS(personal_patients person[] , int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << "patient" << i+1 << endl;
        cout << "patient's name : " << person[i].name << endl;
        cout << "patient's age : " << person[i].age << endl;
        cout << "patient's id : " << person[i].id << endl;
        cout << "patient's diagnosis : " << person[i].diagnosis << endl;
        cout << "patient's medicine : " << person[i].medicine << endl;
        cout << "patient's time of treatment : " << person[i].treatment << endl;
        cout << "\n" << "\n" ;
        cout << "\t \t \t \t Dr \\ " << person[i].doctor << endl;
        cout << "================================================================" << endl;
    }  
};
void Appointments(appointments app[] , int &appcount , personal_patients person[] , int count)
{
    int id;
    bool found = false;
    cout << "Enter patient's id : ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max() , '\n');
    for (int i = 0; i < count; i++)
    {
        if (person[i].id == id)
        {
            found = true;
            break;
        }
    }
    if (found == false)
    {
        cout << "Patient not found" << endl;
        return;
    }
    app[appcount].id = id;
    cout << "Enter date : ";
    getline(cin , app[appcount].date);
    cout << "Enter time : ";
    getline(cin , app[appcount].time);
    appcount++;
    cout << "\n" << "\n";
    cout << "\t APPOINTMENT ADDED SUCCESSFULLY\n";
     cout << "================================================================" << endl;
};
void DISPLAY_APPOINTMENTS(appointments app[] , int appcount , personal_patients person[] , int count)
{
    if (appcount == 0)
    {
        cout << "No appointments found ";
        return;
    }
    for (int i = 0; i < appcount; i++)
    {
        cout << "================================================================" << endl;
        cout << "Patient id : " << app[i].id << endl;
        cout << "Date : " << app[i].date << endl;
        cout << "Time : " << app[i].time << endl;
        cout << "================================================================" << endl;
    }
};
void Search_patient(personal_patients person[] , int count)
{
    long long id;
    bool found = false;
    cout << "Enter patient id : ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max() , '\n');
    for (int i = 0; i < count; i++)
    {
        if(person[i].id == id)
        {
            found = true;
        cout << "patient" << i+1 << endl;
        cout << "patient's name : " << person[i].name << endl;
        cout << "patient's age : " << person[i].age << endl;
        cout << "patient's id : " << person[i].id << endl;
        cout << "patient's diagnosis : " << person[i].diagnosis << endl;
        cout << "patient's medicine : " << person[i].medicine << endl;
        cout << "patient's time of treatment : " << person[i].treatment << endl;
        cout << "\n" << "\n" ;
        cout << "\t \t \t \t Dr \\ " << person[i].doctor << endl;
        cout << "================================================================" << endl;
        break;
        }
    }
    if (!found)
    {
        cout << "Patient is not found \n";
    }  
}
void EDIT_PATIENT(personal_patients person[], int count)
{
    long long id;
    bool found = false;

    cout << "Enter patient id to edit: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < count; i++)
    {
        if (person[i].id == id)
        {
            found = true;
            cout << "\nEditing Patient: " << person[i].name << "\n";

            cout << "Enter new name (current: " << person[i].name << "): ";
            getline(cin, person[i].name);

            cout << "Enter new age (current: " << person[i].age << "): ";
            cin >> person[i].age;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter new diagnosis (current: " << person[i].diagnosis << "): ";
            getline(cin, person[i].diagnosis);

            cout << "Enter new medicine (current: " << person[i].medicine << "): ";
            getline(cin, person[i].medicine);

            cout << "Enter new treatment duration (current: " << person[i].treatment << "): ";
            getline(cin, person[i].treatment);

            cout << "Enter new doctor name (current: " << person[i].doctor << "): ";
            getline(cin, person[i].doctor);

            cout << "\nPatient updated successfully \n";
            break;
        }
    }

    if (!found)
    {
        cout << "Patient not found\n";
    }
}
void DELETE_PATIENT(personal_patients person[], int &count)
{
    long long id;
    bool found = false;

    cout << "Enter patient id to delete: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    for (int i = 0; i < count; i++)
    {
        if (person[i].id == id)
        {
            found = true;
            for (int j = i; j < count - 1; j++)
            {
                person[j] = person[j + 1];
            }

            count--;
            cout << "Patient deleted successfully \n";
            break;
        }
    }
    if (!found)
    {
        cout << "Patient not found\n";
    }
}
int main()
{
    personal_patients person[100];
    appointments app[100];

    int count = 0;      
    int appcount = 0;   
    int choice;
    do
    {
        cout << "\n================ ELECTRONIC CLINIC ================\n";
        string arr[8] = {"Add Patient" , "Display Patients (Show Prescription)" , "Search Patient by ID" , "Edit Patient" , "Delete Patient" , "Book Appointment" , "Display Appointments" , "Exit"};
        for (int i = 0; i < 8; i++)
        {
            cout << i + 1 << " - " << arr[i] << endl;
        }
        cout << "================================================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice)
        {
            case 1:
                ADDPATIENTS(person, count);
                break;
            case 2:
                DISPLAYPATIENTS(person, count);
                break;
            case 3:
                Search_patient(person, count);
                break;
            case 4:
                EDIT_PATIENT(person, count);
                break;
            case 5:
                DELETE_PATIENT(person, count);
                break;
            case 6:
                Appointments(app, appcount, person, count);
                break;
            case 7:
                DISPLAY_APPOINTMENTS(app, appcount, person, count);
                break;
            case 8:
                cout << "Exiting program. Goodbye! \n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 8);
    return 0;
}
