// Client.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#include "pch.h"
#include "framework.h"
#include "Client.h"

#include "CEngine.h"


// 전역 변수:
HINSTANCE   hInst = 0;  // 현재 인스턴스입니다.
HWND        g_hWnd = 0; // int 하나 들고있는 구조체, 더 쉽게는 int 자료형 변수.  핸들 값을 받아오는 전역 변수, 함수 종료 시에도 데이터가 들어있을 수 있도록 밖으로 빼줌

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine, // 쓸모 없다
                     _In_ int       nCmdShow) // 쓸모 없다
{
    // 함수 내에서 창에 대한 정보를 받아와서 이 정보를 기반으로 윈도우 생성
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow)) // HWND에 핸들 값(ID값)을 받아오고, MyRegisterClass()에서 설정한 정보를 기반으로 윈도우 생성
    {
        return FALSE;
    }



    // 엔진 초기화
    CEngine::GetInst()->init(g_hWnd, POINT{1600, 900});
   
    
    
    // 단축 키 테이블 정보를 가지고 옴
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CLIENT)); 

    // 메시지를 담는 msg 객체
    MSG msg;

    while (true) 
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) // 큐에서 메세지를 지우지 않아서 계속 돌게 됨...
        {
            // get에서 할 수 없었던 지속적인 함수 확인이 가능
            if (WM_QUIT == msg.message)
            {
                break;
            }
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) // 만약 메시지가 가져온 단축 키 조합인지 확인
            {
                TranslateMessage(&msg); // 메시지 정보를 분석해서 발생한 윈도우에서의 처리 함수를 그 윈도우 전용으로 만들어진 그 함수를 호출
                DispatchMessage(&msg);  // 
            }



        }
        else // 만약 메세지가 없었다면
        {
            // 사실 상 대부분이 메세지가 없으니까 없는 경우 이 안 쪽 구문을 실행하고, 이 쪽에 게임 구문을 작성하면 된다.
            // 굳이 WM_TIMER를 사용하지 않아도 된다는 뜻이다.
            // 여기에 이 구조 한 번 만들어놓고 메세지 관련 기능은 쓸 일이 없어진다.
            CEngine::GetInst()->tick(); // 1 프레임 실행

        }
    } // 이 while문이 끝나면 창이 닫히며 종료

    // 프로세스 종료 시 창이 닫히며 종료
    // 창이 종료된다고 해서 프로세스가 무조건 종료되는 것이 아님
     
    
    // 타이머를 없애라
    //KillTimer(g_hWnd, TimerID);

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc; // 나한테 처리할 일이 생기면 이 함수를 호출시켜라 하면서 이 함수의 주소를 넘겨줌
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CLIENT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;//MAKEINTRESOURCEW(IDC_CLIENT); // 메뉴를 사용하지 않음
    wcex.lpszClassName  = L"MyWindow";
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   /* WS_OVERLAPPEDWINDOW => 비트 단위마다 상태를 넣고, 상태를 한 번에 받아가므로 어떤 윈도우를 만들 지 정수 하나로 알 수 있다.
   WS_OVERLAPPED     |
   WS_CAPTION        |
   WS_SYSMENU        |
   WS_THICKFRAME     |
   WS_MINIMIZEBOX    |
   WS_MAXIMIZEBOX
   */


   // 윈도우 생성 후 핸들 값 반환 (윈도우에 대한 ID 값을 받아온다고 생각하기)
   g_hWnd = CreateWindowW(L"MyWindow", L"MyGame", WS_OVERLAPPEDWINDOW, // 윈도우에서 많이 쓰이는 조합을 비트 단위로 모아놓음
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!g_hWnd)
   {
      return FALSE;
   }

   ShowWindow(g_hWnd, false);
   UpdateWindow(g_hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
// 인자로 핸들 구분, 메시지, 메시지에 따른 추가 인자(키가 눌리면 wParam, 마우스가 눌리면 lParam)

// POINT 자료형은 보통 x y 값을 담을 때 사용


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT: // 창을 최소화 했다가 키면 발생하는 메시지
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
