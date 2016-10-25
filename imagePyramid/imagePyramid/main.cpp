//
//  main.cpp
//  imagePyramid
//
//  Created by ZHHJemotion on 2016/10/22.
//  Copyright © 2016年 Lukas_Zhang. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#define PATH string("/Users/zhangxingjian/Desktop/Programming/C++/OpenCV/opencv_imagePyramid/imagePyramid/imagePyramid/")
#define WINDOW_NAME "程序窗口"


// ----------------------- the global varibales declaration section --------------------
//    Describe: the global variables
// ---------------------------------------------------------------------------------------
Mat srcImage, dstImage, tmpImage;


// ----------------------- the global function declaration section --------------------------
//    Describe: the global function
// -------------------------------------------------------------------------------------
static void showHelpText();


// -----------------------showHelpText() function ------------------------------

static void showHelpText()
{
    //输出一些帮助信息
    printf("\n\n\n\t欢迎来到OpenCV图像金字塔和resize示例程序~\n\n");
    printf( "\n\n\t按键操作说明: \n\n"
           "\t\t键盘按键【ESC】或者【Q】- 退出程序\n"
           "\t\t键盘按键【1】- 进行基于【pyrUp】函数的图片放大\n"
           "\t\t键盘按键【2】- 进行基于【resize】函数的图片放大\n"
           "\t\t键盘按键【3】- 进行基于【pyrDown】函数的图片缩小\n"
           "\t\t键盘按键【4】- 进行基于【resize】函数的图片缩小\n"
           "\n\n\t\t\t\t\t\t\t\t byZHHJemotion \n\n\n"
           );
}

// --------------------------- main() function ----------------------------------

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    showHelpText();
    
    // read the image
    srcImage = imread(PATH+string("1.jpg"),1);
    
    // exception handlung
    if (!srcImage.data) {
        printf("error, we can't read the image 1.jpg!!!\n");
        return false;
    }
    
    // create a window to show the image
    namedWindow(WINDOW_NAME,WINDOW_AUTOSIZE);
    imshow(WINDOW_NAME, srcImage);
    
    // 参数赋值
    tmpImage = srcImage;
    dstImage = tmpImage;
    
    int key = 0;
    
    // by polling to get the information of the keying 轮询获得按键信息
    while (1)
    {
        key = waitKey(1); // 读取按键值到 key 变量中
        
        // operate different depend on the key 根据 key 变量进行不同的操作
        switch (key)
        {
            // ================== 程序退出处理 ======================
            case 27: // ESC 按键 ASCII 码为27
                return 0;
                break;
                
            case 'q': // 按键'q'
                return 0;
                break;
            
            // =================== 图片放大处理 enlargement ======================
            case '1': // 按键‘1’调用 pyrUp 函数
                //pyrUp(tmpImage, dstImage, Size(tmpImage.cols*2, tmpImage.rows*2));
                pyrUp(tmpImage, dstImage); // 默认状态下 (tmpImage.cols*2)
                printf("-> based on the function pyrUp to enlarge the image x2 \n");
                break;
            
            case '2': // 按键‘2’调用 resize 函数
                resize(tmpImage, dstImage, Size(tmpImage.cols*2, tmpImage.rows*2), INTER_LINEAR); // INTER_LINEAR 线性插值
                printf("-> based on the function resize to enlarge the image x2 \n");
                break;
                
            // =================== 图片缩小处理 reducement ======================
            case '3': // 按键‘3’调用 pyrDown 函数
                //pyrDown(tmpImage, dstImage, Size(tmpImage.cols/2, tmpImage.rows/2));
                pyrDown(tmpImage, dstImage); // 默认状态下 (tmpImage.cols+1)/2
                printf("-> based on the function pyrDown to reduce the image /2 \n");
                break;
                
            case '4': // 按键‘4’调用 resize 函数
                resize(tmpImage, dstImage, Size(tmpImage.cols/2, tmpImage.rows/2), INTER_AREA); // INTER_AREA 区域插值
                printf("-> based on the function resize to resuce the image /2 \n");
                break;
        }
        
        // show the changed image
        imshow(WINDOW_NAME, dstImage);
        
        // 将 dstImage 赋值给 tmpImage，方便下一次循环
        tmpImage = dstImage;
        
    }
    
    
    
    return 0;
}
