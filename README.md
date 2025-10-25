## 🚀 Project Overview
The goal of cub3d is to create a simple 3D game engine inspired by Wolfenstein 3D. Using raycasting and the MLX42 graphics library, the project renders a 3D view from a 2D map, allowing the player to navigate a maze-like world. This project strengthens understanding of:

  - Raycasting techniques for 3D rendering
  - Graphics rendering with [MLX42](https://github.com/codam-coding-college/MLX42)
  - Event handling and player input
  - Map parsing and validation
  - Game logic and collision handling

## 📁 Project Structure
### ✅ Mandatory Part

  - Parse and validate a .cub map file.
  - Render a 3D view using raycasting from a 2D map.
  - Implement player movement and rotation.
  - Handle wall collisions and prevent invalid moves.
  - Support textures for walls and colors for floor/ceiling.
  - Close the game when the player presses ESC or clicks the close button.

### 🗺️ Map Specifications
The map is defined in a .cub file and must include:

  - 1 for walls
  - 0 for empty space
  - N, S, E, or W for player starting position (direction included)
  - Texture paths for walls (north, south, east, west)
  - RGB values for floor and ceiling colors

🔧 Compilation & Usage
The project includes a Makefile for building the game.

    make
    ./cub3d maps/example.cub


### 🎮 Controls

  - W / A / S / D: Move forward / left / backward / right

  - ← / →: Rotate camera left / right

  - ESC: Exit the game

### 🧠 What We Learned

  - Implementing a raycasting algorithm to simulate 3D graphics
  - Using MLX42 for real-time rendering
  - Managing player input and smooth movement/rotation
  - Parsing and validating complex configuration files
  - Handling textures, colors, and collision detection
