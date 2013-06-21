#ifndef VISIBLEOBJECT_H
#define VISIBLEOBJECT_H

#include "GFX.h"
#include <utility>

namespace GFX
{
    class VisibleObject
    {
    public: 
        VisibleObject();
        virtual ~VisibleObject();

        virtual void load( std::string filename );
        virtual void draw( sf::RenderWindow &window ); 

        virtual void setPosition( COORD coord );
        virtual void scaleSprite( float x, float y );
        virtual sf::Sprite sprite() const;
        virtual void setSprite( sf::Sprite &sprite );
        virtual std::string filename() const;
    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
        std::string _filename;
        bool _isLoaded;
    };
}

#endif