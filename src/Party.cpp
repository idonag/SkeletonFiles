#include "Party.h"
#include "Agent.h"
#include "JoinPolicy.h"
#include "Simulation.h"
#include "SelectionPolicy.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting),iterNum(0),agentOffers(),coalition(-1)
{

}
Party::Party(const Party &other): mId(other.mId),mName(other.mName),mMandates(other.mMandates),mJoinPolicy(other.mJoinPolicy->clone()),mState(other.mState),iterNum(other.iterNum),agentOffers(),coalition(other.coalition){ // copy constructor
    for (unsigned int i = 0; i < other.agentOffers.size(); i++)
    {
        agentOffers.push_back(other.agentOffers.at(i));
    } 

}
Party::Party(Party &&other): mId(other.mId),mName(other.mName),mMandates(other.mMandates),mJoinPolicy(other.mJoinPolicy),mState(other.mState),iterNum(other.iterNum),agentOffers(other.agentOffers),coalition(other.coalition){//move constructor - shallow copy
    other.mJoinPolicy = nullptr;
}

Party::~Party(){//destructor    
    if(mJoinPolicy)
        delete mJoinPolicy;
    mJoinPolicy = nullptr;
}
Party& Party::operator=(const Party &other){ // copy assignment opertor
    if(this != &other){
        mId = other.mId;
        mName=other.mName;
        mMandates = other.mMandates;
        mState = other.mState;
        coalition = other.coalition;
        iterNum = other.iterNum;
        agentOffers.clear();
        for (unsigned int i = 0; i < other.agentOffers.size(); i++)
        {
            agentOffers.push_back(other.agentOffers.at(i));
        }
        mJoinPolicy = other.mJoinPolicy->clone();
    }
    return *this;
}
Party& Party::operator=(Party &&other){ // move assignment opertor
if(this!=&other){
    mId = other.mId;
    mName=other.mName;
    mMandates = other.mMandates;
    mJoinPolicy = other.mJoinPolicy;
    mState = other.mState;
    iterNum = other.iterNum;
    coalition = other.coalition;
    agentOffers=other.agentOffers;
    other.mJoinPolicy = nullptr;

}

return *this;
}

State Party::getState() const
{
    return mState;
}
int Party::getCoalition() const{
    return coalition;
}


void Party::setState(State state)
{
    mState = state;
}

void Party::offer(int agentIndex){
    agentOffers.push_back(agentIndex);
    if(mState==Waiting){
        mState=CollectingOffers;
        iterNum++;
    }
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::joinCoalition(int chosenAgentIndex, Simulation &sim){
    
    int indexGenerated = sim.getAgents().size(); //generate index for the new cloned agent 
    SelectionPolicy *otherSel = sim.getAgents().at(chosenAgentIndex).getSelectionPolicy().clone();

    Agent clonedAgent(indexGenerated,mId,otherSel);
    clonedAgent.setCoalition(sim.getAgents().at(chosenAgentIndex).getCoalition());
    coalition = clonedAgent.getCoalition();
    sim.getAgents().push_back(clonedAgent);
    sim.getCoalitions().at(coalition).push_back(mId);                                                                                                                                                                                                                             
    mState=Joined;
}

void Party::step(Simulation &s) //when joining coalition, clone the offering agent to the vector of agents in th simulation
{
    if(mState==CollectingOffers){
        if(iterNum==3){
            int chosenAgentIndex= mJoinPolicy->chooseAgent(s,agentOffers); // join some coalition by the joinPolicy
            joinCoalition(chosenAgentIndex,s);
        }
        else
            iterNum++;
    }

}
bool Party::isOffered(int coalition, Simulation &s){
    for (unsigned int i = 0; i < agentOffers.size(); i++){
        if ( s.getAgents().at(agentOffers.at(i)).getCoalition()==coalition)
        {
            return true;
        }
    }
    return false;
}
void Party::setCoalition(int coal){
    coalition = coal;
}

    // TODO: implement this method