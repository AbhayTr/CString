# CString

C module for working with dynamic strings.

## Working of CString

**CString** works by initialising a **"String" Data Structure** which is defined in **CString module**. **"String"** is basically a **struct** which contains **three fields**.

The first field is **"str"** which is of **char pointer type** and stores the **actual character data**. **"str" is stored in the heap memory** and is allocated and controlled using **malloc(), realloc() and free()**, just like other data present in the **heap memory**.

The second field is **"ulen"** which is of **'int' type** and stores the **number of characters filled in the allocated heap memory**. This is basically the **"length of the dynamic string"**.

The third field is **"alen"** which is of **'int' type** and stores the **number of characters allocated to char pointer "str" in the heap memory**.

**'ulen'** and **'alen'** fields are maintained by the **CString Module** automatically as and when required.

While adding a **character/"String"**, the module **checks if "ulen" is less than "alen"**. If it is not, then the module **calls realloc() and adds the required memory along with a standard buffer memory of 512 bytes** to the **"str" pointer**.

This allows the module user to **freely add as many characters as the user likes** making it a **dynamic string**.

**CString module** does provide **basic functions** like **substring(), index(), etc.** even for **char pointer data type directly**. More details are given in **"Functions"** section.

**Please do note that even though this module protects from attacks like Buffer Overflow, Stack Overflow, etc., it is still the responsibility of the module user to manage heap memory as the module will keep calling realloc() and adding memory to the "str" pointer until Memory Overflow happens, in which case the "str" pointer will be removed.**

## Installation

Simply include the **"cstring.h"** file in your program.

## Usage

Simply use this code (Modify according to your needs):

```C
#include <stdio.h>
#include "cstring.h"

void main()
{
    String string = newString(0);       //newString() will be explained in detail in the functions section.
    addStr(string, "Abhay Tripathi");   //addStr() will be explained in detail in the functions section.
    printf("Value of str: %s.\n", string.str);
    printf("Allocated Memory to str: %d.\n", string.alen);
    printf("Used Memory by str: %d.\n", string.ulen);
}
```

## Functions

### newString(int SIZE)

```C
String string = newString(SIZE);
```

Creates **char pointer** and allocates **SIZE Bytes** using **malloc()** and assigns **0th index as "\0"** (Because in C, String is always terminated by "\0"). If **SIZE is 0**, then **STANDARD SIZE i.e. 512 Bytes** are allocated. Then, creates new **String struct** defined in the module, sets **ulen** and **alen** as **0** (because at the time of creation, the allocated memory is empty apart from the "\0" character which is a null character and hence is not counted in the length of the String) and returns the new **String struct**.

### val(String *string)

```C
char *actualCharValue = val(&string);
```

Returns **char pointer** of **actual char value** i.e. **"str" field**.

**Parameters**

- **String:** **String** of which the **"str"** field is required.

### addChar(String *string, char c)

```C
int addCharStatus = addChar(&string, c);
```

Concatenates **char c** to **String string**, updating the allocated memory if required and updating **ulen** and **alen** accordingly. Returns **0** if **concatenation operation was successful** or **-1** if the **operation failed** due to **Memory Overflow**.

**Parameters**

- **String:** **String** on which the **char** has to be concatenated.
- **char:** **char** which has to be concatenated.

### add(String *string, String *toBeConcatenated)

```C
int addStatus = add(&string, &toBeConcatenated);
```

Concatenates **String toBeConcatenated** to **String string**, updating the allocated memory if required and updating **ulen** and **alen** accordingly. Returns **0** if **concatenation operation was successful** or **-1** if the **operation failed** due to **Memory Overflow**.

**Parameters**

- **String:** **String** on which the **String** has to be concatenated.
- **String:** **String** which has to be concatenated.

### addStr(String *string, char *toBeConcatenated)

```C
int addStatus = addStr(&string, toBeConcatenated);
```

Concatenates **char pointer toBeConcatenated** to **String string**, updating the allocated memory if required and updating **ulen** and **alen** accordingly. Returns **0** if **concatenation operation was successful** or **-1** if the **operation failed** due to **Memory Overflow**.

**Parameters**

- **String:** **String** on which the **char pointer** has to be concatenated.
- **char pointer:** **char pointer** which has to be concatenated.

### indx(String *string, String *toBeFound)

```C
int pos = indx(&string, &toBeFound);
```

Returns position of **first occurence** of **String toBeFound** if it is found, else returns **-1**.

**Parameters**

- **String:** **String** in which **String toBeFound** will be searched.
- **String:** **String** which has to be searched.

### indxStr(String *string, char *toBeFound)

```C
int pos = indxStr(&string, toBeFound);
```

Returns position of **first occurence** of **char pointer toBeFound** if it is found, else returns **-1**.

**Parameters**

- **String:** **String** in which **char pointer toBeFound** will be searched.
- **char pointer:** **char pointer** which has to be searched.

### sindx(char *charString, char *toBeFound)

```C
int pos = sindx(charString, toBeFound);
```

Returns position of **first occurence** of **char pointer toBeFound** if it is found, else returns **-1**.

**Parameters**

- **char pointer:** **char pointer** in which **char pointer toBeFound** will be searched.
- **char pointer:** **char pointer** which has to be searched.

### contains(String *string, String *toBeFound)

```C
int containsStatus = contains(&string, &toBeFound);
```

Returns **1** if **String string** contains **String toBeFound** else **0**.

**Parameters**

- **String:** **String** in which **String toBeFound** will be searched.
- **String:** **String** which has to be searched.

### containsStr(String *string, char *toBeFound)

```C
int containsStatus = containsStr(&string, toBeFound);
```

Returns **1** if **String string** contains **char pointer toBeFound** else **0**.

**Parameters**

- **String:** **String** in which **char pointer toBeFound** will be searched.
- **char pointer:** **char pointer** which has to be searched.

### scontains(char *charString, char *toBeFound)

```C
int containsStatus = scontains(charString, toBeFound);
```

Returns **1** if **char pointer charString** contains **char pointer toBeFound** else **0**.

**Parameters**

- **char pointer:** **char pointer** in which **char pointer toBeFound** will be searched.
- **char pointer:** **char pointer** which has to be searched.

### replace(String *string, String *toBeFound, String *toBeReplaced)

```C
string = replace(&string, &toBeFound, &toBeReplaced);
```

Returns **New String** which was generated by replacing **String toBeFound** with **String toBeReplaced** on **all occurences**.

**Parameters**

- **String:** **String** in which **String toBeFound** will be searched and replaced with **String toBeReplaced**.
- **String:** **String** which has to be searched.
- **String:** **String** which has to be replaced with **String toBeFound**.

### replaceStr(String *string, char *toBeFound, char *toBeReplaced)

```C
string = replaceStr(&string, toBeFound, toBeReplaced);
```

Returns **New String** which was generated by replacing **char pointer toBeFound** with **char pointer toBeReplaced** on **all occurences**.

**Parameters**

- **String:** **String** in which **char pointer toBeFound** will be searched and replaced with **char pointer toBeReplaced**.
- **char pointer:** **char pointer** which has to be searched.
- **char pointer:** **char pointer** which has to be replaced with **char pointer toBeFound**.

### substring(String *string, int startIndex, int endIndex)

```C
String subString = substring(&string, startIndex, endIndex);
```

Returns **New String** which was generated by characters which were present between **startIndex** and **endIndex** (including **startIndex** and excluding **endIndex**).

**Parameters**

- **String:** **String** for which **substring** will be generated.
- **int:** **index** from which the characters will be included (including the **index** itself).
- **int:** **index** till which the characters will be included (excluding the **index** itself).

### strsubstring(char *charString, int startIndex, int endIndex)

```C
String subString = strsubstring(charString, startIndex, endIndex);
```

Returns **New String** which was generated by characters which were present between **startIndex** and **endIndex** (including **startIndex** and excluding **endIndex**).

**Parameters**

- **char pointer:** **char pointer** for which **substring** will be generated.
- **int:** **index** from which the characters will be included (including the **index** itself).
- **int:** **index** till which the characters will be included (excluding the **index** itself).

### ssubstring(char *charString, int startIndex, int endIndex)

```C
char *subString = ssubstring(charString, startIndex, endIndex);
```

Returns **New char pointer** which was generated by characters which were present between **startIndex** and **endIndex** (including **startIndex** and excluding **endIndex**).

**Parameters**

- **char pointer:** **char pointer** for which **substring** will be generated.
- **int:** **index** from which the characters will be included (including the **index** itself).
- **int:** **index** till which the characters will be included (excluding the **index** itself).

### trim(String *string, int startIndex, int endIndex)

```C
trim(&string, startIndex, endIndex);
```

Trims **String string** by replacing whole **char value** with **substring of char value** using **substring(&string, startIndex, endIndex)**. 

**Parameters**

- **Same as substring() function.**

### strim(char *charString, int startIndex, int endIndex)

```C
strim(charString, startIndex, endIndex);
```

Trims **char pointer charString** by replacing whole **char value** with **substring of char value** using **ssubstring(charString, startIndex, endIndex)**. 

**Parameters**

- **Same as ssubstring() function.**

### isNumeric(String *string)

```C
int numericStatus = isNumeric(&string);
```

Returns **1** if **String string** is numeric else **0**.

**Parameters**

- **String:** **String** to be checked.

### isStrNumeric(char *charString)

```C
int numericStatus = isStrNumeric(charString);
```

Returns **1** if **char pointer charString** is numeric else **0**.

**Parameters**

- **char pointer:** **char pointer** to be checked.

### toInteger(String *string)

```C
int numericString = toInteger(&string);
```

Returns **int version** of **String string**. The algorithm **ignores non-numeric characters**.

**Parameters**

- **String:** **String** to be converted.

### strToInteger(char *charString)

```C
int numericString = strToInteger(charString);
```

Returns **int version** of **char pointer charString**. The algorithm **ignores non-numeric characters**.

**Parameters**

- **char pointer:** **char pointer** to be converted.

### clear(String *string)

```C
clear(&string);
```

Sets **"ulen"** field to **0**, hence **over-writing any existing data** on **subsequent add()/addChar()** calls.

**Warning**

Calling **clear() does not delete the existing data which was present in the allocated heap memory**. 

**Parameters**

- **String:** **String** to be freed.

### freestr(String *string)

```C
freestr(&string);
```

Frees **"str" field** i.e. **char pointer containing the actual character value of the String** using **free()**, clearing the **allocated heap memory**.

**Parameters**

- **String:** **String** to be freed.
