class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
	    int group = numRows + (numRows>2)? numRows-1: numRows;
	    vector<string> vec(numRows);
	    int row = 0;
	    bool down = true;
	    for (int i=0; i<s.size(); i++){
	    	vec[row] += s[i];
	    	if (row == numRows-1) 
	    	    down = false;
	    	if (row == 0) 
	    	    down = true;

	    	if (down){
	    		row ++;
	    	}else{
	    		row --;
	    	}
	    }
	    s.clear();
	    for (int i=0; i<numRows; i++) 
	        s.append(vec[i]);
	    return s;
    }
};

