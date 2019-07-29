#pragma once

#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace System::Runtime::InteropServices;

namespace defCamera
{
	class Camera
	{
	
	public:
		Camera();
		System::Drawing::Bitmap^ Show(Mat& colorImage);

		
		
	};
}