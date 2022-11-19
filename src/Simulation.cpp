#include "Simulation.h"
#include <map>
#include <iostream>

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step()
{
    for(int i=0; i< mGraph.getNumVertices(); i++){
        getParty(i).step(*this);
    }
    for (Agent agent : mAgents){
        agent.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    std::map<int,int> *coalitions = new std::map<int, int>();
    
    
    bool allJoined = true;
    bool over_60 = false;
    for(int i=0; i< mGraph.getNumVertices(); i++){
        if(allJoined && getParty(i).getState() != State::Joined){
            allJoined = false;
        }
        
        if (coalitions->find(getParty(i).getCoalition())==coalitions->end())
        {
            coalitions->insert(std::pair<int,int>(getParty(i).getCoalition(),0));
        }
        std::map<int,int>::iterator itr;
        itr = coalitions->find(getParty(i).getCoalition());
        itr->second = itr->second+getParty(i).getMandates();
    }
    std::map<int,int>::iterator itr;
    itr = coalitions->begin();
    while(itr!=coalitions->end())
    {
        if (itr->second > 60)
        {
            over_60 = true;
        }
        itr++;
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
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return vector<vector<int>>();
}
vector<Agent>& Simulation::getAgents(){
    return mAgents;
}
