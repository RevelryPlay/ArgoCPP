#include "include/ArgoProject.hpp"

#include <algorithm>
#include <string>
#include <utility>
#include <vector>

namespace Argo::Core {
Project::Project( std::string _name,
    std::string _dec,
    const std::string & /*filePath*/,
    bool /*defaults*/,
    std::string _ver,
    const std::string &argoVer )
    : name( std::move( _name ) ), desc( std::move( _dec ) ), ver( std::move( _ver ) ), argoMin( argoVer ),
      argoTarget( argoVer ) {
    settings = Settings();
    assets = Assets();

    // When creating a new project we will need to leverage the filesystem to create the project directory and copy
    // the Argo libriaries and assets enabled for that project.
}

void Project::AddAsset( const std::string &type, const std::string &id, const std::string &path ) {
    if ( type == "image" ) {
        if ( !assets.images.contains( id ) ) {
            assets.images.insert( { id, Asset{ id, path, 0 } } );
        }
    }
    if ( type == "font" ) {
        if ( !assets.fonts.contains( id ) ) {
            assets.fonts.insert( { id, Asset{ id, path, 0 } } );
        }
    }
    if ( type == "scene" ) {
        if ( !assets.scenes.contains( id ) ) {
            assets.scenes.insert( { id, Asset{ id, path, 0 } } );
        }
    }
    if ( type == "script" ) {
        if ( !assets.scripts.contains( id ) ) {
            assets.scripts.insert( { id, Asset{ id, path, 0 } } );
        }
    }
}

void Project::RemoveAsset( const std::string &type, const std::string &id ) {
    if ( type == "image" ) {
        if ( assets.images.contains( id ) ) {
            assets.images.erase( id );
        }
    }
    if ( type == "font" ) {
        if ( assets.fonts.contains( id ) ) {
            assets.fonts.erase( id );
        }
    }
    if ( type == "scene" ) {
        if ( assets.scenes.contains( id ) ) {
            assets.scenes.erase( id );
        }
    }
    if ( type == "script" ) {
        if ( assets.scripts.contains( id ) ) {
            assets.scripts.erase( id );
        }
    }
}

void Project::setName( const std::string &newName ) { name = newName; }
void Project::setDescription( const std::string &newDesc ) { desc = newDesc; }
void Project::setVersion( const std::string &newVer ) { ver = newVer; }
void Project::setArgoMin( const std::string &newArgoMin ) { argoMin = newArgoMin; }
void Project::setArgoTarget( const std::string &newArgoTarget ) { argoTarget = newArgoTarget; }
void Project::SetTheme( const std::string &theme ) { settings.theme = theme; }
void Project::SetLang( const std::string &lang ) { settings.lang = lang; }
void Project::SetAutosave( bool autosave ) { settings.autosave = autosave; }
void Project::SetInterval( int interval ) { settings.interval = interval; }

}  // namespace Argo::Core
