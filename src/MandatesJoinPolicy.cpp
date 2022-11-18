#include "../include/JoinPolicy.h"


int MandatesJoinPolicy::chooseAgent(Simulation &sim,const vector<Agent>& offers){
        int maxMandates=0;
        int chosenIndex=0;
        for(int i=0; i<offers.size();i++){
            Agent a = offers.at(i);
            if(sim.getGraph().getParty(a.getPartyId()).getMandates()>maxMandates){
                maxMandates=sim.getGraph().getParty(a.getPartyId()).getMandates();
                chosenIndex =i;
            }
        }
        return offers.at(chosenIndex).getId();
        
}