/*
 * 만든이 : 남지원
 * 날짜   : 2021.09.13
 * 내용   : 크래비스 이미지를 받아서 OpenCV로 cvtColor, Flip하고 user메모리에 할당한 뒤 출력하는 예제
*/

#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <windows.h>
#include "VirtualFG40.h"
#pragma comment (lib, "VirtualFG40.lib")

#include <opencv2/opencv.hpp>
//#include "CvsOpenCV.h"

void SetFeature(int hDevice)
{
	__int32 status = MCAM_ERR_SUCCESS;

	// Set Trigger Mode : OFF -> Continuous
	status = ST_SetEnumReg(hDevice, MCAM_TRIGGER_MODE, TRIGGER_MODE_OFF);
	if (status != MCAM_ERR_SUCCESS)
	{
		printf("Write Register failed : %d\n", status);
	}

	// Continuous모드를 사용하기 위한 세팅
	status = ST_SetContinuousGrabbing(hDevice, MCAMU_CONTINUOUS_GRABBING_ENABLE);
	if (status != MCAM_ERR_SUCCESS)
	{
		printf("Write Register failed : %d\n", status);
	}

	// Set PixelFormat : BayerRG8
	status = ST_SetEnumReg(hDevice, MCAM_PIXEL_FORMAT, PIXEL_FORMAT_BAYERRG8);
	if (status != MCAM_ERR_SUCCESS)
	{
		printf("Write Register failed : %d\n", status);
	}

	// Set GrabTimeout to 5 sec
	status = ST_SetGrabTimeout(hDevice, 5000);
	if (status != MCAM_ERR_SUCCESS)
	{
		printf("Write Register failed : %d\n", status);
	}

	// FilterDriver : Must be "OFF" when debugging. Otherwise, the BSOD may occur.
	status = ST_SetEnumReg(hDevice, MCAM_DEVICE_FILTER_DRIVER_MODE, DEVICE_FILTER_DRIVER_MODE_OFF);
	if (status != MCAM_ERR_SUCCESS)
	{
		printf("Write Register failed : %d\n", status);
	}

	//Heartbeat Disable : Must be "true" when debugging. Otherwise, the device will be disconnected.
	status = ST_SetBoolReg(hDevice, GEV_GVCP_HEARTBEAT_DISABLE, false);
	if (status != MCAM_ERR_SUCCESS)
	{
		printf("Write Register failed : %d\n", status);
	}
}

/// <summary>
/// MAT이미지를 크래비스 이미지로 변환
/// </summary>
/// <param name="src">Mat 이미지</param>
/// <param name="pCvtImage">크래비스 이미지 포인터</param>
void MatToCvsImage(const cv::Mat src, uchar* pCvtImage)
{
	int i, src_idx, dst_idx, buf_len=src.cols * 3;
	uchar* pDst = (uchar*)pCvtImage;
	src_idx = 0;
	dst_idx = 0;
	for (i = 0; i < src.rows; i++)
	{
		memcpy(&pDst[dst_idx], &src.data[src_idx], buf_len);
		src_idx += (int)src.step;
		dst_idx += 3;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	__int32 status = MCAM_ERR_SUCCESS;
	__int32 hDevice;
	unsigned __int32 CamNum;
	__int32 width = 0, height = 0, buffferSize = 0;
	unsigned char* pImage = NULL;
	unsigned char* pCvtImage = NULL;

	// system open
	ST_InitSystem();

	// Update Device List
	status = ST_UpdateDevice();
	if (status != MCAM_ERR_SUCCESS)
	{
		printf("Update device list failed : %d\n", status);
		ST_FreeSystem();
		return 0;
	}

	ST_GetAvailableCameraNum(&CamNum);
	if (CamNum <= 0)
	{
		printf("No device!\n");
		ST_FreeSystem();
		return 0;
	}

	// camera open
	status = ST_OpenDevice(0, &hDevice);
	if (status != MCAM_ERR_SUCCESS)
	{
		printf("Open device failed : %d\n", status);
		ST_FreeSystem();
		return 0;
	}

	SetFeature(hDevice);

	try
	{
		//Get Width
		status = ST_GetIntReg(hDevice, MCAM_WIDTH, &width);
		if (status != MCAM_ERR_SUCCESS)
		{
			printf("Read Register failed : ");
			throw status;
		}

		//Get Height
		status = ST_GetIntReg(hDevice, MCAM_HEIGHT, &height);
		if (status != MCAM_ERR_SUCCESS)
		{
			printf("Read Register failed : ");
			throw status;
		}

		try
		{
			// Image Buffer Allocatation
			buffferSize = width * height;
			pImage = (unsigned char*)malloc(buffferSize);
			if (pImage == 0)
			{
				throw "메모리 할당 에러";
			}
			memset((void*)pImage, 0, buffferSize);

			// Convert Image Buffer Allocation
			pCvtImage = (unsigned char*)malloc(buffferSize * 3);
			if (pCvtImage == 0)
			{
				throw "메모리 할당 에러";
			}
			memset((void*)pCvtImage, 0, buffferSize * 3);

		}
		catch (const char Except)
		{
			printf("에러 : %c", Except);
		}
		printf("Software trigger mode\n");
		printf("-----------------------------\n\n");
		printf("Press <Enter> to start.\n");
		_getch();

		// Acquistion Start
		status = ST_AcqStart(hDevice);
		if (status != MCAM_ERR_SUCCESS)
		{
			printf("Acquisition start failed : ");
			throw status;
		}

		ST_GrabStartAsync(hDevice, -1);

		while (1)
		{
			//Grab Image
			status = ST_GrabImageAsync(hDevice, pImage, buffferSize, -1);
			if (status == MCAM_ERR_TIMEOUT)
			{
				printf("GrabImage timeout : %d\n", status);
				if (_kbhit())
				{
					break;
				}
				continue;
			}
			else if (status != MCAM_ERR_SUCCESS)
			{
				printf("GrabImage failed : ");
				throw status;
			}
			//-----------------------------------
			// OpenCV 구간
			//

			cv::Mat cv_img, color_img, flip_img;
			
			// 크래비스 이미지 -> OpenCV::Mat
			cv_img = cv::Mat(height,				// row : 열의 수(height)
							 width,				// col : 행의 수(width)
							 CV_8UC1,			// type : 이미지 타입
							 pImage,			// *data : 이미지 데이터
							 width				// step : 한 행의 원소 수
			);

			// CvtColor
			// 크래비스 라이브러리 함수와 비교해서 선택 하여 사용 (OpenCV사용시 에지기반으로 인터폴레이션하므로 영상 품질 향상 기대)
			cv:cvtColor(cv_img, color_img, cv::COLOR_BayerRG2RGB_EA);

			// flip 0 : 상하반전
			// flip 1 : 좌우반전
			// flip -1 : 상하좌우반전
			cv::flip(color_img, flip_img, -1);

			// 이미지 출력
			cv::imshow("image", flip_img);
			
			// Mat이미지 -> Crevis이미지 
			MatToCvsImage(flip_img, pCvtImage);

			// 대기
			cv::waitKey(0);

			// Mat 메모리 초기화
			memset(&cv_img, 0, sizeof(cv::Mat));
			memset(&color_img, 0, sizeof(cv::Mat));
			memset(&flip_img, 0, sizeof(cv::Mat));

			//-----------------------------------

			if (_kbhit())
			{
				break;
			}
		}

		// Acquistion Stop
		status = ST_AcqStop(hDevice);
		if (status != MCAM_ERR_SUCCESS)
		{
			printf("Acquisition stop failed : ");
			throw status;
		}
	}
	catch (__int32 err)
	{
		printf("%d\n", err);
	}

	free(pImage);
	free(pCvtImage);

	// Close Device
	ST_CloseDevice(hDevice);

	// Free system
	ST_FreeSystem();

	return 0;
}

