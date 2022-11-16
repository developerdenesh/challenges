1. 1 vs 1
- List 1 wins and increases to 2, 1 of list 1 points to a next
- [1 -> , 2, 4]
- [1, 3, 4]

2. 2 vs 1
List 2 wins and increases to 3, 1 of list 2 points to a next 
[2, 4]
[1 -> , 3, 4]

3. 2 vs 3
List 1 wins and increases to 4, 2 of list 1 points to a next 
[2 -> , 4]
[3, 4]

4. 4 vs 3
List 2 wins and increases to 4, 3 of list 2 points to a next 
[4]
[3 -> , 4]

5. 4 vs 4
List 1 wins and increases to NULL, 4 of list 1 points to a next
[4 -> ]
[4]

6. NULL vs 4
Returns list 2 because list 1 is NULL
[NULL]
[4]

7. Back to 5. Where 4 of list 1 points to [4][4 -> 4]

8. Back to 4. Where 3 of list 2 points to [4, 4][3 -> 4 -> 4]

9. Back to 3. Where 2 of list 1 points to [3, 4, 4][2 -> 3 -> 4 -> 4]

10. Back to 2. Where 1 of list 2 points to [2, 3, 4, 4][1 -> 2 -> 3 -> 4 -> 4]

11. Back to 1 where 1 of list 1 points to [1, 2, 3, 4, 4][1 -> 1 -> 2 -> 3 -> 4 -> 4]