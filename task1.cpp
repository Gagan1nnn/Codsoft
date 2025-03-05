#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0))); 
    int randomNumber = rand() % 100 + 1; 
    int userGuess;

    cout << "Guess the number (between 1 and 100): ";

    do {
        cin >> userGuess; 

        if (userGuess < randomNumber) {
            cout << "Too low! Try again: ";
        } else if (userGuess > randomNumber) {
            cout << "Too high! Try again: ";
        }
    } while (userGuess != randomNumber);

    cout << "Congratulations! You guessed the number: " << randomNumber << endl;

    return 0;
}
