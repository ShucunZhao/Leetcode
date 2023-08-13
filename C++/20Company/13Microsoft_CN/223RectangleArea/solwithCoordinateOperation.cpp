class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int totalArea = (abs(ax1-ax2)*abs(ay1-ay2)+abs(bx1-bx2)*abs(by1-by2));
        cout<<totalArea<<endl;
        int innerX1 = max(ax1,bx1);
        int innerX2 = min(ax2,bx2);
        int innerY1 = max(ay1, by1);
        int innerY2 = min(ay2, by2);
        // cout<<"X1:"<<innerX1<<",Y1:"<<innerY1<<endl;
        // cout<<"X2:"<<innerX2<<",Y2:"<<innerY2<<endl;
        // int maxX = max(ax2, bx2);
        // int minX = min(ax1, bx1);
        // int maxY = max(ay2, by2);
        // int minY = min(ay1, by1);
        // if(innerX1>=maxX||innerX2<=minX||innerY1>=maxY||innerY2<=minY){
        //     return totalArea;
        // }
        if(ax1>=bx2||ax2<=bx1||ay1>=by2||ay2<=by1){
            return totalArea;
        }
        return totalArea - abs(innerX1-innerX2)*abs(innerY1-innerY2);
    }
};