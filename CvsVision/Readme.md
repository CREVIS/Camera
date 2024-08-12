# [필독사항]
- CvsVision Library 사용 전 MCam40_SDK 설치 필요 (아래 링크에서 최신 MCam40_SDK 설치)

| Date | Download Link | Inform |
|------|---------------|--------|
| 2024.04.08 | [링크](https://crevis.co.kr/Customer/download?category=&search_word=MCam40_SDK&depth1=&depth2=&depth3=&module_idx=&product_idx=&order=new) | MCam40_SDK 설치|

<br><br><br>

# CvsVision
| Date | Version | Download Link | Inform | OS |
|------|---------|------|--------|--------|
| 2024.05.13 | 1.0.0.1| [Download](https://github.com/CREVIS/Camera/raw/master/CvsVision/CvsVision%20Library%201.0.0.1.zip)| Vision Tool Library | x64 Windows 10 이상 |
| 2024.04.08 | 1.0.0.0| [Download](https://github.com/CREVIS/Camera/raw/master/CvsVision/CvsVision%20Library%201.0.0.0.zip)| Vision Tool Library | x64 Windows 10 이상 |
  
<br><br><br> 
  
## Update Log
| Date | Version | Update Log |
|------------------------------------|------------------------------|---------------------------|
| 2024.05.13 |1.0.0.1| <br>***[기능 추가 및 변경]*** <br> <ul> **1. PolarizedImageTool 추가** <br><br> **2. ImageMatchTool** <br> <ul><li> 검출 결과 각도를 '0 ~ 360' 에서 '-180 ~ 180'으로 변경 </ul><br> **3. 영상처리 기능 추가** <br> <ul><li> Resize, Threshold, GaussianBlur 기능. </ul><br> **4. CameraLink, CXP 카메라사용시 Tool 활성화 가능.** <br><br> **5. 검사 및 설정 영역 벗어날경우 에러 처리.** <br><br> **6. ImageMatchTool, TemplateMatchTool, AlignmentTool 마스크 기능 추가** <br><br> **7. FindEdge, FindCircle 결과창 UI 변경** <br><br> **8. Brightness Tool 결과 표시 변경** <br><br> **9. 새로운 이미지 또는 GrabImage 시 이전 결과 지우기로 변경.** <br><br> **10. Image 파일 오픈 시 원본 이미지 채널에 맞게 오픈되도록 변경.** <br><br></ul> ***[버그 패치]*** <br> <ul> **1. 다른툴의 ".cvst"파일 불러올 경우 에러 처리 추가** <br><br> **2. ImageMatchTool** <br> <ul><li> Rotate, Skew 파라미터 사용시 영역 밖의 데이터를 사용하는 버그 패치. </ul><br> **3. TemplateMatchTool** <br> <ul><li> 학습 영역 크기가 변함에따른 1픽셀 위치 틀어짐 에러 문제 패치. </ul> <ul><li> 매칭 스코어값 미세하게 다른 문제 패치. </ul> <br> **4. FindCircleTool** <br> <ul><li> 검출된 점과 검출된 원과의 거리값이 0으로 나오는 문제 패치.	 </ul><br> **5. Align 기능** <br> <ul><li> Align을 이용한 검사 후 일반 검사시 이전 Align값이 적용되는 문제 패치.	 </ul><br> **6. RgbMatchTool** <br> <ul><li> 기준 컬러 값 동기화 (설정 표시와 결과표시).	 </ul><br> **7. USB 카메라 Open버그 패치**<br><br>
| 2024.04.08 |1.0.0.0| <br>***[구성 내용]*** <br> <ul> **1. Vision Tool Library** <br> <ul><li> TemplateMatch, Calibration 등 총 21가지 비전 툴 지원 <br> 단, 아래의 6가지 툴은 자사 카메라가 연결된 PC에서만 동작. <br> <ul><li> template_match_tool <br><li> image_match_tool <br><li> find_edge_tool <br><li> find_line_tool <br><li> find_circle_tool <br> <li> alignment_tool </ul></ul><br> **2. C++ Example** <br> <ul><li> 비전 툴의 C++ 예제 </ul><br> **3. C# WPF Example** <br> <ul><li> 비전 툴의 C# WPF 예제 </ul><br> **4. CvsLauncher**<br> <ul><li> 비전 툴을 사용해 볼 수 있는 GUI 프로그램 <br> </ul> </ul> <br>***[최소 사양]*** <br> <ul><ul><li> **Windows 10 이상, x64비트 운영체제** <br><br>
