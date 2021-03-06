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

#ifndef __LAB_2_DATA_H_
#define __LAB_2_DATA_H_

#include <omnetpp.h>
#include <stdio.h>
#include "d_pdu_m.h"
#include <string.h>
/**`1
 * TODO - Generated class
 */
class Data : public cSimpleModule
{
    int id;
    int count;
    int countx=0;
    int countsen;
    int countrecv;
  private:
    simtime_t timeout;  // timeout
    cMessage *timeoutEvent,*delsen,*delrecv;  // holds pointer to the timeout self-message
    D_pdu *copy,*co;

public :
    Data();
 virtual ~Data();
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void display();
};

#endif
