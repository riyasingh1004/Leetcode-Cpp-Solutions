// Time Complexity O(logn)

// Two heaps (or priority queues):
// 1.Max-heap small has the smaller half of the numbers.
// 2.Min-heap large has the larger half of the numbers.

// This gives me direct access to the one or two middle values (they're the tops of the heaps), 
// so getting the median takes O(1) time. And adding a number takes O(log n) time.
// eg. small (2,1) and large(3,4) and median = (2+3)/2

class MedianFinder {
public:
    
    priority_queue<long> small, large;

    
    void addNum(int num) {
        
         small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
        
    }
    
    double findMedian() {
        
        return small.size() > large.size()
               ? small.top()
               : (small.top() - large.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */