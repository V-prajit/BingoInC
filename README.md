# BINGO in C

A simple command-line BINGO game implemented in C.

## Features

- Generates a random BINGO card with numbers according to standard BINGO rules
- Simulates drawing random BINGO numbers
- Checks for winning conditions (row, column, or diagonal)
- Saves the BINGO card and picked numbers to a file

## How to Play

1. Compile the program:
   ```
   gcc Main.c -o bingo
   ```

2. Run the game:
   ```
   ./bingo
   ```

3. When a number is called, respond with 'Y' if you have it or 'N' if you don't.

## Game Rules

- The BINGO card is a 5x5 grid with the middle space marked as 'X' (free space)
- B column contains numbers 1-15
- I column contains numbers 16-30
- N column contains numbers 31-45
- G column contains numbers 46-60
- O column contains numbers 61-75
- The game continues until you complete a row, column, or diagonal