#pragma once
#include <vector>
class Agent;
class Simulation;
using std::vector;

class JoinPolicy {
    public:
        virtual int chooseAgent(Simulation &sim,const std::vector<Agent>& offers)=0;
        virtual JoinPolicy* clone() const = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
    virtual int chooseAgent(Simulation &sim,const std::vector<Agent>& offers);
    virtual MandatesJoinPolicy* clone() const;
};

class LastOfferJoinPolicy : public JoinPolicy
{
    virtual int chooseAgent(Simulation &sim,const std::vector<Agent>& offers);
    virtual LastOfferJoinPolicy* clone() const;
};