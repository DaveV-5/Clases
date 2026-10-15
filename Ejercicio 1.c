// Realice un programa que permita simular una ruleta de opciones y que el usuario pueda elegir entre dos opciones, tres opciones, cuatro o diez. Todas las opciones deben ser ingresadas y validadas por teclado, las opciones pueden ser palabras, numeros o simbolos especiales. No puede usar funciones de estructuras, arreglos bidimensionales, punteros o listas, una vez listo su ejercicio, subalo a su repositorio, con una pequena descripcion

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Función para cambiar el color del texto en la consola de Windows
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Función para imprimir texto centrado (ancho estimado de 80 columnas)
void imprimirCentrado(const char *texto) {
    int ancho_pantalla = 80;
    int longitud = 0;
    int i;
    int espacios; // Declarado al inicio por compatibilidad C89
    
    while (texto[longitud] != '\0') {
        longitud++;
    }
    espacios = (ancho_pantalla - longitud) / 2;
    if (espacios < 0) espacios = 0;
    
    for (i = 0; i < espacios; i++) {
        printf(" ");
    }
    printf("%s\n", texto);
}

// Función para imprimir espacios de centrado sin salto de línea
void espaciosCentro(int cantidad) {
    int i;
    for (i = 0; i < cantidad; i++) {
        printf(" ");
    }
}

int main() {
    // Declaración de todas las variables al inicio de la función (Obligatorio para Dev-C++)
    int n, opcion_ganadora;
    char repetir;
    char o1[100], o2[100], o3[100], o4[100], o5[100];
    char o6[100], o7[100], o8[100], o9[100], o10[100];
    char ganadora[100];

    // Inicializar la semilla para números aleatorios una sola vez
    srand(time(NULL));

    do {
        system("cls"); // Limpiar pantalla

        setColor(11); // Cian
        imprimirCentrado("==================================================");
        imprimirCentrado("               SIMULADOR DE RULETA                ");
        imprimirCentrado("==================================================");
        setColor(7);  // Blanco

        // Validación por teclado de la cantidad de opciones (2, 3, 4 o 10)
        do {
            printf("\n");
            espaciosCentro(18);
            printf("Ingrese cantidad de opciones (2, 3, 4 o 10): ");
            if (scanf("%d", &n) != 1) {
                setColor(12); // Rojo
                printf("\n");
                imprimirCentrado("Error: Debe ingresar un numero entero valido.");
                setColor(7);
                while(getchar() != '\n'); 
                n = 0;
            } else if (n != 2 && n != 3 && n != 4 && n != 10) {
                setColor(12);
                printf("\n");
                imprimirCentrado("Error: Opcion no permitida (Elija 2, 3, 4 o 10).");
                setColor(7);
            }
        } while (n != 2 && n != 3 && n != 4 && n != 10);

        // Ingreso de opciones por teclado alineado al centro
        setColor(14); // Amarillo
        printf("\n");
        imprimirCentrado("--- INGRESE LOS VALORES PARA CADA OPCION ---");
        setColor(7);
        printf("\n");

        if (n >= 1) { espaciosCentro(30); printf("Opcion 1: "); scanf("%s", o1); }
        if (n >= 2) { espaciosCentro(30); printf("Opcion 2: "); scanf("%s", o2); }
        if (n >= 3) { espaciosCentro(30); printf("Opcion 3: "); scanf("%s", o3); }
        if (n >= 4) { espaciosCentro(30); printf("Opcion 4: "); scanf("%s", o4); }
        
        if (n == 10) {
            espaciosCentro(30); printf("Opcion 5: "); scanf("%s", o5);
            espaciosCentro(30); printf("Opcion 6: "); scanf("%s", o6);
            espaciosCentro(30); printf("Opcion 7: "); scanf("%s", o7);
            espaciosCentro(30); printf("Opcion 8: "); scanf("%s", o8);
            espaciosCentro(30); printf("Opcion 9: "); scanf("%s", o9);
            espaciosCentro(30); printf("Opcion 10: "); scanf("%s", o10);
        }

        // Generar un número aleatorio entre 1 y n
        opcion_ganadora = rand() % n + 1;

        // Simulación del giro centrada
        setColor(13); // Magenta
        printf("\n\n");
        imprimirCentrado("Girando la ruleta...");
        Sleep(1000); // Pausa visual de 1 segundo
        
        // Mostrar la opción ganadora con diseño centrado
        setColor(10); // Verde brillante
        printf("\n");
        imprimirCentrado("==================================================");
        imprimirCentrado("             ¡EL RESULTADO GANADOR ES!            ");
        imprimirCentrado("==================================================");
        
        // Seleccionamos el texto ganador según corresponda
        switch (opcion_ganadora) {
            case 1: sprintf(ganadora, "==> [ %s ] <==", o1); break;
            case 2: sprintf(ganadora, "==> [ %s ] <==", o2); break;
            case 3: sprintf(ganadora, "==> [ %s ] <==", o3); break;
            case 4: sprintf(ganadora, "==> [ %s ] <==", o4); break;
            case 5: sprintf(ganadora, "==> [ %s ] <==", o5); break;
            case 6: sprintf(ganadora, "==> [ %s ] <==", o6); break;
            case 7: sprintf(ganadora, "==> [ %s ] <==", o7); break;
            case 8: sprintf(ganadora, "==> [ %s ] <==", o8); break;
            case 9: sprintf(ganadora, "==> [ %s ] <==", o9); break;
            case 10: sprintf(ganadora, "==> [ %s ] <==", o10); break;
        }
        
        printf("\n");
        imprimirCentrado(ganadora);
        printf("\n");
        
        setColor(7); // Restaurar blanco

        // Preguntar si desea volver a usar el programa
        printf("\n");
        espaciosCentro(20);
        printf("¿Desea volver a utilizar la ruleta? (s/n): ");
        scanf(" %c", &repetir);

    } while (repetir == 's' || repetir == 'S');

    system("cls");
    setColor(11);
    printf("\n\n\n");
    imprimirCentrado("¡Gracias por usar el simulador de ruleta!");
    imprimirCentrado("¡Hasta luego!");
    printf("\n\n");
    setColor(7);
    
    return 0;
}
