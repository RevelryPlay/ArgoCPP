#ifndef ARGOPROJECT_HPP
#define ARGOPROJECT_HPP

#include <ctime>
#include <string>
#include <utility>
#include <vector>

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
    std::vector< Asset > images;
    std::vector< Asset > fonts;
    std::vector< Asset > scenes;
    std::vector< Asset > scripts;

    Assets() {
        images = std::vector< Asset >();
        fonts = std::vector< Asset >();
        scenes = std::vector< Asset >();
        scripts = std::vector< Asset >();
    };

    // should file watchers be handled here?
    // void AddWatcher( const std::string &id );
    // void RemoveWatcher( const std::string &id );
    //
    // private:
    // std::vector<Watcers> watchers;
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
    std::vector< OpenEditor > openEditors;
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
