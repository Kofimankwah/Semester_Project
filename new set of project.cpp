#include <iostream>
#include <vector>
using namespace std;
class Question {
public:
    Question(const string& text, const string& answer) : text(text), answer(answer) {}

    bool checkAnswer(const string& userAnswer) const {
        return userAnswer == answer;
    }

    void display() const {
        cout << text << endl;
    }

private:
    string text;
    string answer;
};

class Exam {
public:
    void addQuestion(const string& text, const string& answer) {
        questions.push_back(Question(text, answer));
    }

    void conductExam() {
        for (size_t i = 0; i < questions.size(); ++i) { // Changed "For" to "for"
            cout << "Question " << i + 1 << ": ";
            questions[i].display(); // Changed "Questions[i]" to "questions[i]"
            string userAnswer;
            cout << "Your Answer:";
            cin >> userAnswer;
            if (questions[i].checkAnswer(userAnswer)) {
                cout << "Correct!" <<endl;
            } else {
             cout << "Incorrect." << endl;
            }
        }
    }

private:
    vector<Question> questions;
};

int main() {
    Exam exam;

    exam.addQuestion("what is the biggest country?", "ghana");
    exam.addQuestion("Which planet is known as the Red Planet?", "Mars");
    exam.addQuestion("What is the largest mammal?", "Blue Whale");

    cout << "Welcome to the Online Exam!" << endl;
    cout << "You will be asked a series of questions." << endl;
    cout << "Please answer each question." << endl;

    exam.conductExam();

    cout << "Exam complete. Thank you for participating!" << endl;

    return 0;
}
