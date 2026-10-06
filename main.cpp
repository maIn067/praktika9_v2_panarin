#include <iostream>
using namespace  std;
void increaseBrightness(double* data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = data[i] + 20;
        if (data[i] > 255) {
            data[i] = 255;
        }
    }
}
void decreaseBrightness(double* data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = data[i] - 20;
        if (data[i] < 0) {
            data[i] = 0;
        }
    }
}
void invertBrightness(double* data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = 255 - data[i];
    }
}
void threshold(double* data, int size) {
    for (int i = 0; i < size; i++) {
        if (data[i] < 128) {
            data[i] = 0;
        }
        else {
            data[i] = 255;
        }
    }
}
void applyProcessing(double* data, int size, void (*processor)(double*, int)) {
    if (processor != nullptr) {
        processor(data, size);
    }
}
void printArray(double* data, int size) {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
void copyArray(double* from, double* to, int size) {
    for (int i = 0; i < size; i++) {
        to[i] = from[i];
    }
}
void inputData(double* data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 256;
    }
}
int main() {
    double data[10];
    double original[10];
    int size = 0;
    void (*processors[])(double*, int) = {
        increaseBrightness, decreaseBrightness, invertBrightness, threshold
    };
    int choice = 0;
    while (choice != 5) {
        cout << "1 заполнить данные" << endl;
        cout << "2 показать данные" << endl;
        cout << "3 выбрать и выполнить обработку" << endl;
        cout << "4 восстановить исходные данные" << endl;
        cout << "5 выход" << endl;
        cin >> choice;
        switch (choice) {
        case 1: {
            size = 10;
            inputData(data, size);
            copyArray(data, original, size);
            cout << "данные заполнены: ";
            printArray(data, size);
            break;
        }
        case 2: {
            printArray(data, size);
            break;
        }
        case 3: {
            if (size == 0) {
                cout << "сначала заполни данные" << endl;
                break;
            }
            cout << "1 увеличить яркость на 20" << endl;
            cout << "2 уменьшить яркость на 20" << endl;
            cout << "3 инвертировать яркость" << endl;
            cout << "4 пороговая обработка (порог 128)" << endl;
            cout << "выбирай обработку: ";
            int number;
            cin >> number;
            void (*processor)(double*, int) = nullptr;
            if (number >= 1 && number <= 4) {
                processor = processors[number - 1];
            }
            if (processor == nullptr) {
                cout << "такой обработки нет" << endl;
                break;
            }

            cout << "до: ";
            printArray(data, size);
            applyProcessing(data, size, processor);
            cout << "после: ";
            printArray(data, size);
            break;
        }
        case 4: {
            copyArray(original, data, size);
            cout << "данные восстановлены" << endl;
            break;
        }
        case 5: {
            cout << "выход" << endl;
            break;
        }
        default: {
            cout << "такого пункта нет" << endl;
        }
        }
    }
}