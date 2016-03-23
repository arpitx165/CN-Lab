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

#include "dl2.h"
#include "dpdu_m.h"
Define_Module(Dl2);

void Dl2::initialize()
{
    // TODO - Generated method body
    id=par("id");
    src=par("src");
    timeout=new cMessage();
    flag=0;
    flag1=0;
    curf=0;
    countsen=0;
   countrec=0;
   WATCH(countsen);
   WATCH(countrec);
}

void Dl2::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
          countrec++;
          cPacket* pkt = new cPacket();
          pkt = check_and_cast<cPacket*> (msg);
          if(msg -> getArrivalGate()==gate("upin"))
          {
            Dpdu *pkt1=new Dpdu();
            pkt1->encapsulate(pkt);
            send(pkt1->dup(),gate("downout"));
         }
      else if(msg ->getArrivalGate()==gate("downin"))
      {
         Dpdu *pkt1=new Dpdu();
         pkt1=check_and_cast<Dpdu *>(pkt);
         send(pkt1->decapsulate(),gate("upout"));
      }
      if(ev.isGUI())
             display();
}
void Dl2::display()
{
    char b[10];
    sprintf(b, "recv: %d send: %d", countrec, countsen);
    getDisplayString().setTagArg("t",0,b);


}
