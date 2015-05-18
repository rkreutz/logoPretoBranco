/*******************************************************************************
Author: Rodrigo Kreutz
Date:
Project:
Description:
********************************************************************************/

#include "stdafx.h"

//General Libraries
/*******************************************************************************/
#include <iostream>
/*******************************************************************************/

//OpenCV Libraries
/*******************************************************************************/
#include "opencv2/core/core.hpp"
#include "opencv2/flann/miniflann.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/photo/photo.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/ml/ml.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/core/core_c.h"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/imgproc/imgproc_c.h"
/*******************************************************************************/

//Constants
/*******************************************************************************/

/*******************************************************************************/

//Error Constants
/*******************************************************************************/

/*******************************************************************************/



//Global Variables
/*******************************************************************************/

/*******************************************************************************/


using namespace std;
using namespace cv;

int _tmain (int argc, char **argv) {
	Mat img = imread("7mg182.jpg",CV_LOAD_IMAGE_UNCHANGED),black;
	//int t = 50;
	////resize(img,img,Size(),0.5,0.5);
	//namedWindow("Imagem");
	//createTrackbar("Dif", "Imagem",&t,255);
	//while (waitKey(30) != ' ') {
	//	cvtColor(img,black,CV_BGR2GRAY);
	//	uchar* P;
	//	for (int y = 0; y < black.rows; y++) {
	//		for (int x = 0; x < black.cols; x++){
	//			P = black.ptr<uchar>(y,x);
	//			if(*P <= 255 - t)
	//				*P = 250;
	//			else
	//				*P = (255-*P)*250/t;
	//		}
	//	}
	//	imshow("Imagem",black);
	//}
	//imwrite("FK-branco-no-preto.jpg",black);
	Mat tmp1, tmp2;


	
	GaussianBlur(img, tmp1, cv::Size(3, 3), 1, 2);
	GaussianBlur(img, tmp2, cv::Size(1, 1), 1, 2);
	subtract(tmp1, tmp2, img);
	cvtColor(img, img, CV_BGR2GRAY);
	threshold(img, img, 2, 255, CV_THRESH_BINARY);
	medianBlur(img, img, 3);

	imshow("Imagem", img);

	waitKey();

	return 0;
}