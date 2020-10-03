class EllysBirthdays
{
    public:
        int numFriends(int N)
        {
            int arr[24] = {0, 1, 23, 88, 187, 313, 460, 623, 798, 985, 1181, 1385, 1596, 1813, 2035, 2263, 2494, 2730, 2970, 3213, 3459, 3707, 3959, 4213};
            return arr[N];
        }
};


/*

Are there two people in your class who happen to have a birthday on the same day of the year? Yes? "What a coincidence!" you probably thought the first time you noticed. It turns out
, however, that this is not at all improbable. This is something called "the birthday paradox".

This "paradox" states that the chance at least two out of K randomly-chosen people to have birthday on the same day of the year becomes over 50% when K becomes 23. Since most likely
you have more than 23 people in your class, the chance two of them to have a birthday on the same date is higher than the chance that there are no two people with the same
birthday!

Each day Elly looks which of her Facebook friends have birthdays. Since the girl has hundreds of friends, sometimes it happens that 3, 4, or even more of her friends have birthday on
the same day. For the purpose of this task we will ignore leap years and we will make two assumptions: we will assume that the birthday of each person is chosen uniformly at
random (i.e., for each person the probability of being born on any particular date is 1/365), and we will assume that these random events are mutually independent. Let p(F,N) be
the probability that a person who has a total of F friends has a group of N (or possibly even more) friends who share the same birthday. Elly wonders what is the smallest number
F of friends she needs so that p(F,N) would be strictly larger than 1/2.

You are given the N: the desired number of friends who should share the same birthday. Compute and return the smallest total number of friends for which the probability of some N
friends sharing the same birthday exceeds 50%.

Constraints
- N will be between 1 and 20, inclusive.

Examples
0)
2
Returns: 23
As the birthday paradox states, the chance becomes over 50% when the number of people is at least 23.

1)
3
Returns: 88
We need a little bit fewer than 100 friends in order for the event "some three share the same birthday" to become more likely than the event "at most two were born on each day of the
year".

2)
8
Returns: 798

3)
15
Returns: 2263

*/
