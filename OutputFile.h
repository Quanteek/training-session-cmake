#ifndef OUTPUT_FILE
#define OUTPUT_FILE

#include <string>
#include <vector>
#include <fstream>

//! A simple outputFile that outputs a vector of double on file filename
class OutputFile
{
public:
    //! Default Constructor
    OutputFile(const std::string & filename = "./output.txt");

    //! Default Destructor
    ~OutputFile();

    //! main function that will write the vector to the _file
    void write(const std::vector<double> & vector);

private:
    //! Copy Constructor - Not reachable
    OutputFile(const OutputFile & outputFile){}
    //! Assignment Operator - Not reachable
    OutputFile & operator=(const OutputFile & outputFile){}

private:
    std::ofstream _file;
};

#endif
