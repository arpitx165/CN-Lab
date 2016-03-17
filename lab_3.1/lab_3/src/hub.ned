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

module Hub
{
   parameters :
       int host_id;
   gates :
      input ciaa;
      input cibb;
      output coaa;
      output cobb; 
   submodules :
    
    n1 : Ph1 {host_id=host_id;}
    n2 : Ph_2 {host_id=host_id;} 
   connections:
       n1.inb <-- n2.outaa;
       n1.outb --> n2.inaa;
       n1.ina <--  ciaa;
       n1.outa --> coaa;
       n2.inbb <-- cibb;
       n2.outbb --> cobb;  
}
