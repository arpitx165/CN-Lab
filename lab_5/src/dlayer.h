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

#ifndef __LAB_5_DLAYER_H_
#define __LAB_5_DLAYER_H_

#include <omnetpp.h>
#include <vector>
#include <D_pdu_m.h>
using namespace std;
/**
 * TODO - Generated class
 */
class Dlayer : public cSimpleModule
{

  protected:
        vector<D_pdu *> seq;
        int sf,cvar=0,id;
        int sl,r,s,win=0,tmp=0;
        int timeout;
        cMessage *timeoutEvent,*del;

    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif
