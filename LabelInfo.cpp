/* Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
// LabelInfo.cpp : Implementation of CLabelInfo

#include "stdafx.h"
#include "LabelInfo.h"

#include <comdef.h>

// CLabelInfo



unsigned char power(int a, int b)
{
    int i;
    unsigned char result = 1;
    for(i = 0; i < b; i++)
        result *= a;
        
    return result;
}

int toLower(int c)
{
    if(c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

unsigned char htoi(char *s)
{
    int i, len;
    unsigned char value, result;
    int iCh;
    unsigned char iPow;
    int pos;
    char ch;

    result = 0;
    len = 0;
    value = 0;
    iCh = -1;

    len = (int)strlen(s);
    pos = 0;

    len -= 1;

    for(i = len; (s[i] >= '0' && s[i] <= '9')
                    || (s[i] >= 'a' && s[i] <= 'f')
                    || (s[i] >= 'A' && s[i] <= 'F'); i--) {

        ch = toLower(s[i]); /* tolower() defined in ctype.h */

        switch (ch) {
          case '0':
            iCh = 0;
            break;
          case '1':
            iCh = 1;
            break;
          case '2':
            iCh = 2;
            break;
          case '3':
            iCh = 3;
            break;
          case '4':
            iCh = 4;
            break;
          case '5':
            iCh = 5;
            break;
          case '6':
            iCh = 6;
            break;
          case '7':
            iCh = 7;
            break;
          case '8':
            iCh = 8;
            break;
          case '9':
            iCh = 9;
            break;
          case 'a':
            iCh = 10;
            break;
          case 'b':
           iCh = 11;
            break;
          case 'c':
            iCh = 12;
            break;
          case 'd':
            iCh = 13;
            break;
          case 'e':
            iCh = 14;
            break;
          case 'f':
            iCh = 15;
            break;

          default:
            iCh = -1;
            break;
        }

        iPow = power(16, pos);
        pos++;

        value = iPow * iCh;

        result += value;
    }

    return result;
}

STDMETHODIMP CLabelInfo::getInfo(BSTR labelStr, BSTR* ret)
{
	_bstr_t tempStr = labelStr;

    char temp0, temp1;
	unsigned char char_buf[20], *p, *q;
	int i, j = 0;

	char *strDelimit = ",";
	char string[256];
	int k = 0;
	char *context = NULL;
	// FILE *file; // Debugging

	// TODO: Convert String to byte array
	unsigned char *frame_buf = (unsigned char *)malloc(20);

	memset(frame_buf, 0, sizeof(frame_buf));
	strcpy_s(string, sizeof(string),tempStr);

	char *token = strtok_s((char*)string, strDelimit, &context);
	
	while (token != NULL) {
		frame_buf[k] = htoi(token);
		k++;

		token = strtok_s(NULL, strDelimit, &context);
	}
	// TODO: Convert String to byte array - end


	// TODO: void Decode(unsigned char * frame_buf)
	// Copyright (c) 1991 veic
	p = frame_buf;
	q = char_buf;

	for (j = 0; j < 2; j++ ) {
		
		for (i = 0; i < 2; i++ ) {
			temp0 = (*p & 0xfc );
			*q++  = ((temp0 >> 2) + 0x20 );

			temp0 = ((*p++ & 0x03) << 4 );
			temp1 = ((*p & 0xf0) >> 4);
			*q++ = ((temp1 | temp0) + 0x20);

			temp0 = (*p++ & 0x0f) << 2 ;
			temp1 = (*p & 0xc0) >>  6;
			*q++ = ((temp0 | temp1) + 0x20);

			*q++ = ((*p++ & 0x3f ) + 0x20 );
		}

		temp0 = (*p & 0xfc);
		*q++ = ((temp0 >> 2 ) + 0x20);

		temp0 = ((*p++ & 0x03) << 4 );
		temp1 = ((*p++ & 0xf0) >> 4 );
		*q++ = ((temp0 | temp1) + 0x20);
	}
	// TODO: Decode() - end


	// TODO: add 0x40
	char_buf[0] += 0x40;
	if (!(char_buf[4] >= 0x30) && (char_buf[4] <= 0x39))
		if ((char_buf[4] != 0x20))
			char_buf[4] += 0x40;
	// TODO: add 0x40 - end

	// TODO: Convert unsigned char array to char array
	char *result = (char *)malloc(21);
	memset(result, 0, sizeof(result));
	/*
	// Debug Info
	file = fopen("c:\\datasb113.dat", "w+b");
	int iLen = 0;
	for (iLen = 0; iLen < 20; iLen++) {
		result[iLen] = char_buf[iLen];
		fputc(char_buf[iLen], file);
	}
	fclose(file);
	*/
	int iLen = 0;
	for (iLen = 0; iLen < 20; iLen++)
		result[iLen] = char_buf[iLen];

	result[iLen] = '\0';
	// TODO: Convert unsigned char array to char array - end


	//*ret = _com_util::ConvertStringToBSTR(result);
	*ret = _bstr_t(result);

	return S_OK;
}
