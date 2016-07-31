class TwoSum {
private:
    unordered_map<int, int> mm;
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    mm[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for(auto it=mm.begin(); it!=mm.end(); it++){
	        int a = it->first;
	        int b = value - a;
	        if(a == b && it->second>=2 || a!=b && mm.find(b)!=mm.end()){
	            return true;
	        }
	    }
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
