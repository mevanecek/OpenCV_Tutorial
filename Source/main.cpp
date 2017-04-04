///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _WIN64
#pragma clang diagnostic ignored "-Wdocumentation"
#endif

#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, const char** argv) {

    vector<int> params = {CV_IMWRITE_JPEG_QUALITY, 100};

#ifdef _WIN64
//    string imageFile("C:\\Personal\\03196514\\Documents\\GitHub\\OpenCV-Tutorial\\20160530_guitar_0018.jpg");
//    string outFile("C:\\Personal\\03196514\\Documents\\GitHub\\OpenCV-Tutorial\\20160530_guitar_0018-new.jpg");
	string imageFile("..\\20160530_guitar_0018.jpg");
	string outFile("..\\20160530_guitar_0018-new.jpg");

#else
    string imageFile("/Users/mattvanecek/Development/opencv/OpenCV_Tutorial/20160530_guitar_0018.jpg");
    string outFile("/Users/mattvanecek/Development/opencv/OpenCV_Tutorial/20160530_guitar_0018-new.jpg");
#endif

    Mat img = imread(imageFile.c_str(), CV_LOAD_IMAGE_UNCHANGED);

	if (img.empty()) { //check whether the image is loaded or not
		cout << "Error : Image cannot be loaded..!! " << imageFile << endl;
		// system("pause"); //wait for a key press
		cin.get();
		return -1;
	}

	namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
	imshow("MyWindow", img); //display the image which is stored in the 'img' in the "MyWindow" window

	waitKey(10000); //wait infinite time for a keypress
    imwrite(outFile.c_str(), img, params);

	destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
