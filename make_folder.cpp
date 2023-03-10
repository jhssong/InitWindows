#include "make_folder.h"

wchar_t* makeFolder()
{
    cout << "�ٿ�ε� ���� ��� ���� ��...  ";

    wchar_t* downloadFolderPath = NULL;
    SHGetKnownFolderPath(FOLDERID_Desktop, 0, NULL, &downloadFolderPath);

    const wchar_t* folderName = L"\\InitWindows";
    wcscat(downloadFolderPath, folderName);

    cout << "���� �Ϸ�!" << endl;

    cout << "�ش� ��ο� ������ �̹� �����ϴ��� Ȯ�� ��...  ";

    int isFolderExists;
    if ((_waccess(downloadFolderPath, 0) != -1))  // ���� ���� ���� üũ
    {
        cout << "������ �̹� ������!" << endl;
        isFolderExists = 0;
    }
    else 
    {
        cout << "������ �������� ����!" << endl;
        isFolderExists = 1;
    }

    // ������ �������� ������ ����
    if (isFolderExists == 1)
    {
        cout << "���� ���� ��...  ";

        BOOL res = CreateDirectory(downloadFolderPath, NULL);

        if (res == TRUE) {
            cout << "���� �Ϸ�!" << endl;
        }
        else {
            cout << "���� ����!" << endl;
            return NULL;
        }
    }

    return downloadFolderPath;
}