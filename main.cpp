#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Game.hpp"

void printCards(Cards cards)
{
    if (not cards.size())
    {
        std::cout << "No cards" << std::endl;
    }

    for (unsigned int i = 0; i < cards.size(); i++)
    {
        std::cout << "[" << i << "] ";

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
    unsigned int numberOfPlayers;
    unsigned int numberOfRounds;

    std::cout << "-- PEASANTS --" << std::endl;

    std::cout << "1. Start new game" << std::endl;
    std::cout << "2. Exit" << std::endl;

    std::cin >> choice;

    if (choice == 1)
    {
        std::cout << "Number of players:" << std::endl;
        std::cin >> numberOfPlayers;

        std::cout << "Number of rounds:" << std::endl;
        std::cin >> numberOfRounds;

        Game game(numberOfPlayers);

        for (unsigned int i = 0; i < numberOfRounds; i++)
        {
            std::cout << "Round number " << (i + 1) << std::endl;

            while (not game.hasRoundEnded())
            {
                int option = 0;

                std::cout << "NEW TURN" << std::endl;

                std::cout << std::endl << "Cards on table:" << std::endl;
                printCards(game.getCardsFromTableTop());
                std::cout << std::endl << "Options:" << std::endl;

                std::cout << "1. Select card" << std::endl;
                std::cout << "2. Unselect all cards" << std::endl;
                std::cout << "3. Throw selected cards" << std::endl;
                std::cout << "4. Pass your turn" << std::endl;

                while (option != 3 and option != 4)
                {
                    std::cout << std::endl;
                    std::cout << "Current player: " << game.getCurrentPlayer().getId() << std::endl;
                    std::cout << "Peasant level: " << game.getCurrentPlayer().getPeasantLevel() << std::endl;
                    printCards(game.getCurrentPlayer().getCards());
                    std::cin >> option;
                    try
                    {
                        switch (option)
                        {
                            case 1:
                                int cardToSelect;
                                std::cout << "Enter card number:" << std::endl;
                                std::cin >> cardToSelect;
                                game.getCurrentPlayer().selectCard(cardToSelect);
                                std::cout << "Card " << cardToSelect << " selected" << std::endl;
                                break;
                            case 2:
                                game.getCurrentPlayer().unselectAllCards();
                                break;
                            case 3:
                                game.throwCards(game.getCurrentPlayer().getSelectedCards());
                                game.getCurrentPlayer().removeSelectedCards();
                                game.checkIfPlayerHasEnded();
                                std::cout << "Thrown selected cards" << std::endl;
                                break;
                            case 4:
                                game.passCurrentPlayerTurn();
                                game.getCurrentPlayer().unselectAllCards();
                                std::cout << "Passing turn" << std::endl;
                                break;
                            default:
                                std::cout << "Wrong option" << std::endl;
                        }
                    }
                    catch (const std::runtime_error & e)
                    {
                        std::cout << e.what() << std::endl;
                        option = 0;
                    }
                }

                game.nextPlayer();
            }

            game.nextRound();

            std::cout << "Round has ended! Peasant levels:" << std::endl;
            for (unsigned int id = 0; id < numberOfPlayers; id++)
            {
                std::cout << "Player " << id << " level: " << game.getPlayer(id).getPeasantLevel() << std::endl;
            }
        }

        std::cout << "Game has ended!" << std::endl;
    }

    return 0;
}

