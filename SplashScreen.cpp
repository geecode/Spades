/*
    Author:  Juan P. Alvarado
    
    Date: 
    
    Description:

    Changes:

*/
#include "stdafx.h"
#include "SplashScreen.h"

namespace GFX
{
    void SplashScreen::show( sf::RenderWindow &window )
    {
        sf::Texture texture;

        if ( !texture.loadFromFile( "images/Splash.png" ) )
            return;

        sf::Sprite sprite( texture );

        window.draw( sprite );
        window.display();

        sf::Event curEvent;

        while ( true )
        {
            while ( window.pollEvent( curEvent ) )
            {
                if ( curEvent.type == sf::Event::KeyPressed
                    || curEvent.type == sf::Event::MouseButtonPressed
                    || curEvent.type == sf::Event::Closed )
                    return;
            }
        }
    }
}