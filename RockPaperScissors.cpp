#include <iostream>
#include <string>
#include <random>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <thread>

using namespace std;

// ANSI color codes for terminal styling
namespace color {
    const string reset = "\033[0m";
    const string bold = "\033[1m";
    const string red = "\033[31m";
    const string green = "\033[32m";
    const string yellow = "\033[33m";
    const string blue = "\033[34m";
    const string magenta = "\033[35m";
    const string cyan = "\033[36m";
    const string gray = "\033[90m";
}

// Function to print text one character at a time for a "typing" effect
void typeWrite(const string &text, int delayMs = 15) {
    for (size_t i = 0; i < text.size(); ++i) {
        cout << text[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
}

int main()
{
    // Beautiful ASCII Art Banner at the very beginning of the game
    typeWrite(color::cyan + color::bold + R"(
    ==================================================
    |                                                |
    |          ROCK - PAPER - SCISSORS GAME          |
    |                                                |
    ==================================================
    )" + color::reset);

    // Welcome message with typing effect and cyan color
    typeWrite(color::cyan + "\nWelcome to the game! 😁\n" + color::reset);
    
    string help_input;
    typeWrite(color::yellow + "Press Enter to continue or type (Help) for the rules help 😊👌: " + color::reset);
    getline(cin, help_input);

    // Convert help input to lowercase
    transform(help_input.begin(), help_input.end(), help_input.begin(),
              [](unsigned char c) { return static_cast<char>(tolower(c)); });

    // Check if the user requested the rules
    if (help_input == "help" || help_input == "h")
    {
        typeWrite(color::green + "\n*** RULES ***\n" + color::reset);
        typeWrite("1) You choose and the computer chooses\n");
        typeWrite("2) Rock smashes Scissors -> Rock wins\n");
        typeWrite("3) Scissors cut Paper -> Scissors win\n");
        typeWrite("4) Paper covers Rock -> Paper wins\n");
    }
    
    typeWrite(color::gray + "\nMoving to the next step...\n\n" + color::reset);

    // Dictionary (unordered_map) for ASCII art with colors
    unordered_map<string, string> images = {
        {"rock", color::red + R"(
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
)" + color::reset}, 
    {"paper", color::blue + R"(
     _______
---'    ____)____
           ______)
          _______)
         _______)
---.__________))" + color::reset},
    {"scissors", color::yellow + R"(
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___))" + color::reset}
    };

    // Main game loop for replayability
    while (true) {
        string user_choice;
        typeWrite(color::cyan + "Enter your choice (rock, paper, scissors) or type 'exit' to quit: " + color::reset);
        cin >> user_choice;

        // Convert user choice to lowercase
        transform(user_choice.begin(), user_choice.end(), user_choice.begin(),
                  [](unsigned char c) { return static_cast<char>(tolower(c)); });
        
        // Option to exit the game
        if (user_choice == "exit") {
            typeWrite(color::magenta + "\nThanks for playing! Goodbye! 👋\n" + color::reset);
            break; // Exit the loop
        }

        // Validate user input
        if (user_choice != "rock" && user_choice != "paper" && user_choice != "scissors")
        {
            typeWrite(color::red + "Invalid choice. Please try again.\n\n" + color::reset);
            continue; // Skip this round and prompt again
        }

        // Generate random choice for the computer
        const string options[3] = {"rock", "paper", "scissors"};
        random_device seed_source;
        mt19937 generator(seed_source());
        uniform_int_distribution<int> choice_distribution(0, 2);
        int random_index = choice_distribution(generator);
        string computer_choice = options[random_index];

        // Display user's choice and art
        typeWrite(color::bold + "\n--- Your Choice ---\n" + color::reset);
        cout << images[user_choice] << endl;

        // Display computer's choice and art
        typeWrite(color::bold + "\n--- Computer's Choice ---\n" + color::reset);
        cout << images[computer_choice] << endl;

        typeWrite(color::cyan + "Computer chose : " + computer_choice + "\n" + color::reset);

        // Determine the winner
        if (user_choice == computer_choice)
        {
            typeWrite(color::yellow + "It's a tie! 🤝 \n\n" + color::reset);
        }
        else if ((user_choice == "rock" && computer_choice == "scissors") || 
                 (user_choice == "paper" && computer_choice == "rock") || 
                 (user_choice == "scissors" && computer_choice == "paper"))
        {
            typeWrite(color::green + "You win! 🎉\n\n" + color::reset);
        }
        else 
        {
            typeWrite(color::red + "You lose! 😢\n\n" + color::reset);
        }

        // Ask the user if they want to play again
        string play_again;
        typeWrite(color::yellow + "Do you want to play again? (y/n): " + color::reset);
        cin >> play_again;

        // Convert response to lowercase
        transform(play_again.begin(), play_again.end(), play_again.begin(),
                  [](unsigned char c) { return static_cast<char>(tolower(c)); });

        if (play_again != "y" && play_again != "yes") {
            typeWrite(color::magenta + "\nThanks for playing! Goodbye! 👋\n" + color::reset);
            break; 
        }
        
        typeWrite(color::gray + "\n----------------------------------------\n\n" + color::reset);
    } 

    return 0;
} 