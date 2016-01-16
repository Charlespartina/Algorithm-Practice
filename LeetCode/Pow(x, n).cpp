// The parameter should be a double type
// Pay attention to 0,-1 and 1 case.
// Divide and Conquer to save time. Check if n is odd or even.
class Solution {
public:
    double hpow(double x, int n){
        if(n == 0) return (double)1;
        if(n == 1) return x;
        if(n == -1) return (double)1/x;
        double re;
        if(n%2 == 0){
            re = hpow(x,n/2);
            return re*re;
        }
        else{
            re = hpow(x,(n-1)/2);
            return re*re*x;
        }
    }
    double myPow(double x, int n) {
        double tmp = x;
        if(n%2 == 0) return hpow(x,n);
        else return x*hpow(x,n-1);
    }
};