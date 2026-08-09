class BrowserHistory {
    stack<string> backs;
    stack<string> forwards;
    string current = " ";

public:
    BrowserHistory(string homepage) { current = homepage; }

    void visit(string url) {
        backs.push(current);
        current = url;
        while (!forwards.empty()) {
            forwards.pop();
        }
    }

    string back(int steps) {

        while (steps > 0 && !backs.empty()) {
            forwards.push(current);
            current = backs.top();
            backs.pop();
            steps--;
        }
        return current;
    }

    string forward(int steps) {
        while(steps >0 && !forwards.empty()){
            backs.push(current);
            current = forwards.top();
            forwards.pop();
            steps--;
        }

        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */