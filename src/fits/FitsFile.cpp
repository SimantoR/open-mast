#include <fits/FitsFile.hpp>
#include <cfitsio/fitsio.h>

FitsFile::FitsFile()
{
}

FitsFile::~FitsFile()
{
    delete fitsfile;
}

void FitsFile::open( std::string path )
{
    fits_open_data( &m_FitsFile, path.c_str(), 0, 0 );
}

void FitsFile::close()
{
}