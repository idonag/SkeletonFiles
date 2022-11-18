#include "../include/JoinPolicy.h"


const Agent& LastOfferJoinPolicy::chooseAgent(Simulation &sim,const vector<Agent>& offers){
        return offers.back();
}

 