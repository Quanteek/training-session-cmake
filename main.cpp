#include "Model.h"
#include "OutputFile.h"

#include <boost/lexical_cast.hpp>

//! main function
int main(int argc, char ** argv)
{
    std::string end_value(argv[1]);

    Model model(boost::lexical_cast<double>(end_value));
    model.run();

    OutputFile file("./output.txt");
    file.write(model.output());

    return 0;
}
