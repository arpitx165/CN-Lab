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
    if(id==1)
          {
              cMessage* msg=new cMessage();
              scheduleAt(0,msg);

          }

}

void App::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
  if(count <= 10)
  {
      count++;
       if(msg -> isSelfMessage())
       {
           A_pdu* a=new A_pdu();

           a -> setId(count);
           a -> setType(0);
           send(a,gate("out"));
       }
       else
       {
         A_pdu* pkt=check_and_cast<A_pdu*> (msg);
        if(pkt ->getType()==0)
        {
            pkt -> setId(count);
            pkt -> setType(1);
            send(pkt,gate("out"));

        }
        else
        {

            pkt -> setId(count);
            pkt -> setType(0);
            send(pkt,gate("out"));

        }
       }
  }



}
