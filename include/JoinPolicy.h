#pragma once
#include "Agent.h"
#include "Simulation.h"
#include <vector>

class JoinPolicy {
    public:
        virtual const Agent& chooseAgent(Simulation &sim,const vector<Agent>& offers)=0;
};

class MandatesJoinPolicy : public JoinPolicy {
     virtual const Agent& chooseAgent(Simulation &sim,const vector<Agent>& offers);
};

class LastOfferJoinPolicy : public JoinPolicy {
    virtual const Agent& chooseAgent(Simulation &sim,const vector<Agent> &offers);
};