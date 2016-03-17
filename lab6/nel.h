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

#ifndef __LAB6_NEL_H_
#define __LAB6_NEL_H_

#include <omnetpp.h>
#include <iostream>
#include <map>
using namespace std;
/**
 * TODO - Generated class
 */
class Nel : public cSimpleModule
{
    int id;
    int src;
    int dest,countsen,countrec;
    map <int,pair < char,char > > tab;
    map <int, pair <char ,cGate*>>gtab;
    cLongHistogram delay;
    cOutVector delay1;
 protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void display();
    virtual void finish();
};

#endif
