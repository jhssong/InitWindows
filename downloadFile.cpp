#include <stdio.h>
#include <urlmon.h>
#pragma comment(lib,"urlmon.lib")

int main()
{
    const wchar_t* KakaoTalk = L"https://app-pc.kakaocdn.net/talk/win32/KakaoTalk_Setup.exe";

    const wchar_t* destFolder = L"C:\\jhssong\\KaKaoTalk.exe";

    HRESULT hr = URLDownloadToFile(NULL, KakaoTalk, destFolder, 0, NULL);

    if (hr == S_OK) {
        printf("Saved");
        return 0;
    }
    else {
        printf("Failed");
        return -1;
    }
}