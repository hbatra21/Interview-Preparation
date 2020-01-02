/*
Definition
    	
Class:	QuizShow
Method:	wager
Parameters:	int[], int, int
Returns:	int
Method signature:	int wager(int[] scores, int wager1, int wager2)
(be sure your method is public)
    
 
Constraints
-	scores will contain exactly 3 elements.
-	Each element of scores will be between 0 and 10000, inclusive.
-	wager1 will be between 0 and scores[1], inclusive.
-	wager2 will be between 0 and scores[2], inclusive.
 
Examples
0)	
    	
{ 100, 100, 100 }
25
75
Returns: 76
If you bet 76, you have a 50% chance of winning. In this case, it doesn't matter if your opponents are right or wrong. If you are right, you win. Otherwise, you lose. If you wager less than 76, your chance of winning drops below 50%, and if you wager more, your chance of winning will not increase. Therefore, the correct answer is 76.
1)	
    	
{ 10, 50, 60 }
30
41
Returns: 0
Even if your opponents are both wrong, they will end up with 20 and 19 points. Since you cannot win (even if you wager 10), the correct answer is 0.
2)	
    	
{ 10, 50, 60 }
31
41
Returns: 10
This is the same as the previous example, except in this case your opponents will each end up with 19 points if they are both wrong. Now, you have a 12.5% chance of winning if you wager 10.
3)	
    	
{ 2, 2, 12 }
0
10
Returns: 1
*/

int wager (vector scores, int wager1, int wager2)
{
int best, bet, odds, wage, I, J, K;
best = 0; bet = 0;


for (wage = 0; wage ≤ scores[0]; wage++)
{
odds = 0;
// in ‘odds’ we keep the number of favorable outcomes
for (I = -1; I ≤ 1; I = I + 2)
for (J = -1; J ≤ 1; J = J + 2)
for (K = -1; K ≤ 1; K = K + 2)
if (scores[0] + I * wage > scores[1] + J * wager1 &&
scores[0] + I * wage > scores[2] + K * wager2) { odds++; }
if (odds > best) { bet = wage ; best = odds; }
// a better wager has been found
}
return bet;
}

