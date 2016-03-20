//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "ph1.h"
#include "ppdu_m.h"

Define_Module(Ph1);

void Ph1::initialize()
{
    // TODO - Generated method body
}

void Ph1::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
     cPacket* pkt = new cPacket();
     pkt = check_and_cast<cPacket*> (msg);
    if(msg -> getArrivalGate()==gate("upin"))
    {
       Ppdu *pkt1=new Ppdu();
       pkt1->encapsulate(pkt);
       send(pkt1,gate("downout"));
    }
    else if(msg ->getArrivalGate()==gate("downin"))
    {
        Ppdu *pkt1=new Ppdu();
        Dpdu *pkt2=new Dpdu();
        Ppdu *pkt4;
        cPacket* pkt3;
        pkt1=check_and_cast<Ppdu *>(pkt);
        pkt4=pkt1->dup();
        pkt3=pkt4->decapsulate();
        pkt2=check_and_cast<Dpdu *>(pkt3);

      if(pkt2->getType()==0)
      {
          if (uniform(0,1) < 0.1)
          {
                EV << "\"Losing\" message.\n";
                bubble("message lost");  // making animation more informative...
                delete pkt4;delete pkt1;
          }
        else
         {delete pkt4;send(pkt1->decapsulate(),gate("upout"));}
      }
      else
          {delete pkt4;send(pkt1->decapsulate(),gate("upout"));}
    }

}
