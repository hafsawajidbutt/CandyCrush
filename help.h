#pragma 

#include <cmath>  // Include cmath for mathematical operations
#include <windows.h>

// Move cursor to specified coordinates (x, y) on console
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Draw a line from (x1, y1) to (x2, y2) with specified color
void myLine(int x1, int y1, int x2, int y2, int color)
{
    HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    // Set pen color using specified color value (for grayscale)
    HPEN pen = CreatePen(PS_SOLID, 2, RGB(color, color, color));
    SelectObject(device_context, pen);

    // Draw the line
    MoveToEx(device_context, x1, y1, NULL);
    LineTo(device_context, x2, y2);

    // Release device context and clean up resources
    ReleaseDC(console_handle, device_context);
    DeleteObject(pen);
}

// Check if any cursor key is pressed and identify which key
bool isCursorKeyPressed(int& whichKey)
{
    short key;
    key = GetAsyncKeyState(VK_LEFT);
    if (key & 0x8000)
    {
        whichKey = 1;   // Left key is pressed
        return true;
    }
    key = GetAsyncKeyState(VK_UP);
    if (key & 0x8000)
    {
        whichKey = 2;   // Up key is pressed
        return true;
    }
    key = GetAsyncKeyState(VK_RIGHT);
    if (key & 0x8000)
    {
        whichKey = 3;   // Right key is pressed
        return true;
    }
    key = GetAsyncKeyState(VK_DOWN);
    if (key & 0x8000)
    {
        whichKey = 4;   // Down key is pressed
        return true;
    }
    return false;
}

// Draw a rectangle with specified coordinates, outline color, and fill color
int myRectangle(int x1, int y1, int x2, int y2, int R, int G, int B, int R1, int G1, int B1)
{
    HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    // Set pen color for outline using specified RGB values
    HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
    SelectObject(device_context, pen);

    // Set brush color for filling using specified RGB values
    HBRUSH brush = ::CreateSolidBrush(RGB(R1, G1, B1));
    SelectObject(device_context, brush);

    // Draw the rectangle
    Rectangle(device_context, x1, y1, x2, y2);

    // Release device context and clean up resources
    ReleaseDC(console_handle, device_context);
    DeleteObject(pen);
    DeleteObject(brush);
    return 0;
}

// Draw an ellipse with specified coordinates and color
void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B)
{
    HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    // Set pen color using specified RGB values
    HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
    SelectObject(device_context, pen);

    // Set brush color to fill ellipse (using pen color)
    HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B));
    SelectObject(device_context, brush);

    // Draw the ellipse
    Ellipse(device_context, x1, y1, x2, y2);

    // Release device context and clean up resources
    ReleaseDC(console_handle, device_context);
    DeleteObject(pen);
    DeleteObject(brush);
}



// Draw a triangle with vertices (x1, y1), (x2, y2), (x3, y3) and specified color
void myTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int R, int G, int B)
{
    HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    // Set pen color using RGB values
    HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
    SelectObject(device_context, pen);

    // Draw lines to form a triangle
    MoveToEx(device_context, x1, y1, NULL);
    LineTo(device_context, x2, y2);
    LineTo(device_context, x3, y3);
    LineTo(device_context, x1, y1);

    // Release device context and clean up resources
    ReleaseDC(console_handle, device_context);
    DeleteObject(pen);
}

