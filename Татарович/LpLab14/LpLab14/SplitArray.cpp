#include "stdafx.h"
#include "SplitArray.h"

namespace SA
{
	char* deletesp(char* source)   // убираем лишние пробелы и записываем все в массивы
	{
		int i = 0, j = 0;
		char* dest = new char[1024 * 1024];
		char previous, current, next;
		while (source[i + 1] != NULL)
		{
			current = source[i]; previous = source[i - 1]; next = source[i + 1];

			switch (current)
			{
			case 0x22: dest[j++] = source[i++]; while (source[i - 1] != 0x22) dest[j++] = source[i++];
				break;
			case 0x20:
			{
				switch (next)
				{
				case 0x20: i++; break;// пробел
				case 0x22: dest[j++] = source[++i]; i++;//"
					while (source[i] != 0x22)
						dest[j++] = source[i++];
					dest[j++] = source[i++];
					break;
				case 0x3B: dest[j++] = source[++i]; i++; break;//; 
				case 0x3D: dest[j++] = source[++i]; i++; break;//=
				case 0x2B: dest[j++] = source[++i]; i++; break;//+
				case 0x2D: dest[j++] = source[++i]; i++; break;//-
				case 0x2F: dest[j++] = source[++i]; i++; break;// /
				case 0x2A: dest[j++] = source[++i]; i++; break;//*
				case 0x28: dest[j++] = source[++i]; i++; break;//(
				case 0x29: dest[j++] = source[++i]; i++; break;//)
				case 0x2C: dest[j++] = source[++i]; i++; break;// ,
				case 0x0A: i++; break;//символ перехода на новую строку
				default:
				{
					switch (dest[j - 1])
					{
					case 0x3B: dest[j++] = source[++i]; i++;       //;
					case 0x3D: dest[j++] = source[++i]; i++; break;//=
					case 0x2B: dest[j++] = source[++i]; i++; break;//+
					case 0x2D: dest[j++] = source[++i]; i++; break;//-
					case 0x2F: dest[j++] = source[++i]; i++; break;// /
					case 0x2A: dest[j++] = source[++i]; i++; break;//*
					case 0x28: dest[j++] = source[++i]; i++; break;//(
					case 0x29: dest[j++] = source[++i]; i++; break;//)
					case 0x2C: dest[j++] = source[++i]; i++; break;// ,
					case   -3: i++; break;
					case '\n': dest[j++] = source[++i]; i++; break;
					default: dest[j++] = source[i++]; break;
					}
					break;
				}
				}
				break;
			}
			default: dest[j++] = source[i++]; break;
			}
		}
		dest[j] = 0x00;
		return dest;
	}
	
	void AddToArray(char** &arr, char* source, int id ) // добавляет в массив arr
	{
		arr[id] = new char[strlen(source)];
		strcpy_s(arr[id], strlen(source) + 1, source);
	}

	char** splitArray(char* text)  // массив всех сепараторов (|,+,-,...)  разделить массивы
	{
		int i = 0, j = 0, size = 0;
		char* str = new char[256];
		char** arr = new char*[4096];
		for (int i = 0; i < 4096; i++)
			arr[i] = NULL;
		text = deletesp(text);
		while (text[i] != NULL)
		{
			switch (text[i])
			{
			case 0x0A:
				if (j != 0) { str[j] = 0x00; AddToArray(arr, str, size++); }
				str[0] = '\n'; str[1] = 0x00;
				AddToArray(arr, str, size++);
				i++; j = 0;
				break;
			case 0x20: str[j] = 0x00;
				AddToArray(arr, str, size++);
				i++; j = 0;
				break;
			case ';':
				if (j != 0) { str[j] = 0x00; AddToArray(arr, str, size++); }
				str[0] = ';'; str[1] = 0x00;
				AddToArray(arr, str, size++);
				i++; j = 0;
				break;
			case '(':
				if (j != 0) { str[j] = 0x00; AddToArray(arr, str, size++); }
				str[0] = '('; str[1] = 0x00;
				AddToArray(arr, str, size++);
				i++; j = 0;
				break;
			case ')':
				if (j != 0) { str[j] = 0x00; AddToArray(arr, str, size++); }
				str[0] = ')'; str[1] = 0x00;
				AddToArray(arr, str, size++);
				i++; j = 0;
				break;
			case '{':
				if (j != 0) { str[j] = 0x00; AddToArray(arr, str, size++); }
				str[0] = '{'; str[1] = 0x00;
				AddToArray(arr, str, size++);
				i++; j = 0;
				break;
			case '}':
				if (j != 0) { str[j] = 0x00; AddToArray(arr, str, size++); }
				str[0] = '}'; str[1] = 0x00;
				AddToArray(arr, str, size++);
				i++; j = 0;
				break;
			case ',':
				if (j != 0) { str[j] = 0x00; AddToArray(arr, str, size++); }
				str[0] = ','; str[1] = 0x00;
				AddToArray(arr, str, size++);
				i++; j = 0;
				break;
			case '=':
				if (j != 0) { str[j] = 0x00; AddToArray(arr, str, size++); }
				str[0] = '='; str[1] = 0x00;
				AddToArray(arr, str, size++);
				i++; j = 0;
				break;
			case '/':
				if (j != 0) { str[j] = 0x00; AddToArray(arr, str, size++); }
				str[0] = '/'; str[1] = 0x00;
				AddToArray(arr, str, size++);
				i++; j = 0;
				break;
			case '*':
				if (j != 0) { str[j] = 0x00; AddToArray(arr, str, size++); }
				str[0] = '*'; str[1] = 0x00;
				AddToArray(arr, str, size++);
				i++; j = 0;
				break;
			case '+':
				if (j != 0) { str[j] = 0x00; AddToArray(arr, str, size++); }
				str[0] = '+'; str[1] = 0x00;
				AddToArray(arr, str, size++);
				i++; j = 0;
				break;
			case '-':
				if (j != 0) { str[j] = 0x00; AddToArray(arr, str, size++); }
				str[0] = '-'; str[1] = 0x00;
				AddToArray(arr, str, size++);
				i++; j = 0;
				break;
			case '"':
				if (j != 0) { str[j] = 0x00; AddToArray(arr, str, size++); }
				j = 0;
				str[j++] = text[i++];
				while (text[i] != '"')
					str[j++] = text[i++];
				str[j++] = text[i++];
				str[j] = 0x00;
				AddToArray(arr, str, size++);
				j = 0;
				break;
			default: str[j++] = text[i++];  break;
			}
		}
		return arr;
	}
}