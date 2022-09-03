/*Ethan Tarlov
6/1/22
iGuard.cs
Names all of the public functions from Guard and DataExtractor for the crossFunctions to use
*/
using System;
namespace iGuards
{
    public interface iGuard
    {
        int value(int x);

        int[] any();
        int[] target(int z);
        int sum(int z);
    }
    
}
