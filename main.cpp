/*
  File   : pi.cpp
  Author : Nuno Alves
  Login  : nca@bu.edu

  Purpose: This program estimates the value of pi by using
  the monte carlo method. Monte Carlo simulations use random
  numbers to examine systems (in chemistry, physics,
  economics...) that are too large and complicated to observe
  and reason about directly.
  Here we consider a less sophisticated application: estimating
  the value of pi. First, consider a circle of unit radius inscribed
  in a square. The area of the circle is pi, but let us zoom in on
  the first quadrant. Now imagine throwing a dart at random into this
  square. The probability that it hits the blue region is pi/4
  (since that is the area of the blue region, and the square has
  unit area). So if you throw n darts (at random) and keep track of
  the number of hits h in the blue, you would expect to get h= pi*n/4.
  Thus we can estimate pi by performing this experiment and observing
  the actual value of h. Throwing a dart at random into the
  unit square amounts to choosing two values x and y from the interval
  [0,1]. It was discussed in class how to generate random numbers, and
  in particular how to do so in a given interval. Check that the point
  (x,y) is in the blue by computing its distance from the origin.

*/

#include<iostream>
#include<ctime>
#include<cmath>
#include<iomanip>
#include<cstdlib>

using namespace std;

int main(){
    double x_value, y_value;
    long int hit,n_darts=1;

    //generating the seed value for the random numbers
    srand(time(0));

    while(n_darts!=0){

        cout<<"\nThis program estimates Pi by the Monte Carlo method.\n";
        cout<<"How many darts do you want to throw? (0 to quit) ";
        cin>>n_darts;

        if (n_darts!=0)
            {
                //reset the hit variable
                hit=0;
                clock_t start = clock();
                int i;
#pragma omp parallel for shared(n_darts) private(i,x_value,y_value) reduction(+:hit)
                for(i=0;i<n_darts;i++)
                    {
                        //generates a random value of x and y between 0
                        //and 1 with the precision of a double variable
                        x_value = static_cast<double>(rand())/RAND_MAX;
                        y_value = static_cast<double>(rand())/RAND_MAX;

                        //if the x and y values are inside a circlue of
                        //unit 1 then	we increase the hit counter
                        if (((x_value*x_value)+(y_value*y_value))<=1) hit++;

                    }
                //using the setprecision and setioflags functions to
                //set the precision to 10 digits and to show
                //trailing zeros we estimated the value of pi
                //by multiplying the number of hits by 4 and dividing
                //by the numbers of thrown darts.
                cout<<"There were "<<hit<<" hits in the circle \n";
                cout<<"The estimated value of pi is: "
                    <<setiosflags(ios::fixed|ios::showpoint)
                    <<setprecision(10)
                    <<(hit*4)/static_cast<double>(n_darts)<<"\n";
                clock_t stop = clock();
                std::cout << "Time elapsed " << (stop-start)/(double)CLOCKS_PER_SEC << std::endl;
            }//if (darts!=0)

    }//end of while(n_darts!=0)
    return 0;
}//end of main()
