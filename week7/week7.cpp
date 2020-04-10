// week7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = imread("C:\\Users\\27318\\Desktop\\大二下网络课程\\数字图像\\第七周\\metal-part-distorted-03.png", 1);
	cv::Mat dstMat;
	std::vector<cv::Vec4i> lines;
	int threshold = 50;

	Canny(srcMat, dstMat, threshold, threshold * 3);

	HoughLinesP(dstMat, lines, 1, CV_PI / 180, 50, 0, 20);

	for (int i = 0; i < lines.size(); i++) {
		line(srcMat, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]), Scalar(0, 0, 255), 1, CV_AA);
	}

	cv::imshow("srcMat", srcMat);
	cv::imshow("dstMat", dstMat);
	waitKey(0);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
