// To Do List
// 1. 강사님 코드 전부 구현
//    - main의 쓸모 없는 코드 삭제
//    - 필터 정리
//    - 미리 컴파일 된 헤더 만들기 > pch.h
//        만드는 이유? 헤더의 몸집이 커질수록 컴파일 시간이 늘어나는데
//        미리 컴파일 된 헤더를 만들어서 몸집이 큰 긴소스를 컴파일 시간에서 제외하면 속도를 올리는데 도움이 됨.
//        해당 파일을 가장 위에 include해줘야 함
//    - 엔진 구현
//        엔진은 단 하나여야하기 때문에 싱글턴으로 구현
//        싱글턴 함수는 매크로로 구현하여 이후에 매니져들을 싱글턴 매크로를 호출하면 완성시킬 수 있도록 구현
//        1차 커밋 목표 : 매크로 구현하기 전에 엔진 클래스 구현해보기
//        
#include "pch.h"
#include "framework.h"
#include "Client.h"
#include "CEngine.h"


// 전역 변수:
HINSTANCE hInst = 0;
HWND myHwnd = 0;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

INT_PTR CALLBACK CreateTileProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }


    // 단축키 테이블 참조
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CLIENT));
    MSG msg;

    CEngine::GetInst()->init(myHwnd, POINT{1600, 900});

    // getMessage의 경우 메세지가 들어오지 않으면 리턴값을 주지 않기 때문에 메세지가 들어오지 않으면 함수가 종료되지 않아 while 조건 부분에서 무한루프를 돌게됨
    // 그러므로 메세지를 주지 않을 경우에도 리턴값을 주는 PeekMessage를 이용해 구현할 것임
    // 있으면 true, 없으면 false를 반환
    // 마지막 인자인 PM_REMOVE는 메세지큐에서 해당 메세지를 삭제한다는 매크로 함수임
    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            
            // 메세지가 WM_QUIT 일 경우(게임 창 종료)
            // while문 루프 깨지면서 종료
            if (WM_QUIT == msg.message)
                break;

            // 단축키 조합이 눌렸는지 확인
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                // 메세지 처리
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }

        // 메세지가 없을 경우
        else
        {
            CEngine::GetInst()->tick();
        }
    }


    return (int) msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CLIENT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;// MAKEINTRESOURCEW(IDC_CLIENT);
    wcex.lpszClassName  = L"MyWindow";
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장

   // 윈도우 생성 후 핸들값을 반환한다.
   myHwnd = CreateWindowW(L"MyWindow", L"MyGame", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!myHwnd)
   {
      return FALSE;
   }

   ShowWindow(myHwnd, nCmdShow);
   UpdateWindow(myHwnd);

   return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            // LOWORD(x좌표)
            // HIWORD(y좌표)
            int wmId = LOWORD(wParam);
            int returnValue = 0;
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
            {
                returnValue = DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            }
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case ID_CREATE_TILE:
                returnValue = DialogBox(hInst, MAKEINTRESOURCE(IDD_CREATE_TILE), hWnd, CreateTileProc);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
