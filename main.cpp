#include <iostream>
#include "Game.hpp"

void printCards(Cards cards)
{

}

int main()
{
    int choice;
    int numberOfPlayers;

    std::cout << "-- PEASANTS --" << std::endl;

    std::cout << "1. Start new game" << std::endl;
    std::cout << "2. Exit" << std::endl;

    std::cin >> choice;

    if (choice == 1)
    {
        std::cout << "Number of players:" << std::endl;

        std::cin >> numberOfPlayers;

        Game game(numberOfPlayers);

        while (not game.hasEnded())
        {
            int option;

            std::cout << "Current player " << game.getCurrentPlayer().getId() << std::endl;

            std::cout << "Your cards: ";
            printCards(game.getCurrentPlayer().getCards());
            std::cout << std::endl;
            std::cout << "1. Select Cards" << std::endl;
            std::cin >> option;
            game.nextPlayer();
        }
    }

    return 0;
}

