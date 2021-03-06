class WaterAndOxygen
{
    public:
        double maxDays(double remainH2O, double remainO2, double costH2O, double costO2)
        {
            double daysH2O=remainH2O/costH2O, daysO2=remainO2/costO2,totaldays,remainwater;
            totaldays=daysH2O;
            if(daysH2O>daysO2)
            {
                totaldays=daysO2;
                remainwater=remainH2O-(costH2O*daysO2);
                totaldays+=remainwater/(2*costO2+costH2O);
            }
            return totaldays;
        }
};


/*

You are in a spaceship that is far away from the Earth. Your crew needs costH2O moles of water (H2O) and costO2 moles of oxygen (O2) per day. The spaceship currently has remainH2O 
moles of water and remainO2 moles of oxygen left in the tanks. This ship is old so you don't have any equipment to recycle used water and oxygen: once you use them, they are gone.
The only thing you can do is electrolysis of water. For any positive real x, you can electrolyze x moles of water. You will lose those x moles of water but you will produce x/2
moles of oxygen. (You will also produce x moles of hydrogen but those don't matter in this task.)

Compute and return the longest amount of time (in days) your crew can survive. Note that the answer is not necessarily an integer.

Notes
- The returned value must have an absolute or relative error less than 1e-9.

Constraints
- costH2O will be between 1 and 1,000,000,000, inclusive.
- costO2 will be between 1 and 1,000,000,000, inclusive.
- remainH2O will be between 0 and 1,000,000,000, inclusive.
- remainO2 will be between 0 and 1,000,000,000, inclusive.

Examples
0)
64
70
3
7
Returns: 12.0
If you don't do anything, after 70 / 7 = 10 days you will run out of oxygen. At that time you will have 64 - 10 * 3 = 34 moles of water left. In order to survive longer you will need 
to electrolyze some of your remaining water to produce the oxygen you need. To get enough oxygen for a day, you need to electrolyze 2 * 7 = 14 moles of water. Don't forget that you
also need 3 moles of actual water per day. Thus, on each of the following days you will consume 17 moles of water, which means that you can survive for 34 / 2 = 2 extra days. In 
total you will survive for 10 + 2 = 12 days.

1)
99
102
1
1
Returns: 99.0
You will run out of water after 99/1 = 99 days, while the oxygen will last for 102/1 = 102 days. Electrolysis won't help you live longer than 99 days.

2)
101
99
1
1
Returns: 99.66666666666667
This time you should use 4/3 of a mole of water to produce 2/3 of a mole of oxygen.

3)
123456789
987654321
123
456
Returns: 1003713.731707317

4)
987654321
123456789
456
123
Returns: 1758643.7307692308

5)
0
0
13
27
Returns: 0.0

*/
