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
                std::cout << "Current player " << game.getCurrentPlayer().getId() << std::endl;
                printCards(game.getCurrentPlayer().getCards());
                std::cin >> option;

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
                        try
                        {
                            Cards selectedCards = game.getCurrentPlayer().getSelectedCards();
                            game.throwCards(selectedCards);
                            game.getCurrentPlayer().removeSelectedCards();
                            std::cout << "Thrown selected cards" << std::endl;
                        }
                        catch (const std::runtime_error & e)
                        {
                            std::cout << e.what() << std::endl;
                            option = 0;
                        }
                        break;
                    case 4:
                        if (not game.getCardsFromTableTop().size())
                        {
                            std::cout << "Cannot pass starting turn" << std::endl;
                            option = 0;
                        }
                        else
                        {
                            game.getCurrentPlayer().unselectAllCards();
                            game.passCurrentPlayerTurn();
                            std::cout << "Passing turn" << std::endl;
                        }
                        break;
                    default:
                        std::cout << "Wrong option" << std::endl;
                }
            }

            game.nextPlayer();
        }

        std::cout << "Game has ended!" << std::endl;
    }

    return 0;
}

