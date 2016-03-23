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

#include "ph3.h"
#include "ppdu_m.h"
Define_Module(Ph3);

void Ph3::initialize()
{
    // TODO - Generated method body
}

void Ph3::handleMessage(cMessage *msg)
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
           pkt1=check_and_cast<Ppdu *>(pkt);
      /*  if(pkt1->getType()==1)
        {
           if (uniform(0,1) < 0.1)
           {
                 EV << "\"Losing\" message.\n";
                 bubble("message lost");  // making animation more informative...
                 delete pkt1;
           }
         else
           send(pkt1->decapsulate(),gate("upout"));
        }
        else*/
            send(pkt1->decapsulate(),gate("upout"));
       }
}
