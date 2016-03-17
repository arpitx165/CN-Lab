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
network Network
{
    submodules:
        n1: Anet {
            id = 1;
            @display("p=50,50");
        }
        n2: Bnet {
            id = 2;
            @display("p=243,50");
        }
        n3: Cnet {
            id = 3;
            @display("p=147,142");
        }
        n4: Dnet {
            id = 4;
            @display("p=50,214");
        }
        n5: Enet {
            id = 5;
            @display("p=243,222");
        }
    connections:
        n1.inab <-- n2.outba;
        n1.outab --> n2.inba;
        n1.inac <-- n3.outca;
        n1.outac --> n3.inca;
        n1.inad <-- n4.outda;
        n1.outad --> n4.inda;
        n2.inbe <-- n5.outeb;
        n2.outbe --> n5.ineb;
        n2.inbc <-- n3.outcb;
        n2.outbc --> n3.incb;
        n3.ince <-- n5.outec;
        n3.outce --> n5.inec;
}
