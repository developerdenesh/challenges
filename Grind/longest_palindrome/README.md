Count the number of odd characters, and remove them from the final list, but leave one behind (if there are odd characters)

## STD Libraries used 
1. std::count(c.begin(), c.end(), character);

## Tricks
1. count & 1 returns 1 if both count and 1 are odd numbers. Otherwise, 0 is returned