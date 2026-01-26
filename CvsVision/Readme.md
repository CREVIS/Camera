<br><br>
# [필독사항]
- ### CvsVision Library 사용전 아래에서 필요한 SDK를 **반드시** 설치하여 주십시오. (아래 링크에서 최신 SDK 설치)

| Date | Download Link | Inform |
|------|:-------------:|--------|
| 2026.01.09 | [cvsCam SDK](https://github.com/CREVIS/Camera/tree/master/cvsCam/Windows) | CvsVision 1.0.0.4 사용시 cvsCam v1.1.2 이상 호환  |
| 2024.12.17 | [cvsCam SDK](https://github.com/CREVIS/Camera/tree/master/cvsCam/Windows) | CvsVision 1.0.0.3 사용시 cvsCam v1.0.5 만 호환  |
| 2024.08.13 | [cvsCam SDK](https://github.com/CREVIS/Camera/tree/master/cvsCam/Windows) | CvsVision 1.0.0.2 사용시 cvsCam v1.0.1 이상 필요|
| 2024.04.08 | [Mcam40 SDK](https://crevis.co.kr/Customer/download?category=&search_word=MCam40_SDK&depth1=&depth2=&depth3=&module_idx=&product_idx=&order=new) | CvsVision 1.0.0.1 이하 사용시 필요|

<br>

- VisualStuidio에서 라이브러리 사용시 환경설정
  - C++
    - 구성 속성 -> C/C++ -> 일반 -> 추가 포함 디렉터리 : $(CREVIS_CAM_ROOT)/CvsVision/include;../include;
    - 구성 속성 -> 링커 -> 일반 -> 추가 라이브러리 디렉터리 : $(CREVIS_CAM_ROOT)/CvsVision/lib/x64;
    - 구성 속성 -> 링커 -> 입력 -> 추가 종속성 : cvs_vision.lib;
  - C#
    - 참조 -> 참조 추가 -> 찾아보기 : C:\Program Files\CREVIS\cvsCam\Binaries\cvsCamDotNet.dll
    - 참조 -> 참조 추가 -> 찾아보기 : C:\Program Files\CREVIS\CvsVision\bin\x64\CvsVisionCSharp.dll

<br><br>
# [CvsVision Library]

## Install Manual
| [![View PDF](https://img.shields.io/badge/PDF-View_Manual-blue?style=for-the-badge&logo=adobeacrobatreader)](https://github.com/CREVIS/Camera/blob/master/CvsVision/CvsVision%20%EC%84%A4%EC%B9%98%20%EB%A7%A4%EB%89%B4%EC%96%BC.pdf) | [![Download PDF](https://img.shields.io/badge/PDF-Download_Manual-red?style=for-the-badge&logo=adobeacrobatreader)](https://github.com/CREVIS/Camera/releases/download/CvsVision/CvsVision.Install.Manual.pdf) |

## Download Link
| Date | Version | Download Link | Inform | OS |
|------|---------|:-------------:|--------|----|
| 2026.01.09 | 1.0.0.4| [Download](https://github.com/CREVIS/Camera/releases/download/CvsVision/CvsVision.SDK.1.0.0.4.x64.Setup.exe)| cvsCam v1.1.2 이상 호환 | x64 Windows 10 이상 |
| 2026.01.09 | CvsVisionGPU| [Download](https://github.com/CREVIS/Camera/releases/download/CvsVision/CvsPythonGPU.7z) | [ <img src="https://github.com/CREVIS/Camera/raw/master/CvsVision/crevis.ico" width="30" align="middle"> **설치 매뉴얼 (PDF)** ](https://github.com/CREVIS/Camera/blob/master/CvsVision/CvsVision%20%EC%84%A4%EC%B9%98%20%EB%A7%A4%EB%89%B4%EC%96%BC.pdf) | x64 Windows 10 이상 |
| 2024.12.17 | 1.0.0.3| [Download](https://github.com/CREVIS/Camera/raw/master/CvsVision/CvsVision%20Library%201.0.0.3.zip)| cvsCam v1.0.5 만 호환 | x64 Windows 10 이상 |
| 2024.08.13 | 1.0.0.2| [Download](https://github.com/CREVIS/Camera/raw/master/CvsVision/CvsVision%20Library%201.0.0.2.zip)| cvsCam v1.0.1 이상 호환 | x64 Windows 10 이상 |
| 2024.05.13 | 1.0.0.1| [Download](https://github.com/CREVIS/Camera/raw/master/CvsVision/CvsVision%20Library%201.0.0.1.zip)| Vision Tool Library | x64 Windows 10 이상 |
| 2024.04.08 | 1.0.0.0| [Download](https://github.com/CREVIS/Camera/raw/master/CvsVision/CvsVision%20Library%201.0.0.0.zip)| Vision Tool Library | x64 Windows 10 이상 |
  


## Update Log

| Date | Version | Update Log |
|------------------------------------|------------------------------|---------------------------|
| 2026.01.09 |1.0.0.4| <br>***[cvs_vision]*** <br> <ul> **1. 메모리 관리 예외 처리 추가** <br><br> **2. FindBarcodeTool에 ROI 파라미터 추가** <br><br> **3. FindLineTool** <br> <ul> <li> Position값 검사영역 중심기준으로 변경. <br> <br> </ul> **4. FindCircleTool** <br> <ul> <li> Distance값 음수를 양수로 변경 <br> <br> </ul> **5. 영상처리 함수 추가** <br> <ul> <li> cvs_equalize_hist, cvs_create_rect_mask_image, cvs_create_circle_mask_image, cvs_mask_copy, cvs_structuring_element, cvs_morphology_ex <br> <br> </ul> **6. 구조체 이름 변경** <br> <ul> <li> CVS_BUFFER -> CVS_DATA <br> <li> CVS_IMAGE.pimage -> CVS_IMAGE.pImage <br> </ul> </ul> ***[CvsVisionCSharp]*** <br> <ul> **1. CvsGray8Image,CvsImage에 영상처리 함수 포팅**  <br> <ul> <li> EqualizeHist, CopyByMask </ul> <br> **2. CvsCv 클래스 추가 및 영상처리 함수 포팅** <br> <ul> <li> CreateRectMaskImage, CreateCircleMaskImage, StructuringElement, MorphologyEx  </ul> <br> **3. SegmentTrainTool, ClassifyTrainTool, OnnxRuntimeTool 툴 추가** <br> <br> **4. DistanceCircleLineToolEditor, DistanceLineSegLineToolEditor, DistancePointLineToolEditor 수정**  <br> <ul> <li> LineControl 툴 기울기 패치 : 기울기 범위 -90 ~ 90 으로 제한  </ul> <br> **5. PaddleOCRTool, ToolEditor 추가** <br><br> |
| 2024.12.17 |1.0.0.3| <br>***[cvs_vision]*** <br> <ul> **1. cvs_init_buffer, cvs_free_buffer 함수 내부 InitLibrary 체크 해제**  <br> </ul> ***[CvsVisionCSharp]*** <br> <ul> **1. CvsCamDotNet 카메라 라이브러리로 변경** <br> **2. ICvsImage, CvsOverlay 클래스 Clone() 추가** <br><br>|
| 2024.08.13 |1.0.0.2| <br>***[cvs_vision]*** <br> <ul> **1. BlobTool cvst파일 버그 패치** <br> <br> **2. FindEdgeTool 버그 패치** <br> <ul> <li> 영상의 끝단에서 에지가 검출 되는 문제 패치 <br> <br> </ul> **3. 결과값 sorting** <br> <ul> <li> BlobTool : 영역 크기로 소팅  <br> <li> ImageMatchTool, TemplateMatchTool : 스코어로 소팅 <br> <br> </ul> **4. FindLineTool, FindCircleTool 결과 항목에 FittingError 추가** <br> <br> **5. InRangeTool 추가** <br> <br> **6. FitLineTool 추가** <br> <br> **7. 파라미터 오타 수정**  <br> <br>  </ul> ***[CvsVisionCSharp]*** <br> <ul> **1. AlignmentToolEditor 결과 표시 일부 항목 삭제** <br> <br> **2. 에디터 바인딩 오류 패치** <br> <ul> <li> ConvertImageTool, AlignmentTool, TemplateMatchTool, ImageMatchTool  <br> <br> </ul> **3. CvsDisplay Statusbar 추가**  <br>  <ul> <li> Image Size, Scale, Pixel 좌표 정보 보여주기  <br> <br> </ul> **4. InRangeTool, InRangeToolEditor 추가** <br> <br> **5. FindCircle, FindLine 결과 표시 항목 추가** <br> <ul> <li> 피팅 에러 <br> <br> </ul> **6. FindCircleTool UI 버그 패치** <br> <ul> <li> 특정 구간에서 거꾸로 표시 되는 문제 패치 <br> <br> </ul> **7. CvsImage, CvsGray8Image 고속 디스플레이를 위한 프로퍼티 추가** <br> <ul> <li> WriteableBitmap <br> <br> </ul> **8. FitLineTool, FitLineToolEidtor 추가** <br><br>|
| 2024.05.13 |1.0.0.1| <br>***[기능 추가 및 변경]*** <br> <ul> **1. PolarizedImageTool 추가** <br><br> **2. ImageMatchTool** <br> <ul><li> 검출 결과 각도를 '0 ~ 360' 에서 '-180 ~ 180'으로 변경 </ul><br> **3. 영상처리 기능 추가** <br> <ul><li> Resize, Threshold, GaussianBlur 기능. </ul><br> **4. CameraLink, CXP 카메라사용시 Tool 활성화 가능.** <br><br> **5. 검사 및 설정 영역 벗어날경우 에러 처리.** <br><br> **6. ImageMatchTool, TemplateMatchTool, AlignmentTool 마스크 기능 추가** <br><br> **7. FindEdge, FindCircle 결과창 UI 변경** <br><br> **8. Brightness Tool 결과 표시 변경** <br><br> **9. 새로운 이미지 또는 GrabImage 시 이전 결과 지우기로 변경.** <br><br> **10. Image 파일 오픈 시 원본 이미지 채널에 맞게 오픈되도록 변경.** <br><br></ul> ***[버그 패치]*** <br> <ul> **1. 다른툴의 ".cvst"파일 불러올 경우 에러 처리 추가** <br><br> **2. ImageMatchTool** <br> <ul><li> Rotate, Skew 파라미터 사용시 영역 밖의 데이터를 사용하는 버그 패치. </ul><br> **3. TemplateMatchTool** <br> <ul><li> 학습 영역 크기가 변함에따른 1픽셀 위치 틀어짐 에러 문제 패치. </ul> <ul><li> 매칭 스코어값 미세하게 다른 문제 패치. </ul> <br> **4. FindCircleTool** <br> <ul><li> 검출된 점과 검출된 원과의 거리값이 0으로 나오는 문제 패치.	 </ul><br> **5. Align 기능** <br> <ul><li> Align을 이용한 검사 후 일반 검사시 이전 Align값이 적용되는 문제 패치.	 </ul><br> **6. RgbMatchTool** <br> <ul><li> 기준 컬러 값 동기화 (설정 표시와 결과표시).	 </ul><br> **7. USB 카메라 Open버그 패치**<br><br>
| 2024.04.08 |1.0.0.0| <br>***[구성 내용]*** <br> <ul> **1. Vision Tool Library** <br> <ul><li> TemplateMatch, Calibration 등 총 21가지 비전 툴 지원 <br> 단, 아래의 6가지 툴은 자사 카메라가 연결된 PC에서만 동작. <br> <ul><li> template_match_tool <br><li> image_match_tool <br><li> find_edge_tool <br><li> find_line_tool <br><li> find_circle_tool <br> <li> alignment_tool </ul></ul><br> **2. C++ Example** <br> <ul><li> 비전 툴의 C++ 예제 </ul><br> **3. C# WPF Example** <br> <ul><li> 비전 툴의 C# WPF 예제 </ul><br> **4. CvsLauncher**<br> <ul><li> 비전 툴을 사용해 볼 수 있는 GUI 프로그램 <br> </ul> </ul> <br>***[최소 사양]*** <br> <ul><ul><li> **Windows 10 이상, x64비트 운영체제** <br><br>
