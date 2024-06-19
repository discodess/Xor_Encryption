// 암호화, 복호화

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // system 함수를 사용하기 위해 필요

using namespace std;

char key = 'X'; // 암호화 및 복호화 키, 다른걸로 변경 가능

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
            output[i] = input[i] ^ key; //XOR로 암호화
        }

        return output;
    }
};

void line() {
    cout << ("===============================================================") << endl;
}

void clear_consol() {
    system("cls"); // 콘솔 클리어
    line();
}

void start() {
    //char key = 'X'; // 암호화 및 복호화 키
    vector<Dictionary> messages; // 암호화된 문장들을 저장할 벡터

    while (true) {

        cout << "어떤 것을 하시겠습니까? " << endl;
        cout << "1. 암호화 작업" << endl;
        cout << "2. 복호화된 문장 확인" << endl;
        cout << "3. 암호화된 문장들 확인" << endl;
        cout << "4. 모든 문장 확인" << endl;
        cout << "5. 원하는 데이터 삭제" << endl; // 선택지 수정
        cout << "6. 초기화" << endl;
        cout << "E. 종료" << endl;
        cout << "입력하세요 : ";

        char choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 입력 버퍼 클리어

        string text;

        switch (choice) {
        case '1': {
            cout << "암호화할 문장을 입력하세요 : ";
            getline(cin, text);
            messages.emplace_back(text, key);

            clear_consol();

            cout << "문장이 암호화되었습니다." << endl;

            line();

            break;
        }

        case '2': {
            clear_consol();

            cout << "모든 암호화된 문장들을 복호화합니다:" << endl;
            for (const auto& message : messages) {
                // 각 메시지의 암호화된 문자열을 복호화하여 출력
                cout << Dictionary::xorEncryptDecrypt(message.encrypted, key) << endl;
            }
            line();
            break;
        }
        case '3': {
            clear_consol();

            cout << "암호화된 문장들:" << endl;
            for (const auto& message : messages) {
                cout << message.encrypted << endl;
            }
            line();
            break;
        }
        case '4': {
            clear_consol();

            cout << "모든 문장 (원본 및 암호화):" << endl;
            for (const auto& message : messages) {
                cout << "원본: " << message.original << ", 암호화: " << message.encrypted << endl;
            }
            line();
            break;
        }
        case '5': {
            if (messages.empty()) {
                clear_consol();
                cout << "삭제할 데이터가 없습니다." << endl;
                line();
            }
            else {
                cout << "삭제할 데이터의 인덱스를 입력하세요 (0부터 시작): ";
                int index;
                cin >> index;
                // 입력된 인덱스가 벡터의 범위 내에 있는지 확인
                if (index >= 0 && index < messages.size()) {
                    messages.erase(messages.begin() + index); // 인덱스에 해당하는 데이터 삭제
                    clear_consol();
                    cout << "데이터가 삭제되었습니다." << endl;
                    line();
                }
                else {
                    clear_consol();
                    cout << "잘못된 인덱스입니다." << endl;
                    line();
                }
            }

            break;
        }
        case '6': {
            clear_consol();
            messages.clear(); // 저장된 모든 Dictionary 객체 삭제
            clear_consol();
            cout << "모든 저장된 데이터가 삭제되었습니다." << endl;
            line();
            break;
        }

        case 'E': {
            cout << "프로그램을 종료합니다." << endl;
            return;
        }
        case 'e': {
            cout << "프로그램을 종료합니다." << endl;
            return;
        }
        default: {
            clear_consol();
            cout << "잘못된 문자를 입력했습니다." << endl;
            line();
        }
        }
    }
}

int main() {
    start();
    return 0;
}


