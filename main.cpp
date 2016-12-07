#include <iostream>
#include "genetic.h"
#include "userinput.h"

int main() {

    int i = 10;
    int c = 4;
    int competitors = 3;
    int maxIter = 50000;


    // class input class creation
    inputClass input(c);

    // Creation of the population
    geneticPopulation prova(i, c);

    //prova.printPopulation();
    std::cout << "\nCreating population...\n"  << std::endl;
    prova.creation(input.p_ranges);

    prova.printPopulation();

    std::cout << "\nFitness evalutation...\n" << std::endl;

    prova.evalutation();
    prova.printAverageFitness();

    for(int i = 0; i < maxIter; i++){
        //std::cout << i << std::endl;
        prova.evalutation();
        //prova.printFitness();
        prova.selection(competitors);
        prova.crossover();
        prova.mutation(input.p_ranges);

        //prova.printAverageFitness();
    }

    prova.printAverageFitness();
    prova.printPopulation();
    //prova.printFitness();
    return 0;
}
