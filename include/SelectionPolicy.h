#pragma once
#include "Simulation.h"
#include "Party.h"

class SelectionPolicy {
    public:
        const virtual int select(Simulation &sim,std::vector<int> *parties,int myId)const =0 ;
        virtual SelectionPolicy* clone()=0;
 };

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        MandatesSelectionPolicy(const MandatesSelectionPolicy &other);
        const int select(Simulation &sim,vector<int> *parties,int myId) const;
        MandatesSelectionPolicy* clone();

 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
    public:
        EdgeWeightSelectionPolicy(const EdgeWeightSelectionPolicy &other);
        const int select(Simulation &sim,vector<int> *parties,int myId) const;
        EdgeWeightSelectionPolicy* clone();
};