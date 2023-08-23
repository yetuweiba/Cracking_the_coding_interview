#pragma once

bool is_unique_char_in_string(const char* data, int len);

int reverse_str(char* str);

int remove_duplicate_char_in_string(char* pstr, int len);

int is_string_anagrams(const char* pstr_1, int len_1, const char* pstr_2, int len_2);

char* replace_spaces(char* pstr, int len);

bool isRotation(const char* str1, const int len1,
	const char* str2, const int len2);