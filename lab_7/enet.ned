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

module Enet
{
    parameters:
        int id;
        int src;
        int dest;
    gates:
        input inec;
        input ineb;
        output outec;
        output outeb;
    submodules:
        a5: Alayer {
            @display("p=139,107");
            id=id;
            src=src;
        }
        n5: Nel {
            id=id;
            src=src;
            dest=dest;
            @display("p=139,188");
        }
        d1: Dl1 {
            @display("p=61,285");
                id=id;
                src=src;
        }
        d2: Dl2 {
            @display("p=198,285");
                id=id;
                src=src;
        }
        p1: Ph1 {
            @display("p=61,378");
        }
        p2: Ph2 {
            @display("p=198,378");
        }
    connections:
        a5.inla <-- n5.upout;
        a5.outla --> n5.upin;
        n5.downin <-- d1.upout;
        n5.downout --> d1.upin;
        n5.down1in <-- d2.upout;
        n5.down1out --> d2.upin;
        d1.downin <-- p1.upout;
        d1.downout --> p1.upin;
        d2.downin <-- p2.upout;
        d2.downout --> p2.upin;
        p1.downin <-- inec;
        p1.downout --> outec;
        p2.downin <-- ineb;
        p2.downout --> outeb;

}
