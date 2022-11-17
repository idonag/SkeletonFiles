#include "Agent.h"
#include "Party.h"
#include "Simulation.h"
#include "SelectionPolicy.h"
#pragma once

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
    mSelectionPolicy = selectionPolicy;
}
Agent::Agent(const Agent& other):mAgentId(other.mAgentId),mPartyId(other.mPartyId){
    mSelectionPolicy = other.mSelectionPolicy->clone();
}
Agent::~Agent(){
    delete mSelectionPolicy;
}
Agent* Agent::operator=(const Agent& other){
    if(&other != this){
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
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
                //if(sim.getGraph().getParty(i) ) check if the agent from my coalitoin already offerd
                    vec_to_return->push_back(i);
            }
        }
    }
    int partySelected =mSelectionPolicy->select(sim,vec_to_return,mPartyId);
    //sim.getGraph().getParty(partySelected) //activate get offer function im party class
    delete vec_to_return;

}

