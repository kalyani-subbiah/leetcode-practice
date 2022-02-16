/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/
#include <stack>
#include <iostream>
using namespace std; 

class MinStack {

public:
    stack<int> primary;
    stack<int> minStack;
    MinStack() {
        
    }
    void push(int x) {
      cout<<"Push " + to_string(x)<<endl;
      primary.push(x);
      if(minStack.empty() || x <= minStack.top())
        minStack.push(x);
      printStackTops(primary, minStack);
    };
    
    void pop() {
        cout<<"Pop"<<endl;
        cout << "Pop " + to_string(primary.top()) + " from primary"<<endl;
        if(!primary.empty() && !minStack.empty() && minStack.top() == primary.top())
          cout << "Pop " + to_string(minStack.top()) + " from minStack"<<endl;
          minStack.pop();
        primary.pop();
        printStackTops(primary, minStack);
    }
   
    int top() {
        return primary.top();
    }
    int getMin() {
        return minStack.top();
    }

    void printStackTops(stack<int> primary, stack<int> minStack) {
      cout<<"Primary " + to_string(primary.top())<<endl;
      cout<<"minStack " + to_string(minStack.top())<<endl;
    }
};

int main() {
  MinStack minstack;
  minstack.push(0);
  minstack.push(10);
  minstack.push(5);
  minstack.push(3);
  minstack.push(8);
  minstack.push(-50);
  minstack.pop();
  minstack.push(-100);
  minstack.push(20);
  minstack.pop();
};


