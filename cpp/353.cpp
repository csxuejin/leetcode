class SnakeGame {
private:
    deque<pair<int,int>> que;
    set<pair<int,int>> ss;
    vector<pair<int,int>> food;
    int w, h, pos;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->food = food;
        w = width;
        h = height;
        pos = 0;
        que.push_back({0,0});
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int row = que.back().first;
        int col = que.back().second;
        pair<int,int> d = que.front();
        que.pop_front();
        ss.erase(d);
        
        if (direction == "U")
        	row--;
        else if (direction == "D")
        	row++;
        else if (direction == "L")
        	col--;
        else if (direction == "R")
        	col++;
        
        if(row<0 || row>=h || col<0 || col>=w || ss.count(make_pair(row,col)) ){
            return -1;
        }
        
        ss.insert(make_pair(row, col));
        que.push_back(make_pair(row, col));
        
        if (pos >= food.size())
	    	return que.size() - 1;

    	if (row == food[pos].first && col == food[pos].second) {
    		pos++;
    		que.push_front(d);
    		ss.insert(d);
    	}
    	return que.size() - 1;
     }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */