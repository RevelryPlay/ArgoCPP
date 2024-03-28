#include "include/ArgoProject.hpp"
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
        assets.images.emplace_back( id, path, 0 );
    } else if ( type == "font" ) {
        assets.fonts.emplace_back( id, path, 0 );
    } else if ( type == "scene" ) {
        assets.scenes.emplace_back( id, path, 0 );
    } else if ( type == "script" ) {
        assets.scripts.emplace_back( id, path, 0 );
    }
}

void Project::RemoveAsset( const std::string &type, const std::string &id ) {
    if ( type == "image" ) {
        std::erase_if( assets.images, [ id ]( const Asset &asset ) { return asset.id == id; } );
    } else if ( type == "font" ) {
        std::erase_if( assets.fonts, [ id ]( const Asset &asset ) { return asset.id == id; } );
    } else if ( type == "scene" ) {
        std::erase_if( assets.scenes, [ id ]( const Asset &asset ) { return asset.id == id; } );
    } else if ( type == "script" ) {
        std::erase_if( assets.scripts, [ id ]( const Asset &asset ) { return asset.id == id; } );
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
