#include "../include/JoinPolicy.h"


int LastOfferJoinPolicy::chooseAgent(Simulation &sim,const vector<Agent>& offers){
        return offers.back().getId();
}

 