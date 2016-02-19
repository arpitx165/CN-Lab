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

#include "phy.h"
#include "p_m.h"
Define_Module(Phy);

void Phy::initialize()
{
    // TODO - Generated method body
    id=par("host_id");
}

void Phy::handleMessage(cMessage *msg)
{
    // TODO - Generated method body

      P* a=new P();
      if(msg -> getArrivalGate()== gate("d_in"))
         send(a,gate("c_out"));
    else if(msg -> getArrivalGate()== gate("c_in"))
         send(a,gate("d_out"));

}
