class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x, y;

        if (abs(x1-xCenter) < abs(x2-xCenter))
            x = x1;
        else
            x = x2;

        if (abs(y1-yCenter) < abs(y2-yCenter))
            y = y1;
        else
            y = y2;

        if (xCenter >= x1 && xCenter <= x2)
            x = xCenter;

        if (yCenter >= y1 && yCenter <= y2)
            y = yCenter;
        
        return hypot(x-xCenter, y-yCenter) <= radius;
    }
};
