#pragma once
#include "stdafx.h"

#define ERROR_THROW(id) ERROR::geterror(id);
#define ERROR_THROW_IN(id, l, c) ERROR::geterrorin(id, l, c); //l - строка, c - колонка
#define ERROR_ENTRY(id, m) {id, m, {-1, -1}} //элемент таблицы ошибок
#define ERROR_MAXSIZE_MESSAGE 200 //maximum length of an error's message

// 1 неопределенный элемент ошибок
#define ERROR_ENTRY_NODEF(id) ERROR_ENTRY(-id, "Неопределенная ошибка")

// 10 неопределенных элементов ошибок
#define ERROR_ENTRY_NODEF10(id) ERROR_ENTRY_NODEF(id + 0), ERROR_ENTRY_NODEF(id + 1), ERROR_ENTRY_NODEF(id + 2), ERROR_ENTRY_NODEF(id + 3), \
								ERROR_ENTRY_NODEF(id + 4), ERROR_ENTRY_NODEF(id + 5), ERROR_ENTRY_NODEF(id + 6), ERROR_ENTRY_NODEF(id + 7), \
								ERROR_ENTRY_NODEF(id + 8), ERROR_ENTRY_NODEF(id + 9)
// 100 неопределенных элементов таблицы ошибок
#define ERROR_ENTRY_NODEF100(id) ERROR_ENTRY_NODEF10(id + 0), ERROR_ENTRY_NODEF10(id + 10), ERROR_ENTRY_NODEF10(id + 20), ERROR_ENTRY_NODEF10(id + 30), \
								ERROR_ENTRY_NODEF10(id + 40), ERROR_ENTRY_NODEF10(id + 50), ERROR_ENTRY_NODEF10(id + 60), ERROR_ENTRY_NODEF10(id + 70), \
								ERROR_ENTRY_NODEF10(id + 80), ERROR_ENTRY_NODEF10(id + 90)
//количество элементов в таблице ошибок
#define ERROR_MAX_ENTRY 1000


namespace ERROR
{
	struct ERROR {
		int id;
		char message[ERROR_MAXSIZE_MESSAGE];
		struct IN
		{
			short line = -1;
			short col;
		}err_spec;
	};

	ERROR geterror(int id);
	ERROR geterrorin(int id, int line, int col);
}