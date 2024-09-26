class MyCalendar {
public:

    vector<pair<int, int>> result; // store bookings
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        for(auto pair : result){
            int a = pair.first; 
            int b = pair.second;

            if(a < end && start < b){ // overlapping condition
                return false; 
            }
        } 

        result.push_back({start, end}); // add new booking
        return true; 
    } 
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
