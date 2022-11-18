#include "../include/JoinPolicy.h"


const Agent& MandatesJoinPolicy::chooseAgent(Simulation &sim,const vector<Agent>& offers){
        int maxMandates=0;
        for(Agent a :offers){
            if(sim.getParty(a.getPartyId()).getMandates()>maxMandates)
        }
}