class MinStack {
public:
  list<int> stack;
  int min = INT_MAX;
  /** initialize your data structure here. */
  MinStack() {
  }

  void push(int x) {
    if(x <= min) {
      stack.push_back(min);
      min = x;
    }
    stack.push_back(x);
  }

  void pop() {
    if(stack.back() == min) {
      stack.pop_back();
      min = stack.back();
    }
    stack.pop_back();
  }

  int top() {
    return stack.back();
  }

  int getMin() {
    return min;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
