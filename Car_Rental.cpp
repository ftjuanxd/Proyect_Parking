#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <thread>

using namespace std;

//----------Declaracion Variables----------//

string datosVehiculo[100][10];
string seg;
string tveh;
string kil;
string cost;
int cantKilometrosAndadosArray[100];
int cantVehiculos = 100;
int regisVeh = 0;
int control = 0;
bool ident;

//----------Fin Declaracion Variables----------//

//----------Declaracion de Funciones----------//

//----------Imprension de Datos----------//

void horizontal();
void impVehiculo(int a);
void impSeguro(int a);
void VolMenu();
void ClearScreen();

//----------Base de Datos-- --------//

void guardar();
void cargar();

//----------Conversion o Verificacion de Datos--------------------//

string toLowerCase(const string &input);
bool is_numeric(const string &str);

//---------Opciones del Usuario-----------//

int menu();
int opcion0();
int opcion1();
int opcion2();
int opcion3();
int opcion4();
int opcion5();
int opcion6();
int opcion7();
int opcion8();
int opcion9();
int opcion10();
int opcion11();
int opcion12();
int opcion13();

//----------Main----------//

int main()
{
    cargar();
    menu();
    return 0;
}

//----------Visuales----------//
void horizontal()
{

    for (int i = 0; i < 28; i++)
    {

        cout << " - *";
    }
}

//------Limpiar Pantalla----//
void ClearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
//------Conversion---Minuscula-----//
string toLowerCase(const string &input)
{
    string result = input;
    for (char &c : result)
    {
        c = std::tolower(c);
    }
    return result;
}
//----------Verificar si es un numero--------------//
bool is_numeric(const string &str)
{
    for (char c : str)
    {
        if (!std::isdigit(c))
        {
            return false;
        }
    }
    return true;
}
//------Volver al menu------//
void VolMenu()
{

    guardar();
    char opc;
    cout << "Desea Volver al Menu(S/N): ";
    cin >> opc;

    if (opc == 'S' || opc == 's')
    {

        ClearScreen();
        menu();
    }
    else
    {

        if (opc == 'N' || opc == 'n')
        {

            opcion13();
        }
        else
        {
            cout << "Error valor no identificado. Intente nuevamente." << endl;
            VolMenu();
        }
    }
}
//----------Fin Visuales----------//

int menu()
{

    int opcionMenu_1;

    horizontal();

    cout<<endl;

    cout << "|" << std::setw(113) << "|\n";

    cout << "|" << std::setw(55) << " MENU" << std::setw(58) << "|\n";

    cout << "|" << std::setw(55) << " Opcion 1: Agregar Vehiculo." << std::setw(58) << "|\n";

    cout << "|" << std::setw(55) << " Opcion 2: Modificar Vehiculo."  <<std::setw(50) <<"          ___________________        " << std::setw(8)<<"|\n";

    cout << "|" << std::setw(55) << " Opcion 3: Eliminar Vehiculo." <<std::setw(51) <<" ____    /                   \\    ____" << std::setw(7)<<"|\n";

    cout << "|" << std::setw(55) << " Opcion 4: Alquilar Vehiculo." << std::setw(51)<<" \\___\\  /                     \\  /___/"<< std::setw(7) << "|\n";

    cout << "|" << std::setw(55) << " Opcion 5: Buscar por Placa." << std::setw(46)<<"      \\/_______________________\\/" << std::setw(12) << "|\n";

    cout << "|" << std::setw(55) << " Opcion 6: Buscar por Categoria." << std::setw(48)<<"      /  ____            ____   \\  " <<std::setw(10) << "|\n";

    cout << "|" << std::setw(55) << " Opcion 7: Buscar por Tipo de Seguro."<< std::setw(46)<<"      | |    |  ______  |    |  |" << std::setw(12) << "|\n";

    cout << "|" << std::setw(55) << " Opcion 8: Buscar por Vehiculos Alquilados." <<std::setw(46) <<"      | |____| |______| |____|  |" <<std::setw(12) << "|\n";

    cout << "|" << std::setw(55) << " Opcion 9: Buscar por Vehiculos Disponibles." <<std::setw(46)<<"      |_________________________|"<< std::setw(12) << "|\n";

    cout << "|" << std::setw(55) << " Opcion 10: Devolver Vehiculo." <<std::setw(46)<<"        |___|            |___|  "<< std::setw(12) << "|\n";

    cout << "|" << std::setw(55) << " Opcion 11: Verificar Ingresos." << std::setw(58) << "|\n";

    cout << "|" << std::setw(55) << " Opcion 12: Ver Cantidad de Vehiculos."<< std::setw(58) << "|\n";

    cout << "|" << std::setw(55) << " Opcion 13: Salir."<< std::setw(58) << "|\n";
    
    cout << "|" << std::setw(113) << "|\n";
    
    horizontal();

    cout<<endl;

    cout << std::setw(15) << " Opcion:";
    cin>>opcionMenu_1;
    
    switch (opcionMenu_1)
    {
    // opcion-1
    case 1:
        opcion1();
        break;
        // opcion-2
    case 2:
        if (opcion2() == 1)
        {
            cout << "EL vehiculo no existe\n";
            break;
        }
        break;
        // opcion-3
    case 3:
        if (opcion3() == 1)
        {
            cout << "EL vehiculo no existe\n";
        }
        break;
        // opcion-4
    case 4:
        if (opcion4() == 1)
        {

            cout << "EL vehiculo no existe\n";
        }
        break;
        // opcion-5
    case 5:
        if (opcion5() == 1)
        {
            cout << "EL vehiculo no existe\n";
        }
        break;
        // opcion-6
    case 6:
        if (opcion6() == 1)
        {
            cout << "No existen vehiculos registrados bajo esta Categoria.\n";
        }
        break;
        // opcion-7
    case 7:
        opcion7();
        break;
        // opcion-8
    case 8:
        if (opcion8() == 1)
        {
            cout << "EL vehiculo no existe\n";
        }
        break;
        // Opcion 9
    case 9:
        opcion9();
        break;
        // Opcion 10
    case 10:
        opcion10();
        break;
        // Opcion 11
    case 11:
        opcion11();
        break;
        // Opcion 12
    case 12:
        opcion12();
        break;
    case 13:
        opcion13();
        break;
    default:
        cout << "\nLa opcion digitada no existe intente nuevamente..\n";
        break;
    }
    VolMenu();
    return 0;
}
//----------Fin Funciones Menu----------//

//----------Funciones Menu----------//

// Imprimir carro
void impVehiculo(int i)
{
    cout << endl
         << endl
         << "---  "
         << "Vehiculo #" << i + 1 << "  ---" << endl;
    cout << "Modelo: "
         << "  --->  " << datosVehiculo[i][9] << endl;
    cout << "Marco: "
         << "  --->  " << datosVehiculo[i][8] << endl;
    cout << "Placa: "
         << "  --->  " << datosVehiculo[i][7] << endl;
    cout << "Kilometraje: "
         << "  --->  " << datosVehiculo[i][0] << endl;
    cout << "Costo Alquiler:"
         << "  --->  " << datosVehiculo[i][1] << endl;
    cout << "Tipo Seguro: "
         << "  --->  " << datosVehiculo[i][2] << endl;
    cout << "Tipo de vehiculo: "
         << "  --->  " << datosVehiculo[i][3] << endl;
    cout << "Cantidad de Kilometros Andados: "
         << "  --->  " << datosVehiculo[i][4] << endl;
    cout << "Estado:"
         << "  --->  " << datosVehiculo[i][6] << endl;
}

// Agregar Vehiculo - Funct #1 ......................
int opcion1()
{
    string newPlaca;
    bool yaExiste = false;
    int aux = 0;
    // Comprobando si la placa existe
    cout << endl
         << endl;
    horizontal();
    cout << endl
         << endl;
    cout << "Agregar placa" << endl;
    cout << "Digite el numero de la placa del vehiculo que desea agregar: ";
    cin >> newPlaca;
    newPlaca = toLowerCase(newPlaca);
    int c = newPlaca.length();
    if (c == 6)
    {
        for (int i = 0; i < cantVehiculos; i++)
        {
            if (datosVehiculo[i][7] == newPlaca)
            {
                yaExiste = true;
                aux = i;
                break; // Termina el bucle cuando se encuentra el dato
            }
        }

        if (yaExiste)
        {
            cout << "El Vehiculo que intenta agregar ya se encuentra registrado..." << endl
                 << "Los datos del vehiculo son: ";
            impVehiculo(aux);
        }
        else
        {
            for (int j = 0; j < cantVehiculos; j++)
            {

                if (datosVehiculo[j][7] == "")
                {

                    // Entrada de datos

                    cout << "El vehiculo no se encuentra agregado, digite la informaciona continuacion para agregarlo correctamente.." << endl;
                    cout << "Digite la marca del vehiculo: ";
                    cin >> datosVehiculo[j][8];
                    cout << "Digite el modelo del vehiculo: ";
                    cin >> datosVehiculo[j][9];
                    cout << "Digite el kilometraje del vehiculo: ";
                    cin >> kil;
                    cout << "Digite el costo de alquiler del vehiculo: ";
                    cin >> cost;
                    cout << "Digite el tipo de seguro del vehiculo: ";
                    cin >> seg;
                    cout << "Digite el tipo de Vehiculo: ";
                    cin >> tveh;

                    // conversion de datos
                    seg = toLowerCase(seg);
                    tveh = toLowerCase(tveh);

                    if (is_numeric(kil))
                    {
                        if (is_numeric(cost))
                        {
                            if (seg == "full" || seg == "soat" || seg == "soat-cs")
                            {
                                if (tveh == "economico" || tveh == "intermedio" || tveh == "ejecutivo")
                                {

                                    // guardado de datos
                                    datosVehiculo[j][0] = kil;
                                    datosVehiculo[j][1] = cost;
                                    datosVehiculo[j][2] = seg;
                                    datosVehiculo[j][3] = tveh;
                                    datosVehiculo[j][7] = toLowerCase(newPlaca);
                                    datosVehiculo[j][6] = "disponible"; // alquiler
                                    datosVehiculo[j][4] = "0";          // cantidad de kilometros andados
                                    datosVehiculo[j][5] = "0";          // ingresosTotales

                                    cout << "Vehiculo Agregado Exitosamente\n";

                                    impVehiculo(j);

                                    return 0;
                                }
                                else
                                {
                                    cout << "El valor digitado en el campo de Tipo de Vehiculo es erroneo. Intentelo Nuevamente." << endl;
                                    std::this_thread::sleep_for(std::chrono::seconds(6));
                                    ClearScreen();
                                    opcion1();
                                    return 0;
                                }
                            }
                            else
                            {
                                cout << "El valor digitado en el campo seguro es erroneo. Intentelo Nuevamente." << endl;
                                std::this_thread::sleep_for(std::chrono::seconds(6));
                                ClearScreen();
                                opcion1();
                                return 0;
                            }
                        }
                        else
                        {
                            cout << "El valor digitado en el campo Costo de alquier es erroneo. Intentelo Nuevamente." << endl;
                            std::this_thread::sleep_for(std::chrono::seconds(6));
                            ClearScreen();
                            opcion1();
                            return 0;
                        }
                    }
                    else
                    {
                        cout << "El valor digitado en el campo kilometraje es erroneo. Intentelo Nuevamente." << endl;
                        std::this_thread::sleep_for(std::chrono::seconds(6));
                        ClearScreen();
                        opcion1();
                        return 0;
                    }
                }
            }
        }
    }
    else
    {
        cout << "Los parametros de la placa no cumplen con el estandar de 6 caracteres." << endl;
        opcion1();
    }
    return 0;
}
// Modificar vehiculo - Funct #2 ......................

int opcion2()
{

    string ModPlaca;
    cout << endl
         << endl;
    horizontal();
    cout << endl
         << endl;
    cout << "Modificar Vehiculo" << endl;
    cout << "Digite el numero de la placa del vehiculo que desea modificar: ";
    cin >> ModPlaca;
    ModPlaca = toLowerCase(ModPlaca);
    for (int i = 0; i < cantVehiculos; i++)
    {

        if (ModPlaca == datosVehiculo[i][7])
        {
            cout << "El vehiculo si se encuentra agregado, digite la informaciona a continuacion para modificarlo correctamente..\n";
            cout << "Digite la marca del vehiculo: ";
            cin >> datosVehiculo[i][8];
            cout << "Digite el modelo del vehiculo: ";
            cin >> datosVehiculo[i][9];
            cout << "Digite el kilometraje del vehiculo: ";
            cin >> kil;
            cout << "Digite el costo de alquiler del vehiculo: ";
            cin >> cost;
            cout << "Digite el tipo de seguro del vehiculo: ";
            cin >> seg;
            cout << "Digite el tipo de Vehiculo: ";
            cin >> tveh;

            // conversion de datos
            seg = toLowerCase(seg);
            tveh = toLowerCase(tveh);

            if (is_numeric(kil))
            {
                if (is_numeric(cost))
                {
                    if (seg == "full" || seg == "soat" || seg == "soat-cs")
                    {
                        if (tveh == "economico" || tveh == "intermedio" || tveh == "ejecutivo")
                        {

                            // guardado de datos
                            datosVehiculo[i][0] = kil;
                            datosVehiculo[i][1] = cost;
                            datosVehiculo[i][2] = seg;
                            datosVehiculo[i][3] = tveh;

                            cout << "Vehiculo Mofidicado Exitosamente\n";

                            impVehiculo(i);

                            return 0;
                        }
                        else
                        {
                            cout << "El valor digitado en el campo de Tipo de Vehiculo es erroneo. Intentelo Nuevamente." << endl;
                            std::this_thread::sleep_for(std::chrono::seconds(6));
                            ClearScreen();
                            opcion2();
                            return 0;
                        }
                    }
                    else
                    {
                        cout << "El valor digitado en el campo seguro es erroneo. Intentelo Nuevamente." << endl;
                        std::this_thread::sleep_for(std::chrono::seconds(6));
                        ClearScreen();
                        opcion2();
                        return 0;
                    }
                }
                else
                {
                    cout << "El valor digitado en el campo Costo de alquier es erroneo. Intentelo Nuevamente." << endl;
                    std::this_thread::sleep_for(std::chrono::seconds(6));
                    ClearScreen();
                    opcion2();
                    return 0;
                }
            }
            else
            {
                cout << "El valor digitado en el campo kilometraje es erroneo. Intentelo Nuevamente." << endl;
                std::this_thread::sleep_for(std::chrono::seconds(6));
                ClearScreen();
                opcion2();
                return 0;
            }
        }
    }

    return 1;
}
// Eliminar Vehiculo - Funct #3 ......................

int opcion3()
{
    string DelPlaca;
    cout << endl
         << endl;
    horizontal();
    cout << endl
         << endl;
    cout << "Eliminar Vehiculo" << endl;
    cout << "Digite el numero de la placa del vehiculo que desea eliminar: ";
    cin >> DelPlaca;
    DelPlaca = toLowerCase(DelPlaca);
    for (int i = 0; i < cantVehiculos; i++)
    {

        if (DelPlaca == datosVehiculo[i][7])
        {
            if (datosVehiculo[i][6] == "disponible")
            {
                cout << "El vehiculo si se encuentra se procedera a eliminar..\n";

                datosVehiculo[i][0] = ""; // kilometraje
                datosVehiculo[i][1] = ""; // costoalquiler
                datosVehiculo[i][2] = ""; // tipoSeguro
                datosVehiculo[i][3] = ""; // tipoVehiculo
                datosVehiculo[i][4] = ""; // cantKilometrosAndados
                datosVehiculo[i][5] = ""; // ingresosTotales
                datosVehiculo[i][6] = ""; // alquilado
                datosVehiculo[i][7] = ""; // placa
                datosVehiculo[i][8] = ""; // marca
                datosVehiculo[i][9] = ""; // modelo

                cout << "El vehiculo fue eliminado correctamente..\n";
                return 0;
            }
            else
            {
                cout << "No se puede eliminar un Vehiculo que se encuentra Alquilado." << endl;
                return 0;
            }
        }
    }
    return 1;
}
// Alquilar vehiculo - Funct #4 ......................

int opcion4()
{
    string alqPlaca;
    cout << endl
         << endl;
    horizontal();
    cout << endl
         << endl;
    cout << "Alquilar Auto" << endl;
    cout << "Digite el numero de la placa del vehiculo que desea alquilar: ";
    cin >> alqPlaca;
    alqPlaca = toLowerCase(alqPlaca);
    for (int i = 0; i < cantVehiculos; i++)
    {

        if (alqPlaca == datosVehiculo[i][7])
        {
            if (datosVehiculo[i][6] == "disponible")
            {

                datosVehiculo[i][6] = "alquilado";
                cout << endl
                     << endl;
                horizontal();
                cout << "\n\n";
                cout << "El vehiculo a sido alquilado exitosamente..\n";
                return 0;
            }
            else
            {
                cout << "El vehiculo ya se encuentra alquilado..\n";
                return 0;
            }
        }
    }
    return 1;
}

// Filtrar por placa - Funct #5 ......................

int opcion5()
{
    string opcionFiltroPlaca;
    cout << endl
         << endl;
    horizontal();
    cout << endl
         << endl;
    cout << "Buscar por placa" << endl;
    cout << "Digite el numero de la placa del vehiculo que desea visualizar: ";
    cin >> opcionFiltroPlaca;
    opcionFiltroPlaca = toLowerCase(opcionFiltroPlaca);
    for (int i = 0; i < cantVehiculos; i++)
    {
        if (datosVehiculo[i][7] == opcionFiltroPlaca)
        {
            impVehiculo(i);
            return 0;
        }
    }
    return 1;
}

// Filtrar por tipo vehiculo - Funct #6 ......................
int opcion6()
{

    int opcionFiltroTipoVehiculo;
    ident = false;
    cout << endl
         << endl;
    horizontal();
    cout << endl
         << endl;
    cout << "Filtrar por tipo de vehiculo" << endl;
    cout << "Digite el numero de acuerdo al tipo de vehiculo que desee visualizar.." << endl
         << endl;
    cout << "- Digite '1' si desea ver los vehiculos Economicos." << endl;
    cout << "- Digite '2' si desea ver los vehiculos Intermedios." << endl;
    cout << "- Digite '3' si desea ver los vehiculos Ejecutivos." << endl;
    cout << "- Digite '4' si desea volver al menu" << endl
         << endl;
    cout << "Digite la Opcion: ";
    cin >> opcionFiltroTipoVehiculo;

    switch (opcionFiltroTipoVehiculo)
    {
        // Mostrar vehiculo economico - Op#3
    case 1:
        for (int i = 0; i < cantVehiculos; i++)
        {
            if (datosVehiculo[i][3] == "economico")
            {
                impVehiculo(i);
                ident = true;
            }
        }
        if (!ident)
        {
            cout << "No hay Vehiculos de Categoria Economico." << endl;
        }
        break;

        // Mostrar vehiculo intermedio - Op#3
    case 2:
        for (int i = 0; i < cantVehiculos; i++)
        {
            if (datosVehiculo[i][3] == "intermedio")
            {
                impVehiculo(i);
                ident = true;
            }
        }
        if (!ident)
        {

            cout << "No hay Vehiculos de Categoria Intermedio." << endl;
        }
        break;

        // Mostrar vehiculo ejecutivo - Op#3
    case 3:
        for (int i = 0; i < cantVehiculos; i++)
        {
            if (datosVehiculo[i][3] == "ejecutivo")
            {
                impVehiculo(i);
                ident = true;
            }
        }
        if (!ident)
        {

            cout << "No hay Vehiculos de Categoria Ejecutivo." << endl;
        }
        break;
        // case 4: volver al menu
    case 4:
        ClearScreen();
        main();
        break;
        // Default
    default:
        cout << "La Categoria de Vehiculo Seleccionado no Existe.\n";
        break;
    }
    return 0;
}

// Filtrar por tipo de seguro - Funct #7......................

int opcion7()
{
    int opcionFiltroTipoSeguro;
    ident = false;
    cout << endl
         << endl;
    horizontal();
    cout << endl
         << endl;
    cout << "Filtrar por tipo de Seguro " << endl;
    cout << "Digite el numero de acuerdo al tipo de seguro que desee visualizar.." << endl
         << endl;
    cout << "- Digite '1' si desea ver los Seguros Full." << endl;
    cout << "- Digite '2' si desea ver los Seguros Soat." << endl;
    cout << "- Digite '3' si desea ver los Seguros Soat-cs." << endl;
    cout << "- Digite '4' si desea volver al menu" << endl
         << endl;
    cout << "Digite la Opcion: ";
    cin >> opcionFiltroTipoSeguro;

    switch (opcionFiltroTipoSeguro)
    {
        // Mostrar Seguro Full - Op#1
    case 1:

        for (int i = 0; i < cantVehiculos; i++)
        {
            if (datosVehiculo[i][2] == "full")
            {
                impVehiculo(i);
                ident = true;
            }
        }
        if (!ident)
        {

            cout << "No hay Vehiculos con Seguro Tipo Full." << endl;
        }
        break;

        // Mostrar Seguro Soat - Op#2
    case 2:

        for (int i = 0; i < cantVehiculos; i++)
        {
            if (datosVehiculo[i][2] == "soat")
            {
                impVehiculo(i);
                ident = true;
            }
        }
        if (!ident)
        {

            cout << "No hay Vehiculos con Seguro Tipo Soat." << endl;
        }
        break;

        // Mostrar Seguro Soat-cs - Op#3
    case 3:

        for (int i = 0; i < cantVehiculos; i++)
        {
            if (datosVehiculo[i][2] == "soat-cs")
            {
                impVehiculo(i);
                ident = true;
            }
        }
        if (!ident)
        {

            cout << "No hay Vehiculos Con Seguro Tipo Soat-CS ." << endl;
        }
        break;
    case 4:
        ClearScreen();
        main();
        break;
        // Default
    default:
        cout << "El tipo de Seguro Seleccionado no Existe.\n";
        break;
    }
    return 0;
}

// Filtrar por Alquilados - Funct #8 ......................
int opcion8()
{
    ident = false;
    string opcionFiltroPlaca;
    cout << endl
         << endl;
    horizontal();
    cout << endl
         << endl;
    cout << "Vehiculo/s alquilados" << endl
         << endl;

    for (int i = 0; i < cantVehiculos; i++)
    {
        if (datosVehiculo[i][6] == "alquilado")
        {
            impVehiculo(i);
            ident = true;
        }
    }
    if (!ident)
    {

        cout << "No hay Vehiculos Alquilados." << endl;
    }
    return 0;
}

// Filtrar por Disponibles - Funct #9 ......................
int opcion9()
{

    string opcionFiltroPlaca;
    ident = false;
    cout << endl
         << endl;
    horizontal();
    cout << endl
         << endl;
    cout << "Vehiculo/s Disponiles" << endl
         << endl;

    for (int i = 0; i < cantVehiculos; i++)
    {
        if (datosVehiculo[i][6] == "disponible")
        {
            impVehiculo(i);
            ident = true;
        }
    }
    if (!ident)
    {

        cout << "No hay Vehiculos Disponibles." << endl;
    }

    return 0;
}

// Devolver vehiculo - Funct #10 ......................

int opcion10()
{
    string devPlaca;
    bool yaExiste = false;
    int aux = 0;
    cout << endl
         << endl;
    horizontal();
    cout << endl
         << endl;
    cout << "Devolver Auto" << endl;
    cout << "Digite el numero de la placa del vehiculo que desea devolver: ";
    cin >> devPlaca;
    devPlaca = toLowerCase(devPlaca);
    for (int i = 0; i < cantVehiculos; i++)
    {
        if (datosVehiculo[i][7] == devPlaca)
        {
            yaExiste = true;
            aux = i;
            break; // Termina el bucle cuando se encuentra el dato
        }
    }

    if (yaExiste)
    {
        if (datosVehiculo[aux][6] == "alquilado")
        {
            // Actualizacion de Datos
            datosVehiculo[aux][6] = "disponible";
            // Declaracion de Variables
            int cantKilometrosAndados;
            int kilometraje = 0;

            // Entrada de Datos

            cout << "Digite los Kilometros recorridos:";
            cin >> cantKilometrosAndados;

            cantKilometrosAndadosArray[aux] = cantKilometrosAndados;

            // conversion de string a int

            kilometraje = std::stoi(datosVehiculo[aux][0]);

            // suma de kilometros

            kilometraje += cantKilometrosAndados;

            // conversion de int a strin y asignacion

            datosVehiculo[aux][0] = to_string(kilometraje);
            cout << "El Vehiculo ya fue devuelto.\n";
        }
        else
        {
            cout << "El vehiculo no  esta alquilado..\n";
        }
    }
    else
    {
        cout << "El vehiculo no existe." << endl;
    }

    return 0;
}

// funcion--11
int opcion11()
{
    // declaracion de variables
    int ingresostotales = 0; // Inicializamos en 0}
    int aux_cost[cantVehiculos];
    cout << endl
         << endl;
    horizontal();
    cout << endl
         << endl;
    cout << "Verificar Ingresos\n"
         << endl;
    for (int i = 0; i < cantVehiculos; i++)
    {
        if (datosVehiculo[i][1] != "")
        {
            if (cantKilometrosAndadosArray[i] != 0)
            {
                // asignacion de valores
                aux_cost[i] = stoi(datosVehiculo[i][1]);

                // multiplicacion de los kilometros recorridos por el valor del alquiler
                datosVehiculo[i][5] = to_string(cantKilometrosAndadosArray[i] * aux_cost[i]);

                // guardado de datos de los ingresos
                ingresostotales += stoi(datosVehiculo[i][5]);

                cout << "La cantidad de Kilometros andados por el Vehiculo #" << i + 1 << " es: " << cantKilometrosAndadosArray[i] << " km" << std::endl;
            }
        }
    }
    cout << "\nEl ingreso total de todos los Vehiculos es: " << ingresostotales << std::endl;
    return 0;
}

// funcion-12
int opcion12()
{   
     cout << endl
         << endl;
    horizontal();
    cout << endl
         << endl;
    cout << "\nLa cantidad de vehiculos del parqueadero es: " << cantVehiculos << endl;
    return 0;
}

int opcion13()
{
    cout << "\nAdios";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    exit(1);
}
// Función para guardar el parque automotor en un archivo de texto
void guardar()
{
    ofstream archivo("base de datos.txt");
    if (archivo.is_open())
    {
        archivo << cantVehiculos << endl;
        for (int i = 0; i < cantVehiculos; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                archivo << datosVehiculo[i][j] << endl;
            }
        }
        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir la base de datos." << endl;
    }
}

// Función para cargar un archivo de texto
void cargar()
{
    ifstream archivo("base de datos.txt");
    if (archivo.is_open())
    {
        archivo >> cantVehiculos;
        archivo.ignore(); // Ignorar el salto de línea
        for (int i = 0; i < cantVehiculos; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                getline(archivo, datosVehiculo[i][j]);
            }
        }
        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir la base de datos." << endl;
    }
}
