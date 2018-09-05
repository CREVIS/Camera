# MCam40_SDK

| date | version | link | Inform |
|---|---|---|---|
| 2018.03.13 | 4.3.1 | [Download](https://github.com/CREVIS/Camera/raw/master/MCam40/MCam40_SDK_V4.3.1.zip)| <ul><li>MCam40_SDK_V4.3.1<br/></li> |
| 2018.09.04 | 4.4.0 | [Download](https://github.com/CREVIS/Camera/raw/master/MCam40/MCam40_SDK_V4.4.0.zip)| <ul><li>MCam40_SDK_V4.4.0<br/></li> |

  
  
  
  
---------------
>Update Log

| date | version | Update |
|---|---|---|
| 2018.03.13 |4.3.1| <ul><li> 
#. GenICam 2.3.0 -> 2.3.1로 업데이트
 
#. MVIPConfig 업데이트 
 
    1. 어플리케이션 아이콘 변경
 
    2. 디바이스 상태 아이콘 변경
 
    3. 기능 추가
 
        - LLA 설정
 
        - 자동 설정 기능 추가
 
        - UserSet File Save/Load 기능 추가
#. VirtualFG40 에서 추가 기능
 
1. 로그 기능
 
    1) Open 시 로그 기능 활성화.
 
        - 초기값 = False, 기존과 같이 사용하면 초기값 적용.
 
        - 사용 방법
 
          -> 로그 활성화 : ST_OpenDevice(-, &hDevice, TRUE); 
 
          -> 로그 비활성화 : ST_OpenDevice(-, &hDevice, FALSE); or ST_OpenDevice(-, &hDevice);
 
    2) Open 후 로그 기능 활성화
 
        - 활성화/비활성화 시점부터 로그 기능 적용.
 
        - 사용 방법
 
          -> 로그 활성화 : ST_SetDetailedLog(hDevice, TRUE);
 
          -> 로그 비활성화 : ST_SetDetailedLog(hDevice, FALSE);
 
   3) 로그 저장 경로 C:\CREVIS\Logs\모델명\
 
2. LastError 기능
 
    1) ST_GetLastError 기능 
 
        - 에러 발생시 마지막 에러를 문자열 표기.
 
    2) ST_GetLastErrorDescription 기능 
 
        - 에러 코드에 대한 설명을 문자열로 표기.
 
3. Total Packet Count 기능
 
    1) 함수 호출 이전까지의 총 패킷의 수를 가져오는 기능.
 
 
#. 메뉴얼 추가
 
    1) CamGuide 메뉴얼 추가
 
    2) VirtualFG40 메뉴얼 업데이트
 
 
#. 신규모델 추가
 
  MG-A890M, MG-A890K, MG-A121M, MG-A121K, MG-A121R, MG-A121L, MG-A201R, MG-A201L, MG-A320M, MG-A320K
 
#. Uninstall GenICam 바로 가기 추가
 
GenICam 삭제할 때 첨부된 파일에 바로 가기를 추가하였습니다.
 <br/></li> |
| 2018.09.04 |4.4.0| <ul><li> 1. 모델 추가  <ul><li> GigE : 향후 추가 모델은 Manufactor 이름으로 구분하여 신규 추가 요청 필요 없음. </ul><ul><li>USB2.0 : MV-BW35U, MV-CW35U 모델 추가.</ul> <li>2. 메뉴얼 오탈자 수정 <li>3. 예제 오탈자 수정 <li>4. C# 라이브러리(VirtualFG40Library) 업데이트 <li>5. Library 버그 패치 <br/></li> |
