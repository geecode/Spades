#include "stdafx.h"
#include "VisibleObject.h"

namespace GFX
{
    VisibleObject::VisibleObject()
    {
        _isLoaded = false;
    }

    VisibleObject::~VisibleObject()
    {
    }

    void VisibleObject::load( std::string filename )
    {
        if ( !_texture.loadFromFile( filename ) )
        {
            _filename = "";
            _isLoaded = false;
        }
        else
        {
            _filename = filename;
            _texture.setSmooth( true );        
            _sprite.setTexture( _texture );        
            _isLoaded = true;
        }
    }

    //void VisibleObject::draw() {}
    void VisibleObject::draw( sf::RenderWindow &window )
    {
        if ( _isLoaded )
        {
            window.draw( _sprite );
        }
    }

    void VisibleObject::setPosition( COORD coord )
    {
        if ( _isLoaded )
        {
            _sprite.setPosition( coord.first, coord.second );
        }
    }

    void VisibleObject::scaleSprite( float x, float y )
    {
        _sprite.setScale( x, y );
    }

    sf::Sprite VisibleObject::sprite() const
    {
        return _sprite;
    }

    void VisibleObject::setSprite( sf::Sprite &sprite )
    {
        _sprite = sprite;
    }

    std::string VisibleObject::filename() const
    {
        return _filename;
    }
}
