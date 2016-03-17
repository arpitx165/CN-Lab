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
       if(msg==timeout)
           {
                cancelEvent(timeout);

                 if(curf<10&&flag>flag1)
                 {
                     countsen++;
                      if(curf==flag1)
                      {
                       send(buf[curf++]->dup(),gate("downout"));
                       scheduleAt(simTime()+300,timeout);
                      }
                      else
                      {
                          send(buf[curf-1]->dup(),gate("downout"));
                          scheduleAt(simTime()+300,timeout);
                      }

                  }
                 else if(curf <10)
                  scheduleAt(simTime(),timeout);

           }
      else
       {
          cPacket* pkt = new cPacket();
          pkt = check_and_cast<cPacket*> (msg);
          if(msg -> getArrivalGate()==gate("upin"))
          {

          Dpdu *pkt1=new Dpdu();
          pkt1->encapsulate(pkt);
            if(flag==0)
             {
                buf.push_back(pkt1);
                send(pkt1->dup(),gate("downout"));
                flag++;
                countsen++;
                curf++;
                scheduleAt(simTime()+300,timeout);
             }
              else
              {
                  buf.push_back(pkt1);
                  flag++;
              }


         }
      else if(msg ->getArrivalGate()==gate("downin"))
      {
          Dpdu *pkt1=new Dpdu();
                 pkt1=check_and_cast<Dpdu *>(pkt);
               if(pkt1->getType()==0)
                 {
                   send(pkt1->decapsulate(),gate("upout"));
                   Dpdu *ack=new Dpdu();
                   countsen+=2;
                   ack->setType(1);
                   send(ack->dup(),gate("downout"));
                 }
               else if(pkt1->getType()==1)
               {  delete pkt1;cancelEvent(timeout);flag1++;scheduleAt(simTime(),timeout);}
       }
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
