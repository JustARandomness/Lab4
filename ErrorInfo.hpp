#include <iostream>
#include <cstring>

int NoErrorCode = 0;
int NoListCreatedCode = 1;
int NoArrayCreatedCode = 2;
int IndexOutOfRangeCode = 3;
int NoElementFoundCode = 4;
int NoTreeCreatedCode = 5;
int NoSuchOptionFoundCode = 7;
int NoErrYetCode = 8;
int WrongNumTypeCode = 9;

const char* NoErrorMsg = "No Errors";
const char* NoListCreatedMsg = "No linked list created";
const char* NoArrayCreatedMsg = "No array created";
const char* IndexOutOfRangeMsg = "Index out of range";
const char* NoElementFoundMsg = "No such element found in this tree";
const char* NoSuchOptionFoundMsg = "No such option found. Try again";
const char* WrongNumTypeMsg = "You entered number of the wrong type. Try again";
const char* NoTreeCreatedMsg = "There are no elements in this tree";

class ErrorInfo {
private:
    int code;
    char message[100];
public:
    ErrorInfo() {
        this->code = NoErrorCode;
    };
public:
    void CopyErrorMsg(const char* s) {
        for (int i = 0; i < strlen(s); ++i) {
            this->message[i] = s[i];
        }
        this->message[strlen(s)] = '\0';
    }

    int GetErrorCode() const {
        return this->code;
    }

    void SetErrorCode(int errCode) {
        this->code = errCode;
    }

    void GetErrorMsg() const {
        int i = 0;
        while (this->message[i]) {
            std :: cout << message[i];
            ++i;
        }
        std :: cout << '\n';
    }
};
