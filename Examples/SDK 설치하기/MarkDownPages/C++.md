

속성
=================

* x86
<ul>프로젝트 - 속성 - 구성 속성 - C/C++ - 일반 - 추가 포함 디렉터리 - $(CREVIS_CAM_ROOT)\Cameras\MCam40\include;
<br>프로젝트 - 속성 - 구성 속성 - 링커 - 일반 - 추가 라이브러리 디렉터리 - $(CREVIS_CAM_ROOT)\Cameras\MCam40\lib\x86;</ul>
<br>* x64
프로젝트 - 속성 - 구성 속성 - C/C++ - 일반 - 추가 포함 디렉터리 - $(CREVIS_CAM_ROOT)\Cameras\MCam40\include;
<br>프로젝트 - 속성 - 구성 속성 - 링커 - 일반 - 추가 라이브러리 디렉터리 - $(CREVIS_CAM_ROOT)\Cameras\MCam40\lib\x64;
	



```ruby
#include "stdafx.h"

#include "VirtualFG40.h"
#pragma comment (lib, "VirtualFG40.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	__int32 status = MCAM_ERR_SUCCESS;
	__int32 hDevice = 0;

	// System Open
	status = ST_InitSystem();
	if(status != MCAM_ERR_SUCCESS)
	{
		printf("Initiate device failed : %d\n", status);
		ST_FreeSystem();
		return 0;
	}

	// Free System
	status = ST_FreeSystem();
	if(status != MCAM_ERR_SUCCESS)
	{
		printf("Free system failed : %d\n", status);
		ST_FreeSystem();
		return 0;
	}

	return 0;
}
```
