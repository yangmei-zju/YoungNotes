[website](https://inst.eecs.berkeley.edu/~cs61a/su20/)  [https://inst.eecs.berkeley.edu/~cs61a/su20/](https://inst.eecs.berkeley.edu/~cs61a/su20/)
[textbook](http://composingprograms.com/pages/11-getting-started.html) [http://composingprograms.com/pages/11-getting-started.html](http://composingprograms.com/pages/11-getting-started.html)
> And, as imagination bodies forth
> The forms of things to unknown, and the poet's pen
> Turns them to shapes, and gives to airy nothing
> A local habitation and a name.
> —William Shakespeare, A Midsummer-Night's Dream

[20230116~20230116] week1
[20230117~20230117] week1
[20230118~20230118] week2
[20230119~20230119] week2 
[20230120~20230120] week3
[20230121~20230121] week3
## 1.1 Getting started

- **Statements & Expressions**. Python code consists of expressions and statements. Broadly, computer programs consist of instructions to either
1. Compute some value
2. Carry out some action
- **Functions**. Functions encapsulate logic that manipulates data. 
- **Objects**. A **set** is a type of object, one that supports set operations like computing intersections and membership. An object seamlessly bundles together data and the logic that manipulates that data, in a way that manages the complexity of both. 
- **Interpreters**. Evaluating compound expressions requires a precise procedure that interprets code in a predictable way. A program that implements such a procedure, evaluating compound expressions, is called an interpreter. 
```python
from urllib.request import urlopen)
shakesphere = urlopen('http://composingprograms.com/shakespeare.txt')
words = set(shakespeare.read().decode().split())
{w for w in words if len(w) == 6 and w[::-1] in words}
{'redder', 'drawer', 'reward', 'diaper', 'repaid'}
```

- **Errors Messages**
   - **Error Types**
      1. SyntaxError        Contained improper syntax (e.g. missing a colon after an if statement or forgetting to close parentheses/quotes)
      2. IndentationError Contained improper indentation (e.g. inconsistent indentation of a function body)
      3. TypeError            Attempted operation on incompatible types (e.g. trying to add a function and a number) or called function with the wrong number of arguments
      4. ZeroDivisionError Attempted division by zero
- **Command line**
   - ls: **l**i**s**ts all files in the current directory
   - cd <path to directory>: **c**hange into the specified **d**irectory
   - mkdir <directory name>: **m**a**k**e a new **dir**ectory with the given name
   - mv <source path> <destination path>: **m**o**v**e the file at the given source to the given destination
## 1.2 Elements of Programming
 

- **Importing Library Functions**
```python
from math import sqrt
sqrt(256)

from operator import add, sub, mul
add(14, 28)
sub(100, mul(7, add(8, 4)))

from math import pi
```

- **Names and the Environment**

After assigning **max** to 5, the name **max** is no longer bound to a function, and so attempting to call **max(2, 3, 4)** will cause an error. So in python program,we should use  variable names like max_length.
When executing an assignment statement, Python evaluates the expression to the right of **=** before changing the binding to the name on the left. Therefore, one can refer to a name in right-side expression, even if it is the name to be bound by the assignment statement.

- **Functions**
1. **Pure functions.** Functions have some input (their arguments) and return some output (the result of applying them).
2. **Unpure functions. **
## 1.3 Function

- When it comes to division, Python provides two infix operators: **/** and **//**. The former is normal division, so that it results in a _floating point_, or decimal value, even if the divisor evenly divides the dividend. The **//** operator, on the other hand, rounds the result down to an integer.
- **Documentation**
   - A function definition will often include documentation describing the function, called a _docstring_, which must be indented along with the function body. Docstrings are conventionally triple quoted. The first line describes the job of the function in one line. The following lines can describe arguments and clarify the behavior of the function.
- **Comments**.
   - Comments in Python can be attached to the end of a line following the **#** symbol.
- **Default Argument Values**
```python
def pressure(v, t, n=6.022e23):# the = is not a asignment
        """Compute the pressure in pascals of an ideal gas.

        v -- volume of gas, in cubic meters
        t -- absolute temperature in degrees kelvin
        n -- particles of gas (default: one mole)
        """
        k = 1.38e-23  # Boltzmann's constant
        return n * k * t / v

>>> pressure(1, 273.15)
2269.974834
>>> pressure(1, 273.15, 3 * 6.022e23)
6809.924502
```

- When Python executes a return statement, the function terminates immediately. If Python reaches the end of the function body without executing a return statement, it will automatically return None.
## 1.5 Control

- **Boolean Operators**
   - an order of operation:not > and > or
   - Python values such as 0, None, '' (the empty string), and [] (the empty list) are considered false values. _All_ other values are considered true values.
   - **Short Citrcuiting**
| **oprator** | **checks if:** | **evaluates from left to right up to** | **example** |
| --- | --- | --- | --- |
| and | all value are true  | the first value false | `False and 1/0`evaluates `False` |
| or | at least one value is true | the first value true | `True or 1/0`evaluates `True`
 |

      - If and and or do not _short-circuit_, they just return the last value; another way to remember this is that and and or always return the last thing they evaluate, whether they short circuit or not. Keep in mind that and and or don't always return booleans when using values other than True and False.
```python
>>> 1 and 1 > 0
True

>>> True and 13
13

>>> False and 10
False

>>> 1 or 1/0
1

>>> 1 and 1/0
ZeroDivisonError
```

## H1 Debugging
```python
File "<file name>", line <number>, in <function> 

<error type>: <error message>  

Traceback (most recent call last):
  File "<pyshell#29>", line 3 in <module>   #Traceback Messages
    result = buggy(5)   # the secondline displays the actual line of code that makes the next function cal
  File <pyshell#29>", line 5 in buggy
    return f + x
TypeError: unsupported operand type(s) for +: 'function' and 'int' #Error Messages
```
### **Debugging techniques**
#### **Running doctests**
Python has a great way to quickly write tests for your code. These are called doctests, and look like this:
```python
def foo(x):
    """A random function.

    >>> foo(4)
    4
    >>> foo(5)
    5
    """
```
`python -m doctests file.py`type this in the terminal , it loads your file into the Python interpreter, and checks to see if each doctest input (e.g. foo(4)) is the same as the specified output (e.g. 4). If it isn't, a message will tell you which doctests you failed.
`python -m doctests file.py -v`v stands for _verbose. _In addition to telling you which doctests you failed, it will also tell you which doctests passed.
#### **Writing you own tests**
#### **Using **`**print**`** statement**
```python
def foo(x):
    result = some_function(x)
    print('DEBUG: result is', result)
    tmp = other_function(result)
    print('DEBUG: other_function returns', tmp)
    '''
    Note:prefixing debug statements with the specific string "DEBUG: " 
    allows them to be ignored by the ok autograder used by cs61a.
 	'''
    return tmp

```
#### **Long-term debugging**
```python
debug = True # a global variable

def foo(n):
i = 0
while i < n:
    i += func(i)
    if debug:
        print('DEBUG: i is', i)
```
#### **Interactive Debugging**
`python -i file.py`** **run this statement in the terminal, and then has a session of python where all the difinitions of `file.py`have already been executed.
`python ok -q <question name> -i` If you are using the ok autograder, it has a specific tool that enables you to jump into the middle of a failing test case.
#### **Using **`**assert**`**statements**
```python
def double(x):
    assert isinstance(x, int), "The input to double(x) must be an integer"
    return 2 * x

```
### Error Types
#### SyntaxError

- **Cause**: code syntax mistake
- **Example**:
```python
File "file name", line number 
def incorrect(f)
			    ^
SyntaxError: invalid syntax
```

- **Solution**: the ^ symbol points to the code that contains invalid syntax. The error message doesn't tell you _what_ is wrong, but it does tell you _where_.
- **Notes**: Python will check for SyntaxErrors before executing any code. This is different from other errors, which are only raised during runtime.
#### IndentationError

- **Cause**: improper indentation
- **Example**:  
```python
File "file name", line number   
print('improper indentation') 
IndentationError: unindent does not match any outer indentation level
```

- **Solution**: The line that is improperly indented is displayed. Simply re-indent it.
- **Notes**: If you are inconsistent with tabs and spaces, Python will raise one of these. Make sure you use spaces! (It's just less of a headache in general in Python to use spaces and all cs61a content uses spaces).
#### TypeError

- **Cause 1**:
   - Invalid operand types for primitive operators. You are probably trying to add/subract/multiply/divide incompatible types.
   - **Example**:
```python
TypeError: unsupported operand type(s) for +: 'function' and 'int'
```

- **Cause 2**:
   - Using non-function objects in function calls.
   - **Example**:
```python
>>> square = 3 
>>> square(3)
Traceback (most recent call last):   ... 
TypeError: 'int' object is not callable
```

- **Cause 3**:
   - Passing an incorrect number of arguments to a function.
   - **Example**:
```python
>>> add(3) 
Traceback (most recent call last):   ... 
TypeError: add expected 2 arguments, got 1
```
#### NameError

- **Cause**: variable not assigned to anything OR it doesn't exist. This includes function names.
- **Example:**
```python
:File "file name", line number   
y = x + 3 
NameError: global name 'x' is not defined
```

- **Solution**: Make sure you are initializing the variable (i.e. assigning the variable to a value) before you use it.
- **Notes**: The reason the error message says "global name" is because Python will start searching for the variable from a function's local frame. If the variable is not found there, Python will keep searching the parent frames until it reaches the global frame. If it still can't find the variable, Python raises the error.
#### IndexError

- **Cause**: trying to index a sequence (e.g. a tuple, list, string) with a number that exceeds the size of the sequence.
- **Example:**
```python
File "file name", line number   
x[100]
IndexError: tuple index out of range
```

- **Solution**: Make sure the index is within the bounds of the sequence. If you're using a variable as an index (e.g. seq[x], make sure the variable is assigned to a proper index.
### Common Bugs

- **Spelling**
- **Missing parentheses**
- **Missing closed quotes**
- `**=**`** VS **`**==**`
- **Infinite Loops**
- **Off-by-one errors**
## 1.6 High-order funtion
## Lec 6 Design
WAV Files encodes a simple sound wave
```python
from wave import open 
from struct import Struct
from math import floor
def tri(frequency,  amplitude = 0.3):
    """A continuous triangle wave."""
    period = frame_rate // frequency
    def sampler(t):
        saw_wave = t / period - floor(t / period + 0.5)
        tri_wave = 2 * abs(2 * saw_wave) - 1
        return amplitude * tri_wave
    return sampler
```

### Lec 7 Function Design
fuction decorators

