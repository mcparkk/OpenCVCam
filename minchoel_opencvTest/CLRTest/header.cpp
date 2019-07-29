#include <iostream>
#include <opencv2\opencv.hpp>
#include "header.h"

using namespace cv;
using namespace std;
using namespace defCamera;

String face_cascade_name;
CascadeClassifier face_cascade;



Camera::Camera()
{
}


System::Drawing::Bitmap^ Camera::Show(cv::Mat& colorImage) {
	
	face_cascade_name = "C:\\opencv\\opencv-4.1.0\\data\\haarcascades\\haarcascade_frontalface_alt.xml";
	if (!face_cascade.load(face_cascade_name)) { printf("--(!)Error loading face cascade\n");  };

	std::vector<Rect> faces;
	Mat frame_gray;

	cvtColor(colorImage, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	
	face_cascade.detectMultiScale(colorImage, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(3, 3));


	for (size_t i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
		ellipse(colorImage, center, Size(faces[i].width / 2, faces[i].height / 2),
			0, 0, 360, Scalar(0, 0, 255), 4, 8, 0);
	}



	System::IntPtr ptr(colorImage.ptr());
	System::Drawing::Bitmap^ image;


	switch (colorImage.type())
	{
	case CV_8UC3:
		image = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
		break;
	case CV_8UC1:
		image = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
			System::Drawing::Imaging::PixelFormat::Format8bppIndexed, ptr);
		break;
	default:
		break;
	}

	return image;
}