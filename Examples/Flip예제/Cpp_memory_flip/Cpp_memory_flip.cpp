/*
 * 만든이 : 남지원
 * 날짜   : 2021.09.13
 * 내용   : 크래비스 이미지를 받아서 cvtColor, 메모리 Flip한뒤 OpenCV로 출력하는 예제
*/

#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <windows.h>
#include "VirtualFG40.h"
#pragma comment (lib, "VirtualFG40.lib")

#include <opencv2/opencv.hpp>

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

void FlipForColor(BYTE* SrcImage, BYTE* DstImage, int nImageWidth, int nImageHeight, int nFlipMirrorMode)
{
	int i, j, src_idx, dst_idx;

	switch (nFlipMirrorMode) {
		// 상하 반전
		case 0 :
			for (j = 0; j < nImageHeight; j++)
			{
				// 원본 : j번째 라인
				src_idx = j * nImageWidth * 3;

				// 결과 : (마지막라인 - j)번째 라인 시작위치
				dst_idx = ((nImageHeight - 1) - j) * (nImageWidth * 3);

				for (i = 0; i < nImageWidth; i++)
				{
					DstImage[dst_idx] = SrcImage[src_idx];
					DstImage[dst_idx + 1] = SrcImage[src_idx + 1];
					DstImage[dst_idx + 2] = SrcImage[src_idx + 2];

					// 다음 픽셀 위치로 인덱스 변경
					src_idx += 3;
					// 이전 픽셀 위치로 인덱스 변경
					dst_idx += 3;
				}
			}
		break;

		// 좌우 반전
		case 1 :
			for (j = 0; j < nImageHeight; j++)
			{
				// 원본 : j번째 라인
				src_idx = j * nImageWidth * 3;

				// 결과 : j번째 라인 끝에서 3번째
				dst_idx = ((j + 1) * (nImageWidth * 3)) - 3;

				for (i = 0; i < nImageWidth; i++)
				{
					DstImage[dst_idx] = SrcImage[src_idx];
					DstImage[dst_idx + 1] = SrcImage[src_idx + 1];
					DstImage[dst_idx + 2] = SrcImage[src_idx + 2];

					// 다음 픽셀 위치로 인덱스 변경
					src_idx += 3;
					// 이전 픽셀 위치로 인덱스 변경
					dst_idx -= 3;
				}
			}
		break;

		// 상하좌우 반전
		case 2:
			for (j = 0; j < nImageHeight; j++)
			{
				// 원본 : j번째 라인
				src_idx = j * nImageWidth * 3;

				// 결과 : (마지막라인 - j)번째 라인 끝에서 3번째
				dst_idx = ((nImageHeight - j) * (nImageWidth * 3)) - 3;

				for (i = 0; i < nImageWidth; i++)
				{
					DstImage[dst_idx] = SrcImage[src_idx];
					DstImage[dst_idx + 1] = SrcImage[src_idx + 1];
					DstImage[dst_idx + 2] = SrcImage[src_idx + 2];

					// 다음 픽셀 위치로 인덱스 변경
					src_idx += 3;
					// 이전 픽셀 위치로 인덱스 변경
					dst_idx -= 3;
				}
			}
			break;
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
	unsigned char* pFlipImage = NULL;

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

		// Image Buffer Allocatation
		try
		{
			buffferSize = width * height;
			// 흑백 이미지 메모리 생성
			pImage = (unsigned char*)malloc(buffferSize);
			if (pImage == 0)
			{
				throw "메모리 할당 에러";
			}
			memset((void*)pImage, 0, buffferSize);

			// 컬러 이미지 메모리 생성
			pCvtImage = (unsigned char*)malloc(buffferSize * 3);
			if (pCvtImage == 0)
			{
				throw "메모리 할당 에러";
			}
			memset((void*)pCvtImage, 0, buffferSize * 3);

			// Flip이미지 메모리 생성
			pFlipImage = (unsigned char*)malloc(buffferSize * 3);
			if (pFlipImage == 0)
			{
				throw "메모리 할당 에러";
			}
			memset((void*)pFlipImage, 0, buffferSize * 3);

		}
		catch (const char Except)
		{
			printf(("에러 : %c"), Except);
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
			// pImage : Grab Image, BayerRG Pattern
			// pCvtImage : ColorConvert Image, RGB24
			ST_CvtColor(pImage, pCvtImage, width, height, CVP_BayerRG2RGB);

			//-----------------------------------
			// flip 
			// 0 : 상하 반전
			// 1 : 좌우 반전
			// 2 : 상하좌우 반전
			FlipForColor(pCvtImage, pFlipImage, width, height, 0);

			//-----------------------------------
			// OpenCV -> 출력을 위해 넣음
			//

			cv::Mat cv_img;

			// 크래비스 이미지 -> OpenCV::Mat
			cv_img = cv::Mat(height,				// row : 열의 수(height)
							 width,				// col : 행의 수(width)
							 CV_8UC3,			// type : 이미지 타입
							 pFlipImage,			// *data : 이미지 데이터
							 width*3			// step : 한 행의 원소 수
			);
			
			// 이미지 출력
			cv::imshow("image", cv_img);

			// 대기
			cv::waitKey(0);

			// Mat 메모리 초기화
			memset(&cv_img, 0, sizeof(cv::Mat));

			//-----------------------------------

			//printf("Image(0,0) = R:%d, G:%d, B:%d\n", pCvtImage[2], pCvtImage[1], pCvtImage[0]);

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
	free(pFlipImage);
	// Close Device
	ST_CloseDevice(hDevice);

	// Free system
	ST_FreeSystem();

	return 0;
}

