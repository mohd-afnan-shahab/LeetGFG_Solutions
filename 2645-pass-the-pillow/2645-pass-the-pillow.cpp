class Solution {
public:
    int passThePillow(int n, int time) {
        
        // int i = 1;
        // int dir = 1;            // moving left to right
        // while(time > 0){
        //     if(i + dir >= 1 && i + dir <= n){
        //         i = i + dir;        // Move to the next position
        //         time--;
        //     }
        //     else {
        //         dir = dir * -1;     // Change direction
        //     }
        // }
        // return i;

        int fullround = time/(n-1);
        int timeleft = time % (n-1);    

        if(fullround % 2 == 0){
            return timeleft + 1;      //ill be standing at 1..
        }
        else
            return n - timeleft;       //ill be standing at n.. 
    }
};