#include <iostream>
#include <opencv2/opencv.hpp>
#include <Windows.h>
std::string absPath();

cv::Mat getMat(HWND hWND);

cv::Mat tempMatching(cv::Mat source, cv::Mat input, double threshHold, boolean square);

cv::Mat TplMatch( cv::Mat &img, cv::Mat &mytemplate );

cv::Mat templTresh(cv::Mat src, cv::Mat dst, double min, double max, int type);