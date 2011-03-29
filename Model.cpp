#include "Model.h"

void Model::run()
{
    _result.clear();
    double current_value = 0.0;
    while(current_value < _end_value)
        {
            _result.push_back(current_value);
            current_value+=_step;
        }
}

const std::vector<double> & Model::output() const
{
    return _result;
}
