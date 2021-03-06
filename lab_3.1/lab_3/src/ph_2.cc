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

#include "ph_2.h"
#include "p_m.h"
Define_Module(Ph_2);

void Ph_2::initialize()
{
    // TODO - Generated method body
    id=par("host_id");
}

void Ph_2::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    P *pkt = check_and_cast< P *> (msg);
      if(pkt -> getArrivalGate()==gate("inaa"))
      {
          send(pkt,gate("outbb"));
      }
      else if(pkt -> getArrivalGate() ==gate("inbb"))
      {
          send(pkt,gate("outaa"));
      }
}
