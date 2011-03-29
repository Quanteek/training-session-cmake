#ifndef MODEL
#define MODEL

#include <vector>

//! A simple model that outputs a vector of double
class Model
{
public:
    //! Default Constructor
    Model(double end_value = 100):_end_value(end_value),_step(1.0){}

    //! Default Destructor
    ~Model(){}

    //! main function
    /*!
      computes a vector until _end_value with _step as increment
     */
    void run();

    //! get result of simulation of the model
    const std::vector<double> & output() const;

private:
    //! Copy Constructor - Not reachable
    Model(const Model & model){}
    //! Assignment Operator - Not reachable
    Model & operator=(const Model & model){}

private:
    //! value that stop algorithm
    double _end_value;

    //! step for increasing values
    double _step;

    std::vector<double> _result;
};

#endif
