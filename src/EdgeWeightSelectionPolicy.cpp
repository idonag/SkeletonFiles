#include "../include/SelectionPolicy.h"
#pragma once
const int EdgeWeightSelectionPolicy:: select(Simulation &sim,vector<int> *parties,int myId) const{
    int selectedPartyId(-1);
    for (int i=0;i<sim.getGraph().getNumVertices();i++){
        if (selectedPartyId == -1)
        {
            selectedPartyId = i;
        }
        else if(sim.getGraph().getEdgeWeight(i,myId)> sim.getGraph().getEdgeWeight(selectedPartyId,myId)){
            selectedPartyId = i;
        }
    }
    return selectedPartyId;
}
EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone() const
{
    return new EdgeWeightSelectionPolicy(*this);
} 