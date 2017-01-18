class Stack {
private:
    deque<int> que;
public:
    // Push element x onto stack.
    void push(int x) {
        que.push_front(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        que.pop_front();
    }

    // Get the top element.
    int top() {
        return que.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
};