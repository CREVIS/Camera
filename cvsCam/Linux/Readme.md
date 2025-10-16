# cvsCam SDK for Linux
| date | version | link | Inform |
|------|---------|------|--------|
| 2025.10.14 | 1.1.0.7155 | [Download](https://github.com/CREVIS/Camera/raw/refs/heads/master/cvsCam/Linux/Files/cvsCam_SDK_Ubuntu-18.04-x86_64-1.1.0.7155.deb) | <ul><li>Ubuntu-18.04-x86_64</br></li> |
| 2025.10.14 | 1.1.0.7155 | [Download](https://github.com/CREVIS/Camera/raw/refs/heads/master/cvsCam/Linux/Files/cvsCam_SDK_Ubuntu-20.04-x86_64-1.1.0.7155.deb) | <ul><li>Ubuntu-20.04-x86_64</br></li> |
| 2025.10.14 | 1.1.0.7155 | [Download](https://github.com/CREVIS/Camera/raw/refs/heads/master/cvsCam/Linux/Files/cvsCam_SDK_Ubuntu-22.04-x86_64-1.1.0.7155.deb) | <ul><li>Ubuntu-22.04-x86_64</br></li> |
| 2025.10.14 | 1.1.0.7155 | [Download](https://github.com/CREVIS/Camera/raw/refs/heads/master/cvsCam/Linux/Files/cvsCam_SDK_Raspberry_Pi4_Pi5_linux-aarch64-arm-6.5.3-7155.deb) | <ul><li>Raspberry_Pi4_Pi5_linux-aarch64-arm(bookworm)</br></li> |
| 2025.04.18 | 1.0.6.6797 | [Download](https://github.com/CREVIS/Camera/raw/refs/heads/master/cvsCam/Linux/Files/cvsCam_SDK_linux-x86_64-1.0.6.6797.deb)| <ul><li>x86_64-1.0.6.6797<br/></li> |
| 2025.04.01 | 1.0.5.6797 | [Download](https://github.com/CREVIS/Camera/raw/refs/heads/master/cvsCam/Linux/Files/cvsCam_SDK_linux-x86_64-1.0.5.6797.deb)| <ul><li>x86_64-1.0.5.6797<br/></li> |
| 2025.01.14 | 1.0.4.6797 | [Download](https://github.com/CREVIS/Camera/raw/refs/heads/master/cvsCam/Linux/Files/cvsCam_SDK_linux-x86_64-1.0.4.6797.deb)| <ul><li>x86_64-1.0.4.6797<br/></li> |
| 2024.09.25 | 1.0.3.6797 | [Download](https://github.com/CREVIS/Camera/raw/refs/heads/master/cvsCam/Linux/Files/cvsCam_SDK_linux-x86_64-1.0.3.6797.deb)| <ul><li>x86_64-1.0.3.6797<br/></li> |

<br>

- 지원OS : Ubuntu 18.04 LTS, 20.04 LTS, 22.04 LTS, Raspberry Pi OS(Bookworm)

- 다른 버전은 자사 기술지원팀이나 홈페이지에 문의 바랍니다. (https://www.crevis.co.kr/Customer/contact)

- 필수 요소
    - build-essential
      
        ```bash
        # 필수 요소 build-essential 설치
        sudo apt install build-essential
        ```

- 설치 방법
    - 다운로드 받은 deb 파일을 통하여 설치 합니다.
      
        ```bash
        # ex) linux x86-64, sdk version 1.0.3.6797
        sudo dpkg -i cvsCam_SDK_linux-x86_64-1.0.3.6797.deb
        ```

- 설치 시 ebUniversalProForEthernet 드라이버 설치 중  gcc-12 가 필요하다고 하면서 오류가 발생할 수도 있습니다. (특히 Ubuntu 22.04)

- SDK 설치 완료 후 gcc-12 설치 하고 ebUniversalProForEthernet 드라이버를 재설치 하세요.
  
    ```bash
    # gcc-12 설치
    sudo apt install gcc-12
    # ebUniversalProForEthernet Build 및 install, x86-64의 경우 Linux64, arm64의 경우 aarch64
    cd /opt/CREVIS/cvsCam/Linux64/module
    sudo ./build.sh
    sudo ./install_driver.sh
    sudo reboot
    #ebUniversalProForEthernet 상태 확인
    sudo ./opt/CREVIS/cvsCam/Linux64/module/ebdriverlauncher.sh status
    ```
    
- 또는 SDK 설치 전에 gcc-12를 설치 하세요.
  
- 설치 후 재부팅을 권장합니다.
  
    ```bash
    sudo reboot
    ```

- 설치 완료 후 samples 는 /opt/CREVIS/cvsCam/Linux64/share/samples/ 에 위치합니다.
  <br>(arm64는 /opt/CREVIS/cvsCam/aarch64/share/samples/)
  
- cvsCamPlayer를 위해서는 다음과 같은 라이브러리가 필요합니다.
    - QT5 라이브러리
    
      ```bash
      sudo apt update
      sudo apt install libqt5core5a libqt5gui5 libqt5opengl5
      ```
    
    - ffmpeg 라이브러리
    
      ```bash
      sudo apt update
      sudo apt install ffmpeg
      ```
    
      <br>
    
      <br>

## Update Log
| date | version | Update |
|------|---------|--------|
| 2025.10.14 | 1.1.0.7155 | <br><ul> <li> cvsCamCtrl <br><ul><li> 멀티캐스트 기능 지원을 위한 ST_OpenDeviceMulticast 함수와 CvsAccessType 열거형 추가<br/><li> 패킷 자동 협상 기능이 수정<br/><li> 방화벽 설정에 관계없이 GEV 장치가 작동하도록 수정<br/><li> 각종 버그 패치<br><br></ul> <li> cvsCamPlayer <br/><ul> <li> 동영상 녹화 기능 추가. <br/><br> |
| 2025.04.18 | 1.0.6.6797 | <br> <ul> <li> cvsCamCtrl <br><ul><li> Color Convert 관련 Feature 재정의 <br><br></ul><li> cvsCamPlayer <br> <ul> <li> cvsCamPlayer : Scale 기능 추가. <br> <br> |
| 2024.09.25 | 1.0.3.6797 | 최초 Release |

<br>
