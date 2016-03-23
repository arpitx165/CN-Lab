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
    tab.insert(make_pair(0,make_pair('A',make_pair(5,'-'))));
    tab.insert(make_pair(1,make_pair('B',make_pair(0,'-'))));
    tab.insert(make_pair(2,make_pair('C',make_pair(4,'-'))));
    tab.insert(make_pair(3,make_pair('D',make_pair(inf,'n'))));
    tab.insert(make_pair(4,make_pair('E',make_pair(3,'-'))));
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
        Tmp& v = pkt1->getMtab();
        for(int i=0;i<5;i++)
         v.insert(make_pair(i,make_pair(tab[i].first,make_pair(tab[i].second.first,tab[i].second.second))));
        for(int i=0;i<5;i++)
        {
          if(i!=(id-1)&&tab[i].second.second=='-')
           {
             send(pkt1->dup(),gtab[i].second);
           }
        }
      }
      else
      {
        Npdu *pkt1=new Npdu();
        pkt1=check_and_cast<Npdu*>(pkt);
        Tmp& v = pkt1->getMtab();
        int flag=0,tx=0;
        tx=pkt1->getId();
           for(int i=0;i<5;i++)
            {
              if(v[i].second.first + tab[tx-1].second.first < tab[i].second.first)
               {
                   tab[i].second.first=v[i].second.first + tab[tx-1].second.first;
                   if((tx-1)==i)
                   tab[i].second.second='-';
                  else
                   tab[i].second.second='A'+tx-1;
                   v[i].second.first=tab[i].second.first;
                   v[i].second.second=tab[i].second.second;
                 flag=1;
               }
              else
              {
                    if((id-1)==i)
                     v[i].second.second='-';
                    else if((tx-1)==i)
                      v[i].second.second='-';
                    else
                     v[i].second.second='A'+id-1;
                    v[i].second.first=tab[i].second.first;
              }
            }
         if(flag)
          {
            for(int i=0;i<5;i++)
             {
                if(i!=(id-1)&&tab[i].second.second=='-')
                   {
                       pkt1->setId(id);
                       send(pkt1->dup(),gtab[i].second);
                   }
                EV << tab[i].first << " " << tab[i].second.first << " " << tab[i].second.second <<endl;
             }
          }
          else
          {
            for(int i=0;i<5;i++)
             EV << tab[i].first << " " << tab[i].second.first << " " << tab[i].second.second <<endl;
             delete pkt1;
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
