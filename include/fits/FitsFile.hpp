#ifndef FITS_FILE_HPP
#define FITS_FILE_HPP

#include <iostream>

struct fitsfile;

class FitsHeader
{
public:
    FitsHeader() {};
    ~FitsHeader() {};
};

class FitsFile
{
public:
    FitsFile();
    ~FitsFile();

    void open( std::string path );
    void close();

    FitsHeader** getHeaders();

private:
    fitsfile* m_FitsFile = nullptr;
};

#endif