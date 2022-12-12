class MedianFinder {
public:
    priority_queue<int> p;
    priority_queue<int, vector<int>, greater<int>> q;
    MedianFinder() {
       
    }
    
    void addNum(int num) {
        if(p.size() == 0)
            p.push(num);

        else if( p.top() >= num){
            p.push(num);
            if(p.size() - q.size() > 1){
                q.push(p.top());
                p.pop();
            }
        }
        else if (p.top() < num){
            q.push(num);
            if(q.size() - p.size() > 1){
                p.push(q.top());
                q.pop();
            }
        }
    }
    
    double findMedian() {
        if(p.size() == q.size()){
            return (double)(p.top() + q.top()) /2.0;
        }
        else if(p.size() > q.size()){
            return p.top();
        }
        else{
            return q.top();
        }
        }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */