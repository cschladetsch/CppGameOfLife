# Conway's Game of Life in C++23

## Overview

This is a terminal-based implementation of Conway's Game of Life, written in modern C++23. The simulation runs on a 20x20 grid, displaying the evolution of cellular automata using a classic glider pattern as the initial configuration.

## Features

- 20x20 grid simulation
- Implemented using modern C++23 features
- Real-time visualization in the terminal
- Automatic generation updates
- ANSI terminal control for smooth rendering

## Game of Life Rules

The simulation follows the classic Conway's Game of Life rules:

1. Any live cell with fewer than two live neighbors dies (underpopulation)
2. Any live cell with two or three live neighbors lives on to the next generation
3. Any live cell with more than three live neighbors dies (overpopulation)
4. Any dead cell with exactly three live neighbors becomes a live cell (reproduction)

## Prerequisites

- A modern C++ compiler supporting C++23 (GCC 13+, Clang 16+, or MSVC 19.35+)
- CMake (optional, but recommended for building)

## Compilation

Simply run

```bash
$ ./r
```

Or, if you want to do it manually:

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./life
```

## Running the Simulation

Execute the compiled binary:

```bash
./life
```

## Initial Pattern

The simulation starts with a classic "glider" pattern:

```
  .O.
  ..O
  OOO
```

This pattern will move diagonally across the grid, demonstrating the interesting emergent behavior of cellular automata.

## Controls

- The simulation runs automatically
- Press `Ctrl+C` to exit

## Terminal Requirements

- The application uses ANSI escape codes for screen manipulation
- Works best in Unix-like terminals (Linux, macOS)
- Windows users may need to use Windows Terminal or WSL

## Customization

To modify the simulation, you can adjust the following in the source code:
- Grid size (currently hardcoded to 20x20)
- Initial pattern configuration
- Update interval (currently set to 100ms)

## Performance Notes

- The implementation uses `std::array` for compile-time fixed-size grid
- Neighbor counting is optimized with bounds checking
- Real-time rendering may have slight performance overhead

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

MIT

## Acknowledgments

- Inspired by the original Game of Life concept by John Conway
- Converted from an x86-64 assembly implementation

## See Also

- [Cellular Automata on Wikipedia](https://en.wikipedia.org/wiki/Cellular_automaton)
- [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)
