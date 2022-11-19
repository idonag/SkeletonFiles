

#include <vector>

#include"Graph.h"
#include"Agent.h"
#include"Party.h"

#pragma once

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph graph, vector<Agent> agents);
    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    Graph &getGraph();
    const vector<Agent> &getAgents() const;
    vector<Agent> &getAgents();
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;


private:
    Graph mGraph;
    vector<Agent> mAgents;
    Party &getParty(int partyId);
};
