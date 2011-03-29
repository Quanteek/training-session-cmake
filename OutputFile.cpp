#include "OutputFile.h"

#include <stdexcept>

OutputFile::OutputFile(const std::string & filename)
{
    _file.open(filename.c_str());
    if(!_file.is_open())
        {
            throw std::runtime_error("cannot open "+filename);
        }
    _file << "Results of the Model" << std::endl;
}

//! Default Destructor
OutputFile::~OutputFile()
{
    _file.close();
}

void OutputFile::write(const std::vector<double> & vector)
{
    for(std::vector<double>::const_iterator it = vector.begin() ; it != vector.end() ; it++)
        {
            _file << *it << std::endl;
        }
}
