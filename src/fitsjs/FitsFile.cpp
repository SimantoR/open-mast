#include <fits/FitsFile.hpp>
#include <emscripten/bind.h>
#include <memory>

std::shared_ptr<FitsFile> createFitsFile( std::string path )
{
    auto filePtr = std::make_shared<FitsFile>();
    filePtr->open( path );

    return filePtr;
}

EMSCRIPTEN_BINDINGS( FITS_FILE_HPP )
{
    emscripten::class_<FitsFile>( "FitsFile" ) //
        .smart_ptr_constructor<std::shared_ptr<FitsFile>, std::string>( "FitsFile", &createFitsFile )
        .function( "close", &FitsFile::close );
}