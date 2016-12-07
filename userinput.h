#ifndef USERINPUT_H
#define USERINPUT_H

//#include <iostream>
//#include "genetic.h"
#include "userinput.h"

float fitnessFuction(const float * individual,  const int _numChromosomes);

class inputClass{
    private:

    public:
        float * p_ranges;

        //constructor
        inputClass(int N);

        // destuctor
        ~inputClass();
};

#endif
