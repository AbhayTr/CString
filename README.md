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
int pos = indx(&string, toBeFound);
```

Returns position of **first occurence** of **char pointer toBeFound** if it is found, else returns **-1**.

**Parameters**

- **String:** **String** in which **char pointer toBeFound** will be searched.
- **char pointer:** **char pointer** which has to be searched.

### sindx(char *charString, char *toBeFound)

```C
int pos = indx(charString, toBeFound);
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
int containsStatus = contains(&string, toBeFound);
```

Returns **1** if **String string** contains **char pointer toBeFound** else **0**.

**Parameters**

- **String:** **String** in which **char pointer toBeFound** will be searched.
- **char pointer:** **char pointer** which has to be searched.

More details about the module will be updated soon. So stay tuned for more info...
