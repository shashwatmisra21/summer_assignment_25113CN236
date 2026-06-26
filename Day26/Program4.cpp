#include <iostream>
#include <string>
#include <vector>

class Question {
private:
    std::string questionText;
    std::string options[4];
    char correctAnswer;

public:
    Question(std::string text, std::string o1, std::string o2, std::string o3, std::string o4, char ans) {
        questionText = text;
        options[0] = o1;
        options[1] = o2;
        options[2] = o3;
        options[3] = o4;
        correctAnswer = ans;
    }
    void displayQuestion() const {
        std::cout << "\n" << questionText << "\n";
        std::cout << "A. " << options[0] << "\n";
        std::cout << "B. " << options[1] << "\n";
        std::cout << "C. " << options[2] << "\n";
        std::cout << "D. " << options[3] << "\n";
    }
    bool checkAnswer(char userAns) const {
        return (std::toupper(userAns) == correctAnswer);
    }
    char getCorrectAnswer() const {
        return correctAnswer;
    }
};

int main() {
    std::vector<Question> quiz;
    quiz.push_back(Question("What is the correct syntax to print text in C++?", "print(\"Hello\");", "cout << \"Hello\";", "System.out.print(\"Hello\");", "echo \"Hello\";", 'B'));
    quiz.push_back(Question("Which data type is used to store text characters in C++?", "string", "int", "float", "boolean", 'A'));
    quiz.push_back(Question("Which operator is used to find the remainder of a division?", "/", "*", "%", "#", 'C'));
    quiz.push_back(Question("How do you insert a single-line comment in C++ code?", "# Comment", "/* Comment */", "<!-- Comment -->", "// Comment", 'D'));

    int score = 0;
    char userAnswer;

    std::cout << "=================================\n";
    std::cout << "       WELCOME TO THE QUIZ       \n";
    std::cout << "=================================\n";
    std::cout << "Answer the following multiple-choice questions:\n";
    for (size_t i = 0; i < quiz.size(); ++i) {
        std::cout << "\nQuestion " << (i + 1) << " of " << quiz.size();
        quiz[i].displayQuestion();

        std::cout << "Your answer (A/B/C/D): ";
        std::cin >> userAnswer;

        if (quiz[i].checkAnswer(userAnswer)) {
            std::cout << "✅ Correct!\n";
            score++;
        } else {
            std::cout << "❌ Wrong! The correct answer was " << quiz[i].getCorrectAnswer() << ".\n";
        }
    }
    std::cout << "\n=================================\n";
    std::cout << "           QUIZ OVER!            \n";
    std::cout << "=================================\n";
    std::cout << "Your Final Score: " << score << " out of " << quiz.size() << "\n";
    if (score == quiz.size()) {
        std::cout << "🏆 Perfect Score! Brilliant job!\n";
    } else if (score >= quiz.size() / 2) {
        std::cout << "👍 Good effort! Keep practicing.\n";
    } else {
        std::cout << "📚 Time to study up and try again!\n";
    }

    return 0;
}
