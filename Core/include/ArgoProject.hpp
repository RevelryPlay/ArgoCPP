#ifndef ARGOPROJECT_HPP
#define ARGOPROJECT_HPP

#include <ctime>
#include <list>
#include <map>
#include <string>
#include <utility>

namespace Argo::Core {
struct Asset {
    std::string id;
    std::string path;
    time_t lastModified{ 0 };

    Asset( std::string id, std::string path, const time_t _lastModified = 0 ) : lastModified( _lastModified ) {
        id = std::move( id );
        path = std::move( path );
    }
};

struct Assets {
    std::map< std::string, Asset > images;
    std::map< std::string, Asset > fonts;
    std::map< std::string, Asset > scenes;
    std::map< std::string, Asset > scripts;

    Assets() {
        images = std::map< std::string, Asset >();
        fonts = std::map< std::string, Asset >();
        scenes = std::map< std::string, Asset >();
        scripts = std::map< std::string, Asset >();
    };

    // should file watchers be handled here?
    // void AddWatcher( const std::string &id );
    // void RemoveWatcher( const std::string &id );
    //
    // private:
    // std::map<std::string, Watchers> watchers;
};

struct EditorPosition {
    int x{ 0 };
    int y{ 0 };
    bool docked{ true };
    std::string space = "main";

    EditorPosition() = default;
};

struct OpenEditor {
    std::string type = "scene";
    std::string id;
    EditorPosition position;

    OpenEditor() = default;
};

struct Settings {
    std::list< OpenEditor > openEditors;
    std::string theme = "default";
    std::string lang = "en";
    bool autosave = true;
    int interval = 300000;
    bool watchFiles = true;
};

struct Project {
    std::string name;
    std::string desc;
    std::string ver;
    std::string argoMin;
    std::string argoTarget;
    Settings settings;
    Assets assets;

    Project( std::string _name,
        std::string _dec,
        const std::string & /*filePath*/,
        bool /*defaults*/,
        std::string _ver,
        const std::string &argoVer );

    void AddAsset( const std::string &type, const std::string &id, const std::string &path );
    void RemoveAsset( const std::string &type, const std::string &id );

    void setName( const std::string &newName );
    void setDescription( const std::string &newDesc );
    void setVersion( const std::string &newVer );
    void setArgoMin( const std::string &newArgoMin );
    void setArgoTarget( const std::string &newArgoTarget );
    void SetTheme( const std::string &theme );
    void SetLang( const std::string &lang );
    void SetAutosave( bool autosave );
    void SetInterval( int interval );
};
}  // namespace Argo::Core

#endif  // ARGOPROJECT_HPP
