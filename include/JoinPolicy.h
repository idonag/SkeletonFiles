#pragma once
#include "Agent.h"

#include <vector>

class JoinPolicy {
    public:
        virtual const Agent& chooseAgent(const vector<Agent>& offers)=0;
};

class MandatesJoinPolicy : public JoinPolicy {
     virtual const Agent& chooseAgent(const vector<Agent>& offers);
};

class LastOfferJoinPolicy : public JoinPolicy {
    virtual const Agent& chooseAgent(const vector<Agent> &offers);
};