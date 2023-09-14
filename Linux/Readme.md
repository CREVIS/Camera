## cvsGEV

Refer to [cvsGEVConfigure.pdf](https://github.com/CREVIS/Camera/blob/master/Linux/cvsGEVConfigure.pdf) for IP settings.

| Date | Version | Architecture | Operating System | Depends | Link |
| --- | --- | --- | --------- | --- | --- |
| 2023.09.05 | 1.0.0 | amd64 | Ubuntu 18.04 or newer.| libxml2(≥2.9.4+dfsg1-6)<br>libxslt1.1(≥1.1.29.5)<br>|[Download](https://github.com/CREVIS/Camera/raw/master/Linux/deb%20Package/libcvsGEV_1.0.0_amd64.deb)|
| 2023.09.05 | 1.0.0 | arm64 | Ubuntu 18.04 or newer.| libxml2(≥2.9.4+dfsg1-6)<br>libxslt1.1(≥1.1.29.5)<br>|[Download](https://github.com/CREVIS/Camera/raw/master/Linux/deb%20Package/libcvsGEV_1.0.0_arm64.deb)|

## cvsU3V

| Date | Version | Architecture | Operating System | Depends | Link |
| --- | --- | --- | --------- | --- | --- |
| 2023.09.05 | 1.1.1-2 | amd64 | Ubuntu 18.04 or newer.| libusb-1.0.0(≥ 2:1.0.21-2)<br>libxml2(≥ 2.9.4+dfsg1-6)<br>libxslt1.1(≥ 1.1.29.5)<br>|[Download](https://github.com/CREVIS/Camera/raw/master/Linux/deb%20Package/libcvsU3V_1.1.1-2_amd64.deb)|
| 2023.09.05 | 1.1.1-2 | arm64 | Ubuntu 18.04 or newer.| libusb-1.0.0(≥ 2:1.0.21-2)<br>libxml2(≥ 2.9.4+dfsg1-6)<br>libxslt1.1(≥ 1.1.29.5)<br>|[Download](https://github.com/CREVIS/Camera/raw/master/Linux/deb%20Package/libcvsU3V_1.1.1-2_arm64.deb)|

### Install :
```sh
$ sudo dpkg -i "deb package"
```

ex) cvsU3V (amd64)
```sh
$ sudo dpkg -i libcvsU3V_1.1.1-2_amd64.deb
```

### Remove (without the configuration files) :
```sh
$ sudo dpkg -r "package"
```
ex) cvsU3V
```sh
$ sudo dpkg -r libcvsU3V
```

### Purge (with configuration files) :
```sh
$ sudo dpkg -P "package"
```
ex) cvsU3V (amd64)
```sh
$ sudo dpkg -P libcvsU3V
```


