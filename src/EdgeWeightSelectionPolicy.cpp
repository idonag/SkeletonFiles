#include "../include/SelectionPolicy.h"
#pragma once
const int EdgeWeightSelectionPolicy:: select(Simulation &sim,vector<int> *parties,int myId) const{
    int selectedPartyId(-1);
    for (int partyId :*parties){
        if (selectedPartyId == -1)
        {
            selectedPartyId = partyId;
        }
        else if(sim.getGraph().getEdgeWeight(partyId,myId)> sim.getGraph().getEdgeWeight(selectedPartyId,myId)){
            selectedPartyId = partyId;
        }
    }
    return selectedPartyId;
}
EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone()
{
            return new EdgeWeightSelectionPolicy(*this);
} 