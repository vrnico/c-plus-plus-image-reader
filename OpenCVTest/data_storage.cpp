#include "opencv2/opencv.hpp"
using namespace cv;

int file_storage(int, char** argv)
{
	FileStorage fs("nico_test.yml", FileStorage::WRITE);
	int fps = 5;
	fs << "fps" << fps;
	Mat m1 = Mat::eye(2, 3, CV_32F);
	Mat m2 = Mat::ones(3, 2, CV_32F);
	Mat result = (m1 + 1).mul(m1 + 3);
	fs << "Result" << result;
	fs.release();

	FileStorage fs2("nico_test.yml", FileStorage::READ);

	Mat r;
	fs2["Result"] >> r;
	std::cout << r << std::endl;

	fs2.release();

	return 0;
}
