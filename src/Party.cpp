#include "Party.h"
#include <vector>

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting),iterNum(0),coalition(-1) 
{
    
    agentOffers = new vector<Agent>();

}
Party::Party(Party &other): mId(other.mId),mName(other.mName),mMandates(other.mMandates),mState(other.mState),coalition(other.coalition),iterNum(other.iterNum){ // copy constructor
    agentOffers = new vector<Agent>();
    for (int i = 0; i < other.agentOffers->size(); i++)
    {
       agentOffers->push_back(other.agentOffers->at(i));
    } 

}
Party::Party(Party &&other): mId(other.mId),mName(other.mName),mMandates(other.mMandates),mState(other.mState),coalition(other.coalition),iterNum(other.iterNum){//move constructor - shallow copy
   agentOffers = other.agentOffers;
}

Party::~Party(){//destructor
    if(agentOffers)
         delete agentOffers;
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

void Party::joinCoalition(int chosenAgentIndex, Simulation &a){
    
    Agent temp =a.getAgents().at(chosenAgentIndex);
    int indexGenerated = a.getAgents().size(); //generate index for the new cloned agent 

    a.getAgents().push_back(new Agent(indexGenerated,mId,new SelectionPolicy(temp.getSelectionPolicy())));
    
    coalition = a.getAgents().at(chosenAgentIndex).getCoalition();                                                                                                                                                                                                                                       
    mState=Joined;
}

void Party::step(Simulation &s) //when joining coalition, clone the offering agent to the vector of agents in th simulation
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

    // TODO: implement this method
    

