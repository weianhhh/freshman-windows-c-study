#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
int main()
{
	Mat img = imread("miao.jpg");
	namedWindow("��ŮͼƬ");
	imshow("��ŮͼƬ",img);
	waitKey(6000);
	return 0;
}