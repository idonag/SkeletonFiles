#include "Simulation.h"
#include <map>
#include <iostream>
#include "Party.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents),coalitions() 
{

    // You can change the implementation of the constructor, but not the signature!
    for(unsigned int i = 0 ; i < agents.size(); i++){
        mAgents.at(i).setCoalition(i);
        mGraph.getParty(mAgents.at(i).getPartyId()).setCoalition(i);
        vector<int> c;
        c.push_back(mAgents.at(i).getPartyId());
        coalitions.push_back(c);
    }
}
void Simulation::step()
{
    for(unsigned int i=0; i< (unsigned) mGraph.getNumVertices(); i++){
        getParty(i).step(*this);
    }
    for (unsigned int i=0; i<mAgents.size();i++){

        mAgents.at(i).step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    // std::map<int,int> *coalitions = new std::map<int, int>();
    
    
    bool allJoined = true;
    bool over_60 = false;
    for (unsigned i = 0; i < (unsigned) getGraph().getNumVertices(); i++)
    {
         if(allJoined && getParty(i).getState() != State::Joined){
                allJoined = false;
            }
    }
    
    int maxMandates = 0;
    for(unsigned int i=0; i<(unsigned) coalitions.size(); i++){
        for (unsigned int  j = 0; j < (unsigned) coalitions.at(i).size(); j++)
        {
            maxMandates+= getParty(coalitions.at(i).at(j)).getMandates();
        }
        if(maxMandates > 60)
            over_60 = true;
        maxMandates = 0;
    }
    return allJoined||over_60;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
} 
Graph &Simulation::getGraph() 
{
    return mGraph;
}
const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}
Party &Simulation::getParty(int partyId)
{
    return mGraph.getParty(partyId);
}
/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    return coalitions;
}
vector<Agent>& Simulation::getAgents(){
    return mAgents;
}
vector<vector<int>>& Simulation::getCoalitions(){
    return coalitions;
}