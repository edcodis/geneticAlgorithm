#ifndef GENETIC_H
#define GENETIC_H

#include <iostream>
#include "genetic.h"
#include "userinput.h"

class geneticPopulation{
  private:
      int _numIndividuals;
      int _numChromosomes;

      float * p_individuals;
      float * p_fitness;

      float randomFloat(float a, float b);
      int   positionBest(int * posVector, float * fitnessVector, int numCompetitor);
      void  copyPopulationA2B(float * a, float * b);

  public:
      // constructor
      geneticPopulation(const int i, const int c){

	  _numIndividuals = i;
	  _numChromosomes = c;

	  p_individuals = new float [_numIndividuals * _numChromosomes];
	  p_fitness     = new float [_numIndividuals];

      }

      // destuctor
      ~geneticPopulation(){
	         delete[] p_individuals;
             delete[] p_fitness;
      }

      // other functions
      int     returnNumChromosomes();
      int     returnNumIndividuals();
      float * returnPopulation();
      float * returnFitnessEvaluation();

      void extractIndividual(int i, float * p_vector);

      void creation(float * p_ranges);
      void evalutation();
      void selection(int numCompetitor);
      void crossover();
      void mutation(float * p_ranges);
      void printPopulation();
      void printFitness();
      void printAverageFitness();


};



#endif // GENETICPOPULATION_H
