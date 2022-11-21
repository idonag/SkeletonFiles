#include "JoinPolicy.h"
#include "Agent.h"
#include "Simulation.h"
#include "Party.h"
int MandatesJoinPolicy::chooseAgent(Simulation &sim,const vector<int>& offers){   
        int maxMandates=sim.getGraph().getParty(offers.at(0)).getMandates();
        int chosenIndex=0;
        for(unsigned int i=1; i< (unsigned) offers.size();i++){
            Agent a = sim.getAgents().at(i);
            if(sim.getGraph().getParty(a.getPartyId()).getMandates()>maxMandates){
                maxMandates=sim.getGraph().getParty(a.getPartyId()).getMandates();
                chosenIndex =i;
            }
        }
        return offers.at(chosenIndex);
}
MandatesJoinPolicy* MandatesJoinPolicy::clone() const{
        return new MandatesJoinPolicy();
}