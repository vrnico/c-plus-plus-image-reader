#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;
using namespace cv;

const char* keys =
{
	"{help h usage ? | | print this message}"
	"{@video | | Video file, if not defined try to use webcamera}"
};

int camera(int argc, const char** argv)
{
	CommandLineParser parser(argc, argv, keys);
	parser.about("Nico's Camera v 0.9");

	if (parser.has("help"))
	{
		parser.printMessage();
		return 0;
	}

	String videoFile = parser.get<String>(0);


	if (!parser.check())
	{
		parser.printErrors();
		return 0;
	}

	VideoCapture cap;
	if (videoFile != "")
		cap.open(videoFile);
	else
		cap.open(0);
	if (!cap.isOpened())
		return -1;

	namedWindow("Video", 1);
	for (;;)
	{
		Mat frame;
		cap >> frame;
		imshow("Video", frame);
		if (waitKey(30) >= 0) break;
	}

	cap.release();

	return 0;
}