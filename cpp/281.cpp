class ZigzagIterator {
private:
    bool odd;
    int cnt1, cnt2;
    vector<int> v1, v2;
public:
    ZigzagIterator(vector<int>& vec1, vector<int>& vec2) {
       odd = true;
       cnt1 = 0;
       cnt2 = 0;
       v1 = vec1;
       v2 = vec2;
    }

    int next() {
        if(cnt1<v1.size() && cnt2>=v2.size()){
            return v1[cnt1++];
        }else if(cnt1>=v1.size() && cnt2<v2.size()){
            return v2[cnt2++];
        }else{
            if(odd){
                odd = false;
                return v1[cnt1++];
            }else{
                odd = true;
                return v2[cnt2++];
            }
        }
    }

    bool hasNext() {
        return cnt1<v1.size() || cnt2<v2.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */