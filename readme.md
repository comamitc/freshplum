This solution to Freshplum's employment puzzle calculates the same as it does in javascript. 

I remove the 100 ms pause and instead calculate the seconds using that constant * loops taken to acheive 99% flipped.

I used C as to not run into any stack recursion problems (can be had in Python) and to test without any browser degredation.  This allows 50,000+ iterations of this test for averaging.
