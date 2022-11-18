#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"
#include "../include/Party.h"
#pragma once
const int MandatesSelectionPolicy::select(Simulation &sim,std::vector<int> *parties,int myId) const
{
    int selectedPartyId(-1);
    for (int partyId :*parties){
        if (selectedPartyId == -1)
        {
            selectedPartyId = partyId;
        }
        else if(sim.getGraph().getMandates(partyId)> sim.getGraph().getMandates(selectedPartyId)){
            selectedPartyId = partyId;
        }
    }
    return selectedPartyId;
} 
MandatesSelectionPolicy* MandatesSelectionPolicy::clone()
{
    return new MandatesSelectionPolicy(*this);
}  
 