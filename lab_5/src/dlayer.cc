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

#include "dlayer.h"
#include "D_pdu_m.h"
Define_Module(Dlayer);

void Dlayer::initialize()
{
    // TODO - Generated method body
    id=par("did");
      timeout=15;
            s=0;
            sf=0;
            win=4;
            sl=4;
            r=0;
            tmp=0;
            timeoutEvent = new cMessage("timeoutevent");
            del =new cMessage("delay");
      if(id ==1)
      {

          cMessage *msg = new cMessage();
          scheduleAt(0,msg);

      }
}

void Dlayer::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg == del)
         {
                          D_pdu* tmp=new D_pdu();
                          seq.push_back(tmp);
                          seq[s]->setId(s);
                          seq[s]->setType(0);
                          seq[s]->setA('a'+s);
                          if((s+1)!=sl)
                             scheduleAt(simTime(),del);
                          send(seq[s]->dup(),gate("downout"));
                          s+=1;


         }
       else if(msg ==timeoutEvent)
       {
               s=tmp;
               sf=tmp;
               sl=tmp+win;
           scheduleAt(simTime()+timeout,timeoutEvent);
           scheduleAt(simTime(),del);


       }
       else if(msg -> isSelfMessage())
       {

           scheduleAt(simTime()+timeout,timeoutEvent);
           scheduleAt(simTime(),del);

       }
       else
         {

            //  cPacket* pkt = new cPacket();
              D_pdu* pkt1 = check_and_cast<D_pdu*> (msg);
             // pkt1->encapsulate(pkt);
               if(pkt1 -> getArrivalGate()==gate("downin"))
               {

                  if(pkt1 -> getType()==0)
                  {
                  //   EV << pkt -> getId() << endl;
                      if(pkt1->getId()==r)
                      {
                        pkt1 -> setType(1);
                        r++;
                        send(pkt1,gate("downout"));
                      }
                      else if(pkt1 -> getId()!=r)
                        delete  pkt1;
                  }
                  else if(pkt1 ->getType()==1)
                  {
                     EV << pkt1 -> getId() << endl;

                      cancelEvent(del);
                      cancelEvent(timeoutEvent);
                      tmp=pkt1->getId();
                      sf++;
                      tmp+=1;
                      scheduleAt(simTime()+timeout,timeoutEvent);

                  }

               }




             }

}
