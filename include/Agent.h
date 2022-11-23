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
    Agent(Agent &&other);
    int getPartyId() const;
    int getId() const;
    void step(Simulation &sim);
    ~Agent();
    Agent& operator= (const Agent& other);
    Agent& operator=(Agent&& other);
    const int getCoalition() const;
    void setCoalition(int coal);
    const  SelectionPolicy& getSelectionPolicy() const;
private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int coalition;
    
};
