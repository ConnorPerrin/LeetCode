#include <iostream>
#include <stack>

class MinStack_v1 {
public:
    MinStack_v1() {
        
    }
    
    void push(int val) {
        if(m_minStack.empty()) 
            m_minStack.push({val, val});
        else{
            m_minStack.push({val, std::min(val, m_minStack.top().second)});
        }
    }
    
    void pop() {
        m_minStack.pop();
    }
    
    int top() {
        return m_minStack.top().first;
    }
    
    int getMin() {
        return m_minStack.top().second;
    }

private:
    std::stack<std::pair<int, int>> m_minStack;
};

class MinStack_v2 {
public:
    MinStack_v2() { }

    void push(int val) {
        topStack.push(val);
        
        if((minStack.empty()) || (val <= minStack.top()))
            minStack.push(val);
    }
    
    void pop() {
        if(topStack.top() == minStack.top())
           minStack.pop();
        topStack.pop();
    }
    
    int top() {
       return topStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }

private:
    std::stack<int> topStack;
    std::stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
    std::cout << "LeetCode Problem 155 - Min Stack" << std::endl;
    
    MinStack_v2 ms = MinStack_v2();

    ms.push(1);
    ms.push(2);
    ms.push(-1);
    std::cout << "Top: " << ms.top() << " || Min: " << ms.getMin() << std::endl;


    return 0;
}