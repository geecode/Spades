#include "stdafx.h"
#include "HandGFX.h"
#include "GFX.h"

namespace GFX
{
    HandGFX::HandGFX( std::vector< Spades::Card > hand, int playerNumber )
        : _playerNumber( playerNumber )
    {
       
        setCardPosition();
        for( std::vector< Spades::Card >::const_iterator it = hand.begin();
            it != hand.end(); ++it )
        {
            GFX::CardGFX *c = new GFX::CardGFX( it->filename(), it->cardName() );
            // set position of first card           
            
            if ( _playerNumber == 1 )
                _cardPosition.first += 16;
            if ( _playerNumber == 2 )
                _cardPosition.second += 16;
            if ( _playerNumber == 3 )
                _cardPosition.first -= 16;
            if ( _playerNumber == 4 )
                _cardPosition.second -= 16;
            c->setPosition( _cardPosition );
            
            _hand.push_back( c );
        }
    }

    HandGFX::~HandGFX()
    {
    }

    std::vector< CardGFX* > HandGFX::hand() const
    {
        return _hand;
    }

    void HandGFX::setCardPosition()
    {
        // x, y position of first card in hand
                
        switch( _playerNumber )
        {
        case 1:
            _cardPosition.first = ( int )( SCREEN_WIDTH / 3 );
            _cardPosition.second = ( int )( SCREEN_HEIGHT - 125 );
            break;
        case 2:
            _cardPosition.first = 125;
            _cardPosition.second = ( int )( SCREEN_HEIGHT / 3 );
            break;
        case 3:
            _cardPosition.first = ( int )( SCREEN_WIDTH / 3 );
            _cardPosition.second = 125;
            break;
        case 4:
            _cardPosition.first =  ( int )( ( SCREEN_WIDTH / 3 ) * 2 );
            _cardPosition.second = ( int )( SCREEN_WIDTH - 125 );
            break;
        default:
            std::printf( "<<<<<<<<<<<<  SHOULDN'T GET HERE!  >>>>>>>>>>" );
            break;
        }
        
    }
    
    GFX::COORD HandGFX::cardPosition() const
    {
        return _cardPosition;
    }

    void setPosition( GFX::CardGFX *card, COORD coord )
    {  
        card->setPosition( coord );
    }
                
                
                
                

                    
                    


}