#include<bits/stdc++.h>

class SnakeAndLadder {
private:
    const int WIN_POINT = 100;
    std::map<int, int> snakes;
    std::map<int, int> ladders;
    std::map<std::string, int> players;

public:
    SnakeAndLadder() {
        // Initialize random seed
        srand(time(0));
    }

    void addSnake(int head, int tail) {
        snakes[head] = tail;
    }

    void addLadder(int start, int end) {
        ladders[start] = end;
    }

    void addPlayer(const std::string& name) {
        // All players start at position 0
        players[name] = 0;
    }

    int rollDice() {
        return (rand() % 6) + 1;
    }

    void movePlayer(const std::string& player) {
        int diceValue = rollDice();
        int initialPosition = players[player];
        int newPosition = initialPosition + diceValue;

        // Check for snake or ladder
        if (snakes.find(newPosition) != snakes.end()) {
            newPosition = snakes[newPosition];
        } else if (ladders.find(newPosition) != ladders.end()) {
            newPosition = ladders[newPosition];
        }

        // Check for win condition
        if (newPosition > WIN_POINT) {
            newPosition = initialPosition; // Player does not move if roll exceeds WIN_POINT
        } else {
            std::cout << player << " rolled a " << diceValue << " and moved from " << initialPosition << " to " << newPosition << std::endl;
        }

        players[player] = newPosition;

        if (newPosition == WIN_POINT) {
            std::cout << player << " wins the game!" << std::endl;
        }
    }

    void startGame() {
        bool gameWon = false;
        while (!gameWon) {
            for (auto& player : players) {
                movePlayer(player.first);
                if (players[player.first] == WIN_POINT) {
                    gameWon = true;
                    break;
                }
            }
        }
    }
};

int main() {
    SnakeAndLadder game;

    // Example setup
    game.addSnake(99, 54);
    game.addLadder(4, 14);
    game.addPlayer("Alice");
    game.addPlayer("Bob");

    game.startGame();

    return 0;
}
