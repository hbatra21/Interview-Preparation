Let the number of jumbo burgers and small burgers that will be our answer be x and y respectively. Now, the tomato slices and cheese slices used in each of our burgers will be:

Jumbo Burger
Tomato Slices = 4*x
Cheese Slices = x

Small Burger
Tomato Slices = 2*y
Cheese Slices = y

Now, for no wastage of ingredients, the number of tomato slices and cheese slices used must be equal to the available number of tomato slices and cheese slices respectively. Therefore, the following 2 equations must hold:

4*x + 2*y = tomatoSlices
x + y = cheeseSlices
Solving for x and y gives us:

x = tomatoSlices/2 - cheeseSlices
y = 2*cheeseSlices - tomatoSlices/2
For our answers to be valid, both x and y must not be negative as well as fractional. For integral answers, tomatoSlices/2 must be an integer, which is only possible when tomatoSlices is divisible by 2. For non-negative answers, we will compute x and y and check if they are both positive. If they are, we will return them as the answer.

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> result;
        if(tomatoSlices%2 == 0)
        {
            int x = tomatoSlices/2 - cheeseSlices;
            int y = 2*cheeseSlices - tomatoSlices/2;
            if(x>=0 && y>=0)
            {
                result.push_back(x);
                result.push_back(y);
            }
        }
        
        return result;
    }
};
