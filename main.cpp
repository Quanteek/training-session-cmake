#include "Model.h"
#include "OutputFile.h"

//! main function
int main(int argc, char ** argv)
{
    double end_value = 10.0;

    Model model(end_value);
    model.run();

    OutputFile file("./output.txt");
    file.write(model.output());

    return 0;
}
