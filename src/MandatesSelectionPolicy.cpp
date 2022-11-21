#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"
#include "../include/Party.h"
#pragma once
const int MandatesSelectionPolicy::select(Simulation &sim,std::vector<int> &parties,int myId) const
{
    int selectedParty=0;
    for (int i=1;i<parties.size();i++){
        if(sim.getGraph().getMandates(parties.at(selectedParty))> sim.getGraph().getMandates(parties.at(selectedParty))){
            selectedParty = i;
        }
    }
    return parties.at(selectedParty);
} 
 MandatesSelectionPolicy* MandatesSelectionPolicy::clone() const
{
    return new MandatesSelectionPolicy(*this);
}  
 