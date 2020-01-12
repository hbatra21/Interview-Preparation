class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for(int i = 0; i < 32; i++) {
            bool aa = a & (1 << i), bb = b & (1 << i), cc = c & (1 << i);
            bool res = aa + bb;
            if(res == cc)// no flips required
                continue;
            if(cc)
                flips++;
            else
            {
                if(aa && bb)// when both a, b have 1 bit then flip both to 0
                    flips += 2;
                else
                    flips += 1;
            }
        }
        return flips;
    }
};
