class Solution {
public:     int mod = 1e9 + 7;
    int knightDialer(int n) {
        if(n == 1)  return 10;  //10 ways to dial nos of length 1 each
        int A = 4, B = 2, C = 2, D = 1; //total no of states
        for(int i=0; i<n-1; i++){
            int tmpA = A, tmpB = B, tmpC = C, tmpD = D;
            A = ((2 * tmpB) % mod + (2 * tmpC) % mod) % mod;
            B = tmpA;
            C = (tmpA + (2 * tmpD) % mod) % mod;
            D = tmpC;
        }

        int ans = (A + B) % mod;
        ans = (ans + C) % mod;
        return (ans + D) % mod;
    }
};