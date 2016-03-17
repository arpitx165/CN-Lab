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

#include "nbl.h"
#include "npdu_m.h"
Define_Module(Nbl);

void Nbl::initialize()
{
    // TODO - Generated method body
    id=par("id");
    src=par("src");
    dest=par("dest");
    tab.insert(make_pair(0,make_pair('A','-')));
    tab.insert(make_pair(1,make_pair('B','-')));
    tab.insert(make_pair(2,make_pair('C','-')));
    tab.insert(make_pair(3,make_pair('D','A')));
    tab.insert(make_pair(4,make_pair('E','-')));
    gtab.insert(make_pair(0,make_pair('A',gate("downout"))));
    gtab.insert(make_pair(1,make_pair('B',gate("upout"))));
    gtab.insert(make_pair(2,make_pair('C',gate("down1out"))));
    gtab.insert(make_pair(3,make_pair('D',gate("downout"))));
    gtab.insert(make_pair(4,make_pair('E',gate("down2out"))));
    delay.setName("delaystats");
    delay.setRangeAutoUpper(0, 10, 1.5);
    delay1.setName("delay");
    countsen=0;
    countrec=0;
    WATCH(countsen);
    WATCH(countrec);
}

void Nbl::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
      cPacket* pkt = new cPacket();
       pkt = check_and_cast<cPacket*> (msg);
       countrec++;
      if(msg -> getArrivalGate()==gate("upin"))
      {
        Npdu *pkt1=new Npdu();
        pkt1->encapsulate(pkt);
        pkt1->setType(0);
        pkt1->setId(id);
        pkt1->setSrc(src);
        pkt1->setDest(dest);
        countsen++;
        pkt1->setDel(simTime());
        send(pkt1,gtab[dest-1].second);
      }
      else
      {
          Npdu *pkt1=new Npdu();
          pkt1=check_and_cast<Npdu*>(pkt);
          if(pkt1 ->getDest()== id)
          {
              EV << simTime()-pkt1->getDel() << endl;
             delay1.record(simTime()-pkt1->getDel());
             countsen++;
             delay.collect(simTime()-pkt1->getDel());
              send(pkt1->decapsulate(),gtab[id-1].second);
          }
          else
          {
              int tmp=pkt1->getDest();
              countsen++;
              send(pkt1,gtab[tmp-1].second);
          }
       }
      if(ev.isGUI())
      {
          display();
      }
}
void Nbl::display()
{
    char b[10];
    sprintf(b, "recv: %d send: %d", countrec, countsen);
    getDisplayString().setTagArg("t",0,b);


}
void Nbl::finish()
{
    // This function is called by OMNeT++ at the end of the simulation.
    EV << "Sent:     " << countsen << endl;
    EV << "Received: " << countrec << endl;
    EV << "delay, min:    " << delay.getMin() << endl;
    EV << "delay, max:    " << delay.getMax() << endl;
    EV << "delay, mean:   " << delay.getMean() << endl;
    EV << "delay, stddev: " << delay.getStddev() << endl;

    recordScalar("#sent", countsen);
    recordScalar("#received", countrec);

    delay.recordAs("delay");
}


