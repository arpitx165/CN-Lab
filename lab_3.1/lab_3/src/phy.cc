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

#include "phy.h"
#include "p_m.h"

Define_Module(Phy);

void Phy::initialize()
{
    // TODO - Generated method body
    id=par("host_id");
    countsen=0;
    countrecv=0;
    WATCH(countsen);
    WATCH(countrecv);
}

void Phy::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    cPacket* pkt = new cPacket();
    pkt = check_and_cast<cPacket*> (msg);
    countrecv++;
    if(ev.isGUI())
        display();
    countsen++;
    if(ev.isGUI())
           display();
  if(pkt-> getArrivalGate()==gate("d_in"))
  {

          P* a=new P();
          a -> encapsulate(pkt);
          send(a,gate("c_out"));

  }
  else
  {

                  P* b=new P();
                  b = check_and_cast<P *> (pkt);
                 if(b -> getType()==0)
                 {
                     if (uniform(0,1) < 0.1)
                         {
                             EV << "\"Losing\" message.\n";
                             bubble("message lost");  // making animation more informative...
                             delete msg;
                         }
                     else
                     send(b->decapsulate(),gate("d_out"));
                 }
                 else
                 {
                     if (uniform(0,1) < 0.15)
                           {
                              EV << "\"Losing\" message.\n";
                               bubble("message lost");  // making animation more informative...
                               delete msg;
                           }
                     else
                       send(b->decapsulate(),gate("d_out"));
                 }


  }

}
void Phy::display()
{
    char bx[30];
       sprintf(bx, "recv: %d send: %d", countrecv, countsen);
       getDisplayString().setTagArg("t",0,bx);
}

