#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"
#include "../include/Party.h"

const int MandatesSelectionPolicy::select(Simulation &sim,std::vector<int> &parties,int myId) const
{
    int selectedParty=0;
    for (unsigned int i=1;i< (unsigned) parties.size();i++){
        if((unsigned) sim.getGraph().getMandates(parties.at(selectedParty))> (unsigned) sim.getGraph().getMandates(parties.at(selectedParty))){
            selectedParty = i;
        }
    }
    return parties.at(selectedParty);
} 
 MandatesSelectionPolicy* MandatesSelectionPolicy::clone() const
{
    return new MandatesSelectionPolicy();
}

 