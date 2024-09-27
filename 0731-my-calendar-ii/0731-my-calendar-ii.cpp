class MyCalendarTwo {
public:

    vector<pair<int, int>> doubleBookings;
    vector<pair<int, int>> bookings;
    
    bool checkOverlap(int start1, int end1, int start2, int end2){
        return max(start1, start2) < min(end1, end2);
    }

    pair<int, int> findOverlappedRegion(int start1, int end1, int start2, int end2){
        return {max(start1, start2), min(end1, end2)};
    }

    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        
        // check for triple bookings
        for(auto region : doubleBookings){
            if(checkOverlap(region.first, region.second, start, end)){
                return false;
            }
        }

        // check for double bookings
        for(auto booking : bookings){
            if(checkOverlap(booking.first, booking.second, start, end)){
                doubleBookings.push_back(findOverlappedRegion(booking.first, booking.second, start, end)); 
            }
        }

        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */