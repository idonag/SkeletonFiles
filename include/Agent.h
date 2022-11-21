#pragma once

#include <vector>
#include "Graph.h"


class SelectionPolicy;
class Simulation;
class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(const Agent &other);
    int getPartyId() const;
    int getId() const;
    void step(Simulation &sim);
    virtual ~Agent();
    Agent* operator= (const Agent& other);
    const int getCoalition() const;
    void setCoalition(int coal);
    const  SelectionPolicy& getSelectionPolicy() const;
private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int coalition;
    
};
