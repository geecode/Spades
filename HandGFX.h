#ifndef HANDGFX_H
#define HANDGFX_H

#include "CardGFX.h"
#include "Card.h"

namespace GFX
{
    class HandGFX
    {
    public:
        HandGFX( std::vector< Spades::Card > hand, int playerNumber );
        ~HandGFX();
        std::vector< GFX::CardGFX* > hand() const;

    private:
        void setCardPosition();
        COORD cardPosition() const;
        void setPosition( GFX::CardGFX *card, COORD &coord );

        GFX::COORD _cardPosition;
        std::vector< GFX::CardGFX* > _hand;
        int _playerNumber;
    };
}                

#endif