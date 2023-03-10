#include "make_folder.h"

wchar_t* makeFolder()
{
    cout << "다운로드 폴더 경로 생성 중...  ";

    wchar_t* downloadFolderPath = NULL;
    SHGetKnownFolderPath(FOLDERID_Desktop, 0, NULL, &downloadFolderPath);

    const wchar_t* folderName = L"\\InitWindows";
    wcscat(downloadFolderPath, folderName);

    cout << "생성 완료!" << endl;

    cout << "해당 경로에 폴더가 이미 존재하는지 확인 중...  ";

    int isFolderExists;
    if ((_waccess(downloadFolderPath, 0) != -1))  // 폴더 존재 여부 체크
    {
        cout << "폴더가 이미 존재함!" << endl;
        isFolderExists = 0;
    }
    else 
    {
        cout << "폴더가 존재하지 않음!" << endl;
        isFolderExists = 1;
    }

    // 폴더가 존재하지 않으면 생성
    if (isFolderExists == 1)
    {
        cout << "폴더 생성 중...  ";

        BOOL res = CreateDirectory(downloadFolderPath, NULL);

        if (res == TRUE) {
            cout << "생성 완료!" << endl;
        }
        else {
            cout << "생성 실패!" << endl;
            return NULL;
        }
    }

    return downloadFolderPath;
}