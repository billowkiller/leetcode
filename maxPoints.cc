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
        int max = 0;
        for (int i=0; i<points.size();i++)
        {
            for (int j=0; j<points.size();j++)
            {
               if() 
            }
        }
    }
};

int main()
{
    vector<Point> points;
    points.push_back(Point(1,0));
    points.push_back(Point(2,0));
    points.push_back(Point(3,0));
    points.push_back(Point(1,1));
    points.push_back(Point(1,1));
    points.push_back(Point(2,1));

    Solution sol;
    cout << sol.maxPoints(points) <<endl;
}
