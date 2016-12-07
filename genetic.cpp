#include "genetic.h"
#include "userinput.h"
#include <iostream>
#include <cstdlib>  // rand()
#include <ctime>    // time()




int geneticPopulation::returnNumChromosomes(){
    return _numChromosomes;
}

int geneticPopulation::returnNumIndividuals(){
    return _numIndividuals;
}

float * geneticPopulation::returnPopulation(){
    return p_individuals;
}

float * geneticPopulation::returnFitnessEvaluation(){
    return p_fitness;
}

void geneticPopulation::extractIndividual(const int i, float * p_vector){
    //float p_vector[_numChromosomes];

    for(int j = 0; j < _numChromosomes; j++){
        p_vector[j] = p_individuals[i*_numChromosomes + j];
    }



}

void geneticPopulation::creation(float * p_ranges){
    // first population creation function
    float a, b;

    // initialize random number generetor
    srand (time(NULL));

    for(int i = 0; i < _numIndividuals; i++){
        for(int j = 0; j < _numChromosomes; j++){
            // exstract the right ranges from a user defined vector
            a = p_ranges[2*j];
            b = p_ranges[2*j+1];

            // generate random number in the range
            p_individuals[i*_numChromosomes + j] = randomFloat(a, b);
        }
    }

}

void geneticPopulation::evalutation(){
    // pass pointer to store the individual that must be exstracted
    float p_vector[_numChromosomes];

    for(int i = 0; i < _numIndividuals; i++){

        extractIndividual(i, p_vector);

        // evalutation of fitness function
        p_fitness[i] = fitnessFuction(p_vector, _numChromosomes);
    }
}

void geneticPopulation::crossover(){

    // one point crossover
    int posCrossover;
    const int range = _numChromosomes; // range for random number generator
    float temp; // temporary variable

    srand (time(NULL));

    for(int i = 0; i < _numIndividuals-1 ; i += 2){

        // generate a random position to start the crossover
        posCrossover = rand() % range; //initial value equal to zero

        // debug
        //std::cout << "posCrossover: " << posCrossover << std::endl;

        //real crossover
        for(int j = 0; j < posCrossover; j++){
            temp = p_individuals[i*_numChromosomes + j];
            p_individuals[i*_numChromosomes + j] = p_individuals[(i+1)*_numChromosomes+j];
            p_individuals[(i+1)*_numChromosomes + j] = temp;
        }
    }
}

void geneticPopulation::selection(int numCompetitor){
    // tournament selection: better of numCompetitor

    // to copy currente population
    float * p_indAux = new float [_numIndividuals * _numChromosomes];

    // copy current population
    copyPopulationA2B(p_individuals, p_indAux);

    int   posVector[numCompetitor];
    float fitnessVector[numCompetitor];
    int posBest;

    srand (time(NULL));

    for(int i = 0; i < _numIndividuals; i++){
        for(int k = 0; k < numCompetitor; k++){
            int posInd = rand() % _numIndividuals;
            posVector[k] = posInd;
            fitnessVector[k] = p_fitness[posInd];
        }

        // extract the winner
        posBest = positionBest(posVector, fitnessVector, numCompetitor);
        //std::cout << posBest << std::endl;
        // copy the winner in the population
        for(int j = 0; j< _numChromosomes; j++){

            p_individuals[i * _numChromosomes + j] = p_indAux[posBest * _numChromosomes + j];
            //std::cout << p_individuals[i * _numChromosomes + j] << std::endl;
            //std::cout << p_indAux[posBest * _numChromosomes + j] << std::endl;
        }
    }

    delete[] p_indAux;
}

void geneticPopulation::mutation(float * p_ranges){
    // uniform mutation

    int pos;
    float a, b;

    srand (time(NULL));

    for(int i = 0; i < _numIndividuals; i++){

        pos = rand() % _numChromosomes;
        a = p_ranges[2*pos];
        b = p_ranges[2*pos + 1];

        p_individuals[i*_numChromosomes + pos] = randomFloat(a, b);
    }


}

void geneticPopulation::printPopulation(){

    std::cout << "\nPrinting current population..." << std::endl;

    for(int i = 0; i < _numIndividuals; i++){
	    std::cout << "\nIndividual: " << i+1 << std::endl;
	    for(int j = 0; j < _numChromosomes; j++){
	        std::cout << "chromosome: " << j+1 << " value: " << p_individuals[i*_numChromosomes + j] << std::endl;
	    }
    }
}

void geneticPopulation::printFitness(){

    std::cout << "\nPrinting current value fitness function...\n" << std::endl;
    for(int i = 0; i < _numIndividuals; i++){
        std::cout << "Individual: " << i+1 << " Fitness: " << p_fitness[i] << std::endl;
    }
}

float geneticPopulation::randomFloat(float a, float b){

    float random  = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

int geneticPopulation::positionBest(int * posVector, float * fitnessVector, int numCompetitor){

    // extract the position of the individual with best fitness function

    int best = 0;

    //std::cout << fitnessVector[0] << std::endl;


    for(int i = 1; i < numCompetitor; i++){
        //std::cout << fitnessVector[i] << std::endl;
        if(fitnessVector[i] > fitnessVector[best]) {
            best = i;
        }
    }

    //std::cout << "best:" << best << std::endl;
    //std::cout << posVector[best] << std::endl;

    return posVector[best];
}

void geneticPopulation::copyPopulationA2B(float * a, float * b){
    for(int i = 0; i < _numIndividuals; i++){
        for(int j = 0; j < _numChromosomes; j++){
            b[i * _numChromosomes + j] = a[i * _numChromosomes + j];
        }
    }

}

void geneticPopulation::printAverageFitness(){

    std::cout << "\nPrinting average fitness value...\n" << std::endl;

    float sumFitness = 0;
    for(int i = 0; i < _numIndividuals; i++){
        sumFitness += p_fitness[i];
    }

    std::cout << "Average Fitness: " << sumFitness/((float) _numIndividuals) << std::endl;

}
