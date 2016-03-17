//
// This program is free software: you can redistribute itpdu and/or modify
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

#include "alayer.h"
#include "apdu_m.h"
Define_Module(Alayer);

void Alayer::initialize()
{
    // TODO - Generated method body
    id=par("id");
    src=par("src");
    countsen=0;countrec=0;
    WATCH(countsen);
    WATCH(countrec);
    if(id==src)
    {
        cMessage *pkt=new cMessage();
        scheduleAt(0,pkt);
    }
}

void Alayer::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg ->isSelfMessage())
    {
       for(int i=1;i<=10;i++)
       {

            Apdu *pkt1=new Apdu();
            pkt1->setId(i);
            pkt1->setType(0);
            countsen++;

            send(pkt1->dup(),gate("outla"));
       }
    }
    else
    {
        countrec++;
        delete msg;
    }
    if(ev.isGUI())
           display();
}
void Alayer::display()
{
    char b[10];
    sprintf(b, "recv: %d send: %d", countrec, countsen);
    getDisplayString().setTagArg("t",0,b);


}
