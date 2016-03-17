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

#include "data.h"
#include "d_pdu_m.h"
Define_Module(Data);
Data::Data()
 {
    timeoutEvent = NULL;
 }
 Data::~Data()
 {
     cancelAndDelete(timeoutEvent);
 }
void Data::initialize()
{
    // TODO - Generated method body

    id=par("host_id");
    count=0;
    countx=0;
    countsen=0;
    timeout = 1.0;
    countrecv=0;
    copy=NULL;
    co=NULL;
    // Generate and send initial message.
     //EV << "Sending initial message\n";
    delsen=new cMessage("delaysender");
    delrecv=new cMessage("delayreciever");
    timeoutEvent = new cMessage();
     if(id==1)
      {
         scheduleAt(simTime()+timeout, timeoutEvent);
      }
}

void Data::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    countrecv++;
 if(msg == delsen)
 {
     D_pdu *tmp;
         tmp = co -> dup();
     send(tmp,gate("d_out"));
     countrecv++;
     countsen++;
     if(ev.isGUI())
         display();
     scheduleAt(simTime()+timeout, timeoutEvent);
 }
 else if(msg == delrecv)
 {
     D_pdu *tmp;
     tmp = copy -> dup();
     send(tmp,gate("d_out"));

     countsen++;
          if(ev.isGUI())
              display();
          scheduleAt(simTime()+timeout, timeoutEvent);
 }
 else if(msg==timeoutEvent)
 {
    if(countx < 9)
        {
          EV << countx << "Timeout expired, resending message and restarting timer\n";
          D_pdu *tmp;
           tmp = co -> dup();
           send(tmp,"d_out");
           scheduleAt(simTime()+timeout, timeoutEvent);
        }
 }
 else
 {
             EV << "Timer cancelled.\n";
               cancelEvent(timeoutEvent);
               countrecv++;
               if(ev.isGUI())
                     display();
               cPacket* pkt1 = new cPacket();
               pkt1 = check_and_cast<cPacket*> (msg);

               if(pkt1 -> getArrivalGate() == gate("a_in"))
               {
                      D_pdu* aa = new D_pdu();
                      aa -> encapsulate(pkt1);
                      aa -> setType(count%2);
                      count=count%2;
                      count++;
                      countx++;
                      countsen++;
                      co=aa->dup();
                      if(uniform(0,1)< 0.30)
                           scheduleAt(simTime()+2,delsen);
                     else
                           scheduleAt(simTime()+1,delsen);
               }
               else
               {
                   D_pdu* a= new D_pdu();
                   a = check_and_cast<D_pdu*> (pkt1);
                   if(a -> getType()== 1 || a -> getType()==0)
                   {
                       D_pdu* ab=new D_pdu();
                        ab->setType(-1);
                        ab->setId(a->getId());
                        copy = ab->dup();
                        send(a -> decapsulate(),gate("a_out"));
                        countsen++;
                        if(uniform(0,1)<0.40)
                          scheduleAt(simTime()+2,delrecv);
                       else
                          scheduleAt(simTime()+1,delrecv);
                   }
                   else
                     delete msg;

               }
               if(ev.isGUI())
                     display();
 }
}
void Data::display()
{
    char b[30];
       sprintf(b, "recv: %d send: %d", countrecv, countsen);
       getDisplayString().setTagArg("t",0,b);
}
