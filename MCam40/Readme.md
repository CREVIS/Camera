# MCam40_SDK

| date | version | link | Inform |
|---|---|---|---|
| 2018.03.13 | 4.3.1 | [Download](https://github.com/CREVIS/Camera/raw/master/MCam40/MCam40_SDK_V4.3.1.zip)| <ul><li>MCam40_SDK_V4.3.1<br/></li> |
| 2018.09.04 | 4.4.0 | [Download](https://github.com/CREVIS/Camera/raw/master/MCam40/MCam40_SDK_V4.4.0.zip)| <ul><li>MCam40_SDK_V4.4.0<br/></li> | 
  
<br><br><br><br>  
---------------
## Update Log

| date | version | Update |
|---|---|---|
| 2018.03.13 |4.3.1|  **<ul><br>  #. GenICam 2.3.0 -> 2.3.1로 업데이트**  **<br><br>#. MVIPConfig 업데이트** <ul>1. 어플리케이션 아이콘 변경<br>2. 디바이스 상태 아이콘 변경<br>3. 기능 추가<ul>- LLA 설정<br>- 자동 설정 기능 추가<br>- UserSet File Save/Load 기능 추가 **</ul></ul><br> #. VirtualFG40 에서 추가 기능** <ul>1. 로그 기능<ul>1) Open 시 로그 기능 활성화.<ul>- 초기값 = False, 기존과 같이 사용하면 초기값 적용.<br>- 사용 방법<br>-> 로그 활성화 : ST_OpenDevice(-, &hDevice, TRUE); <br>-> 로그 비활성화 : ST_OpenDevice(-, &hDevice, FALSE); or ST_OpenDevice(-, &hDevice);</ul>2) Open 후 로그 기능 활성화<ul>- 활성화/비활성화 시점부터 로그 기능 적용.<br>- 사용 방법<br>-> 로그 활성화 : ST_SetDetailedLog(hDevice, TRUE);<br>-> 로그 비활성화 : ST_SetDetailedLog(hDevice, FALSE);</ul>3) 로그 저장 경로 C:\CREVIS\Logs\모델명\ </ul>2. LastError 기능<ul>1) ST_GetLastError 기능 <ul>- 에러 발생시 마지막 에러를 문자열 표기.</ul>2) ST_GetLastErrorDescription 기능 <ul>- 에러 코드에 대한 설명을 문자열로 표기. </ul></ul> 3. Total Packet Count 기능<ul>1) 함수 호출 이전까지의 총 패킷의 수를 가져오는 기능. **</ul></ul><br>#. 메뉴얼 추가** <ul>1) CamGuide 메뉴얼 추가<br> 2) VirtualFG40 메뉴얼 업데이트 **</ul><br>#. 신규모델 추가** <ul> MG-A890M, MG-A890K, MG-A121M, MG-A121K, MG-A121R, MG-A121L, MG-A201R, MG-A201L, MG-A320M, MG-A320K **</ul><br>#. Uninstall GenICam 바로 가기 추가** <ul>GenICam 삭제할 때 첨부된 파일에 바로 가기를 추가하였습니다.| 
| 2018.09.04 |4.4.0| **<ul><li> 1. 모델 추가**  <ul><li>GigE : 현재 버전부터는 “Device Vendor Name (Crevis Co., LTD)”으로 리스트 업 되기 때문에 향후 신규 추가 요청은 필요 없음. </ul><ul><li>USB2.0 : MV-BW35U, MV-CW35U 모델 추가. **</ul><li>2. 메뉴얼 오탈자 수정** **<li>3. 예제 오탈자 수정** **<li>4. C# 라이브러리(VirtualFG40Library) 업데이트** **<li> 5. Library 버그 패치** </li> |