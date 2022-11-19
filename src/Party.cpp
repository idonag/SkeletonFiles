#include "Party.h"
#include "Agent.h"
#include "JoinPolicy.h"
#include "Simulation.h"
#include "SelectionPolicy.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting),iterNum(0),coalition(-1) 
{
    
    agentOffers = new vector<Agent>();

}
Party::Party(const Party &other): mId(other.mId),mName(other.mName),mMandates(other.mMandates),mState(other.mState),coalition(other.coalition),iterNum(other.iterNum){ // copy constructor
    mJoinPolicy = other.mJoinPolicy->clone();
    agentOffers = new vector<Agent>();
    for (int i = 0; i < other.agentOffers->size(); i++)
    {
        agentOffers->push_back(other.agentOffers->at(i));
    } 

}
Party::Party(const Party &&other): mId(other.mId),mName(other.mName),mMandates(other.mMandates),mState(other.mState),coalition(other.coalition),iterNum(other.iterNum){//move constructor - shallow copy
   agentOffers = other.agentOffers;
   mJoinPolicy = other.mJoinPolicy;
}

Party::~Party(){//destructor
    if(agentOffers)
         delete agentOffers;
    delete mJoinPolicy;
}
Party& Party::operator=(const Party &other){ // copy assignment opertor
    if(this != &other){
        if(agentOffers)
            delete agentOffers;
        mId = other.mId;
        mName=other.mName;
        mMandates = other.mMandates;
        mState = other.mState;
        coalition = other.coalition;
        iterNum = other.iterNum;
        agentOffers = new vector<Agent> ();
        for (int i = 0; i < other.agentOffers->size(); i++)
        {
            agentOffers->push_back(other.agentOffers->at(i));
        }
        mJoinPolicy = other.mJoinPolicy->clone();
    }
    return *this;
}
Party& Party::operator=(const Party &&other){ // move assignment opertor
if(this!=&other){
    if(agentOffers)
        delete agentOffers;
    agentOffers=other.agentOffers;
    mId = other.mId;
    mName=other.mName;
    mMandates = other.mMandates;
    mState = other.mState;
    coalition = other.coalition;
    iterNum = other.iterNum;
    mJoinPolicy = other.mJoinPolicy;

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

void Party::offer(const Agent &offer){
    agentOffers->push_back(offer);
    if(mState!=CollectingOffers)
        mState=CollectingOffers;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s) 
{
    if(mState==CollectingOffers){
        if(iterNum==3){
            int chosenAgentIndex= mJoinPolicy->chooseAgent(s,*agentOffers); // join some coalition by the joinPolicy
            joinCoalition(chosenAgentIndex,s);
        }
        else
            iterNum++;
    }

}
bool Party::isOffered(int coalition)const{
    for (int i = 0; i < agentOffers->size(); i++){
        if (agentOffers->at(i).getCoalition()==coalition)
        {
            return true;
        }
    }
    return false;
}

    // TODO: implement this method
    
}
