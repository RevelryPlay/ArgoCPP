#include "include/ArgoProject.hpp"

#include <gtest/gtest.h>

using namespace Argo::Core;

TEST( Project, Create ) {
    const auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    EXPECT_EQ( project->name, "Test" );
    EXPECT_EQ( project->desc, "Test Project" );
    EXPECT_EQ( project->ver, "0.0.1" );
    EXPECT_EQ( project->argoMin, "0.0.2" );
}

TEST( Project, SetName ) {
    auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    project->setName( "New Name" );
    EXPECT_EQ( project->name, "New Name" );
}

TEST( Project, SetDescription ) {
    auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    project->setDescription( "New Description" );
    EXPECT_EQ( project->desc, "New Description" );
}

TEST( Project, SetVersion ) {
    auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    project->setVersion( "0.0.2" );
    EXPECT_EQ( project->ver, "0.0.2" );
}

TEST( Project, SetArgoMin ) {
    auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    project->setArgoMin( "0.0.3" );
    EXPECT_EQ( project->argoMin, "0.0.3" );
}

TEST( Project, SetArgoTarget ) {
    auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    project->setArgoTarget( "0.0.4" );
    EXPECT_EQ( project->argoTarget, "0.0.4" );
}

TEST( Project, SetTheme ) {
    auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    project->SetTheme( "dark" );
    EXPECT_EQ( project->settings.theme, "dark" );
}

TEST( Project, SetLang ) {
    auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    project->SetLang( "es" );
    EXPECT_EQ( project->settings.lang, "es" );
}

TEST( Project, SetAutosave ) {
    auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    project->SetAutosave( false );
    EXPECT_EQ( project->settings.autosave, false );
}

TEST( Project, SetInterval ) {
    auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    project->SetInterval( 600000 );
    EXPECT_EQ( project->settings.interval, 600000 );
}

TEST( Project, AddImageAsset ) {
    auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    project->AddAsset( "image", "test", "test.png" );
    EXPECT_EQ( project->assets.images.size(), 1 );
}

TEST( Project, AddFontAsset ) {
    auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    project->AddAsset( "font", "test", "test.ttf" );
    EXPECT_EQ( project->assets.fonts.size(), 1 );
}

TEST( Project, AddSceneAsset ) {
    auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    project->AddAsset( "scene", "test", "test.scene" );
    EXPECT_EQ( project->assets.scenes.size(), 1 );
}

TEST( Project, AddScriptAsset ) {
    auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    project->AddAsset( "script", "test", "test.js" );
    EXPECT_EQ( project->assets.scripts.size(), 1 );
}

TEST( Project, RemoveImageAsset ) {
    auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    project->AddAsset( "image", "test", "test.png" );
    project->RemoveAsset( "image", "test" );
    EXPECT_EQ( project->assets.images.size(), 0 );
}

TEST( Project, RemoveFontAsset ) {
    auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    project->AddAsset( "font", "test", "test.ttf" );
    project->RemoveAsset( "font", "test" );
    EXPECT_EQ( project->assets.fonts.size(), 0 );
}

TEST( Project, RemoveSceneAsset ) {
    auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    project->AddAsset( "scene", "test", "test.scene" );
    project->RemoveAsset( "scene", "test" );
    EXPECT_EQ( project->assets.scenes.size(), 0 );
}

TEST( Project, RemoveScriptAsset ) {
    auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
    project->AddAsset( "script", "test", "test.js" );
    project->RemoveAsset( "script", "test" );
    EXPECT_EQ( project->assets.scripts.size(), 0 );
}

// TEST( Project, AddOpenEditor ) {
//     auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
//     OpenEditor editor;
//     editor.id = "test";
//     project->settings.openEditors.push_back( editor );
//     EXPECT_EQ( project->settings.openEditors.size(), 1 );
// }
//
// TEST( Project, RemoveOpenEditor ) {
//     auto *project = new Project( "Test", "Test Project", "", false, "0.0.1", "0.0.2" );
//     OpenEditor editor;
//     editor.id = "test";
//     project->settings.openEditors.push_back( editor );
//     std::erase_if( project->settings.openEditors, [ editor ]( const OpenEditor &e ) { return e.id == editor.id; } );
//     EXPECT_EQ( project->settings.openEditors.size(), 0 );
// }
