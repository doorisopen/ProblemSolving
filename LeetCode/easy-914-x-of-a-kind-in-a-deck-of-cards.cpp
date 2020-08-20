/**
 * deck 배열 원소의 빈도수를 check배열에 저장하고 
 * 각 원소 빈도수의 최대공약수를 구한다.
 */
class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b,a%b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        int check[10000]={0};
        vector<int> v;
        set<int> s;
        for(int i : deck) {
            check[i]++;
            s.insert(i);
        }
        int num = -1;
        for(int i : s) {
            if(num == -1) {
                num = check[i];
            } else {
                num = gcd(check[i], num);  
            }
        }
        return num >= 2;
    }
};