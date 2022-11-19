#pragma once
#include <vector>
#include "Agent.h"
#include "Simulation.h"



class JoinPolicy {
    public:
        virtual int chooseAgent(Simulation &sim,const std::vector<Agent>& offers)=0;
};

class MandatesJoinPolicy : public JoinPolicy {
     virtual int chooseAgent(Simulation &sim,const std::vector<Agent>& offers);
};

class LastOfferJoinPolicy : public JoinPolicy {
    virtual int chooseAgent(Simulation &sim,const std::vector<Agent>& offers);
};