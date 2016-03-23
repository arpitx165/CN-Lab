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

module Dnet
{
    parameters:
        int id;
        int src;
        int dest;
    gates:
        input inda;
        output outda;
    submodules:
        a4: Alayer {
            id=id;
            src=src;
            @display("p=151,76");
        }
        n4: Ndl {
            id=id;
            src=src;
            dest=dest;
            @display("p=151,174");
        }
        d1: Dl1 {
            @display("p=151,262");
                id=id;
                src=src;
        }
        p1: Ph1 {
            @display("p=151,360");
        }

    connections:
        a4.inla <-- n4.upout;
        a4.outla --> n4.upin;
        n4.downin <-- d1.upout;
        n4.downout --> d1.upin;
        d1.downin <-- p1.upout;
        d1.downout --> p1.upin;
        p1.downin <-- inda;
        p1.downout --> outda;

}
