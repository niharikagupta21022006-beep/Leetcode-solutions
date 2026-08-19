class MyStack {
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
         q.push(x);
        int n = q.size() - 1;
        while (n--) {
            int y = q.front();
            q.pop();
            q.push(y);
        }
    }

    int pop() {
        int y = q.front();
        q.pop();
        return y;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        if(q.empty()){
            return true;
        }

        else{
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */