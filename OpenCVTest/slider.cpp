#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(int argc, const char * argv[]) {
	Mat img, roi, tmp;

	//initialize cascade
	CascadeClassifier cascade;
	cascade.load("./data/haarcascades/haarcascade_frontalface_default.xml");
	vector<Rect> faces;

	//initialize webcam
	VideoCapture cam(0);
	if (!cam.isOpened()) {
		cout << "error" << endl;
		return -1;
	}


	while (true) {
		cam >> img;

		cascade.detectMultiScale(img, faces, 1.1, 3, 0, Size(100, 100));

		if (faces.size() > 0) {
			for (int i = 0; i<faces.size(); i++) {
				Rect f = faces[i];

				roi = img(Rect(f.x, f.y, f.width, f.height));

				resize(roi, tmp, Size(roi.cols / 20, roi.rows / 20));
				resize(tmp, roi, Size(roi.cols, roi.rows), 0, 0, INTER_NEAREST);
			}
		}

		imshow("Face", img);

		if (waitKey(1) == 'q') {
			cam.release();
			break;
		}
	}


	return 0;
}