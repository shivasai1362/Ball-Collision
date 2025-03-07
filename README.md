# Ball Collision Simulation

This project is a simple physics engine that simulates the collision of balls. It allows users to create new balls within the simulation environment and apply random impulses to all balls, resulting in dynamic interactions.

## Features

- **Interactive Ball Creation**: Left-click within the simulation window to create a new ball at the cursor's position.
- **Random Impulse Application**: Right-click to apply a random impulse to all balls, causing them to move in random directions.

## Important Note

- **To run the project directly, clone the repository in CLion.**

## Prerequisites

- No external dependencies are required. **SFML is preinstalled within the repository**, so users do not need to install SFML separately.

## Installation

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/shivasai1362/Ball-Collision.git
   ```

2. **Navigate to the Project Directory**:

   ```bash
   cd Ball-Collision
   ```

3. **Build the Project**:

   - Ensure that you have a C++ compiler and CMake installed.
   - Run the following commands:

     ```bash
     mkdir build
     cd build
     cmake ..
     make
     ```

## Usage

- **Controls**:

  - **Left Click**: Create a new ball at the cursor's position.
  - **Right Click**: Apply a random impulse to all balls, causing them to move in random directions.

## Implementation Details

The simulation handles ball interactions by resolving collisions using physics principles, including the conservation of momentum and kinetic energy. Each ball has properties such as position, velocity, radius, and mass, which influence their behavior during collisions.

## Acknowledgments

- This project was developed by [shivasai1362](https://github.com/shivasai1362).
- Inspired by various ball collision simulations and physics engines available in the open-source community.

