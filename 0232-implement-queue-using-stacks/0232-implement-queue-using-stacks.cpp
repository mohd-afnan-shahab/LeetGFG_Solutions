class MyQueue {
public:

    stack<int> input;
    stack<int> output;
    int peekelement = -1;

    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()){
            peekelement = x;
        }
        input.push(x);      //ye to har bar krna hai..
    }
    
    //Amortised O(1)
    int pop() {
        if(output.empty()){
            //input ko output me dalo   O(N)
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }

        int result = output.top();      //O(1)
        output.pop();
        return result;
    }
    
    int peek() {
        if(output.empty()){
            return peekelement;
        }
        return output.top();
    }
    
    bool empty() {
        if(input.empty() && output.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */