#include "../include/SelectionPolicy.h"

const int EdgeWeightSelectionPolicy:: select(Simulation &sim,vector<int> &parties,int myId) const{
    int selectedParty=0;
    for (unsigned int i=1;i<(unsigned) parties.size();i++){
        if(sim.getGraph().getEdgeWeight(parties.at(i),myId)> sim.getGraph().getEdgeWeight(parties.at(selectedParty),myId)){
            selectedParty = i;
        }
    }
    return parties.at(selectedParty);
}
EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone() const
{
    return new EdgeWeightSelectionPolicy();
}
SelectionPolicy::~SelectionPolicy(){}