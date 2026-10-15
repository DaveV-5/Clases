// Realice un programa que permita hacer conversiones entre unidades de longitud, masa y tiempo. considere las mas usadas. valide la entrada por teclado y considere las restricciones del ultimo ejercicio. Importante: El usuario debe ser capaz de seleccionar las unidades que desea converti

#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

// Función para colores llamativos y modernos en la consola de Windows
void cambiarColor(int color) {
    #ifdef _WIN32
    switch(color) {
        case 1: cout << "\033[1;36m"; break; // Cian brillante (Títulos principales)
        case 2: cout << "\033[1;32m"; break; // Verde brillante (Resultados exitosos)
        case 3: cout << "\033[1;33m"; break; // Amarillo brillante (Prompts y selección)
        case 4: cout << "\033[1;31m"; break; // Rojo brillante (Errores)
        case 5: cout << "\033[1;35m"; break; // Magenta brillante (Subtítulos/Categorías)
        case 7: cout << "\033[0;37m"; break; // Texto normal
        default: cout << "\033[0m"; break;
    }
    #endif
}

// Función para validar entradas enteras centradas
int obtenerOpcion(int minVal, int maxVal) {
    int opcion;
    while (true) {
        cambiarColor(3);
        cout << "               Seleccione una opcion: ";
        if (cin >> opcion) {
            if (opcion >= minVal && opcion <= maxVal) {
                return opcion;
            } else {
                cambiarColor(4);
                cout << "               [Error] Ingrese un numero entre " << minVal << " y " << maxVal << ".\n";
            }
        } else {
            cambiarColor(4);
            cout << "               [Error] Entrada invalida. Ingrese un numero entero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Función para validar valores numéricos (con opción de permitir negativos solo para temperatura)
double obtenerValorNumerico(bool permitirNegativos = false) {
    double valor;
    while (true) {
        cambiarColor(3);
        cout << "               Ingrese el valor a convertir: ";
        if (cin >> valor) {
            if (!permitirNegativos && valor < 0) {
                cambiarColor(4);
                cout << "               [Error] El valor no puede ser negativo para esta magnitud.\n";
                continue;
            }
            return valor;
        } else {
            cambiarColor(4);
            cout << "               [Error] Entrada invalida. Ingrese un numero valido.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Pregunta de continuidad (s/n)
bool preguntarContinuar() {
    char respuesta;
    while (true) {
        cambiarColor(5);
        cout << "\n               Desea realizar otra conversion? (s/n): ";
        cin >> respuesta;
        if (respuesta == 's' || respuesta == 'S') {
            return true;
        } else if (respuesta == 'n' || respuesta == 'N') {
            return false;
        } else {
            cambiarColor(4);
            cout << "               [Error] Ingrese unicamente 's' o 'n'.\n";
        }
    }
}

void convertirLongitud() {
    string nombres[] = {"Metros (m - SI)", "Kilometros (km)", "Centimetros (cm)", "Milimetros (mm)", "Millas (mi)", "Pulgadas (in)", "Pies (ft)"};
    double factores[] = {1.0, 1000.0, 0.01, 0.001, 1609.34, 0.0254, 0.3048};
    int totalUnidades = 7;

    do {
        system("cls");
        cambiarColor(1);
        cout << "\n\n";
        cout << "        ================================================\n";
        cout << "                   CONVERSION DE LONGITUD               \n";
        cout << "        ================================================\n";
        
        cambiarColor(7);
        for (int i = 0; i < totalUnidades; i++) {
            cout << "          [" << i + 1 << "] " << nombres[i] << "\n";
        }
        cambiarColor(1);
        cout << "        ------------------------------------------------\n";
        
        cambiarColor(5);
        cout << "          Unidad de origen:\n";
        int origen = obtenerOpcion(1, totalUnidades) - 1;

        cout << "          Unidad de destino:\n";
        int destino = obtenerOpcion(1, totalUnidades) - 1;
        
        cambiarColor(1);
        cout << "        ------------------------------------------------\n";

        double valor = obtenerValorNumerico(false);

        double valorEnMetros = valor * factores[origen];
        double resultado = valorEnMetros / factores[destino];

        cambiarColor(2);
        cout << "\n        [RESULTADO EXITOSO]:\n";
        cout << "          " << valor << " " << nombres[origen] << "\n";
        cout << "          EQUIVALEN A: " << resultado << " " << nombres[destino] << "\n";
        cambiarColor(7);

    } while (preguntarContinuar());
}

void convertirMasa() {
    string nombres[] = {"Kilogramos (kg - SI)", "Gramos (g)", "Miligramos (mg)", "Toneladas (t)", "Libras (lb)", "Onzas (oz)"};
    double factores[] = {1.0, 0.001, 0.000001, 1000.0, 0.453592, 0.0283495};
    int totalUnidades = 6;

    do {
        system("cls");
        cambiarColor(1);
        cout << "\n\n";
        cout << "        ================================================\n";
        cout << "                    CONVERSION DE MASA                  \n";
        cout << "        ================================================\n";
        
        cambiarColor(7);
        for (int i = 0; i < totalUnidades; i++) {
            cout << "          [" << i + 1 << "] " << nombres[i] << "\n";
        }
        cambiarColor(1);
        cout << "        ------------------------------------------------\n";
        
        cambiarColor(5);
        cout << "          Unidad de origen:\n";
        int origen = obtenerOpcion(1, totalUnidades) - 1;

        cout << "          Unidad de destino:\n";
        int destino = obtenerOpcion(1, totalUnidades) - 1;
        
        cambiarColor(1);
        cout << "        ------------------------------------------------\n";

        double valor = obtenerValorNumerico(false);

        double valorEnKg = valor * factores[origen];
        double resultado = valorEnKg / factores[destino];

        cambiarColor(2);
        cout << "\n        [RESULTADO EXITOSO]:\n";
        cout << "          " << valor << " " << nombres[origen] << "\n";
        cout << "          EQUIVALEN A: " << resultado << " " << nombres[destino] << "\n";
        cambiarColor(7);

    } while (preguntarContinuar());
}

void convertirTiempo() {
    string nombres[] = {"Segundos (s - SI)", "Milisegundos (ms)", "Minutos (min)", "Horas (h)", "Dias (d)"};
    double factores[] = {1.0, 0.001, 60.0, 3600.0, 86400.0};
    int totalUnidades = 5;

    do {
        system("cls");
        cambiarColor(1);
        cout << "\n\n";
        cout << "        ================================================\n";
        cout << "                   CONVERSION DE TIEMPO                 \n";
        cout << "        ================================================\n";
        
        cambiarColor(7);
        for (int i = 0; i < totalUnidades; i++) {
            cout << "          [" << i + 1 << "] " << nombres[i] << "\n";
        }
        cambiarColor(1);
        cout << "        ------------------------------------------------\n";
        
        cambiarColor(5);
        cout << "          Unidad de origen:\n";
        int origen = obtenerOpcion(1, totalUnidades) - 1;

        cout << "          Unidad de destino:\n";
        int destino = obtenerOpcion(1, totalUnidades) - 1;
        
        cambiarColor(1);
        cout << "        ------------------------------------------------\n";

        double valor = obtenerValorNumerico(false);

        double valorEnSegundos = valor * factores[origen];
        double resultado = valorEnSegundos / factores[destino];

        cambiarColor(2);
        cout << "\n        [RESULTADO EXITOSO]:\n";
        cout << "          " << valor << " " << nombres[origen] << "\n";
        cout << "          EQUIVALEN A: " << resultado << " " << nombres[destino] << "\n";
        cambiarColor(7);

    } while (preguntarContinuar());
}

void convertirTemperatura() {
    string nombres[] = {"Celsius (C - SI)", "Fahrenheit (F)", "Kelvin (K)"};
    int totalUnidades = 3;

    do {
        system("cls");
        cambiarColor(1);
        cout << "\n\n";
        cout << "        ================================================\n";
        cout << "                 CONVERSION DE TEMPERATURA              \n";
        cout << "        ================================================\n";
        
        cambiarColor(7);
        for (int i = 0; i < totalUnidades; i++) {
            cout << "          [" << i + 1 << "] " << nombres[i] << "\n";
        }
        cambiarColor(1);
        cout << "        ------------------------------------------------\n";
        
        cambiarColor(5);
        cout << "          Unidad de origen:\n";
        int origen = obtenerOpcion(1, totalUnidades) - 1;

        cout << "          Unidad de destino:\n";
        int destino = obtenerOpcion(1, totalUnidades) - 1;
        
        cambiarColor(1);
        cout << "        ------------------------------------------------\n";

        // La temperatura permite valores negativos
        double valor = obtenerValorNumerico(true);

        // Convertir origen a Celsius como base de temperatura
        double enCelsius = 0.0;
        if (origen == 0) enCelsius = valor;                                 // Celsius
        else if (origen == 1) enCelsius = (valor - 32.0) * 5.0 / 9.0;       // Fahrenheit a Celsius
        else if (origen == 2) enCelsius = valor - 273.15;                   // Kelvin a Celsius

        // Convertir Celsius a la unidad de destino
        double resultado = 0.0;
        if (destino == 0) resultado = enCelsius;                            // A Celsius
        else if (destino == 1) resultado = enCelsius * 9.0 / 5.0 + 32.0;    // A Fahrenheit
        else if (destino == 2) resultado = enCelsius + 273.15;              // A Kelvin

        cambiarColor(2);
        cout << "\n        [RESULTADO EXITOSO]:\n";
        cout << "          " << valor << " " << nombres[origen] << "\n";
        cout << "          EQUIVALEN A: " << resultado << " " << nombres[destino] << "\n";
        cambiarColor(7);

    } while (preguntarContinuar());
}

int main() {
    int opcion;
    do {
        system("cls");
        cambiarColor(1);
        cout << "\n\n";
        cout << "        ================================================\n";
        cout << "                 SISTEMA DE CONVERSION DE UNIDADES      \n";
        cout << "        ================================================\n";
        
        cambiarColor(7);
        cout << "          [1] Longitud\n";
        cout << "          [2] Masa\n";
        cout << "          [3] Tiempo\n";
        cout << "          [4] Temperatura\n";
        cout << "          [5] Salir\n";
        cambiarColor(1);
        cout << "        ------------------------------------------------\n";
        
        cambiarColor(5);
        opcion = obtenerOpcion(1, 5);

        switch (opcion) {
            case 1:
                convertirLongitud();
                break;
            case 2:
                convertirMasa();
                break;
            case 3:
                convertirTiempo();
                break;
            case 4:
                convertirTemperatura();
                break;
            case 5:
                system("cls");
                cambiarColor(2);
                cout << "\n\n";
                cout << "        ================================================\n";
                cout << "            ¡GRACIAS POR USAR EL CONVERSOR! HASTA PRONTO\n";
                cout << "        ================================================\n\n";
                cambiarColor(7);
                break;
        }
    } while (opcion != 5);

    return 0;
}
