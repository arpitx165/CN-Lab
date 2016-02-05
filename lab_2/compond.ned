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

package lab_2;

module Compond
{
    parameters :
        int host_id;
    gates:
        input in;
        output out;
    submodules:
        h1: App {
           host_id=host_id;
        }
        h2: Data {
            
            @display("p=50,161");
             host_id=host_id;
        }
        h3: Phy {
             host_id=host_id;
            @display("p=161,161");
        }
    connections:
        h1.in <-- h2.a_out;
        h1.out --> h2.a_in;
        h2.d_in <-- h3.d_out;
        h2.d_out --> h3.d_in;
        h3.c_in <-- in;
        h3.c_out --> out;
}
