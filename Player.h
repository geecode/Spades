// Player.h - class definition for Player

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

namespace Spades
{
    class Player
    {
    public:
        Player( std::string playerName, int playerNumber );
        ~Player();
        void takeNextCard( Card &c );
        void sortSuits();
        void sortHand();
        std::vector< Card > playerHand() const;
        int playerNumber() const;    
        //void resetHand( sf::RenderWindow &window );        
    private:
        std::vector< Card > _playerHand;
        int _hearts;
        int _clubs;
        int _diamonds;
        int _spades;
        int _booksMade;
        int _bid;
        const int _playerNumber;
        std::string _playerName;
   
    };
}

#endif