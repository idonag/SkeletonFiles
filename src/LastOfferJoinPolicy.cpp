#pragma once
#include "JoinPolicy.h"
#include "Agent.h"
#include "Simulation.h"
int LastOfferJoinPolicy::chooseAgent(Simulation &sim,const vector<Agent>& offers){
        return offers.back().getId();

}
LastOfferJoinPolicy* LastOfferJoinPolicy::clone() const{
        return new LastOfferJoinPolicy(*this);
}

