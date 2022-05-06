class MyStack {
public:
    int index;
    int arr[100];
    MyStack() {
        index = -1;
    }
    
    void push(int x) {
        index++;
        arr[index] = x;
    }
    
    int pop() {
        index--;
        return arr[index+1];
    }
    
    int top() {
        return arr[index];
    }
    
    bool empty() {
        return index==-1;
    }
};