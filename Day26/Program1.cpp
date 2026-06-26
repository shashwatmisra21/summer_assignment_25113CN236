#include <iostream>
#include <cstdlib> 
#include <ctime>  
int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int secretNumber = std::rand() % 100 + 1;
    int userGuess = 0;
    int attempts = 0;

    std::cout << "=================================\n";
    std::cout << "   WELCOME TO THE GUESSING GAME  \n";
    std::cout << "=================================\n";
    std::cout << "I have chosen a number between 1 and 100.\n";
    std::cout << "Can you guess what it is?\n\n";
    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess > secretNumber) {
            std::cout << "Too high! Try a lower number.\n\n";
        } else if (userGuess < secretNumber) {
            std::cout << "Too low! Try a higher number.\n\n";
        } else {
            std::cout << "\n🎉 Congratulations! You guessed it right!\n";
            std::cout << "It took you " << attempts << " attempts.\n";
        }
    } while (userGuess != secretNumber);

    return 0;
}
