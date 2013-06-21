/*
    Author:  Juan P. Alvarado
    
    Date: 
    
    Description:

    Changes:

*/

#ifndef MAINMENU_H
#define MAINMENU_H


#include <list>

namespace GFX
{
    class MainMenu
    {
    public:
        enum MenuResult { NOTHING, EXIT, PLAY };

        struct MenuItem
        {
            sf::Rect< int > rect;
            MenuResult action;
        };

        MenuResult show( sf::RenderWindow &window );
    private:
        MenuResult menuResponse( sf::RenderWindow &window );
        MenuResult handleClick( int x, int y );
        std::list< MenuItem > _menuItems;
    };
}

#endif