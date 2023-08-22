# Battleship Game

A simple implementation of the Battleship game in C++ played in the console.

## Table of Contents

- [How to Play](#how-to-play)
- [Game Mechanics](#game-mechanics)
- [Files](#files)
- [Note](#note)

## How to Play

This repository contains a console-based version of the classic Battleship game. Follow these steps to play the game:

1. **Clone the Repository:** Clone this repository to your local machine:

   ```bash
   git clone https://github.com/your-username/battleship.git

2. **Compile and Run:**

   a) Navigate to the repository's directory and compile the code:

      ```bash
         cd battleship
         g++ main.cpp -o battleship
      ```

   b) Run the compiled executable:

      ```bash
         ./battleship
      ```

## Game Mechanics

- Ships are placed randomly on a 10x10 game board.
- Players take turns firing shots at each other's boards.
- The game indicates hits and misses, and the first player to sink all opponent's ships wins.

## Files

`main.cpp`: The main driver of the game, initializing and managing gameplay.  
`model.h`: Defines the model class for managing the game board and interactions.  
`point.h`: Contains the point class to handle coordinates.  
`ship.h`: Defines the ship class for ship-related functionality.  



   
