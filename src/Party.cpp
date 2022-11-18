#include "Party.h"
#include <vector>

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting),iterNum(0),coalition(-1) 
{
    
    agentOffers = new vector<Agent>();

}
Party::Party(Party &other){ // copy constructor
    mId=other.mId;
    mName=other.mName;
    mMandates=other.mMandates;
    mState=other.mState;
    agentOffers = new vector<Agent>();
    for(Agent a: *(other.agentOffers)){//copy the pointers to the agents to the new vector
            agentOffers->push_back(a);
    }


}
Party::Party(Party &&other){//move constructor - shallow copy
    mId=other.mId;
    mName=other.mName;
    mMandates=other.mMandates;
    mState=other.mState;
    agentOffers=other.agentOffers;
}

Party::~Party(){//destructor
    if(agentOffers)
         delete agentOffers;
}
Party& Party::operator=(const Party &other){ // copy assignment opertor
    if(this != &other){
//delete this resources
    }
}
Party& Party::operator=(const Party &&other){ // move assignment opertor

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
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::joinCoalition(const Agent & chosenAgent, const Simulation &a){
    
    a.g

    mState=Joined;
}

void Party::step(Simulation &s) //when joining coalition, clone the offering agent to the vector of agents in th simulation
{
    if(mState==CollectingOffers){
        if(iterNum==3){
            const Agent &a= mJoinPolicy->chooseAgent(*agentOffers); // join some coalition by the joinPolicy
            joinCoalition(a,s);
            mState=Joined;
        }
        else
            iterNum++;
    }

}

    // TODO: implement this method
    

