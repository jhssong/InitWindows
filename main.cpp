#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "make_folder.h"

// ��ΰ� �̹� �����ϴ��� Ȯ���ϱ� ���� �������
#include <io.h>

// ������ �ٿ�ޱ� ���� �������
#include <urlmon.h>
#pragma comment(lib,"urlmon.lib")

// char* <-> wchar_t* ����ȯ�� ���� �������
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

    // TODO: �ٿ�ε� ����� �ٸ� ���Ͽ��� �ҷ�����
    const char* KakaoTalk_Name = "KakaoTalk";
    const wchar_t* KakaoTalk_URL = L"https://app-pc.kakaocdn.net/talk/win32/KakaoTalk_Setup.exe";
    const wchar_t* KakaoTalk_File = L"\\KaKaoTalk.exe";
    
    // ���� �ٿ�ε� �ϱ�
	downloadFile(downloadFolderPath, KakaoTalk_Name, KakaoTalk_URL, KakaoTalk_File);
    
    // �ٷ� ���� �ȵǰ� �ǹ̾��� Input �ޱ�
    int trash_input_for_wait;
    cout << "�����Ϸ��� �ƹ� ���ڳ� �Է� �� ���͸� ��������.";
    cin >> trash_input_for_wait;

    return 0;
}

int downloadFile(wchar_t* downloadFolderPath, const char* Name, const wchar_t* URL, const wchar_t* FileName)
{
    wcscat(downloadFolderPath, FileName);

    if ((_access(ConvertWCtoC(downloadFolderPath), 0) != -1))  // ���� ���� ���� üũ
    {
        cout << "������ �̹� �����մϴ�. (" << Name << ")" << endl;
        return 0;
    }
    else
        cout << "��ġ�� ���: " << ConvertWCtoC(downloadFolderPath) << endl;
    
    HRESULT hr = NULL;
    hr = URLDownloadToFile(NULL, L"https://app-pc.kakaocdn.net/talk/win32/KakaoTalk_Setup.exe", L"C:\\Users\\jhssong\\Desktop\\InitWindows\\KaKaoTalk.exe", 0, NULL);
    
    if (hr == S_OK) {
        cout << "���� �ٿ�ε� ��...  ";
        
        // ��¥ ��ġ�ƴ��� Ȯ��
        if ((_access(ConvertWCtoC(downloadFolderPath), 0) != -1))  // ���� ���� ���� üũ
        {
            cout << "���� �ٿ�ε� �Ϸ�. (" << Name << ")" << endl;
            return 0;
        }
        else
            cout << "�� �� ���� ���� (" << Name << ")" << endl;
        return 0;
    }
    else if (hr == E_OUTOFMEMORY) {
        cout << "���� �ٿ�ε� ����! (" << Name << ") - �޸� ����" << endl;
        return 1;
    }
    else if (hr == INET_E_DOWNLOAD_FAILURE) {
        cout << "���� �ٿ�ε� ����! (" << Name << ") - ������ ã�� �� ����" << endl;
        return 1;
    }
    else {
        cout << "���� �ٿ�ε� ����! (" << Name << ") - �˼� ���� ����" << endl;
        return 1;
    }
}