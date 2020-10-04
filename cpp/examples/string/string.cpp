#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void write_to_file(const char *file_name)
{
    ofstream f_out;
    // myfile.open ("example.txt");
    f_out.open(file_name);
    

    f_out << "Writing this to a file: " << file_name << ". ❤️\n";
    f_out.close();
}

int main() {

    string heart = "❤️";
    char h[] = "❤️";
    write_to_file(h);
    // string space = " ";
    // // char *heart = new char[100];
    // // const char = L"â\u009d¤ï¸\u008f";
    // // E2 9D A4 EF B8 8F
    // char hh[7] = (char) L"\u00e2\u009d\u00a4\u00ef\u00b8\u008f";
    // // char h[] = "\u2764";
    cout << h << endl;
    // const char hhhh = L"\u00e2\u009d\u00a4\u00ef\u00b8\u008f";
    // // char h[] = "\uE2\u9DA4\uEFB8\u8F0A";

    // cout << "Hello, ф or \u0444!\n";
    
    // // Create some strings with Unicode characters
    // wstring ws1 = L"Infinity: \u221E";
    // wstring ws2 = L"Euro: _";
    // wstring ws3 = L"❤️";

    // wchar_t w[] = L"Infinity: \u221E";

    // wofstream out("unicode.txt");
    // out << ws3 << endl;
    // wcout << ws3 << endl;
}