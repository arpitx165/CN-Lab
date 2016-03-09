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

#include "player.h"
#include "P_pdu_m.h"
Define_Module(Player);

void Player::initialize()
{
    // TODO - Generated method body
    id=par("did");
}

void Player::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
        cPacket* pkt = new cPacket();
        pkt = check_and_cast<cPacket*> (msg);
      //  D_pdu *pkt=check_and_cast<D_pdu*>(msg);
        if(pkt-> getArrivalGate()==gate("upin"))
         {
                 P_pdu* a=new P_pdu();
                 a -> encapsulate(pkt);
               if(a -> getType()==0)
               {
                 EV << a -> getId() << endl;
                if (uniform(0,1) < 0.1)
                   {
                         EV << "\"Losing\" message.\n";
                         bubble("message lost");  // making animation more informative...
                         delete a;
                   }
                 else
                 send(a,gate("downout"));
               }
               else
                   send(a,gate("downout"));

         }
        else if(pkt -> getArrivalGate()==gate("downin"))
        {
            P_pdu* b=new P_pdu();
            b = check_and_cast<P_pdu*> (pkt);
            EV << "hi" << endl;
           send((b->decapsulate()),gate("upout"));
        }

}
