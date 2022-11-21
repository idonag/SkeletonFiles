
#include "JoinPolicy.h"
#include "Agent.h"
#include "Simulation.h"
int LastOfferJoinPolicy::chooseAgent(Simulation &sim,const vector<int>& offers){
        return offers.at(offers.size()-1);

}
LastOfferJoinPolicy* LastOfferJoinPolicy::clone() const{
        return new LastOfferJoinPolicy();
}
JoinPolicy::~JoinPolicy(){}

