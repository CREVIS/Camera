
## 예제 1. OpenCv를 사용한 버전
- OpenCV_Flip

## 예제 2. OpenCV를 사용하지 않고 메모리를 사용한 버전(이미지 출력을 위해서만 사용)
- Cpp_memory_flip

<br></br>
### 참고 사항
- Continuous Grab을 위한 함수 수정 : Continuous Grab을 사용하기 위해선 TriggerMode=OFF, ContinuousGrabbing(1) 설정필요
- GrabAsync를 위한 함수 수정 : 비동기 그랩을 위해서 GrabAsyncStart, GrabAsync필요

<br></br>
### 기타 사항
- OpenCV버전은 3.4.15 버전 사용.
