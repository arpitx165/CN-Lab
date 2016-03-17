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

#include "app.h"
#include "a_pdu_m.h"
Define_Module(App);

void App::initialize()
{
    // TODO - Generated method body
    id=par("host_id");
    countsen=0;
    countrecv=0;
    count=0;
    rtt=0.0;
    WATCH(countsen);
    WATCH(countrecv);
    hopCountStats.setName("hopCountStats");
        hopCountStats.setRangeAutoUpper(0, 10, 1.5);
        hopCountVector.setName("HopCount");
    if(id==1)
          {
              cMessage* msg=new cMessage();
              scheduleAt(0,msg);

          }

}

void App::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
       int hopcount;
       count++;
       if(msg -> isSelfMessage())
       {
           A_pdu* a=new A_pdu();
           a -> setId(count);
           a -> setType(0);
           countsen++;
           rtt=simTime();
           a->setHopCount(a->getHopCount()+1);
           hopcount=a->getHopCount();
           hopCountVector.record(hopcount);
           hopCountStats.collect(hopcount);
           send(a,gate("out"));
           if(ev.isGUI())
                display();
       }
    else
      {
           countrecv++;
          if(ev.isGUI())
               display();
       if(count < 10)
       {
           countsen++;
         A_pdu* pkt=check_and_cast<A_pdu*> (msg);
        if(pkt ->getType()==0)
        {
            bubble("message received");
            pkt -> setId(count);
            pkt -> setType(1);
            send(pkt,gate("out"));
        }
        else
        {
            bubble("ack received");
            EV << "RTT " << simTime()-rtt;
            rtt=simTime();
            pkt -> setId(count);
            pkt -> setType(0);
            send(pkt,gate("out"));

        }
        pkt->setHopCount(pkt->getHopCount()+1);
              hopcount=pkt->getHopCount();
              hopCountVector.record(hopcount);
              hopCountStats.collect(hopcount);
       }
       if(ev.isGUI())
             display();
      }

}
void App::display()
{
    char b[10];
    sprintf(b, "recv: %d send: %d", countrecv, countsen);
    getDisplayString().setTagArg("t",0,b);


}
void App::finish()
{
    // This function is called by OMNeT++ at the end of the simulation.
    EV << "Sent:     " << countsen << endl;
    EV << "Received: " << countrecv << endl;
    EV << "Hop count, min:    " << hopCountStats.getMin() << endl;
    EV << "Hop count, max:    " << hopCountStats.getMax() << endl;
    EV << "Hop count, mean:   " << hopCountStats.getMean() << endl;
    EV << "Hop count, stddev: " << hopCountStats.getStddev() << endl;

    recordScalar("#sent", countsen);
    recordScalar("#received", countrecv);

    hopCountStats.recordAs("hop count");
}


