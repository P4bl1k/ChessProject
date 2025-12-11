# ChessProject
Created by Pavel Zhernoklev and Mike Agarunov
Magshimim C++ Course — Mid-Year Project
Introduction ( ^_^ )

Welcome to ChessProject, a full C++ implementation of the classic game of chess.
This project was developed as part of the Magshimim C++ course, combining object-oriented programming, clean architecture, and game logic.
Our goal was to create a structured, readable, and fully functional chess engine.
We focused heavily on clarity, modularity, and accurate game mechanics.

Project Features

Full chess game logic

All pieces implemented with proper move rules

Turn-based system for two players

Check, checkmate, and illegal move detection

Board rendering in console and in gui of magshimim

Strong OOP design: inheritance, polymorphism

Clear separation between game engine, board representation, and input handling

User-friendly and robust error handling

Clean comments and organized code structure

Architecture Overview ( ^‿^ )

The project is built around several core components:

1. Piece Hierarchy

Each chess piece is represented by its own class, all inheriting from a common Figure base class.
This allows shared behavior while keeping the move logic unique to each piece type.

2. Board Class

Manages:

Piece positions

Move validation

Checking for threats

Game state updates

3. Game Controller

Handles:

Turn switching

Input parsing

Game flow

Win/lose conditions

4. Utility Modules

Small helper functions for coordinate translation, input sanitization, and color/piece representation.

How to Run ( ^_− )

Compile all .cpp files together using your preferred compiler.

Run the executable.

Enter moves in the required notation (for example: e2 e4).

Play until checkmate or stalemate.

Enjoy.

Design Principles

Code should be easy to understand, even months later

Classes have one clear responsibility

Reusability and maintainability were prioritized

Avoid unnecessary complexity

Keep everything readable and beginner-friendly

Credits ( ≧▽≦ )

This project was created by:

Pavel Zhernoklev

Mike Agarunov

Both contributors worked together on architecture, implementation, debugging, and overall design.
