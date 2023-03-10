#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "make_folder.h"

// 경로가 이미 존재하는지 확인하기 위한 헤더파일
#include <io.h>

// 파일을 다운받기 위한 헤더파일
#include <urlmon.h>
#pragma comment(lib,"urlmon.lib")

// char* <-> wchar_t* 형변환을 위한 헤더파일
#include "convert_char.h"

using namespace std;

int downloadFile(wchar_t*, const char*, const wchar_t*, const wchar_t*);

int main() 
{
    wchar_t* downloadFolderPath = makeFolder();
    if (downloadFolderPath == NULL) {
        cout << "ERROR!" << endl;
        return 0;
    }

    // TODO: 다운로드 목록을 다른 파일에서 불러오기
    const char* KakaoTalk_Name = "KakaoTalk";
    const wchar_t* KakaoTalk_URL = L"https://app-pc.kakaocdn.net/talk/win32/KakaoTalk_Setup.exe";
    const wchar_t* KakaoTalk_File = L"\\KaKaoTalk.exe";
    
    // 파일 다운로드 하기
	downloadFile(downloadFolderPath, KakaoTalk_Name, KakaoTalk_URL, KakaoTalk_File);
    
    // 바로 종료 안되게 의미없는 Input 받기
    int trash_input_for_wait;
    cout << "종료하려면 아무 문자나 입력 후 엔터를 누르세요.";
    cin >> trash_input_for_wait;

    return 0;
}

int downloadFile(wchar_t* downloadFolderPath, const char* Name, const wchar_t* URL, const wchar_t* FileName)
{
    wcscat(downloadFolderPath, FileName);

    if ((_access(ConvertWCtoC(downloadFolderPath), 0) != -1))  // 파일 존재 여부 체크
    {
        cout << "파일이 이미 존재합니다. (" << Name << ")" << endl;
        return 0;
    }
    else
        cout << "설치할 경로: " << ConvertWCtoC(downloadFolderPath) << endl;
    
    HRESULT hr = NULL;
    hr = URLDownloadToFile(NULL, L"https://app-pc.kakaocdn.net/talk/win32/KakaoTalk_Setup.exe", L"C:\\Users\\jhssong\\Desktop\\InitWindows\\KaKaoTalk.exe", 0, NULL);
    
    if (hr == S_OK) {
        cout << "파일 다운로드 중...  ";
        
        // 진짜 설치됐는지 확인
        if ((_access(ConvertWCtoC(downloadFolderPath), 0) != -1))  // 파일 존재 여부 체크
        {
            cout << "파일 다운로드 완료. (" << Name << ")" << endl;
            return 0;
        }
        else
            cout << "알 수 없는 에러 (" << Name << ")" << endl;
        return 0;
    }
    else if (hr == E_OUTOFMEMORY) {
        cout << "파일 다운로드 실패! (" << Name << ") - 메모리 부족" << endl;
        return 1;
    }
    else if (hr == INET_E_DOWNLOAD_FAILURE) {
        cout << "파일 다운로드 실패! (" << Name << ") - 파일을 찾을 수 없음" << endl;
        return 1;
    }
    else {
        cout << "파일 다운로드 실패! (" << Name << ") - 알수 없는 오류" << endl;
        return 1;
    }
}