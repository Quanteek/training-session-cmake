#include <iostream>
#include <vector>
#include <algorithm>

//! main function
int main(int argc, char ** argv)
{
    //! Hello World !
    std::cout << "Hello World !" << std::endl;

    //Max between two reals
    std::cout << "max(3.14,2.72)==" << std::max(3.14,2.72) << std::endl;

    //Create a vector
    std::vector<int> myvector;
    myvector.push_back(10);
    myvector.push_back(20);
    myvector.push_back(30);
    myvector.push_back(40);

    //Find 30 in vector and display next element value
    std::vector<int>::iterator it;
    it = find (myvector.begin(), myvector.end(), 30);
    ++it;
    std::cout << "The element following 30 is " << *it << std::endl;

    return 0;
}
