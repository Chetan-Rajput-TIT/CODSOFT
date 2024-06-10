#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

     srand(time(0));
    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;

    // Variables to store user input and feedback
    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Guessing Game!\n";
    std::cout << "Try to guess the number between 1 and 100.\n\n";

    do {
        // Prompt user for guess
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        // Check if the guess is too high, too low, or correct
        if (guess > randomNumber) {
            std::cout << "Too high! Try again.\n";
        } else if (guess < randomNumber) {
            std::cout << "Too low! Try again.\n";
        }

        attempts++;

    } while (guess != randomNumber);

    // Congratulate the user on guessing the correct number
    std::cout << "\nCongratulations! You guessed the number " << randomNumber << " correctly in " << attempts << " attempts.\n";

    return 0;
}
