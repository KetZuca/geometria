/*
 * Programa en C++ - Geometría
 * Asignatura: Taller de Programación
 * Sección: 03
 */

#include <iostream>
using namespace std;

// Clase Figura
class Figura {
    // Encapsulamiento
    protected:
        string nombre;
        int numLados;
        double area;

    public:
        // Constructor
        Figura(string _nombre, int _numLados) : nombre(_nombre), numLados(_numLados), area(0.0) {}

        // Destructor
        ~Figura() { 
            cout << "Destruyendo figura: " << nombre << endl; 
        }

        // Metodos abstractos (Polimorfismo)
        virtual double calcularArea() = 0;
        
        // Método getter para obtener el nombre
        string getNombre() { return nombre; }

        // Método setter para establecer el número de lados
        void setNumLados(int numLados) { 
            this->numLados = numLados; 
        }

        //Metodo getter para obtener el numero de lados
        int getNumLados() { return numLados; }

        // Método getter para obtener el área
        double getArea() { return area; }
};

// Clase Circulo
class Circulo : public Figura {
    // Encapsulamiento
    private:
        double radio; // Radio del círculo

    public:
        // Constructor sin parámetros
        Circulo() : Figura("Círculo", 0), radio(0.0) {}

        // Constructor con parámetros
        Circulo(string _nombre, double _radio) : Figura(_nombre, 0), radio(_radio) {}

        // Destructor
        ~Circulo() { 
            cout << "Destruyendo círculo" << endl; 
        }

        // Método para calcular el área del círculo
        double calcularArea() override { return 3.141592 * radio * radio; }

        // Método getter para obtener el radio
        double getRadio() { return radio; }

        // Método setter para establecer el radio
        void setRadio(double radio) { 
            this->radio = radio; 
        }
};

// Clase Rectangulo
class Rectangulo : public Figura {
    // Encapsulamiento
    private:
        double base; // Base del rectángulo
        double altura; // Altura del rectángulo

    public:
        // Constructor sin parámetros
        Rectangulo() : Figura("Rectángulo", 4), base(0.0), altura(0.0) {}

        // Constructor con parámetros
        Rectangulo(string _nombre, double _base, double _altura) : Figura(_nombre, 4), base(_base), altura(_altura) {}

        // Destructor
        ~Rectangulo() {
            cout << "Destruyendo rectángulo" << endl;
        }

        // Método para calcular el área del rectángulo
        double calcularArea() override { return base * altura; }

        // Método getter para obtener la base
        double getBase() { return base; }

        // Método setter para establecer la base
        void setBase(double base) { 
            this->base = base; 
        }

        // Método getter para obtener la altura
        double getAltura() { return altura; }

        // Método setter para establecer la altura
        void setAltura(double altura) { 
            this->altura = altura; 
        }
};

// Clase Triangulo
class Triangulo : public Figura {
    // Encapsulamiento
    private:
        double base; // Base del triángulo
        double altura; // Altura del triángulo

    public:
        // Constructor sin parámetros
        Triangulo() : Figura("Triángulo", 3), base(0.0), altura(0.0) {}

        // Constructor con parámetros
        Triangulo(string _nombre, double _base, double _altura) : Figura(_nombre, 3), base(_base), altura(_altura) {}

        // Destructor
        ~Triangulo() {
            cout << "Destruyendo triángulo" << endl;
        }

        // Método para calcular el área del triángulo
        double calcularArea() override { return (base * altura) / 2; }

        // Método getter para obtener la base
        double getBase() { return base; }

        // Método setter para establecer la base
        void setBase(double base) {
            this->base = base;
        }

        // Método getter para obtener la altura
        double getAltura() { return altura; }

        // Método setter para establecer la altura
        void setAltura(double altura) {
            this->altura = altura;
        }
};

// Función principal
int main() {
    const int maxfig = 100;
    Figura* figuras[maxfig];
    int opcion, numFiguras = 0, opNombre, indice;
    string nombre;
    double base = 0, altura = 0, radio = 0;

    do {
        cout << "Menu de opciones:" << endl;
        cout << "1. Agregar figura" << endl;
        cout << "2. Modificar figura" << endl;
        cout << "3. Calcular area y mostrar caracteristicas" << endl;
        cout << "4. Eliminar figura" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                if (numFiguras >= maxfig) {
                    cout << "No se pueden agregar mas figuras." << endl;
                    break;
                }
                int tipoFigura;
                cout << "Seleccione el tipo de figura a agregar:" << endl;
                cout << "1. Circulo" << endl;
                cout << "2. Rectangulo" << endl;
                cout << "3. Triangulo" << endl;
                cin >> tipoFigura;

                if (tipoFigura == 1) {
                    cout << "Ingrese el radio del circulo: ";
                    cin >> radio;
                    figuras[numFiguras++] = new Circulo("Circulo", radio);
                } else if (tipoFigura == 2) {
                    cout << "Ingrese el largo y el ancho del rectangulo: ";
                    cin >> base >> altura;
                    figuras[numFiguras++] = new Rectangulo("Rectangulo", base, altura);
                } else if (tipoFigura == 3) {
                    cout << "Ingrese la base y la altura del triangulo: ";
                    cin >> base >> altura;
                    figuras[numFiguras++] = new Triangulo("Triangulo", base, altura);
                } else {
                    cout << "Opcion no valida." << endl;
                }
                break;
            case 2:
                cout << "Seleccione el indice de la figura a modificar (0 a " << numFiguras - 1 << "): ";
                cin >> indice;

                if (indice >= 0 && indice < numFiguras) {
                    if (Circulo* c = dynamic_cast<Circulo*>(figuras[indice])) {
                        cout << "Ingrese el nuevo radio del circulo: ";
                        cin >> radio;
                        c->setRadio(radio);
                    } else if (Rectangulo* r = dynamic_cast<Rectangulo*>(figuras[indice])) {
                        cout << "Ingrese el nuevo largo y ancho del rectangulo: ";
                        cin >> base >> altura;
                        r->setBase(base);
                        r->setAltura(altura);
                    } else if (Triangulo* t = dynamic_cast<Triangulo*>(figuras[indice])) {
                        cout << "Ingrese la nueva base y altura del triangulo: ";
                        cin >> base >> altura;
                        t->setBase(base);
                        t->setAltura(altura);
                    }
                } else {
                    cout << "Indice no valido." << endl;
                }
                break;
            case 3:
                cout << "Seleccione el indice de la figura para ver su area (0 a " << numFiguras - 1 << "): ";
                cin >> indice;
                if (indice >= 0 && indice < numFiguras) {
                    if (Circulo* c = dynamic_cast<Circulo*>(figuras[indice])) {
                            cout << "\nEl circulo en la posicion " << indice << " presenta estas caracteristicas:" << endl << "Radio: " << c->getRadio() << endl << "Lados: " << c->getNumLados() << endl << "Area: " << c->calcularArea() << endl << endl;
                        } else if (Rectangulo* r = dynamic_cast<Rectangulo*>(figuras[indice])) {
                            cout << "\nEl rectangulo en la posicion " << indice << " presenta estas caracteristicas:" << endl << "Base: " << r->getBase() << endl << "Altura: " << r->getAltura() << endl << "Lados: " << r->getNumLados() << endl << "Area: " << r->calcularArea() << endl << endl;
                        } else if (Triangulo* t = dynamic_cast<Triangulo*>(figuras[indice])) {
                            cout << "\nEl triangulo en la posicion " << indice << " presenta estas caracteristicas:" << endl << "Base: " << t->getBase() << endl << "Altura: " << t->getAltura() << endl << "Lados: " << t->getNumLados() << endl << "Area: " << t->calcularArea() << endl << endl;
                        }
                } else {
                    cout << "Indice no valido." << endl;
                }
                break;
            case 4:
                cout << "Seleccione el indice de la figura a eliminar (0 a " << numFiguras - 1 << "): ";
                cin >> indice;

                if (indice >= 0 && indice < numFiguras) {
                    delete figuras[indice];
                    for (int i = indice; i < numFiguras - 1; i++) {
                        figuras[i] = figuras[i + 1];
                    }
                    numFiguras--;
                    cout << "Figura eliminada." << endl;
                } else {
                    cout << "Índice no válido." << endl;
                }
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    } while (opcion != 5);
    return 0;
}

/*
Integrantes
David Herrera C.I: 31213680
Victor Díaz C.I: 31772274
José Fernández C.I: 30331861
Bryant Sifontes C.I: 30289709
*/