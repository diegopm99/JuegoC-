#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>

//posicionar el cursor en la consola
void gotoxy(int x, int y) {
    HANDLE posicion = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordenadas;
    coordenadas.X = x;
    coordenadas.Y = y;
    SetConsoleCursorPosition(posicion, coordenadas);
}

//dibujar el personaje en la consola
void dibujarPersonaje(int x, int y) {
    gotoxy(x, y);     printf("%c%c%c%c%c%c%c%c\n", 32, 32, 32, 32, 32, 47, 32, 92);
    gotoxy(x, y + 1); printf("%c%c%c%c%c%c%c%c%c\n", 32, 32, 32, 32, 47, 40, 32, 41, 92);
    gotoxy(x, y + 2); printf("%c%c%c%c%c%c%c%c%c%c\n", 32, 32, 32, 40, 32, 94, 95, 94, 32, 41);
    gotoxy(x, y + 3); printf("%c%c%c%c%c%c%c%c%c%c%c%c\n", 32, 92, 32, 95, 95, 95, 95, 95, 95, 95, 95, 47);
    gotoxy(x, y + 4); printf("%c%c%c%c%c%c%c%c%c%c%c\n", 32, 32, 92, 40, 95, 41, 32, 40, 95, 41, 47);
    gotoxy(x, y + 5); printf("%c%c%c%c%c%c%c%c%c%c\n", 32, 32, 32, 92, 95, 95, 95, 95, 95, 47);
}

//borrar el personaje de la consola
void borrarPersonaje(int x, int y) {
    gotoxy(x, y);     printf("        ");
    gotoxy(x, y + 1); printf("         ");
    gotoxy(x, y + 2); printf("          ");
    gotoxy(x, y + 3); printf("            ");
    gotoxy(x, y + 4); printf("           ");
    gotoxy(x, y + 5); printf("          ");
}
//ocultar el cursor en la consola
void ocultarCursor() {
    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO infoCursor;
    infoCursor.dwSize = 100;
    infoCursor.bVisible = FALSE;
    SetConsoleCursorInfo(consola, &infoCursor);
}

int main() {
    //ocultar el cursor
    ocultarCursor();

    //dibuja los bordes
    for (int i = 0; i < 119; i++) {
        gotoxy(i, 0); printf("*");
    }
    for (int i = 0; i < 119; i++) {
        gotoxy(i, 19); printf("*");
    }
    for (int j = 0; j < 20; j++) {
        gotoxy(0, j); printf("*");
    }
    for (int j = 0; j < 20; j++) {
        gotoxy(119, j); printf("*");
    }

    int x = 10, y = 10;
    dibujarPersonaje(x, y);

    bool fin_juego = false;
    while (!fin_juego) {
        if (_kbhit()) {
            char tecla = _getch();
            borrarPersonaje(x, y);
            if (tecla == 'a' && x > 1) x--;
            if (tecla == 'd' && x < 105) x++;
            if (tecla == 'w' && y > 1) y--;
            if (tecla == 's' && y < 13) y++;
            dibujarPersonaje(x, y);
        }
    }

    return 0;
}