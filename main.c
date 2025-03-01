#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MIN_NUMBER 1
#define MAX_NUMBER 100
#define MAX_GUESSES 10

// Function to display the game instructions
void displayInstructions() {
    printf("Welcome to the Random Number Guesser!\n");
    printf("I have selected a number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
    printf("You have %d attempts to guess the number.\n", MAX_GUESSES);
    printf("Let's begin!\n\n");
}

// Function to get a valid guess from the user
int getGuess(int attempt) {
    int guess;
    while (1) {
        printf("Attempt %d: Guess the number (%d-%d): ", attempt, MIN_NUMBER, MAX_NUMBER);
        if (scanf("%d", &guess) == 1 && guess >= MIN_NUMBER && guess <= MAX_NUMBER) {
            return guess;
        } else {
            printf("Invalid input! Please enter a number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
            // Clear the input buffer
            while (getchar() != '\n');
        }
    }
}

int main() {
    srand(time(0)); // Seed the random number generator

    int randomNumber = (rand() % MAX_NUMBER) + MIN_NUMBER; // Generate random number
    int attempts = 0;
    int guess;

    displayInstructions();

    do {
        attempts++;
        guess = getGuess(attempts);

        if (guess < randomNumber) {
            printf("Too low! Try again.\n");
        } else if (guess > randomNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        }

        if (attempts >= MAX_GUESSES) {
            printf("Sorry, you've used all %d attempts. The number was %d.\n", MAX_GUESSES, randomNumber);
            break;
        }
    } while (guess != randomNumber);

    return 0;
}