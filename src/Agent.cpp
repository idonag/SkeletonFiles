#include "Agent.h"
#include "Party.h"
#include "Simulation.h"
#include "SelectionPolicy.h"
#pragma once

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId)
{
    // You can change the implementation of the constructor, but not the signature!
    mSelectionPolicy = selectionPolicy->clone();
    coalition = -1;
}
Agent::Agent(const Agent& other):mAgentId(other.mAgentId),mPartyId(other.mPartyId){
    mSelectionPolicy = other.mSelectionPolicy->clone();
}
Agent::~Agent(){
    if(mSelectionPolicy){
        delete mSelectionPolicy;
    }
}
Agent* Agent::operator=(const Agent& other){
    if(&other != this){
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        delete mSelectionPolicy;
        mSelectionPolicy = other.mSelectionPolicy->clone();
        
    }
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
    std::vector<int> *vec_to_return = new vector<int>();
    for(int i = 0; i < sim.getGraph().getNumVertices();i++){
        if(sim.getGraph().getEdgeWeight(this->getPartyId(),i)>0){
            if (sim.getGraph().getParty(i).getState() != State::Joined){
                if(!sim.getGraph().getParty(i).isOffered(coalition)) //check if an agent from my coalitoin already offerd
                    vec_to_return->push_back(i);
            }
        }
    }
    int partySelected =mSelectionPolicy->select(sim,vec_to_return,mPartyId);
    sim.getGraph().getParty(partySelected).offer(*this); //activate get offer function im party class
    delete vec_to_return;
}
int Agent::getCoalition() const{
    return coalition;
}
void Agent::setCoalition(int coal){
    coalition = coal;
}
SelectionPolicy* Agent::getSelectionPolicy() const{
    return mSelectionPolicy;
}
