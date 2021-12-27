/*

Introducing CString!

C module for working with dynamic strings.
This module contains all basic string operations
such as substring, index, replace, etc.

To use this module, simply include this file
i.e. "cstring.h" in your C program.

To know more about this module and its functions,
go to https://github.com/abhaytr/cstring.

© Abhay Tripathi

*/

#include <stdlib.h>
#include <String.h>
#include <ctype.h>

#define STANDARD_SIZE 512

typedef struct
{
    char* str;
    size_t alen;
    size_t ulen;
} String;

const String nullString = 
{
    NULL,
    0,
    0
};

String newString(int SIZE)
{
    if (SIZE == 0)
    {
        SIZE = STANDARD_SIZE;
    }
    char *str = (char *) malloc(sizeof(char) * SIZE);
    str[0] = '\0';
    String nstr = 
    {
        str,
        SIZE,
        0
    };
    return nstr;
}

int validateMemory(String *str, int size)
{
    int alen = str->alen;
    int ulen = str->ulen;
    if ((ulen + size) >= alen - 1)
    {
        int NEW_SIZE = str->alen + (sizeof(char) * (size + STANDARD_SIZE));
        str->str = (char *) realloc(str->str, NEW_SIZE);
        if (str->str == NULL)
        {
            return -1;
        }
        str->alen = NEW_SIZE;
    }
    return 0;
}

char* val(String *str)
{
    return str->str;
}

int addChar(String *str, char c)
{
    int li = str->ulen;
    if (validateMemory(str, 1) < 0)
    {
        return -1;
    }
    str->str[li] = c;
    str->str[li + 1] = '\0';
    (str->ulen)++;
    return 0;
}

int add(String *str, String* sta)
{
    int li = str->ulen;
    if (validateMemory(str, sta->ulen) < 0)
    {
        return -1;
    }
    for (int i = 0; i < sta->ulen; i++)
    {
        str->str[li] = sta->str[i];
        str->str[li + 1] = '\0';
        (str->ulen)++;
        li++;
    }
    return 0;
}

int addStr(String* str, char* sta)
{
    int sl = strlen(sta);
    int li = str->ulen;
    if (validateMemory(str, sl) < 0)
    {
        return -1;
    }
    for (int i = 0; i < sl; i++)
    {
        str->str[li] = sta[i];
        str->str[li + 1] = '\0';
        str->ulen++;
        li++;
    }
    return 0;
}

void freestr(String *str)
{
    free(str->str);
}

void clear(String *str)
{
    str->ulen = 0;
}

int indx(String *str, String *vtc)
{
    int pos = 0;
    int ci = 0;
    for (int i = 0; i < str->ulen; i++)
    {
        if (ci == vtc->ulen)
        {
            return pos;
        }
        if (str->str[i] == vtc->str[ci])
        {
            if (ci == 0)
            {
                pos = i;
            }
            ci++;
        }
        else
        {
            ci = 0;
            pos = 0;
        }
    }
    if (ci == vtc->ulen)
    {
        return pos;
    }
    return -1;
}

int indxStr(String *str, char *vtc)
{
    int pos = 0;
    int ci = 0;
    int sl = strlen(vtc);
    for (int i = 0; i < str->ulen; i++)
    {
        if (ci == sl)
        {
            return pos;
        }
        if (str->str[i] == vtc[ci])
        {
            if (ci == 0)
            {
                pos = i;
            }
            ci++;
        }
        else
        {
            ci = 0;
            pos = 0;
        }
    }
    if (ci == sl)
    {
        return pos;
    }
    return -1;
}

int sindx(char *str, char *vtc)
{
    int pos = 0;
    int ci = 0;
    int sl = strlen(vtc);
    for (int i = 0; i < strlen(str); i++)
    {
        if (ci == sl)
        {
            return pos;
        }
        if (str[i] == vtc[ci])
        {
            if (ci == 0)
            {
                pos = i;
            }
            ci++;
        }
        else
        {
            ci = 0;
            pos = 0;
        }
    }
    if (ci == sl)
    {
        return pos;
    }
    return -1;
}

int contains(String *str, String *vtc)
{
    if (indx(str, vtc) == -1)
    {
        return 0;
    }
    return 1;
}

int containsStr(String *str, char *vtc)
{
    if (indxStr(str, vtc) == -1)
    {
        return 0;
    }
    return 1;
}

int scontains(char *str, char *vtc)
{
    if (sindx(str, vtc) == -1)
    {
        return 0;
    }
    return 1;
}

String replace(String *str, String *ttf, String *vtr)
{
    String rs = newString(str->alen);
    if (rs.str == NULL)
    {
        return nullString;
    }
    int ci = 0;
    int cl = ttf->ulen;
    int sl = str->ulen;
    int pos = 0;
    for (int i = 0; i < sl; i++)
    {
        if (ci == cl)
        {
            ci = 0;
            pos = 0;
            if (add(&rs, vtr) < 0)
            {
                freestr(&rs);
                return nullString;
            }
        }
        if (str->str[i] == ttf->str[ci])
        {
            if (ci == 0)
            {
                pos = i;
            }
            ci++;
        }
        else
        {
            if (ci != 0)
            {
                for (int j = pos; j < i; j++)
                {
                    if (addChar(&rs, str->str[j]) < 0)
                    {
                        freestr(&rs);
                        return nullString;
                    }
                }
            }
            ci = 0;
            pos = 0;
            if (addChar(&rs, str->str[i]) < 0)
            {
                freestr(&rs);
                return nullString;
            }
        }
    }
    if (ci == cl)
    {
        ci = 0;
        pos = 0;
        if (add(&rs, vtr) < 0)
        {
            freestr(&rs);
            return nullString;
        }
    }
    else
    {
        if (ci != 0)
        {
            for (int j = pos; j < sl; j++)
            {
                if (addChar(&rs, str->str[j]) < 0)
                {
                    freestr(&rs);
                    return nullString;
                }
            }
        }
        ci = 0;
        pos = 0;
    }
    return rs;
}

String replaceStr(String *str, char *ttf, char *vtr)
{
    String rs = newString(str->alen);
    if (rs.str == NULL)
    {
        return nullString;
    }
    int ci = 0;
    int cl = strlen(ttf);
    int sl = str->ulen;
    int pos = 0;
    for (int i = 0; i < sl; i++)
    {
        if (ci == cl)
        {
            ci = 0;
            pos = 0;
            if (addStr(&rs, vtr) < 0)
            {
                freestr(&rs);
                return nullString;
            }
        }
        if (str->str[i] == ttf[ci])
        {
            if (ci == 0)
            {
                pos = i;
            }
            ci++;
        }
        else
        {
            if (ci != 0)
            {
                for (int j = pos; j < i; j++)
                {
                    if (addChar(&rs, str->str[j]) < 0)
                    {
                        freestr(&rs);
                        return nullString;
                    }
                }
            }
            ci = 0;
            pos = 0;
            if (addChar(&rs, str->str[i]) < 0)
            {
                freestr(&rs);
                return nullString;
            }
        }
    }
    if (ci == cl)
    {
        ci = 0;
        pos = 0;
        if (addStr(&rs, vtr) < 0)
        {
            freestr(&rs);
            return nullString;
        }
    }
    else
    {
        if (ci != 0)
        {
            for (int j = pos; j < sl; j++)
            {
                if (addChar(&rs, str->str[j]) < 0)
                {
                    freestr(&rs);
                    return nullString;
                }
            }
        }
        ci = 0;
        pos = 0;
    }
    return rs;
}

String substring(String *str, int startIndex, int endIndex)
{
    int sl = str->alen;
    if (endIndex > sl || startIndex < 0)
    {
        return nullString;
    }
    String ss = newString(sl);
    if (ss.str == NULL)
    {
        return nullString;
    }
    for (int i = startIndex; i < endIndex; i++)
    {
        if (addChar(&ss, str->str[i]) < 0)
        {
            return nullString;
        }
    }
    return ss;
}

String strsubstring(char *str, int startIndex, int endIndex)
{
    int sl = strlen(str);
    if (endIndex > sl || startIndex < 0)
    {
        return nullString;
    }
    String ss = newString(sl);
    if (ss.str == NULL)
    {
        return nullString;
    }
    for (int i = startIndex; i < endIndex; i++)
    {
        if (addChar(&ss, str[i]) < 0)
        {
            return nullString;
        }
    }
    return ss;
}

char *ssubstring(char *str, int startIndex, int endIndex)
{
    int sl = strlen(str);
    if (endIndex > sl || startIndex < 0)
    {
        return NULL;
    }
    char *ss = (char *) malloc(sizeof(char) * (sl + 1));
    if (ss == NULL)
    {
        return NULL;
    }
    int i;
    for (i = startIndex; i < endIndex; i++)
    {
        ss[i - startIndex] = str[i];
    }
    ss[i - startIndex] = '\0';
    return ss;
}

void trim(String *str, int startIndex, int endIndex)
{
    *str = substring(str, startIndex, endIndex);
}

void *strim(char *str, int startIndex, int endIndex)
{
    char *tstr = ssubstring(str, startIndex, endIndex);
    int i;
    for (i = 0; i < strlen(tstr); i++)
    {
        str[i] = tstr[i];
    }
    for (int j = i; j < strlen(str); j++)
    {
        str[j] = '\0';
    }
    free(tstr);
}

int isNumeric(String *str)
{
    for (int i = 0; i < str->ulen; i++)
    {
        if (isdigit(str->str[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int isStrNumeric(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int toInteger(String *str)
{
    int num = 0;
    for (int i = 0; i < str->ulen; i++)
    {
        char c = str->str[i];
        if (isdigit(c))
        {
            num *= 10;
            int ci = c - '0';
            num += ci;
        }
    }
    return num;
}

int strToInteger(char *str)
{
    int num = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        char c = str[i];
        if (isdigit(c))
        {
            num *= 10;
            int ci = c - '0';
            num += ci;
        }
    }
    return num;
}