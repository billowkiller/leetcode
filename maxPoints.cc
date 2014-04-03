/*
 * =====================================================================================
 *
 *       Filename:  maxPoints.cc
 *
 *    Description:  
 *    Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 *
 *        Version:  1.0
 *        Created:  04/01/2014 05:15:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  billowkiller (), billowkiller@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <float.h>

using namespace std;
/**
 * Definition for a point.
 */

 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(0==points.size())
            return 0;
        int max = 0;
        map<float, int> table;
        for (int i=0; i<points.size();i++)
        {
            int samep = 0;
            int maxp = 0;
            for (int j=0; j<points.size();j++)
            {
               if(i!=j)
               {
                   if(points[j].x==points[i].x && points[j].y==points[i].y)
                   { 
                       samep++;
                       continue;
                   }

                   float a = points[j].x==points[i].x?FLT_MAX:
                       (float)(points[j].y-points[i].y)/(points[j].x-points[i].x);

                   table[a]++; 
                   maxp = maxp > table[a]? maxp : table[a];
               }
            }
            maxp += samep;
            max = max > maxp? max : maxp;
           table.clear(); 
        }
        return max+1;
    }
};

int main()
{
    Solution sol;
    vector<Point> points;
    cout << (0==sol.maxPoints(points)) <<endl;
    points.push_back(Point(1,1));
    points.push_back(Point(2,2));
    points.push_back(Point(2,2));
    points.push_back(Point(1,1));

    cout << sol.maxPoints(points) <<endl;

}
