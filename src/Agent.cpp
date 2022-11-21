// #pragma once
#include "Agent.h"
#include "Party.h"
#include "Simulation.h"
#include "SelectionPolicy.h"


Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId),mSelectionPolicy(selectionPolicy->clone()),coalition(-1)
{
    // You can change the implementation of the constructor, but not the signature!
}
Agent::Agent(const Agent& other):mAgentId(other.mAgentId),mPartyId(other.mPartyId),mSelectionPolicy(other.mSelectionPolicy->clone()),coalition(other.coalition){
}
Agent::Agent(Agent &&other): mAgentId(other.mAgentId),mPartyId(other.mPartyId),mSelectionPolicy(other.mSelectionPolicy->clone()),coalition(other.coalition){//move constructor - shallow copy
    other.mSelectionPolicy = nullptr;
}
Agent::~Agent(){
    if(mSelectionPolicy){
        delete mSelectionPolicy;
    }
}
Agent& Agent::operator=(const Agent& other){
    if(&other != this){
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        delete mSelectionPolicy;
        mSelectionPolicy = other.mSelectionPolicy->clone();
    }
    return *this;
}
Agent& Agent::operator=(const Agent &&other){ // move assignment opertor
    if(this!=&other){
        if(mSelectionPolicy)
            delete mSelectionPolicy;
        mAgentId = other.mAgentId;
        mPartyId=other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy->clone();
    }
    return *this;
}
int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}
void Agent::step(Simulation &sim)
{
    vector<int> vec_to_return;
    for(unsigned int i = 0; i < (unsigned) sim.getGraph().getNumVertices();i++){
        if(sim.getGraph().getEdgeWeight(this->getPartyId(),i)>0){
            if (sim.getGraph().getParty(i).getState() != State::Joined){
                if(!sim.getGraph().getParty(i).isOffered(coalition,sim)){ //check if an agent from my coalitoin already offerd
                    vec_to_return.push_back(i);
                }
            }
        }
    }
    if(vec_to_return.size()>0){
        int partySelectedId =mSelectionPolicy->select(sim,vec_to_return,mPartyId);
        sim.getGraph().getParty(partySelectedId).offer(mAgentId); //activate get offer function im party class
    }

}
const int Agent::getCoalition() const{
    return coalition;
}
void Agent::setCoalition(int coal){
    coalition = coal;
}
const SelectionPolicy& Agent::getSelectionPolicy() const{
    return *mSelectionPolicy;
}
