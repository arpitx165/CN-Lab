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

#include "simple.h"
#include "mypacket_m.h"

Define_Module(Simple);

void Simple::initialize()
{
    // TODO - Generated method body
    id=par("host_id");
    in=gate("in");
    out=gate("out");

       if(id==1)
       {
           cMessage* msg=new cMessage();
           scheduleAt(0,msg);

       }
}

void Simple::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(counter <10)
       {
          if(msg->isSelfMessage())
          {
              Mypacket* m=new Mypacket();
              m->setId(0);
              m->setType(0);
              counter++;
              send(m,out);


          }
           else
              {

               Mypacket * m = check_and_cast<Mypacket*> (msg);
               if(m-> getType() ==0)
                {

                   m->setId(1);
                   m->setType(1);
                   counter++;
                   send(m,out);

                }

              else
                {

                  m->setId(0);
                  m->setType(0);
                  counter++;
                  send(m,out);

                 }
              }
       }
}
