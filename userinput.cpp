#include <iostream>
#include <cmath>
#include "userinput.h"
//#include "genetic.h"


        //constructor
inputClass::inputClass(int N){
    p_ranges = new float[2*N];

    p_ranges[0] = 1;  // spessore min soletta
    p_ranges[1] = 10; // spessore max soletta

    p_ranges[2] = 1;  // spessore min anima
    p_ranges[3] = 10; // spessore max anima

    p_ranges[4] = 0;  // distanza min asse-soletta
    p_ranges[5] = 10; // distanza max asse-soletta

    p_ranges[6] = 0;  // distanza min asse verticale-soletta
    p_ranges[7] = 10; // distanza max asse verticale-soletta

}

        // destuctor
inputClass::~inputClass(){
    delete[] p_ranges;
}



float fitnessFuction(const float * individual, const int _numChromosomes){
    //do something
    float maxArea, weightArea;

    //float spanDivision, heigthDivision;

    float c = individual[0]; // spessore soletta
    float b = individual[1]; // spessore anima
    float y = individual[2]; // distanza asse-soletta
    float x = individual[3]; // distanza asse verticale-soletta

    float inertia = (b*y)*(y/2)*(y/2) + (c*(x+b))*(y+c/2)*(y+c/2);

    float area = b*y + c*(x+b);

    maxArea = 10;
    weightArea = 0;
    if(area > maxArea) weightArea = 5000;

    float fitnessValue = inertia + weightArea*log(maxArea/area);

    return fitnessValue;
}
