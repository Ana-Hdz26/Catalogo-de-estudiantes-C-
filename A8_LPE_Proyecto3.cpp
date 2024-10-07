#include <iostream>
#include <string>
using namespace std;

// Estructura Estudiante
struct Estudiante {
    int numeroEstudiante;
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;
    string carrera;
    string correoElectronico;
    string numeroTelefono;
};

// Alta de un estudiante
void altaEstudiante(Estudiante estudiantes[], int& ultimoIndice) {
    cout << "Ingrese el número de estudiante (matrícula): ";
    cin >> estudiantes[ultimoIndice].numeroEstudiante;

    cout << "Ingrese el nombre del estudiante: ";
    cin.ignore();
    getline(cin, estudiantes[ultimoIndice].nombre);

    cout << "Ingrese el apellido paterno del estudiante: ";
    getline(cin, estudiantes[ultimoIndice].apellidoPaterno);

    cout << "Ingrese el apellido materno del estudiante: ";
    getline(cin, estudiantes[ultimoIndice].apellidoMaterno);

    cout << "Ingrese la carrera del estudiante: ";
    getline(cin, estudiantes[ultimoIndice].carrera);

    cout << "Ingrese el correo electrónico del estudiante: ";
    getline(cin, estudiantes[ultimoIndice].correoElectronico);

    cout << "Ingrese el número de teléfono del estudiante: ";
    getline(cin, estudiantes[ultimoIndice].numeroTelefono);

    ultimoIndice++;
    cout << "¡Estudiante dado de alta exitosamente!" << endl;
}

// Baja de un estudiante
void bajaEstudiante(Estudiante estudiantes[], int& ultimoIndice) {
    int matricula;
    cout << "Ingrese el número de estudiante (matrícula) a dar de baja: ";
    cin >> matricula;

    int posicion = -1;
    for (int i = 0; i < ultimoIndice; i++) {
        if (estudiantes[i].numeroEstudiante == matricula) {
            posicion = i;
            break;
        }
    }

    if (posicion != -1) {
        cout << "Datos del estudiante con matrícula " << estudiantes[posicion].numeroEstudiante << endl;
        cout << "Nombre: " << estudiantes[posicion].nombre << endl;
        cout << "Apellido Paterno: " << estudiantes[posicion].apellidoPaterno << endl;
        cout << "Apellido Materno: " << estudiantes[posicion].apellidoMaterno << endl;
        cout << "Carrera: " << estudiantes[posicion].carrera << endl;
        cout << "Correo Electrónico: " << estudiantes[posicion].correoElectronico << endl;
        cout << "Número de Teléfono: " << estudiantes[posicion].numeroTelefono << endl;

        cout << "¿Estás seguro de que deseas eliminar al estudiante? 1. Para sí / 2. Para no: ";
        int respuesta;
        cin >> respuesta;

        if (respuesta == 1) {
            for (int i = posicion; i < ultimoIndice - 1; i++) {
                estudiantes[i] = estudiantes[i + 1];
            }
            ultimoIndice--;
            cout << "¡Estudiante dado de baja exitosamente!" << endl;
        } else {
            cout << "Operación cancelada." << endl;
        }
    } else {
        cout << "Estudiante con matrícula " << matricula << " no encontrado." << endl;
    }
}

// Base de datos de todos los estudiantes dados de alta
void basedatosEstudiante(Estudiante estudiantes[], int& ultimoIndice) {
    cout << "Base de datos de estudiantes:" << endl;
    for (int i = 0; i < ultimoIndice; i++) {
        cout << "Matrícula: " << estudiantes[i].numeroEstudiante << endl;
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Apellido Paterno: " << estudiantes[i].apellidoPaterno << endl;
        cout << "Apellido Materno: " << estudiantes[i].apellidoMaterno << endl;
        cout << "Carrera: " << estudiantes[i].carrera << endl;
        cout << "Correo Electrónico: " << estudiantes[i].correoElectronico << endl;
        cout << "Número de Teléfono: " << estudiantes[i].numeroTelefono << endl;
        cout << endl;
    }
}

// Consultar los datos de un estudiante
void consultarEstudiante(Estudiante estudiantes[], int& ultimoIndice) {
    int matricula;
    cout << "Ingrese el número de estudiante (matrícula) a consultar: ";
    cin >> matricula;

    int posicion = -1;
    for (int i = 0; i < ultimoIndice; i++) {
        if (estudiantes[i].numeroEstudiante == matricula) {
            posicion = i;
            break;
        }
    }

    if (posicion != -1) {
        cout << "Datos del estudiante con matrícula " << estudiantes[posicion].numeroEstudiante << endl;
        cout << "Nombre: " << estudiantes[posicion].nombre << endl;
        cout << "Apellido Paterno: " << estudiantes[posicion].apellidoPaterno << endl;
        cout << "Apellido Materno: " << estudiantes[posicion].apellidoMaterno << endl;
        cout << "Carrera: " << estudiantes[posicion].carrera << endl;
        cout << "Correo Electrónico: " << estudiantes[posicion].correoElectronico << endl;
        cout << "Número de Teléfono: " << estudiantes[posicion].numeroTelefono << endl;
    } else {
        cout << "Estudiante con matrícula " << matricula << " no encontrado." << endl;
    }
}

// Modificar los datos de un estudiante
void modificarEstudiante(Estudiante estudiantes[], int& ultimoIndice) {
    int matricula;
    cout << "Ingrese la matrícula del estudiante a modificar: ";
    cin >> matricula;

    // Buscar el estudiante en el arreglo
    int indiceEstudiante = -1;
    for (int i = 0; i < ultimoIndice; i++) {
        if (estudiantes[i].numeroEstudiante == matricula) {
            indiceEstudiante = i;
            break;
        }
    }

    if (indiceEstudiante != -1) {
        Estudiante& estudiante = estudiantes[indiceEstudiante];
        
        cout << "Información del estudiante:" << endl;
        cout << "Matrícula: " << estudiante.numeroEstudiante << endl;
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Apellido Paterno: " << estudiante.apellidoPaterno << endl;
        cout << "Apellido Materno: " << estudiante.apellidoMaterno << endl;
        cout << "Carrera: " << estudiante.carrera << endl;
        cout << "Correo Electrónico: " << estudiante.correoElectronico << endl;
        cout << "Número de Teléfono: " << estudiante.numeroTelefono << endl;

        cout << "¿Estás seguro de que deseas modificar la información del estudiante? 1. Para sí / 2. Para no: ";
        int respuesta;
        cin >> respuesta;

        if (respuesta == 1) {
            cout << "Ingrese el nuevo nombre del estudiante: ";
            cin.ignore();
            getline(cin, estudiante.nombre);

            cout << "Ingrese el nuevo apellido paterno del estudiante: ";
            getline(cin, estudiante.apellidoPaterno);

            cout << "Ingrese el nuevo apellido materno del estudiante: ";
            getline(cin, estudiante.apellidoMaterno);

            cout << "Ingrese la nueva carrera del estudiante: ";
            getline(cin, estudiante.carrera);

            cout << "Ingrese el nuevo número de teléfono del estudiante: ";
            getline(cin, estudiante.numeroTelefono);

            cout << "Ingrese el nuevo correo electrónico del estudiante: ";
            getline(cin, estudiante.correoElectronico);

            cout << "¡Datos del estudiante actualizados exitosamente!" << endl;
        } else {
            cout << "Modificación cancelada." << endl;
        }
    } else {
        cout << "El estudiante con matrícula " << matricula << " no se encuentra en el catálogo." << endl;
    }
}



int main() {
    Estudiante estudiantes[100]; // Se puede cambiar el tamaño del arreglo según la cantidad máxima de estudiantes
    int ultimoIndice = 0;
    int opcion;

    do {
        cout << "\nMenú de opciones:" << endl;
        cout << "1. Alta de estudiantes" << endl;
        cout << "2. Baja de estudiantes" << endl;
        cout << "3. Modificaciones de estudiantes" << endl;
        cout << "4. Base de datos de estudiantes" << endl;
        cout << "5. Consulta de estudiantes" << endl;
        cout << "6. Salir" << endl;
        cout << "Elija una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                altaEstudiante(estudiantes, ultimoIndice);
                break;
            case 2:
                bajaEstudiante(estudiantes, ultimoIndice);
                break;
            case 3:
                modificarEstudiante(estudiantes, ultimoIndice);
                break;
            case 4:
                basedatosEstudiante(estudiantes, ultimoIndice);
                break;    
            case 5:
                consultarEstudiante(estudiantes, ultimoIndice);
                break;
            case 6:
                cout << "¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}
