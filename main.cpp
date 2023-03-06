#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;


float inches2mm(int inches)
{
    return float(inches*25.4);
}

float deg2rad(int deg)
{
    return deg*3.1416/180;
}

float mm2inches(int mm)
{
    return float(mm/25.4);
}

int main()
{
    // Initialize variables

    int radii = 18;
    int ratio = 50;
    int width = 225;
    float radio_rib = 5;

    float out_radio = inches2mm(radii)+width*ratio/100;

    vector<vector<float>> points;
    vector<float> single_point;

    int i = 0;

    // Generate points

    for(int deg=0; deg < 360; deg+=10)
    {
        points.push_back({float(radii)*sin(deg2rad(deg)), 0, float(radii)*cos(deg2rad(deg))});
        cout << points[i][0] << "," << points[i][1]<< ","  << points[i][2] << endl;
        i++;
    }

    for(int deg=0; deg < 360; deg+=10)
    {
        points.push_back({float(mm2inches(out_radio))*sin(deg2rad(deg)), 0, float(mm2inches(out_radio))*cos(deg2rad(deg))});
        cout << points[i][0] << "," << points[i][1]<< ","  << points[i][2] << endl;
        i++;
    }

    return 0;
}
