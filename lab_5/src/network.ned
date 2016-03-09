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

package lab_5;
network Network
{
    submodules:
        c1: Cm{
            id = 1;
            @display("p=93,80");
        }
        c3: Cm {
            id = 2;
            @display("p=251,80");
        }
        c2: Hub;

    connections:
        c1.in <-- {delay = 100ms;} <-- c2.hOut;
        c1.out --> {delay = 100ms;} --> c2.hIn;
        c3.in <-- {delay = 100ms;} <-- c2.hOut1;
        c3.out -->{delay = 100ms;}--> c2.hIn1;

}
