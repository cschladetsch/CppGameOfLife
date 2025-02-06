#include <iostream>
#include <array>
#include <chrono>
#include <thread>

// Grid dimensions
constexpr int ROWS = 20;
constexpr int COLS = 20;

// Grid representation
class GameOfLife {
private:
    // Two grids for current and next generation
    std::array<std::array<bool, COLS>, ROWS> current_grid{};
    std::array<std::array<bool, COLS>, ROWS> next_grid{};

    // Count live neighbors with bounds checking
    [[nodiscard]] int count_neighbors(int row, int col) const {
        int neighbors = 0;
        for (int r = std::max(0, row - 1); r <= std::min(ROWS - 1, row + 1); ++r) {
            for (int c = std::max(0, col - 1); c <= std::min(COLS - 1, col + 1); ++c) {
                // Skip the cell itself
                if (r == row && c == col) continue;
                
                // Count live neighbors
                neighbors += current_grid[r][c];
            }
        }
        return neighbors;
    }

    // Apply Game of Life rules
    void update_generation() {
        // Clear next grid
        next_grid = {};

        // Process each cell
        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                int live_neighbors = count_neighbors(row, col);

                // Apply Game of Life rules
                if (current_grid[row][col]) {
                    // Live cell survives with 2 or 3 neighbors
                    next_grid[row][col] = (live_neighbors == 2 || live_neighbors == 3);
                } else {
                    // Dead cell becomes alive with exactly 3 neighbors
                    next_grid[row][col] = (live_neighbors == 3);
                }
            }
        }

        // Update current grid
        current_grid = next_grid;
    }

    // Display the grid
    void display_grid() const {
        // ANSI clear screen and move cursor to home
        std::cout << "\033[2J\033[H";

        for (const auto& row : current_grid) {
            for (bool cell : row) {
                std::cout << (cell ? '*' : '.');
            }
            std::cout << '\n';
        }
        std::cout.flush();
    }

    // Initialize grid with a glider pattern
    void initialize_grid() {
        // Clear grid first
        current_grid = {};

        // Set up glider:
        //   .O.     position (1,1)
        //   ..O     position (2,2)
        //   OOO     position (3,0),(3,1),(3,2)
        current_grid[1][1] = true;  // (1,1)
        current_grid[2][2] = true;  // (2,2)
        current_grid[3][0] = true;  // (3,0)
        current_grid[3][1] = true;  // (3,1)
        current_grid[3][2] = true;  // (3,2)
    }

public:
    // Run the Game of Life simulation
    void run() {
        // Hide cursor and save screen
        std::cout << "\033[?1049h\033[?25l";

        // Initialize grid
        initialize_grid();

        // Main simulation loop
        while (true) {
            // Display current generation
            display_grid();

            // Update to next generation
            update_generation();

            // Sleep for 100ms
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    // Destructor to restore screen and show cursor
    ~GameOfLife() {
        std::cout << "\033[?25h\033[?1049l";
    }
};

int main() {
    try {
        GameOfLife().run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
