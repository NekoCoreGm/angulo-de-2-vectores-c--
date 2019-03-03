#include <stdio.h>
#include <math.h>
#include <windows.h>//para travajar con las funciones de windows

//////////////////////////////////////////////////////////

#define PI 3.14159265
/*funciones para convertir grados a radianes y viceversa*/
float degToRad(float x) { return (PI / 180) * x; };
float radToDeg(float x) { return (180 / PI) * x; };

float rad2Deg(float x) { return (x / (2 * PI)) * 360; }
float deg2Rad(float x) { return (x * (2 * PI)) / 360; }

float rad3Deg(float x) { return (x * PI) * 180; }
float deg3Rad(float x) { return (x * 180) / PI; }
/*------------------------------------------------------*/

//la fuente de los vectores
struct vector
{ float x;float y; };

float angle(vector a, vector b)//la función para obtener el angulo
{ return atan2(a.y-b.y, a.x-b.x)+PI; }

//////////////////////////////////////////////////////////

int main()
{
    int pWidth = GetSystemMetrics(SM_CXSCREEN);//obtener el ancho de la pantalla
    int pHeight = GetSystemMetrics(SM_CYSCREEN);//obtener el alto de la pantalla
    vector p;//este vector sera nuestro eje
    p.x = pWidth/2;
    p.y = pHeight/2;
    vector m;//este vector sera del cual obtendremos el angulo
    m.x = 0;
    m.y = 0;


    POINT point;
    while(!GetAsyncKeyState(VK_F8))
    {

        if(GetCursorPos(&point))
        {
                m.x = point.x;
                m.y = point.y;
        }
        printf
        (
            "|%f|-|%f_%f|-|%f_%f|\n",
            radToDeg(angle(m, p)),
            m.x,//cordenadas del mouse
            m.y,//---/
            p.x,//cordenadaa del centro de la pantalla
            p.y//---/
        );

        Sleep(100);

    }
    return 0;
}
