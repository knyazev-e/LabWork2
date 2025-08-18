# System Description

## 1. General System Description

The project is a turn-based battle game that combines character classes, diverse actions, and item usage mechanics. It features a battle system where players and enemies take turns performing actions and equipping affecting health, mana, attack and defense attributes. The core system is implemented in C++ with an object-oriented design using class hierarchy, polymorphysm and smart pointers to manage object lifetimes safely.

Key components:

- **Game Controller:** Manages game flow, user input, state transitions, characters, battles and enemies.
- **Battle System:** Manages turn order, actions, damage calculations, and battle state, storing catalogs of actions and items.
- **Character Classes:** Players and enemies derive from a common Character class with specialized subclasses for class-specific stats and behaviors.
- **Actions and Items:** Abstract Action and Item classes define interfaces for various derived concrete classes (e.g., spells, attacks, weapons, armor) implementing gameplay functionality.

## 2. System Requirements

### Hardware

- CPU: Modern dual-core processor
- Memory: Approximately 50-100 MB RAM
- Storage: No more than 100 MB for executable, related files and the source code.

### Software

- Operating System: Ubuntu
- Compiler: G++ (supporting C++17 standard)
- Build system: Make

The game requires a terminal environment and is designed to run as a command-line executable.

## 3. Usage Scenarios

### Starting the Game

- The player launches the executable from the terminal.
- The main menu displays options: start battle, character selection, statistics, settings, quit.
- Player inputs choice to navigate the menu.

### Battle Flow

- Selecting "start battle" initializes the battle with player and enemy characters.
- Turn-based loop begins with action selection for player and AI decision for enemy.
- Actions cause changes in attributes, calculated using defined mechanics.
- Battle proceeds until one character's health reaches zero.
- Post-battle statistics are recorded; player returns to main menu.

### Character Editing

- Player can edit character name and class via menu.
- Class selection sets the player's charcter to a default character of the chosen class.

### Game Settings

- Player can configure difficulty and view help screens.
