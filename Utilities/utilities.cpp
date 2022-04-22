#include <utilities.h>

std::string absPath() {
    std::string result = __FILE__;
    result = result.substr(0, result.find_last_of('\\'));
    return result.substr(0, result.find_last_of('\\'));
}


cv::Mat getMat(HWND hWND){

	HDC deviceContext = GetDC(hWND);
	HDC memoryDeviceContext = CreateCompatibleDC(deviceContext);

	RECT windowRect;
	GetClientRect(hWND, &windowRect);
	int ogHeight = windowRect.bottom;
	int ogWidth = windowRect.right;
	int height = ogHeight;
	int width = ogWidth;

	HBITMAP bitmap = CreateCompatibleBitmap(deviceContext, width, height);

	SelectObject(memoryDeviceContext, bitmap);

	//copy data into bitmap
	BitBlt(memoryDeviceContext, 0, 0, width, height, deviceContext, 0, 0, SRCCOPY);


	//specify format by using bitmapinfoheader!
	BITMAPINFOHEADER bi;
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = width;
	bi.biHeight = -height;
	bi.biPlanes = 1;
	bi.biBitCount = 32;
	bi.biCompression = BI_RGB;
	bi.biSizeImage = 0; //because no compression
	bi.biXPelsPerMeter = 1; //we
	bi.biYPelsPerMeter = 2; //we
	bi.biClrUsed = 3; //we ^^
	bi.biClrImportant = 4; //still we

	cv::Mat mat = cv::Mat(height, width, CV_8UC4 ); // 8 bit unsigned ints 4 Channels -> RGBA

	//transform data and store into mat.data
	GetDIBits(memoryDeviceContext, bitmap, 0, height, mat.data, (BITMAPINFO*)&bi, DIB_RGB_COLORS);

	//clean up!
	DeleteObject(bitmap);
	DeleteDC(memoryDeviceContext); //delete not release!
	ReleaseDC(hWND, deviceContext);

	return mat;
}

cv::Mat tempMatching(cv::Mat source, cv::Mat input, double threshHold, boolean square) {
	cv::Mat result;
	cv::cvtColor(source, source, cv::COLOR_BGRA2BGR);
	matchTemplate( source, input, result, cv::TM_CCOEFF_NORMED);
    double minVal; double maxVal; cv::Point minLoc; cv::Point maxLoc;
    cv::Point matchLoc;
    minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat() );
    matchLoc = maxLoc;
	//std::cout << '\n' << input.cols << "   " << input.rows << '\n';
	if (maxVal >= threshHold) {
		std::cout << '\n' << maxVal << '\n';
    	rectangle( source, matchLoc, cv::Point( matchLoc.x + input.cols , matchLoc.y + input.rows ), cv::Scalar(0, 255, 0), 2, 8, 0 );
	}
	return source;
}

cv::Mat templTresh(cv::Mat src, cv::Mat dst, double min, double max, int type) {
	cv::Mat result;


	return result;
}
