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

module Cm
{
    
      parameters :
        int id;
    gates:
        input in;
        output out;
    submodules:
        h2: Dlayer{did=id;} 
        h3: Player{did=id;} 
    connections:
        h2.downin <-- h3.upout;
        h2.downout --> h3.upin;
        h3.downin <-- in;
        h3.downout --> out;
}
