# cvsCam SDK for Linux
| date | version | link | Inform |
|------|---------|------|--------|
| 2025.01.14 | 1.0.4.6797 | [Download](https://github.com/CREVIS/Camera/raw/refs/heads/master/cvsCam/Linux/Files/cvsCam_SDK_linux-x86_64-1.0.4.6797.deb)| <ul><li>x86_64-1.0.4.6797<br/></li> |
| 2024.09.25 | 1.0.3.6797 | [Download](https://github.com/CREVIS/Camera/raw/refs/heads/master/cvsCam/Linux/Files/cvsCam_SDK_linux-x86_64-1.0.3.6797.deb)| <ul><li>x86_64-1.0.3.6797<br/></li> |


<br>

- cvsCam SDK for Linux는 Ubuntu 20.04 이상을 지원합니다.
- 지원OS : Ubuntu 20.04.6 LTS, 22.04.5 LTS, Debian 11(Bullseye), 12(Bookworm), Raspberry Pi OS
- 다른 버전은 자사 기술지원팀에 문의 바랍니다.

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

- 설치 시 ebUniversalProForEthernet 드라이버 설치 중  gcc-12 가 필요하다고 하면서 오류가 발생할 수도 있습니다.
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
    
- 설치 후 재부팅을 권장합니다.
    
    ```bash
    sudo reboot
    ```

- 설치 완료 후 samples 는 /opt/CREVIS/cvsCam/Linux64/share/samples/ 에 위치합니다.
  <br>(arm64는 /opt/CREVIS/cvsCam/aarch64/share/samples/)
- cvsCamPlayer를 위해서는 다음과 같은 라이브러리가 필요합니다.
    - libqt5core5a, libqt5gui5, libqt5opengl5, libavcodec58
    
    ```bash
    # libqt5core5a libqt5gui5 libqt5opengl5 libavcodec58 설치
    sudo apt install libqt5core5a libqt5gui5 libqt5opengl5 libavcodec58
    ```
    
    - Debian 12(Bookworm) 의 경우 libavcodec58의 패키지가 공식적으로 제공되지 않습니다.
      
    - 설치 시 다음과 같은 작업이 필요합니다.
      
         1. 저장소 추가      
            - 먼저 멀티미디어 저장소를 추가해야 합니다.      
            - ‘/etc/apt/sources.list’ 파일을 편집합니다            
            ```
            sudo nano /etc/apt/sources.list
            ```

            - 다음 줄을 추가합니다.               
            ```
            deb https://www.deb-multimedia.org bookworm main non-free
            ```
 
            - 만약 GPG Error 발생하면 다음단계를 따릅니다.             
            ```
            sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys "해당 키"
            ```

            - ex) GPG error: https://www.deb-nultimedia.org bookworm InRelease: The follwing signatures coutdn't be verified because the pubtic key is not available: NO_PUBKEY 5C808C2B65558117
            ```
            sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 5C808C2B65558117
            ```
                
         3. 패키지 설치 
            - 저장소를 추가한 후 다음 단계를 따릅니다               
                1.패키지 목록을 업데이트합니다
                ```bash
                sudo apt update
                ```
                2.libavcodec58 패키지를 설치합니다
                ```bash
                sudo apt install libavcodec58
                ```

         4. 주의 사항
            - Debian 12(Bookworm)에서는 기본적으로 libavcodec59가 제공됩니다.
            - libavcodec58은 이전 버전이므로 호환성 문제가 발생할 수 있습니다.
            - cvsCamCtrl 라이브러리만 사용한다면 설치 하지 않아도 됩니다.
        
<br><br>

## Update Log
| date | version | Update |
|------|---------|--------|
| 2024.09.25 | 1.0.3.6797 | 최초 Release |

<br>
