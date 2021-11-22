//============================================================================
// Name        : 3dot.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

///////client data///////

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

int main()
{
    int CreateSocket = 0,n = 0;
    char dataReceived[1024];
    struct sockaddr_in ipOfServer;

    memset(dataReceived, '0' ,sizeof(dataReceived));

    if((CreateSocket = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
        printf("Socket not created \n");
        return 1;
    }

    ipOfServer.sin_family = AF_INET;
    ipOfServer.sin_port = htons(2017);
    ipOfServer.sin_addr.s_addr = inet_addr("127.0.0.1");
 cout<<"For testing"<<endl;
    if(connect(CreateSocket, (struct sockaddr *)&ipOfServer, sizeof(ipOfServer))<0)
    {
        printf("Connection failed due to port and ip problems\n");
        return 1;
    }
    n = read(CreateSocket, dataReceived, sizeof(dataReceived)-1);
//    while((n = read(CreateSocket, dataReceived, sizeof(dataReceived)-1)) > 0) // one time o/p
    while(n > 0) //continue o/p
    {
        dataReceived[n] = 0;
        if(fputs(dataReceived, stdout) == EOF)
        {
            printf("\nStandard output error");
        }
        printf("\n");
    }

    if( n < 0)
    {
        printf("Standard input error \n");
    }
    return 0;
}
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include<iostream>
//#include<algorithm>
//#include<math.h>
//#define PI 3.141
//using namespace cv;
//using namespace std;
//struct myclass {
//   bool operator() (Point pt1, Point pt2)
//    {
//    	return (pt1.y < pt2.y);
//    }
//} myobject;
//
//int main(int argc, char** argv)
// {
//     Mat img;
//   Mat Channels[3];
//  img= imread("/home/yoga/Pictures/task1.jpg");//task1.jpg,task2.jpg,task3.jpg,task4.jpg
//    split(img,Channels);
//  Mat gray;
//  cvtColor(img, gray, COLOR_BGR2GRAY);
//Mat binImg,bin;
//adaptiveThreshold(Channels[1], binImg, 255, CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY_INV, 13, 32);
//Mat edges,dst;
//int morph_size = 0;
//   Mat element = getStructuringElement(2, Size(1 * morph_size + 1,1 * morph_size + 1),Point(morph_size, morph_size));
//   Mat dill,dill1,edge,edge1;
// dilate( Channels[1], dill, element,Point(-1, -1), 1);
// erode(dill, dill1, element,Point(-1, -1), 1);
// Canny(dill1, edge,650, 800);
// imshow("centerimg",edge);
//vector<vector<Point> > contours;
//  vector<Vec4i> hierarchy;
//  findContours(edge, contours, hierarchy,CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE );
//  double Area;
//  vector<Vec3f> centerimg;
//  vector<int>circles;
//  vector<Moments> mu(contours.size() );
//  vector<Point2f> mc( contours.size() );
//  vector<Point> Pxy;
// for(size_t i = 0; i< contours.size(); i++)
// {
//	  Area = contourArea(contours[i],false);
//	  mu[i] = moments( contours[i], false );
//	  mc[i] = Point2f( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 );
//	  double arclength = arcLength(contours[i], true);
//      double circularity = 4 * CV_PI * Area / (arclength * arclength);
// if(circularity > 0.85 && Area > 3)
//   {
//	 circles.push_back(Area);
//	 Pxy.push_back(mc[i]);
// }
//}
////Pxy size()----
//cout<<"Pxy = "<<Pxy.size()<<endl;
//sort(Pxy.begin(),Pxy.end(),myobject);
//Point startxy = Pxy.front();
//   cout<<"start = "<<startxy<<endl;
//Point endxy = Pxy.back();
//    cout<<"end = "<<endxy<<endl;
// if(Pxy.size() <= 3)
//    {
//line(img,startxy,endxy,Scalar(0,0,0),2,8);
//    cout<<"Point = "<<Pxy<<endl;
//    int xc = (startxy.x + endxy.x)/2;
//    int yc = (startxy.y + endxy.y)/2;
//cout<<"c1 = "<<xc<<" , c2 = "<<yc<<endl;
//
//  cout<<"c1 = "<<xc<<" , c2 = "<<yc<<endl;
//circle(img,Point(xc,yc),5,Scalar(0,255,0),3,8);
//line(img,Pxy[1],Point(xc,yc),Scalar(0,0,0),2,8);
//int xd = xc - Pxy[1].x ;
//int yd = yc - Pxy[1].y ;
//cout<<"(xd = "<<xd<<",yd = "<<yd<<")"<<endl;
//
//stringstream s3;
//s3<<xd;
//string s4;
//s3>>s4;
//stringstream s5;
//s5<<yd;
//string s6;
//s5>>s6;
//string str = "Offset of(X :" + s4 + ",Y:"+ s6 + ")";
//cout << str;
//putText(img,str,Point(xc,yc),16,1,Scalar(0,0,0),2,false);
//imshow("RESULT Image", img);
// waitKey();
//    }
// putText(img,"Pxy value is more than 3",Point(100,100),16,1,Scalar(0,0,0),2,false);
// imshow("failed Image", img);
//  waitKey();
// return 0;
//}
//
//
//
//
//
////vector<vector<Point> > contours; // Vector for storing contour
//////	    vector<Vec4i> hierarchy;
//////	    findContours(redOnly, contours, hierarchy,CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE );
//////	    // iterate through each contour.
//////	    vector<int> v;
//////	    for( int i = 0; i< contours.size(); i++)
//////	    {threshold(edge, edge1,300, 800,THRESH_BINARY); //Threshold the gray
//////	        //  Find the area of contour
//////	       a =contourArea( contours[i],false);
//////	      double arclength = arcLength(contours[i], true);
//////	      double circularity = 4 * CV_PI * a / (arclength * arclength);
//////    if((a < smaller_area) && (circularity > 0.86))
//////	    {
//////	 smaller_area = a;
//////	 v.push_back(a);
//////	 largest_contour_index= i;
//
////    }else
////line(img,startxy,Pxy[2],Scalar(0,0,0),2,8);
////     cout<<"Point = "<<Pxy<<endl;
////  xc = (startxy.x + Pxy[2].x)/2;
////  yc = (startxy.y + Pxy[2].y)/2;
//
//
////// HoughCircles(edge, centerimg, CV_HOUGH_GRADIENT,2,edge.rows/5,30,10, 1, 30);//task2
//// HoughCircles(edge, centerimg, CV_HOUGH_GRADIENT,1,edge.rows/16,30,10, 1, 30);//task1,3,
////// HoughCircles(edge, centerimg, CV_HOUGH_GRADIENT,1,edge.rows/32,30,8, 1, 30);//task4
////// HoughCircles(edge, centerimg, CV_HOUGH_GRADIENT,1,edge.rows/16,10,8, 1, 30);//task12
