#include <iostream>
#include <limits>

using namespace std;
 
const int MAX_STUDENTS = 100;
const int MAX_SEMESTERS = 3;
//data storage
struct SemesterData {
    string stdname,stdsection,stdcourse;
double Quizave[MAX_SEMESTERS];
double Actave[MAX_SEMESTERS];
double Recitave[MAX_SEMESTERS];
double Attendave[MAX_SEMESTERS];
double Labave[MAX_SEMESTERS];
double Examave[MAX_SEMESTERS];
double AveGrade[MAX_SEMESTERS];
};
 
int main() {
	//Preperations
string Semester[3] = { "Prelim", "Midterm", "Final" };
SemesterData Students[MAX_STUDENTS];
string Name, Section, key;
string course;
int numStudents=0;
int Quizzes[20][2], numQuizzes, sumQuizzes = 0;
int Act[20][2], numAct, sumAct = 0;
int Recit, numRecit;
int totalClasses,attendedClasses;
int Lab[20][2],numLab,sumLab=0;
int Exam[2],choose;
double Quizave, Actave, Recitave,Attendave,Labave,Examave;
double Quizpercent,Actpercent,Recitpercent,Attenpercent,Labpercent,Exampercent;
double totalQuizScore = 0,totalActScore=0,totalRecitScore=0,totalLabScore=0,totalExamScore=0;
char separator;
double percentage;
char ans;
cout<<"Welcome to our Grading System"<<endl<<"Press enter when you are ready : ]"<<endl;
do{     
  
    cout << "\t\t\t__________________________________________________\n\n\n";
    cout << "\t\t\t                Welcome to registrar\n\n";
    cout << "\t\t\tChoices:\n\n";
    cout << "\t\t\t        Press 1 to Enter Student Grades\n\n";
    cout << "\t\t\t        Press 2 to Search Student Grades\n\n";
    cout << "\t\t\t        Press 3 to See Masterlist\n\n";
    cout << "\t\t\t        Press 4 to Exit\n\n";

    cout << "\t\t\tPlease Enter your choice: ";
    cin >> choose;
    SemesterData studentData;

switch(choose){

    case 1: 
    cin.ignore(); // Add this line to clear the input buffer
    cout << "Enter the Student Name: ";
    getline(cin, studentData.stdname);
        for (char& c : studentData.stdname) {
            c = std::toupper(c);
        }
        cout << "Enter the Section Name: ";
getline(cin, studentData.stdsection);
        for (char& c : studentData.stdsection) {
            c = std::toupper(c);
        }
    cout << "Enter the Student Course Name: ";
getline(cin, studentData.stdcourse);
        for (char& c : studentData.stdcourse) {
            c = std::toupper(c);
        }


cout << "\n\n---------------------------------------------------------------\n\n\n";

for(int sem=0;sem<MAX_SEMESTERS;sem++){
    int sumLab=0, sumAct = 0, sumQuizzes = 0;
    double totalQuizScore = 0,totalActScore=0,totalRecitScore=0,totalLabScore=0,totalExamScore=0;


	cout<<"SEMESTER "<<Semester[sem]<<endl;
	cout << "\n\n---------------------------------------------------------------\n\n\n";

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

Quizave = (sumQuizzes / totalQuizScore) * 100;
studentData.Quizave[sem]=Quizave;
    cout << "Average Quiz Score: " <<Quizave<< endl;

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

Actave =(sumAct/totalActScore)*100;
    cout << "Average Activity Score: " << Actave << endl;
studentData.Actave[sem]=Actave;
cout << "\n\n---------------------------------------------------------------\n\n\n";

// Recitations
do{
cout << "Enter the total number of Recitation: ";
cin >> numRecit;
cout << "Enter the number of Student Recitation: ";
cin >> Recit;

        if (numRecit < Recit) {
            cout << "Invalid input. Please enter a valid input as the number of classes attended should be less than the total number of classes.\n";
        }
}while(numRecit<Recit);

Recitave = (static_cast<double>(Recit) / numRecit) * 100;
cout << "Average Recitation Score: " << Recitave << endl;
studentData.Recitave[sem]=Recitave;
cout << "\n\n---------------------------------------------------------------\n\n\n";

// Attendance
do{
cout << "Enter the total number of classes: ";
cin >> totalClasses;
cout << "Enter the number of classes attended: ";
cin >> attendedClasses;

        if (totalClasses < attendedClasses) {
            cout << "Invalid input. Please enter a valid input as the number of classes attended should be less than the total number of classes.\n";
        }
}while(totalClasses<attendedClasses);
Attendave = (static_cast<double>(attendedClasses) / totalClasses) * 100;
cout << "Average Attendace Score: " << Attendave << endl;
studentData.Attendave[sem]=Attendave;
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

Labave =(sumLab/totalLabScore)*100;
cout << "Average Laboratory Score: " << Labave << endl;
studentData.Labave[sem]=Labave;
cout << "\n\n---------------------------------------------------------------\n\n\n";

//Exam
    cout << "Enter the Exam score(score/total): ";
    while (!(cin >> Exam[0]>>separator>>Exam[1])||separator !='/'||Exam[0]>Exam[1]) {
        // Clear the input stream
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid score as score/total (score <= total): ";
    }
Examave = (static_cast<double>(Exam[0]) / Exam[1]) * 100;
studentData.Examave[sem]=Examave;
cout << "Average Exam Score: " << Examave << endl;

//to calculate the Average of the grades

do{
    cout << "\n\n---------------------------------------------------------------\n\n\n";

    cout << "\n\nEnter the weightage or percentage for each component:" << endl;
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
 studentData.AveGrade[sem]=percentage;
   
    if (percentage != 100) {
        cout << "The total weightage or percentage should be 100%. Please try again.\n" << endl;
    }
} while (percentage!=100);

//to display all average scores and grades

    double weightedAverage = (Quizpercent * Quizave +
                              Actpercent * Actave +
                              Recitpercent * Recitave +
                              Attenpercent * Attendave +
                              Labpercent * Labave +
                              Exampercent * Examave) /
                             (Quizpercent + Actpercent + Recitpercent + Attenpercent + Labpercent + Exampercent);
cout << "\n\nStudent Name: " << studentData.stdname << endl;
cout << "Section: " << studentData.stdsection << endl;
cout << "Course: " << studentData.stdcourse << endl;
cout << "Average Quiz Score: " << Quizave << endl;
cout << "Average Activity Score: " << Actave << endl;
cout << "Average Recitation Score: " << Recitave << endl;
cout << "Average Attendace Score: " << Attendave << endl;
cout << "Average Laboratory Score: " << Labave << endl;
cout << "Average Exam Score: " << Examave << endl;
cout << "Weighted Average: " << weightedAverage << endl;
cout << "\n\n---------------------------------------------------------------\n\n\n";




}
Students[numStudents]=studentData;
numStudents++;
break;

case 2:
//To search Student Data
        string searchName;
        cout << "Enter the student name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, searchName);
        for (char& c : searchName) {
            c = std::toupper(c);
        }
        bool found = false;

        for (int student = 0; student < numStudents; student++) {
            string storedName = Students[student].stdname; // Store the student's name in a separate variable
        for (char& c : storedName) {
            c = std::toupper(c);
        }
            if (searchName == storedName) { // Compare the search query with the uppercase name
                found = true;
                cout << "Student Name: " << Students[student].stdname << endl;
                cout << "Section Name: " << Students[student].stdsection << endl;
                cout << "Course Name " << Students[student].stdcourse << "\n\n" << endl;

                for (int sem = 0; sem < MAX_SEMESTERS; sem++) {
                    cout << "Semester " <<  Semester[sem] << ":" << endl;
                    cout << "Quiz: " << Students[student].Quizave[sem] << endl;
                    cout << "Activity: " << Students[student].Actave[sem] << endl;
                    cout << "Recitation: " << Students[student].Recitave[sem] << endl;
                    cout << "Attendance: " << Students[student].Attendave[sem] << endl;
                    cout << "Lab Act: " << Students[student].Labave[sem] << endl;
                    cout << "Exam: " << Students[student].Examave[sem] << endl;
                    cout << "\n\n---------------------------------------------------------------\n\n\n";

                }

                break;
            }
        }

        if (!found) {
            cout << "No data found for the entered name." << endl;
            cout << "\n\n---------------------------------------------------------------\n\n\n";

        }



break;
case 3:
        for (int student = 0; student < numStudents; student++) {
            // Store the student's name in a separate variable
                cout << "Student Name: " << Students[student].stdname << endl;
                cout << "Section Name: " << Students[student].stdsection << endl;
                cout << "Course Name " << Students[student].stdcourse << "\n\n" << endl;

                for (int sem = 0; sem < MAX_SEMESTERS; sem++) {
                    cout << "Semester " <<  Semester[sem] << ":" << endl;
                    cout << "Quiz: " << Students[student].Quizave[sem] << endl;
                    cout << "Activity: " << Students[student].Actave[sem] << endl;
                    cout << "Recitation: " << Students[student].Recitave[sem] << endl;
                    cout << "Attendance: " << Students[student].Attendave[sem] << endl;
                    cout << "Lab Act: " << Students[student].Labave[sem] << endl;
                    cout << "Exam: " << Students[student].Examave[sem] << endl;
                    cout << "\n\n---------------------------------------------------------------\n\n\n";

                }

            }
        
break;




}

}while(choose!=4);
    cout<<"Thank You for Using our System <33"<<endl;




// Pause before program exit
system("pause");
return 0;
}
