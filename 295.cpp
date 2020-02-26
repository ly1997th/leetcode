//295. Find Median from Data Stream

class MedianFinder {
private:
    priority_queue<int> first;
    priority_queue<int,vector<int>,greater<int>> second;
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) 
    {
        if(first.empty()||num<=first.top())
            first.push(num);
        else
            second.push(num);

        if(first.size()>second.size()+1)
        {
            second.push(first.top());
            first.pop();
        }
        if(second.size()>first.size())
        {
            first.push(second.top());
            second.pop();
        }
    }
    
    double findMedian() 
    {
        if(first.size()==second.size())
            return (first.top()+second.top())/2.0;
        else
            return first.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */