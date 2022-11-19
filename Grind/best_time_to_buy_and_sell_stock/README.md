Run through the list updating the lowest value when needed
While running through the list check if selling on that day yields a profit greater than the max. If so, update the max
This provides a solution which satisfies the constraint that selling should always be on the same day or later as compared to buying

## STD Libraries used 
1. std::numeric_limits<int>::max();
2. std::min(4, 5);
3. std::max(4, 5);