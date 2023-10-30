#include <iostream>
#include <limits>
#include <cctype>
using namespace std;

struct SemesterData {
    double Quizave;
    double Actave;
    double Recitave;
    double Attendave;
    double Labave;
    double Examave;
    string name;
    string Section;
    string course;
    
} ;
int main() {
    string Semester[3] = { "Prelim", "Midterm", "Final" };
    SemesterData previousData[3];
        char ans1, ans;
    size_t i=0 ,j=0;
int Quizzes[20][2], numQuizzes, sumQuizzes = 0;
int Act[20][2], numAct, sumAct = 0;
int Recit, numRecit;
int totalClasses,attendedClasses;
int Lab[20][2],numLab,sumLab=0;
int Exam[2];
double Quizave, Actave, Recitave,Attendave,Labave,Examave;
double Quizpercent,Actpercent,Recitpercent,Attenpercent,Labpercent,Exampercent;
double totalQuizScore = 0,totalActScore=0,totalRecitScore=0,totalLabScore=0,totalExamScore=0;
char separator;
double percentage;
        do {




cout << "Enter the Student Name: ";
getline(cin, previousData[j].name);
cout << "Enter the Section Name: ";
getline(cin, previousData[j].Section);
cout << "Enter the Student Course Name: ";
getline(cin, previousData[j].course);

for (char& c : previousData[j].name) {
    c = std::toupper(c);
}
for (char& c : previousData[j].Section) {
    c = std::toupper(c);
}
for (char& c : previousData[j].course) {
    c = std::toupper(c);
}

j++;
for (size_t j = 0; j < 1; j++) {


cout << "\n\n---------------------------------------------------------------\n\n\n";

            cout << "Semester " << Semester[j] << endl;




// Quizzes
cout << "Enter the number of quizzes: ";
cin >> numQuizzes;

for (int i = 0; i < numQuizzes; i++) {
    cout << "Enter the Quiz " << i + 1 << " score (score/total): ";
    while (!(cin >> Quizzes[i][0] >> separator >> Quizzes[i][1]) || separator != '/' || Quizzes[i][0] > Quizzes[i][1]) {
        // Clear the input stream                           
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid score as score/total (score <= total): ";
    }
    sumQuizzes += Quizzes[i][0];
}

for (int i = 0; i < numQuizzes; i++) {
    totalQuizScore += Quizzes[i][1];
}

previousData[j].Quizave = (sumQuizzes / totalQuizScore) * 100;

    cout << "Average Quiz Score: " << previousData[j].Quizave << endl;

cout << "\n\n---------------------------------------------------------------\n\n\n";
// Activities
cout << "Enter the number of activities: ";
cin >> numAct;

for (int i = 0; i < numAct; i++) {
    cout << "Enter the Activity " << i + 1 << " score(score/total): ";
    while (!(cin >> Act[i][0]>>separator>>Act[i][1])||separator !='/'||Act[i][0]>Act[i][1]) {
        // Clear the input stream
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid score as score/total (score <= total): ";
    }
    sumAct += Act[i][0];
}
for (int i = 0; i < numAct; i++){
    totalActScore += Act[i][1];

}

previousData[j].Actave =(sumAct/totalActScore)*100;
    cout << "Average Activity Score: " << previousData[j].Actave << endl;

cout << "\n\n---------------------------------------------------------------\n\n\n";

// Recitations
cout << "Enter the total number of Recitation: ";
cin >> numRecit;
cout << "Enter the number of Student Recitation: ";
cin >> Recit;

previousData[j].Recitave = (static_cast<double>(Recit) / numRecit) * 100;
cout << "Average Recitation Score: " << previousData[j].Recitave << endl;

cout << "\n\n---------------------------------------------------------------\n\n\n";

// Attendance
cout << "Enter the total number of classes: ";
cin >> totalClasses;
cout << "Enter the number of classes attended: ";
cin >> attendedClasses;

previousData[j].Attendave = (static_cast<double>(attendedClasses) / totalClasses) * 100;
cout << "Average Attendace Score: " << previousData[j].Attendave << endl;

cout << "\n\n---------------------------------------------------------------\n\n\n";
//Laboratory
cout << "Enter the number of Lab Act: ";
cin >> numLab;

for (int i = 0; i < numLab; i++) {
    cout << "Enter the Lab Act " << i + 1 << " score(score/total): ";
    while (!(cin >> Lab[i][0]>>separator>>Lab[i][1])||separator !='/'||Lab[i][0]>Lab[i][1]) {
        // Clear the input stream
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid score as score/total (score <= total): ";
    }
    sumLab += Lab[i][0];
}
for (int i = 0; i < numLab; i++){
    totalLabScore += Lab[i][1];

}

previousData[j].Labave =(sumLab/totalLabScore)*100;
cout << "Average Laboratory Score: " << previousData[j].Labave << endl;

cout << "\n\n---------------------------------------------------------------\n\n\n";

//Exam
    cout << "Enter the Exam score(score/total): ";
    while (!(cin >> Exam[0]>>separator>>Exam[1])||separator !='/'||Exam[0]>Exam[1]) {
        // Clear the input stream
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid score as score/total (score <= total): ";
    }
previousData[j].Examave = (static_cast<double>(Exam[0]) / Exam[1]) * 100;
cout << "Average Exam Score: " << previousData[j].Examave << endl;

do{
    cout << "Enter the weightage or percentage for each component:" << endl;
    cout << "Quiz: ";
    cin >> Quizpercent;
    cout << "Activity: ";
    cin >> Actpercent;
    cout << "Recitation: ";
    cin >> Recitpercent;
    cout << "Attendance: ";
    cin >> Attenpercent;
    cout << "Lab: ";
    cin >> Labpercent;
    cout << "Exam: ";
    cin >> Exampercent;
percentage=Quizpercent+Actpercent+Recitpercent+Attenpercent+Labpercent+Exampercent;
    if (percentage != 100) {
        cout << "The total weightage or percentage should be 100%. Please try again.\n" << endl;
    }
} while (percentage!=100);

cout << "Average Quiz Score: " << previousData[j].Quizave << endl;
cout << "Average Activity Score: " << previousData[j].Actave << endl;
cout << "Average Recitation Score: " << previousData[j].Recitave << endl;
cout << "Average Attendace Score: " << previousData[j].Attendave << endl;
cout << "Average Laboratory Score: " << previousData[j].Labave << endl;
cout << "Average Exam Score: " << previousData[j].Examave << endl;




    double weightedAverage = (Quizpercent * previousData[j].Quizave +
                              Actpercent * previousData[j].Actave +
                              Recitpercent * previousData[j].Recitave +
                              Attenpercent * previousData[j].Attendave +
                              Labpercent * previousData[j].Labave +
                              Exampercent * previousData[j].Examave) /
                             (Quizpercent + Actpercent + Recitpercent + Attenpercent + Labpercent + Exampercent);

    cout << "Weighted Average: " << weightedAverage << endl;
            cout << endl;

}
        cout << "Do you want to continue? (Y/N): ";
        cin >> ans1;
        ans1 = tolower(ans1);

        if (ans1 != 'y' && ans1 != 'n') {
            cout << "Invalid input. Please enter Y or N." << endl;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (ans1 == 'y');
    cout << "Do you want to search for a student name? Y/N: ";
    cin >> ans;
    ans = tolower(ans);

    if (ans == 'y') {
        string searchName;
        cin.ignore(); // Ignore the newline character
        cout << "Enter the student name: ";
        getline(cin, searchName);

        // Convert search name to uppercase
        for (char& c : searchName) {
            c = std::toupper(c);
        }

        // Search for the student name in the previous data
        bool found = false;
        for (size_t i = 0; i < j; i++) {
            if (previousData[j].name == searchName) {
                found = true;
                cout << "Previous Data for " << searchName << ":" << endl;
                cout << "Semester " << Semester[j] << ":" << endl;
                cout << "Quiz: " << previousData[j].Quizave << endl;
                cout << "Activity: " << previousData[j].Actave << endl;
                cout << "Recitation: " << previousData[j].Recitave << endl;
                cout << "Attendance: " << previousData[j].Attendave << endl;
                cout << "Lab Act: " << previousData[j].Labave << endl;
                cout << "Exam: " << previousData[j].Examave << endl;
                cout << endl;
            }
        }

        if (!found) {
            cout << "No previous data found for " << searchName << endl;
        }
    }


// Pause before program exit
system("pause");
return 0;
}
