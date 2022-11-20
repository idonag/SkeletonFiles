#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"
#include "../include/Party.h"
#pragma once
const int MandatesSelectionPolicy::select(Simulation &sim,std::vector<int> *parties,int myId) const
{
    int selectedPartyId(-1);
    for (int i=0;i<sim.getGraph().getNumVertices();i++){
        if (selectedPartyId == -1)
        {
            selectedPartyId = i;
        }
        else if(sim.getGraph().getMandates(i)> sim.getGraph().getMandates(selectedPartyId)){
            selectedPartyId = i;
        }
    }
    return selectedPartyId;
} 
 MandatesSelectionPolicy* MandatesSelectionPolicy::clone() const
{
    return new MandatesSelectionPolicy(*this);
}  
 