#include "../include/SelectionPolicy.h"
#pragma once
const int EdgeWeightSelectionPolicy:: select(Simulation &sim,vector<int> &parties,int myId) const{
    int selectedParty=0;
    for (int i=1;i<parties.size();i++){
        if(sim.getGraph().getEdgeWeight(parties.at(i),myId)> sim.getGraph().getEdgeWeight(parties.at(selectedParty),myId)){
            selectedParty = i;
        }
    }
    return parties.at(selectedParty);
}
EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone() const
{
    return new EdgeWeightSelectionPolicy(*this);
} 