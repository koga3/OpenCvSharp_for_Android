#include <jni.h>
#include <string>

#include <opencv2/opencv.hpp>

#define CV_EXTERN_C extern "C"

#ifndef CVAPI
#  define CVAPI(rettype) CV_EXTERN_C rettype
#endif

CVAPI(int) Sample( int n )
{
    return n * 2;
}


//CVAPI(cv::Mat*) imgproc_getGaussianKernel(int ksize, double sigma, int ktype)
//{
//    cv::Mat ret = cv::getGaussianKernel(ksize, sigma, ktype);
//    return new cv::Mat(ret);
//}
//
//CVAPI(void) imgproc_getDerivKernels(cv::_OutputArray *kx, cv::_OutputArray *ky,
//int dx, int dy, int ksize, int normalize, int ktype)
//{
//cv::getDerivKernels(*kx, *ky, dx, dy, ksize, normalize != 0, ktype);
//}

//CVAPI(cv::Mat*) imgproc_getGaborKernel(MyCvSize ksize, double sigma, double theta,
//double lambd, double gamma, double psi, int ktype)
//{
//cv::Mat ret = cv::getGaborKernel(cpp(ksize), sigma, theta, lambd, gamma, psi, ktype);
//return new cv::Mat(ret);
//}