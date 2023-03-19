#include "errors.h"

void handle_error(const ret_code_t &code)
{
    switch (code)
    {
        case ERR_NO_MEMORY:
            QMessageBox::critical(nullptr, "Ошибка",
                                  "Произошла ошибка при выделении памяти");
            break;

        case ERR_FILE_NAME:
            QMessageBox::critical(nullptr, "Ошибка",
                                  "Некорректное имя файла");
            break;

        case ERR_FILE_OPEN:
            QMessageBox::critical(nullptr, "Ошибка",
                                  "Произошла ошиба при открытии файла");
            break;

        case ERR_FILE_STRUCTURE:
            QMessageBox::critical(nullptr, "Ошибка",
                                  "Структура файла повреждена");
            break;

        case ERR_DATA_CORRUPTED:
            QMessageBox::critical(nullptr, "Ошибка",
                                  "Попытка обработки повреждённых данных");
            break;

        case ERR_NO_DATA:
            QMessageBox::critical(nullptr, "Ошибка",
                                  "Нет данных для обработки");
            break;

        case ERR_ARRAY_OVERFLOW:
            QMessageBox::critical(nullptr, "Ошибка",
                                  "Попытка выхода за границы массива");
            break;

        default:
            QMessageBox::critical(nullptr, "Ошибка",
                                  "Неизвестная команда");
    }
}
