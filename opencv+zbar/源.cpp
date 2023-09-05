#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
int main()
{
	Mat img = imread("miao.jpg");
	namedWindow("美女图片");
	imshow("美女图片",img);
	waitKey(6000);
	return 0;
}