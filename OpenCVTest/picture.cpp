#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int picture()
{
	Mat img = imread("peace.jpg");
	Mat photo = imread("photo.jpg");
	namedWindow("image", WINDOW_NORMAL);
	imshow("image", img);
	namedWindow("photo", WINDOW_NORMAL);
	imshow("photo", photo);
	waitKey(0);
	return 0;
}