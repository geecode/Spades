// Card.h class definition

#ifndef CARD_H
#define CARD_H

#include <string>
#include "VisibleObject.h"

namespace Spades
{

    class Card 
    {
    public:
        enum Suits { HEARTS, CLUBS, DIAMONDS, SPADES };
        enum Faces { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
            NINE, TEN, JACK, QUEEN, KING, ACE };

	    static const std::string _faces[ 13 ]; 
	    static const std::string _suits[ 4 ];
        Card();
	    Card( int f, int s );
        ~Card();
    
        int faceValue() const;

        std::string filename() const;
        std::string cardName() const;
        std::string face() const;
        std::string suit() const;
    private:
	    int _suit;
	    int _face;    
        std::string _cardName;
        std::string _filename;

};

}

#endif