# 🎮 Rock - Paper - Scissors (C++ Console Game)

A colorful terminal version of the classic **Rock-Paper-Scissors** game written in modern C++. It features ASCII art, ANSI colors, a typewriter text effect, and a replayable game loop.

![C++](https://img.shields.io/badge/C%2B%2B-11%2B-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey.svg)

## ✨ Features

- 🎨 Colored output using ANSI escape codes
- ⌨️ Typewriter ("typing") effect for all messages
- 🖼️ ASCII art for Rock, Paper, and Scissors
- 📖 Built-in rules via the `help` command
- 🎲 Fair computer choice using `std::random_device` and `std::mt19937`
- 🔁 Play as many rounds as you like, or type `exit` to quit
- ✅ Input validation and case-insensitive input

## 📋 Rules

| Your choice | Beats    |
|-------------|----------|
| Rock        | Scissors |
| Scissors    | Paper    |
| Paper       | Rock     |

If both choose the same, it's a tie.

## 🛠️ Requirements

- A C++ compiler with C++11 support or newer (`g++`, `clang++`, or MSVC)
- A terminal that supports ANSI colors and UTF-8 (for emojis)

## 🚀 Build & Run

### Linux / macOS

```bash
g++ -std=c++17 -O2 rock_paper_scissors.cpp -o rps
./rps
```

### Windows (MinGW / MSYS2)

```bash
g++ -std=c++17 -O2 rock_paper_scissors.cpp -o rps.exe
rps.exe
```

> 💡 On Windows, use **Windows Terminal** (or run `chcp 65001` in CMD) for correct colors and emoji display.

## 🕹️ How to Play

1. Run the program.
2. Press **Enter** to start, or type `help` (or `h`) to read the rules.
3. Type `rock`, `paper`, or `scissors`.
4. See the result, then choose `y` to play again or `n` to quit.
5. Type `exit` at any prompt for a choice to leave the game.

## 📸 Preview

```text
    ==================================================
    |                                                |
    |          ROCK - PAPER - SCISSORS GAME          |
    |                                                |
    ==================================================

Welcome to the game! 😁
Enter your choice (rock, paper, scissors) or type 'exit' to quit: rock

--- Your Choice ---
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)

Computer chose : scissors
You win! 🎉
```

## 📁 Project Structure

```text
.
├── rock_paper_scissors.cpp
├── README.md
└── LICENSE
```

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to open an issue or submit a pull request.

Ideas for improvement:
- Score tracking across rounds
- Best-of-N mode
- Difficulty levels
- Rock-Paper-Scissors-Lizard-Spock mode

## 📄 License

This project is licensed under the [MIT License](LICENSE).

## 👤 Author

**Your Name** — [@your-github-username](https://github.com/your-github-username)
