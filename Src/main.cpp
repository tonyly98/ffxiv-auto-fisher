#include <iostream>
#include <opencv2/opencv.hpp>
#include <../Utilities/utilities.h>
#include <Windows.h>
int main(int, char**) {
    // String for program FINAL FANTASY XIV
    std::string rootDir = absPath();
    HWND hWND = FindWindow(NULL, "FINAL FANTASY XIV");
    while (!hWND) {
        std::system("cls");
        std::cout << "Launch FFXIV" << std::endl;
        Sleep(3500);
    }

    cv::Mat source, input, result;
    //IMREAD_GRAYSCALE OR CV_8UC4
    input = cv::imread(rootDir + "/Resources/caught.png");

	cv::cvtColor(input, input, cv::COLOR_BGRA2BGR);
    while (true)  {
        source = getMat(hWND);
        cv::imshow("View", tempMatching(source, input, 0.7, true));
        cv::waitKey(30);
    }
}
