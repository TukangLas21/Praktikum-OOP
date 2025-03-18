#include "Agent.hpp"
#include "SuperAgent.hpp"
using namespace std;

int main() {
    SuperAgent agentX;
    
    Agent* agentY = &agentX;
    agentY->setID(1337);
    agentX.setID(9999);

    agentX.print();
    return 0;
}