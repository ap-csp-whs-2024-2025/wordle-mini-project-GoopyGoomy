/**
* listhelpers.hpp has been provided by the instructor as starter code
* contains the following procedures to work with lists:
* display, append, insert, remove, length
*/
#include "listhelpers.hpp"

#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include <iostream>  // std::cin, std::cout
#include <string>    // std::string, std::getline
#include <vector>    // std::vector

std::vector<int> createSecret(int size) {
    std::vector<int> code = {};
    int counter = 0;
    while (counter < 4) //REPEAT 4 TIMES
    {
        int val = rand() % 10; //random  number between 0 and 9
        code.push_back(val); //append (code, val); This is pushing back val into the list code
        counter = counter + 1;
    }
    return code;    
}

std::vector<std::string> getHint(std::vector<int> secret, std::vector<int> guess) {
    // Write this procedure here
    //maybe make a list for the X's and O's
    //go down the list of randomied numbers and do if statements
    std::vector<std::string> hint = {};
    int curr_index = 0;

    while(curr_index < length(guess))
    {
        if (guess[curr_index] != secret[curr_index])
        {
            //append(hint, "X")
            hint.push_back("X");
        }
        else
        {
            hint.push_back("O");
        }
        curr_index = curr_index + 1;
    }
    return hint;    // replace this with your code
}

bool winGame(std::vector<int> secret, std::vector<int> guess) {
    // Write this procedure here
    std::vector<std::string> win = {};
    int curr_index = 0;

    while (curr_index < length(secret))
    {
        if(guess[curr_index] != secret[curr_index])
        {
            return false;
        }
        curr_index = curr_index + 1;
    }
    return true;
     // replace this with your code
}

int main()
{
    // Seeding the random number generator
    // Uncomment the code when you are finished testing your program
    // and want to have the program run for real
    // srand(time(0));

    srand(time(0)); // seeds our random number generator
    int random_num = rand() % 10;  // random number between 0 and 9
    
    std::vector<int> secret_code = createSecret(4);
    std::cout << "Here is the secret code: ";
    display (secret_code);
    std::vector<int> user_guess = {-1, -1, -1, -1};
    std::vector<std::string> hint = {};    // an empty list

    int secret_code_length = 4;
    int num_guesses = 0;

    std::cout << "Welcome to Number Wordle!\n";
    
    while (!winGame(secret_code, user_guess))    // while you have not won the game yet
    {
        std::cout << "\nEnter your guess: ";
        user_guess = {};    // reset the guess for the next guess
        for (int counter = 0; counter < secret_code_length; counter = counter + 1)
        {
            int input;
            std::cin >> input;
            user_guess.push_back(input);    // can also do append(guess, input);
        }

        hint = getHint(secret_code, user_guess);
        display(hint);
        num_guesses = num_guesses + 1;
    }

    std::cout << "Congrats!  You guessed the code!  It took you " << num_guesses << " tries.\n";
    return 0;
}
