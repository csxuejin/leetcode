class Queue {
private:
    stack<int> sta;
public:
    // Push element x to the back of queue.
    void push(int x) {
        sta.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> tmp;
        while(!sta.empty()){
            tmp.push(sta.top());
            sta.pop();
        }
        tmp.pop();
        while(!tmp.empty()){
            sta.push(tmp.top());
            tmp.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        stack<int> tmp;
        while(!sta.empty()){
            tmp.push(sta.top());
            sta.pop();
        }
        int t = tmp.top();
        while(!tmp.empty()){
            sta.push(tmp.top());
            tmp.pop();
        }
        return t;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return sta.empty();
    }
};


