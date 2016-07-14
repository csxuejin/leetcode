class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1 = (C-A)*(D-B);
        int s2 = (G-E)*(H-F);
        if(C<=E || G<=A || B>=H || F>=D){
            return s1+s2;
        }
        vector<int> v1{A,C,E,G};
        sort(v1.begin(), v1.end());
        vector<int> v2{D,H,B,F};
        sort(v2.begin(), v2.end());
        return s1+s2-(v1[2]-v1[1])*(v2[2]-v2[1]);
    }
};