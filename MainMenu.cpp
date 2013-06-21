/*
    Author:  Juan P. Alvarado
    
    Date: 
    
    Description:

    Changes:

*/

#include "stdafx.h"
#include "MainMenu.h"
#include "CardGame.h"
#include <list>

namespace GFX
{
    MainMenu::MenuResult MainMenu::show( sf::RenderWindow &window )
    {
        // load menu image
        sf::Texture texture;
        texture.loadFromFile( "images/MainMenu.png" );
        sf::Sprite sprite( texture );

        /********************************
        * setup clickable regions
        *********************************/

        // Play menu item coordinates
        MenuItem playButton;
        playButton.rect.top = 0;
        playButton.rect.height = 290;
        playButton.rect.left = 0;
        playButton.rect.width = SCREEN_WIDTH - 1;
        playButton.action = PLAY;

        // Quit menu item coordinates
        MenuItem quitButton;
        quitButton.rect.top = 310;
        quitButton.rect.height = 599;
        quitButton.rect.left = 0;
        quitButton.rect.width = SCREEN_WIDTH - 1;
        quitButton.action = EXIT;

        _menuItems.push_back( playButton );
        _menuItems.push_back( quitButton );

        window.draw( sprite );
        window.display();

        return menuResponse( window );
    }

    MainMenu::MenuResult MainMenu::handleClick( int x, int y )
    {
        std::list< MenuItem >::iterator it;

        for ( it = _menuItems.begin(); it != _menuItems.end(); ++it )
        {
            sf::Rect< int > menuItemRect = ( *it ).rect;
            if ( menuItemRect.height > y && menuItemRect.top < y
                && menuItemRect.width > x && menuItemRect.left < x )
            {
                return ( *it ).action;
            }
        }
        return NOTHING;
    }

    MainMenu::MenuResult MainMenu::menuResponse( sf::RenderWindow &window )
    {
        sf::Event menuEvent;

        while( true )
        {
            while ( window.pollEvent( menuEvent ) )
            {
                if ( menuEvent.type == sf::Event::MouseButtonPressed )
                {
                    return handleClick( menuEvent.mouseButton.x, menuEvent.mouseButton.y );
                }
            
                if ( menuEvent.type == sf::Event::Closed )
                {
                    return EXIT;
                }
            }
        }
    }
}