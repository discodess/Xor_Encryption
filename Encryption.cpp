// ��ȣȭ, ��ȣȭ

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // system �Լ��� ����ϱ� ���� �ʿ�

using namespace std;

char key = 'X'; // ��ȣȭ �� ��ȣȭ Ű, �ٸ��ɷ� ���� ����

class Dictionary {
public:
    string original;
    string encrypted;

    Dictionary(const string& original, char key) {
        this->original = original;
        this->encrypted = xorEncryptDecrypt(original, key);
    }

    static string xorEncryptDecrypt(const string& input, char key) {
        string output = input;

        for (size_t i = 0; i < input.size(); ++i) {
            output[i] = input[i] ^ key; //XOR�� ��ȣȭ
        }

        return output;
    }
};

void line() {
    cout << ("===============================================================") << endl;
}

void clear_consol() {
    system("cls"); // �ܼ� Ŭ����
    line();
}

void start() {
    //char key = 'X'; // ��ȣȭ �� ��ȣȭ Ű
    vector<Dictionary> messages; // ��ȣȭ�� ������� ������ ����

    while (true) {

        cout << "� ���� �Ͻðڽ��ϱ�? " << endl;
        cout << "1. ��ȣȭ �۾�" << endl;
        cout << "2. ��ȣȭ�� ���� Ȯ��" << endl;
        cout << "3. ��ȣȭ�� ����� Ȯ��" << endl;
        cout << "4. ��� ���� Ȯ��" << endl;
        cout << "5. ���ϴ� ������ ����" << endl; // ������ ����
        cout << "6. �ʱ�ȭ" << endl;
        cout << "E. ����" << endl;
        cout << "�Է��ϼ��� : ";

        char choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �Է� ���� Ŭ����

        string text;

        switch (choice) {
        case '1': {
            cout << "��ȣȭ�� ������ �Է��ϼ��� : ";
            getline(cin, text);
            messages.emplace_back(text, key);

            clear_consol();

            cout << "������ ��ȣȭ�Ǿ����ϴ�." << endl;

            line();

            break;
        }

        case '2': {
            clear_consol();

            cout << "��� ��ȣȭ�� ������� ��ȣȭ�մϴ�:" << endl;
            for (const auto& message : messages) {
                // �� �޽����� ��ȣȭ�� ���ڿ��� ��ȣȭ�Ͽ� ���
                cout << Dictionary::xorEncryptDecrypt(message.encrypted, key) << endl;
            }
            line();
            break;
        }
        case '3': {
            clear_consol();

            cout << "��ȣȭ�� �����:" << endl;
            for (const auto& message : messages) {
                cout << message.encrypted << endl;
            }
            line();
            break;
        }
        case '4': {
            clear_consol();

            cout << "��� ���� (���� �� ��ȣȭ):" << endl;
            for (const auto& message : messages) {
                cout << "����: " << message.original << ", ��ȣȭ: " << message.encrypted << endl;
            }
            line();
            break;
        }
        case '5': {
            if (messages.empty()) {
                clear_consol();
                cout << "������ �����Ͱ� �����ϴ�." << endl;
                line();
            }
            else {
                cout << "������ �������� �ε����� �Է��ϼ��� (0���� ����): ";
                int index;
                cin >> index;
                // �Էµ� �ε����� ������ ���� ���� �ִ��� Ȯ��
                if (index >= 0 && index < messages.size()) {
                    messages.erase(messages.begin() + index); // �ε����� �ش��ϴ� ������ ����
                    clear_consol();
                    cout << "�����Ͱ� �����Ǿ����ϴ�." << endl;
                    line();
                }
                else {
                    clear_consol();
                    cout << "�߸��� �ε����Դϴ�." << endl;
                    line();
                }
            }

            break;
        }
        case '6': {
            clear_consol();
            messages.clear(); // ����� ��� Dictionary ��ü ����
            clear_consol();
            cout << "��� ����� �����Ͱ� �����Ǿ����ϴ�." << endl;
            line();
            break;
        }

        case 'E': {
            cout << "���α׷��� �����մϴ�." << endl;
            return;
        }
        case 'e': {
            cout << "���α׷��� �����մϴ�." << endl;
            return;
        }
        default: {
            clear_consol();
            cout << "�߸��� ���ڸ� �Է��߽��ϴ�." << endl;
            line();
        }
        }
    }
}

int main() {
    start();
    return 0;
}


