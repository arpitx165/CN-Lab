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

package lab6;

module Cnet
{
    parameters :
        int id;
        int dest;
        int src;
    gates :
         input inca;
         input incb;
         input ince;
         output outce;
         output outcb;
         output outca;    
    submodules:
        a3: Alayer {
            @display("p=190,100");
            id=id;
            src=src;
        }
        n3: Ncl {
            id=id;
            src=src;
            dest=dest;
            @display("p=190,193");
        }
        d1: Dl1 {
            @display("p=100,285");
                id=id;
                src=src;
        }
        d2: Dl2 {
            @display("p=190,285");
                id=id;
                src=src;
        }
        d3: Dl3 {
            @display("p=304,285");
                id=id;
                src=src;
        }
        p1: Ph1 {
            @display("p=100,389");
        }
        p2: Ph2 {
            @display("p=196,389");
        }
        p3: Ph3 {
            @display("p=310,397");
        }
    connections:
        a3.inla <-- n3.upout;
        a3.outla --> n3.upin;
        n3.downin <-- d1.upout;
        n3.downout --> d1.upin;
        n3.down1in <-- d2.upout;
        n3.down1out --> d2.upin;
        n3.down2in <-- d3.upout;
        n3.down2out --> d3.upin;
        d1.downin <-- p1.upout;
        d1.downout --> p1.upin;
        d2.downin <-- p2.upout;
        d2.downout --> p2.upin;
        d3.downin <-- p3.upout;
        d3.downout --> p3.upin;
        p1.downin <-- inca;
        p1.downout --> outca;
        p2.downin <-- incb;
        p2.downout --> outcb;
        p3.downin <-- ince;
        p3.downout --> outce;      
}
