#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Game.hpp"

void printCards(Cards cards)
{
    std::cout << "Number of cards: " << cards.size() << std::endl;

    for (unsigned int i = 0; i < cards.size(); i++)
    {
        switch (cards[i].value)
        {
            case jack:
                std::cout << "jack";
                break;
            case queen:
                std::cout << "queen";
                break;
            case king:
                std::cout << "king";
                break;
            case ace:
                std::cout << "ace";
                break;
            default:
                std::cout << cards[i].value;
        }

        std::cout << " ";

        switch (cards[i].color)
        {
            case hearts:
                std::cout << "hearts";
                break;
            case diamonds:
                std::cout << "diamonds";
                break;
            case clubs:
                std::cout << "clubs";
                break;
            case spades:
                std::cout << "spades";
                break;
        }

        if (cards[i].selected)
        {
            std::cout << " (selected)";
        }

        std::cout << std::endl;
    }
}

int main()
{
    std::srand(std::time(0));

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
            int option = 0;

            std::cout << "Current player " << game.getCurrentPlayer().getId() << std::endl;

            std::cout << "Your cards:" << std::endl;
            printCards(game.getCurrentPlayer().getCards());
            std::cout << std::endl;
            std::cout << "1. Select cards" << std::endl;
            std::cout << "2. Unselect all cards" << std::endl;
            std::cout << "3. Throw selected cards" << std::endl;
            std::cout << "4. Pass your turn" << std::endl;
            std::cin >> option;

            while (option != 3 and option != 4)
            {
                switch (option)
                {
                    case 1:
                        break;
                    case 2:
                        game.getCurrentPlayer().unselectAllCards();
                        break;
                    case 3:
                        break;
                    case 4:
                        game.getCurrentPlayer().unselectAllCards();
                        std::cout << "Passing turn" << std::endl;
                        break;
                    default:
                        std::cout << "Wrong option" << std::endl;
                }
            }

            game.nextPlayer();
        }
    }

    return 0;
}

