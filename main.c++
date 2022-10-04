#include <iostream>
#include <sstream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::ostringstream;
using std::stoi;
using std::string;
using std::stringstream;
// using namespace std;

//* LIMPIAR CONSOLA
void clear()
{
    cout << "\x1B[2J\x1B[H";
}

class Converter
{
private:
    int decimal;
    int binary[100];
    int bits = 0;
    char hexaNumber[100];
    int position = 0;

public:
    // Converter();
    void decimaltoBinary(int);
    void printBinary();
    void decimaltoHexa(int);
    void printHexa();
};

void Converter::decimaltoBinary(int decimal)
{
    do
    {
        binary[bits] = decimal % 2;
        decimal = decimal / 2;
        bits++;
    } while (decimal != 0);

    for (int j = bits; j < 100; j++) // Separar basura en el arreglo
    {
        binary[j] = 2;
    }
}

void Converter::printBinary()
{
    for (bits = 99; bits >= 0; bits--) // Imprimimos el numero binario filtrando la basura
    {
        if (binary[bits] == 0 || binary[bits] == 1)
        {
            cout << binary[bits];
        }
    }
}

void Converter::decimaltoHexa(int decimal)
{
    do
    {
        int temp = 0;
        temp = decimal % 16;

        if (temp < 10)
        {
            hexaNumber[position] = temp + 48;
            position++;
        }
        else
        {
            hexaNumber[position] = temp + 55;
            position++;
        }

        decimal = decimal / 16;
    } while (decimal != 0);
}

void Converter::printHexa()
{
    for (int j = position - 1; j >= 0; j--)
    {
        cout << hexaNumber[j];
    }
}

int main()
{
    char opc;
    int decimal;

    do
    {
        Converter c;

        int opc2;
        cout << "Select an option to convert:" << endl;
        cout << "1.- Decimal to Binary" << endl;
        cout << "2.- Decimal to hexadecimal" << endl;
        cin >> opc2;

        switch (opc2)
        {
        case 1:
            cout << "Enter a decimal number: " << endl;
            cin >> decimal;

            c.decimaltoBinary(decimal);
            c.printBinary();

            break;
        case 2:
            cout << "Enter a decimal number: " << endl;
            cin >> decimal;

            c.decimaltoHexa(decimal);
            c.printHexa();
            break;

        default:
            break;
        }
        cout << endl;
        cout << "Do you want to repeat the program? Yes = y | No = n" << endl;
        cin >> opc;
        clear();
    } while (opc != 'n');

    return 0;
}