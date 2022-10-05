#include <iostream>
#include <conio.h>
#include <string>


using namespace std;

int main() {

    string message;
    const int block_size = 8;
    int key[block_size];

    cout << "Введите текст: ";
    cin >> message;
    for (int i = 0; i < message.length()%block_size; i++){
        message+= "_";
    };
    cout << "Введите ключ через пробел(размер ключа: " << block_size << " ): ";
    for (int i = 0; i < block_size; i++)
    {
        cin >> key[i];
    }

    string encrypt_message = "";

    int text_length = message.length();
    for (int block_index = 0; block_index <= text_length/block_size; block_index++) {
    	for (int offset = 0; offset < block_size; offset++) {
    		encrypt_message += message[block_index*block_size + key[offset] - 1];
    	};
    };

    cout << "Зашифрованный текст: " << encrypt_message;

    getch();
    return 0;
}