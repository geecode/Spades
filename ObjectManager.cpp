#include "stdafx.h"
#include "ObjectManager.h"
#include "VisibleObject.h"
#include <map>

namespace GFX
{
    ObjectManager::ObjectManager()
    {
    }
    
    ObjectManager::~ObjectManager()
    {
        std::for_each( _gameObjects.begin(), _gameObjects.end(),
            ObjectDeallocator() );
    }

    void ObjectManager::Add(VisibleObject* gameObject )
    {
        _gameObjects.push_back( gameObject );
    }

    void ObjectManager::Add( std::vector< GFX::CardGFX* > gameObjects )
    {
        for ( std::vector< GFX::CardGFX* >::const_iterator it = gameObjects.begin();
            it != gameObjects.end(); ++it )
        {
            GFX::CardGFX *c = *it;
            _gameObjects.push_back( c ) ;
        }
    }

    void ObjectManager::Remove( std::string name )
    {
        for ( std::vector< VisibleObject* >::const_iterator results = _gameObjects.begin();
             results != _gameObjects.end(); ++results )
        {
            VisibleObject *obj = *results;
            if ( obj->filename() == name  )
                delete *results;
        }
    }

    VisibleObject* ObjectManager::Get( std::string name ) const
    {
        VisibleObject *obj;
        for ( std::vector< VisibleObject* >::const_iterator results = _gameObjects.begin();
            results != _gameObjects.end(); ++results )
        {
            obj = *results;
            if ( results == _gameObjects.end() )
            {
                return NULL;
            }
            if ( obj->filename() == name )
                return obj;
             
        } 
        return NULL;
        
    }

    int ObjectManager::getObjectCount() const
    {
        return _gameObjects.size();
    }

    void ObjectManager::DrawAll( sf::RenderWindow &window )
    {
        std::vector< VisibleObject* >::iterator it = _gameObjects.begin();
        while ( it != _gameObjects.end() )
        {
             VisibleObject* v = *it;
             v->draw( window );
             ++it;
        }
    }

}