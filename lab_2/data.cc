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

void Data::initialize()
{
    // TODO - Generated method body
    id=par("host_id");
    count=0;
}

void Data::handleMessage(cMessage *msg)
{
    // TODO - Generated method body

    cPacket* pkt1 = new cPacket();
    pkt1 = check_and_cast<cPacket*> (msg);

  if(pkt1 -> getArrivalGate() == gate("a_in"))
  {
         D_pdu* aa = new D_pdu();
         aa -> encapsulate(pkt1);
         aa -> setType(count%2);
         count++;
         send(aa,"d_out");

  }
  else
  {
      D_pdu* a= new D_pdu();
      a = check_and_cast<D_pdu*> (pkt1);
      if(a -> getType()==0 || a ->getType()==1)
      {
          D_pdu* ab=new D_pdu();
          ab->setType(-1);
          ab->setId(a->getId());
          send(ab,"d_out");
          send(a -> decapsulate(),gate("a_out"));
      }
      else
        delete msg;
  }

}
