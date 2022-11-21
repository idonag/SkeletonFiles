#pragma once
#include <string>
#include <vector>


using std::string;
class Agent;
class JoinPolicy;
class Simulation;
class SelectionPolicy;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 
    Party(const Party &other);
    Party(const Party &&other);
    virtual ~Party();
    Party& operator=(const Party &other);
    Party& operator=(const Party &&other);

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s) ;
    const string &getName() const;
    void offer(int agentInd);
    int getCoalition() const;
    void joinCoalition(int chosenAgentIndex, Simulation &a);
    bool isOffered(int coalition,Simulation &s) ;
    void setCoalition(int coal);

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int iterNum;
    std::vector<int> *agentOffers; 
    int coalition;
};
