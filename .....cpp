
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iomanip>

using namespace std;


// =====================================================
// QUESTION STRUCTURE
// =====================================================

struct Question
{
    int id;
    string category;
    string difficulty;
    string topic;

    string question;
    string optionA;
    string optionB;
    string optionC;
    string optionD;

    char correctAnswer;
};


// =====================================================
// GLOBAL USED QUESTION LIST
// =====================================================

vector<int> usedQuestionIDs;


// =====================================================
// ADD QUESTION
// =====================================================

void addQuestion(
    vector<Question> &questions,
    int id,
    string category,
    string difficulty,
    string topic,
    string question,
    string a,
    string b,
    string c,
    string d,
    char answer)
{
    Question q;

    q.id = id;
    q.category = category;
    q.difficulty = difficulty;
    q.topic = topic;

    q.question = question;
    q.optionA = a;
    q.optionB = b;
    q.optionC = c;
    q.optionD = d;

    q.correctAnswer = answer;

    questions.push_back(q);
}


// =====================================================
// CHECK WHETHER QUESTION WAS USED
// =====================================================

bool isUsed(int id)
{
    int i;

    for (i = 0; i < (int)usedQuestionIDs.size(); i++)
    {
        if (usedQuestionIDs[i] == id)
        {
            return true;
        }
    }

    return false;
}


// =====================================================
// LOAD USED QUESTIONS
// =====================================================

void loadUsedQuestions()
{
    ifstream file("used_questions.txt");

    int id;

    if (!file)
    {
        return;
    }

    while (file >> id)
    {
        if (!isUsed(id))
        {
            usedQuestionIDs.push_back(id);
        }
    }

    file.close();
}


// =====================================================
// SAVE USED QUESTION
// =====================================================

void saveUsedQuestion(int id)
{
    ofstream file("used_questions.txt", ios::app);

    file << id << endl;

    file.close();
}


// =====================================================
// USER DETAILS MODULE
// =====================================================

void getUserDetails(
    string &name,
    string &category,
    string &difficulty)
{
    int choice;

    cout << "\n========================================\n";
    cout << "           QUIZ GAME SYSTEM\n";
    cout << "========================================\n";

    cout << "\nEnter your name: ";
    cin >> name;


    // CATEGORY

    cout << "\nSelect Category\n";
    cout << "1. Programming\n";
    cout << "2. Science\n";
    cout << "3. General Knowledge\n";

    cout << "\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        category = "Programming";
    }
    else if (choice == 2)
    {
        category = "Science";
    }
    else
    {
        category = "General Knowledge";
    }


    // DIFFICULTY

    cout << "\nSelect Difficulty\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";

    cout << "\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        difficulty = "Easy";
    }
    else if (choice == 2)
    {
        difficulty = "Medium";
    }
    else
    {
        difficulty = "Hard";
    }
}


// =====================================================
// QUESTION DISPLAY MODULE
// =====================================================

void displayQuestion(
    const Question &q,
    int number)
{
    cout << "\n----------------------------------------\n";

    cout << "Question " << number << endl;

    cout << "Topic      : " << q.topic << endl;
    cout << "----------------------------------------\n";

    cout << q.question << endl;

    cout << "\nA. " << q.optionA << endl;
    cout << "B. " << q.optionB << endl;
    cout << "C. " << q.optionC << endl;
    cout << "D. " << q.optionD << endl;
}


// =====================================================
// ANSWER VALIDATION MODULE
// =====================================================

bool validateAnswer(
    char userAnswer,
    char correctAnswer)
{
    userAnswer = (char)toupper(userAnswer);
    correctAnswer = (char)toupper(correctAnswer);

    if (userAnswer == correctAnswer)
    {
        return true;
    }

    return false;
}


// =====================================================
// RANDOM SHUFFLE
// =====================================================

void shuffleQuestions(
    vector<Question> &questions)
{
    int i;
    int j;

    Question temp;

    for (i = (int)questions.size() - 1;
         i > 0;
         i--)
    {
        j = rand() % (i + 1);

        temp = questions[i];

        questions[i] = questions[j];

        questions[j] = temp;
    }
}


// =====================================================
// GET QUESTIONS BASED ON
// CATEGORY + DIFFICULTY
// =====================================================

vector<Question> getQuizQuestions(
    vector<Question> &allQuestions,
    string category,
    string difficulty)
{
    vector<Question> result;

    int i;

    for (i = 0;
         i < (int)allQuestions.size();
         i++)
    {
        if (allQuestions[i].category == category &&
            allQuestions[i].difficulty == difficulty &&
            !isUsed(allQuestions[i].id))
        {
            result.push_back(allQuestions[i]);
        }
    }

    shuffleQuestions(result);

    return result;
}


// =====================================================
// QUIZ MODULE
// =====================================================

void startQuiz(
    vector<Question> &quizQuestions,
    vector<Question> &wrongAnswers,
    int &score,
    int &correct,
    int &wrong)
{
    int i;

    char answer;

    score = 0;
    correct = 0;
    wrong = 0;


    cout << "\n========================================\n";
    cout << "             QUIZ STARTED\n";
    cout << "========================================\n";


    for (i = 0;
         i < (int)quizQuestions.size();
         i++)
    {
        displayQuestion(
            quizQuestions[i],
            i + 1);


        cout << "\nEnter your answer (A/B/C/D): ";
        cin >> answer;

        answer = (char)toupper(answer);


        // ANSWER VALIDATION

        if (validateAnswer(
                answer,
                quizQuestions[i].correctAnswer))
        {
            cout << "\nCorrect Answer!\n";

            score++;
            correct++;
        }
        else
        {
            cout << "\nWrong Answer!\n";

            cout << "Correct Answer: "
                 << quizQuestions[i].correctAnswer
                 << endl;

            wrong++;

            // Store wrong question

            wrongAnswers.push_back(
                quizQuestions[i]);
        }


        // SAVE QUESTION AS USED

        if (!isUsed(quizQuestions[i].id))
        {
            saveUsedQuestion(
                quizQuestions[i].id);

            usedQuestionIDs.push_back(
                quizQuestions[i].id);
        }
    }
}


// =====================================================
// SCORE AND RESULT MODULE
// =====================================================

void displayResult(
    int score,
    int correct,
    int wrong,
    int total)
{
    float accuracy;

    if (total > 0)
    {
        accuracy =
            ((float)correct / total) * 100;
    }
    else
    {
        accuracy = 0;
    }


    cout << "\n========================================\n";
    cout << "             QUIZ RESULT\n";
    cout << "========================================\n";

    cout << "Total Questions : "
         << total << endl;

    cout << "Correct Answers : "
         << correct << endl;

    cout << "Wrong Answers   : "
         << wrong << endl;

    cout << "Score           : "
         << score << endl;

    cout << "Accuracy        : "
         << fixed << setprecision(2)
         << accuracy << "%\n";

    cout << "========================================\n";
}


// =====================================================
// CHECK PRACTICE DUPLICATE
// =====================================================

bool practiceAlreadyExists(
    vector<Question> &practiceQuestions,
    int id)
{
    int i;

    for (i = 0;
         i < (int)practiceQuestions.size();
         i++)
    {
        if (practiceQuestions[i].id == id)
        {
            return true;
        }
    }

    return false;
}


// =====================================================
// PRACTICE MODULE
// =====================================================
//
// IMPORTANT:
//
// Wrong Question:
//     Q1
//
// Practice:
//     NOT Q1
//
// Instead:
//     Another question from SAME TOPIC
//
// Example:
//
// Wrong:
// "What does a pointer store?"
//
// Practice:
// "Which symbol is used to get
//  the address of a variable?"
//
// SAME TOPIC
// DIFFERENT QUESTION
//
// =====================================================

void practiceWrongAnswers(
    vector<Question> &allQuestions,
    vector<Question> &wrongAnswers)
{
    int i;
    int j;

    char answer;

    int practiceScore = 0;


    if (wrongAnswers.size() == 0)
    {
        cout << "\nNo wrong answers.\n";
        cout << "Practice is not required.\n";

        return;
    }


    cout << "\n========================================\n";
    cout << "          PRACTICE QUESTIONS\n";
    cout << "========================================\n";


    vector<Question> practiceQuestions;


    // -------------------------------------------------
    // FIND DIFFERENT QUESTIONS
    // FROM SAME TOPIC
    // -------------------------------------------------

    for (i = 0;
         i < (int)wrongAnswers.size();
         i++)
    {
        string wrongTopic;

        int found = 0;

        wrongTopic =
            wrongAnswers[i].topic;


        for (j = 0;
             j < (int)allQuestions.size();
             j++)
        {

            // SAME TOPIC

            if (allQuestions[j].topic ==
                wrongTopic)
            {

                // ------------------------------------
                // DO NOT USE THE SAME WRONG QUESTION
                // ------------------------------------

                if (allQuestions[j].id ==
                    wrongAnswers[i].id)
                {
                    continue;
                }


                // ------------------------------------
                // DO NOT REPEAT PRACTICE QUESTION
                // ------------------------------------

                if (practiceAlreadyExists(
                        practiceQuestions,
                        allQuestions[j].id))
                {
                    continue;
                }


                // ------------------------------------
                // ADD DIFFERENT QUESTION
                // ------------------------------------

                practiceQuestions.push_back(
                    allQuestions[j]);

                found = 1;

                break;
            }
        }


        if (found == 0)
        {
            cout << "\nNo different practice question "
                 << "available for topic: "
                 << wrongTopic << endl;
        }
    }


    // -------------------------------------------------
    // RANDOMIZE PRACTICE QUESTIONS
    // -------------------------------------------------

    shuffleQuestions(
        practiceQuestions);


    // -------------------------------------------------
    // DISPLAY PRACTICE QUESTIONS
    // -------------------------------------------------

    for (i = 0;
         i < (int)practiceQuestions.size();
         i++)
    {
        cout << "\n----------------------------------------\n";

        cout << "Practice Question "
             << i + 1 << endl;

        cout << "Topic: "
             << practiceQuestions[i].topic
             << endl;

        cout << "----------------------------------------\n";


        cout << practiceQuestions[i].question
             << endl;


        cout << "\nA. "
             << practiceQuestions[i].optionA
             << endl;

        cout << "B. "
             << practiceQuestions[i].optionB
             << endl;

        cout << "C. "
             << practiceQuestions[i].optionC
             << endl;

        cout << "D. "
             << practiceQuestions[i].optionD
             << endl;


        cout << "\nEnter your answer (A/B/C/D): ";

        cin >> answer;

        answer = (char)toupper(answer);


        if (validateAnswer(
                answer,
                practiceQuestions[i].correctAnswer))
        {
            cout << "\nCorrect! You improved.\n";

            practiceScore++;
        }
        else
        {
            cout << "\nWrong again.\n";

            cout << "Correct Answer: "
                 << practiceQuestions[i].correctAnswer
                 << endl;
        }
    }


    // -------------------------------------------------
    // PRACTICE RESULT
    // -------------------------------------------------

    cout << "\n========================================\n";
    cout << "           PRACTICE RESULT\n";
    cout << "========================================\n";

    cout << "Practice Questions : "
         << practiceQuestions.size()
         << endl;

    cout << "Correct Answers    : "
         << practiceScore
         << endl;

    cout << "Wrong Answers      : "
         << (int)practiceQuestions.size()
            - practiceScore
         << endl;

    cout << "========================================\n";
}


// =====================================================
// PERFORMANCE MODULE
// =====================================================

void showPerformance(
    int score,
    int total)
{
    float accuracy;

    if (total > 0)
    {
        accuracy =
            ((float)score / total) * 100;
    }
    else
    {
        accuracy = 0;
    }


    cout << "\n========================================\n";
    cout << "             PERFORMANCE\n";
    cout << "========================================\n";

    cout << "Score    : "
         << score << "/" << total
         << endl;

    cout << "Accuracy : "
         << fixed << setprecision(2)
         << accuracy << "%"
         << endl;


    if (accuracy >= 80)
    {
        cout << "Performance: Excellent\n";
    }
    else if (accuracy >= 60)
    {
        cout << "Performance: Good\n";
    }
    else if (accuracy >= 40)
    {
        cout << "Performance: Average\n";
    }
    else
    {
        cout << "Performance: Needs Improvement\n";
    }

    cout << "========================================\n";
}


// =====================================================
// SAVE HISTORY
// =====================================================

void saveHistory(
    string name,
    string category,
    string difficulty,
    int score,
    int total)
{
    ofstream file(
        "quiz_history.txt",
        ios::app);


    float accuracy;

    if (total > 0)
    {
        accuracy =
            ((float)score / total) * 100;
    }
    else
    {
        accuracy = 0;
    }


    file << "Name: "
         << name

         << " | Category: "
         << category

         << " | Difficulty: "
         << difficulty

         << " | Score: "
         << score << "/" << total

         << " | Accuracy: "
         << fixed << setprecision(2)
         << accuracy << "%"

         << endl;


    file.close();
}


// =====================================================
// HISTORY MODULE
// =====================================================

void showHistory()
{
    ifstream file(
        "quiz_history.txt");


    string line;


    cout << "\n========================================\n";
    cout << "              QUIZ HISTORY\n";
    cout << "========================================\n";


    if (!file)
    {
        cout << "No history available.\n";

        cout << "========================================\n";

        return;
    }


    while (getline(file, line))
    {
        cout << line << endl;
    }


    file.close();


    cout << "========================================\n";
}


// =====================================================
// MAIN FUNCTION
// =====================================================

int main()
{
    srand(
        (unsigned int)time(NULL));


    vector<Question> questions;


    // =================================================
    // PROGRAMMING - EASY
    // =================================================

    addQuestion(
        questions,
        1,
        "Programming",
        "Easy",
        "C++ Basics",
        "Which language is used in this project?",
        "Java",
        "Python",
        "C++",
        "HTML",
        'C');


    addQuestion(
        questions,
        2,
        "Programming",
        "Easy",
        "C++ Basics",
        "Which symbol ends a C++ statement?",
        ".",
        ":",
        ";",
        ",",
        'C');


    addQuestion(
        questions,
        3,
        "Programming",
        "Easy",
        "Variables",
        "Which keyword declares an integer?",
        "float",
        "int",
        "char",
        "double",
        'B');


    // =================================================
    // PROGRAMMING - MEDIUM
    // =================================================

    addQuestion(
        questions,
        4,
        "Programming",
        "Medium",
        "Pointers",
        "Which symbol gives the address of a variable?",
        "&",
        "*",
        "#",
        "@",
        'A');


    addQuestion(
        questions,
        5,
        "Programming",
        "Medium",
        "Pointers",
        "Which symbol is used to declare a pointer?",
        "&",
        "*",
        "%",
        "$",
        'B');


    addQuestion(
        questions,
        6,
        "Programming",
        "Medium",
        "Functions",
        "Which keyword returns a value from a function?",
        "break",
        "continue",
        "return",
        "exit",
        'C');


    // =================================================
    // PROGRAMMING - HARD
    // =================================================

    addQuestion(
        questions,
        7,
        "Programming",
        "Hard",
        "OOP",
        "Which concept allows a class to acquire properties of another class?",
        "Inheritance",
        "Encapsulation",
        "Abstraction",
        "Overloading",
        'A');


    addQuestion(
        questions,
        8,
        "Programming",
        "Hard",
        "OOP",
        "Which concept hides internal implementation details?",
        "Inheritance",
        "Abstraction",
        "Looping",
        "Compilation",
        'B');


    addQuestion(
        questions,
        9,
        "Programming",
        "Hard",
        "Data Structures",
        "Which data structure follows LIFO?",
        "Queue",
        "Stack",
        "Tree",
        "Graph",
        'B');


    // =================================================
    // SCIENCE - EASY
    // =================================================

    addQuestion(
        questions,
        10,
        "Science",
        "Easy",
        "Physics",
        "What is the SI unit of force?",
        "Joule",
        "Newton",
        "Watt",
        "Pascal",
        'B');


    addQuestion(
        questions,
        11,
        "Science",
        "Easy",
        "Biology",
        "Which organ pumps blood?",
        "Brain",
        "Lungs",
        "Heart",
        "Kidney",
        'C');


    addQuestion(
        questions,
        12,
        "Science",
        "Easy",
        "Chemistry",
        "What is the chemical formula of water?",
        "CO2",
        "H2O",
        "O2",
        "NaCl",
        'B');


    // =================================================
    // SCIENCE - MEDIUM
    // =================================================

    addQuestion(
        questions,
        13,
        "Science",
        "Medium",
        "Physics",
        "What is the approximate speed of light?",
        "3 x 10^8 m/s",
        "3 x 10^5 m/s",
        "3 x 10^3 m/s",
        "3 x 10^2 m/s",
        'A');


    addQuestion(
        questions,
        14,
        "Science",
        "Medium",
        "Physics",
        "Which device measures temperature?",
        "Barometer",
        "Thermometer",
        "Ammeter",
        "Voltmeter",
        'B');


    addQuestion(
        questions,
        15,
        "Science",
        "Medium",
        "Chemistry",
        "What is the pH value of pure water?",
        "5",
        "6",
        "7",
        "8",
        'C');


    // =================================================
    // SCIENCE - HARD
    // =================================================

    addQuestion(
        questions,
        16,
        "Science",
        "Hard",
        "Physics",
        "Which law states action and reaction are equal and opposite?",
        "Newton's First Law",
        "Newton's Second Law",
        "Newton's Third Law",
        "Ohm's Law",
        'C');


    addQuestion(
        questions,
        17,
        "Science",
        "Hard",
        "Biology",
        "Which molecule carries genetic information?",
        "Protein",
        "DNA",
        "Glucose",
        "Lipid",
        'B');


    addQuestion(
        questions,
        18,
        "Science",
        "Hard",
        "Chemistry",
        "Which gas is most abundant in Earth's atmosphere?",
        "Oxygen",
        "Nitrogen",
        "Carbon Dioxide",
        "Hydrogen",
        'B');


    // =================================================
    // GENERAL KNOWLEDGE - EASY
    // =================================================

    addQuestion(
        questions,
        19,
        "General Knowledge",
        "Easy",
        "Countries",
        "What is the capital of India?",
        "Mumbai",
        "New Delhi",
        "Chennai",
        "Kolkata",
        'B');


    addQuestion(
        questions,
        20,
        "General Knowledge",
        "Easy",
        "Countries",
        "Which country is known as the Land of the Rising Sun?",
        "India",
        "China",
        "Japan",
        "Russia",
        'C');


    addQuestion(
        questions,
        21,
        "General Knowledge",
        "Easy",
        "Countries",
        "Which is the largest continent?",
        "Asia",
        "Africa",
        "Europe",
        "Australia",
        'A');


    // =================================================
    // GENERAL KNOWLEDGE - MEDIUM
    // =================================================

    addQuestion(
        questions,
        22,
        "General Knowledge",
        "Medium",
        "World",
        "Which is the largest ocean?",
        "Atlantic Ocean",
        "Indian Ocean",
        "Pacific Ocean",
        "Arctic Ocean",
        'C');


    addQuestion(
        questions,
        23,
        "General Knowledge",
        "Medium",
        "World",
        "Which is the smallest country in the world?",
        "India",
        "Vatican City",
        "Japan",
        "Nepal",
        'B');


    addQuestion(
        questions,
        24,
        "General Knowledge",
        "Medium",
        "World",
        "Which is the longest river in the world according to commonly cited measurements?",
        "Amazon",
        "Nile",
        "Ganga",
        "Yangtze",
        'B');


    // =================================================
    // GENERAL KNOWLEDGE - HARD
    // =================================================

    addQuestion(
        questions,
        25,
        "General Knowledge",
        "Hard",
        "World",
        "Which civilization built Machu Picchu?",
        "Roman",
        "Inca",
        "Greek",
        "Egyptian",
        'B');


    addQuestion(
        questions,
        26,
        "General Knowledge",
        "Hard",
        "World",
        "Which treaty ended World War I?",
        "Treaty of Versailles",
        "Treaty of Paris",
        "Treaty of Rome",
        "Treaty of Vienna",
        'A');


    addQuestion(
        questions,
        27,
        "General Knowledge",
        "Hard",
        "World",
        "Which ancient civilization developed near the Nile River?",
        "Roman",
        "Egyptian",
        "Greek",
        "Inca",
        'B');


    // =================================================
    // LOAD USED QUESTIONS
    // =================================================

    loadUsedQuestions();


    // =================================================
    // USER DETAILS
    // =================================================

    string name;
    string category;
    string difficulty;


    getUserDetails(
        name,
        category,
        difficulty);


    // =================================================
    // GET AVAILABLE QUESTIONS
    // =================================================

    vector<Question> quizQuestions;


    quizQuestions =
        getQuizQuestions(
            questions,
            category,
            difficulty);


    // =================================================
    // CHECK QUESTIONS
    // =================================================

    if (quizQuestions.size() == 0)
    {
        cout << "\n========================================\n";

        cout << "No new questions available for:\n";

        cout << "Category   : "
             << category << endl;

        cout << "Difficulty : "
             << difficulty << endl;

        cout << "\nPlease choose another category or "
             << "difficulty.\n";

        cout << "========================================\n";

        return 0;
    }


    // =================================================
    // TAKE MAXIMUM 3 QUESTIONS
    // WITHOUT resize()
    // =================================================

    vector<Question> selectedQuestions;

    int i;

    for (i = 0;
         i < (int)quizQuestions.size() && i < 3;
         i++)
    {
        selectedQuestions.push_back(
            quizQuestions[i]);
    }


    // =================================================
    // WRONG ANSWERS
    // =================================================

    vector<Question> wrongAnswers;


    // =================================================
    // QUIZ
    // =================================================

    int score = 0;
    int correct = 0;
    int wrong = 0;


    startQuiz(
        selectedQuestions,
        wrongAnswers,
        score,
        correct,
        wrong);


    // =================================================
    // SCORE & RESULT
    // =================================================

    displayResult(
        score,
        correct,
        wrong,
        (int)selectedQuestions.size());


    // =================================================
    // PERFORMANCE
    // =================================================

    showPerformance(
        score,
        (int)selectedQuestions.size());


    // =================================================
    // SAVE HISTORY
    // =================================================

    saveHistory(
        name,
        category,
        difficulty,
        score,
        (int)selectedQuestions.size());


    // =================================================
    // PRACTICE
    // =================================================
    if (wrongAnswers.size() > 0)
    {
        char choice;

        cout << "\nDo you want to practice "
             << "your weak topics? (Y/N): ";

        cin >> choice;

        choice = (char)toupper(choice);


        if (choice == 'Y')
        {
            practiceWrongAnswers(
                questions,
                wrongAnswers);
        }
    }
    else
    {
        cout << "\nExcellent!\n";
        cout << "You answered all questions correctly.\n";
        cout << "No practice required.\n";
    }
    // =================================================
    // HISTORY
    // =================================================
    char historyChoice;
    cout << "\nDo you want to view history? (Y/N): ";
    cin >> historyChoice;
    historyChoice =
        (char)toupper(historyChoice);


    if (historyChoice == 'Y')
    {
        showHistory();
    }
    // =================================================
    // END
    // =================================================
    cout << "\n========================================\n";
    cout << "        Thank You For Playing!\n";
    cout << "========================================\n";
    return 0;
}
