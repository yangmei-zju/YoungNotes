c小程的错题以及一些零碎的知识点总结。<br />参考
> https://www.yuque.com/linguisty/zju_courses/correction_of_c#OJEwz




<a name="YLGCx"></a>
## 理论
> - 运算符
>    - C 语言中`5/9`等于 0，而`5.0/9`等于 0.555……
>    - `-7/2 = -3; 7/2 = 3;`
>    - 使用乘法时要用*，`2*i-1`。

```c
#include <stdio.h>
int main ()
{
    int n;
    double sum = 0;
    scanf("%d",&n);
    for (int i = 1; i <=n;i++)
    {
        sum = sum + 1.0/(2*i - 1);
    }
    printf("sum = %.6f",sum);
    return 0;
}
```
> - 检查该赋值的变量是否都赋值了或者初始化了。
>    - 初始化`int a , b = 0;`a未被初始化，b初始化为0。
> - 判断相等关系是`==`不是`=`，单个等号是赋值符。

```c
int x, y;
scanf("%d", &x);
if (x > 0){ 
    y = 1;
}else if (x = 0){
    y = 0;
}else{
   y = -1;
}  
//输入-10，x的值为0;
//输入10，x的值为10。
```
> - do-while 循环的`while(循环条件);`最后面是有分号的。
>    - `#define MAX 11` 无分号。
>    - `double fact(int n);`函数声明放在开头需要`;`。
>    - `struct student{ };`
> - switch - case 语句
>    - 检查 switch 语句中各个 case 后面是否需要`break;`。
>    - 不使用`break`时，将从相等的常量表达式开始，执行其后所有语句直到`break;`或者执行完所有情况。
>    - 在`switch` 语句中，表达式和常量表达式的值一般是整型或字符型，所有的常量表达式的值都不相等。

```c
switch ( k ) {
    case 1: printf("one"); break;
    case 2: printf("two"); break;
    case 1: printf("one"); break;
    default: printf("zero"); break;
}//常量重复
n = 10;
switch ( k ) {
    case n%3: printf("one");
    case n%4: printf("two");
    default: printf("zero");
}//非常量
switch ( k%2 ) {
    default: printf("zero"); break;
    case 1: printf("one");
    case 1+1: printf("two");
}//这是对的



```
> - 填空题注意检查有没有通过`++`、`--`和指针对变量的修改。
> - 要用 strlen( ) 等函数的话别忘了引用 string.h 头文件。

- 输入scanf（），`scanf("%d",&x);`。检查输入输出尤其是输出的格式。
- `gets() puts()`在PTA使用时会报错。
- 判断题
   1. 若变量定义为double x;，则x % 2是符合C语言语法的表达式。取整运算符只能是对整型。✔️
   2. 假设某段C语言程序中定义了三个变量a、b和c并且三个变量都不为0，则表达式a / b * c和a * c / b是等价的，其值相同。❌
- for循环不是从`i = 0`开始时，要检查未进入循环的特殊情况；double n ＝1/2，此时n为0.，因为先计算1/2为0，再将0转化为double类型0.，所以不能因为变量类型为double，就认为结果为浮点数，计算过程不用浮点数，必须用1.0/2进行计算。
> - 写出满足下列条件的C表达式：<br />“year 是闰年，即 year 能被 4 整除但不能被 100 整除，或 year 能被 400 整除。”<br />一种正确解答：year%4==0 && year%100!=0 || year%400==0<br />可以这么记：||长得更高，优先级却反而比&&低。<br />当然，记不住这个优先级是很正常的，写代码的人最好考虑到读代码的人的感受。所以更好的解答是：((year%4==0) && (year%100!=0)) || (year%400==0

> - 在C程序运行过程中，其值不能被改变的量称为常量，其值可以改变的量称为变量。（✔️）<br />有些同学学到后来会把“标识符”和“变量”搞混，以为标识符就是变量名。标识符是用户编程时使用的名字，用于给变量、常量、函数等命名，以建立起名称与实体之间的关系。

![](https://cdn.nlark.com/yuque/0/2022/jpeg/25775350/1652962262468-67220a9a-e64e-4711-acd2-3417ba8b8b64.jpeg)

- 表达式`(z=0, (x=2)||(z=1),z)`的值是（ 0 ）

用printf( )打印这个逗号表达式的值，输出0。整个逗号表达式的值是最后一个分句的值。在||处，x=2的返回值是2，表示true，所以整个逻辑表达式的值一定是true，所以后面的z=1就不执行了，直接返回整个逻辑表达式的值为1。如果||左边是x=0，返回0，就得继续执行z=1才能判断整个逻辑表达式是true还是false，逻辑表达式的值为1。<br />这种只计算逻辑表达式的一部分就已经能确定整个逻辑表达式的值的现象称为“逻辑短路”。<br />exp1 && exp2,若为exp1为false,则不对exp2操作，逻辑表达式值为0； exp1|| exp2,若exp1为true,则不计算exp2，逻辑表达式的值为1.

- 为了检查以下 if-else 语句的两个分支是否正确，至少需要设计 3 组测试用例。（✔️）

测试的时候一定要单独测试临界点。尽管这里 x 等于 15 的情况也是进入`if(x <= 15)`的分支，但必须单独测试，也就是需要 x 小于 / 等于 / 大于 15，三种测试用例。
```c
if (x <= 15)
{ 
   y = 4 * x / 3;
} 
else
{
   y = 2.5 * x - 10.5;
}
```

- 在C语言的函数定义中，如果省略了return语句，函数就无法返回主调函数。❌
- 若表达式sizeof(int)的值为4，则int类型数据可以表示的最大整数为2^31−1。✔️
```c
char str[]= "abc\0def\0ghi", *p = str;
    
  printf("%s", p+5) ;//答案为 ef,printf()遇到'\0'则结束输出
```

- 构造类型-数组，结构，指针
   - `int *s,a[] = {1,3,5}``s[0] = a[0]`是错误的赋值方法，s为赋值，不指向一个数组，不能用s[0];`s = &a[1]`s为a[1]的地址
   - `char s1[] = "hello,world";s1[0] = 'H';puts(s1);`s1是省略数组长度的字符数组名，所指向的字符串存放在堆栈。`char *s2 = "hello,world";s2[0] = 'H';puts(s2);`s2指向字符串常量"hello,world"的字符指针，所指向的字符串存放在文字常量区。文字常量区存放的字符串常量不允许修改，因此错误。
   - `char str[] = "hello\t\0world\n";printf("%d %d %c",sizeof(str),strlen(str),``*(str+10));`注意转义字符\t\0\n，\x是一个字符，而不是三个字符，sizeof全部字符，strlen()，'\0'之前的所有字符且不记'\0'。
- 静态局部变量以及全局变量
- 运算符的优先级与结合性
- 运算及流程控制
   - 表达式语句、空语句、复合语句
   - 控制语句`break,continue,return`
   - 选择控制 `if(),if else(),else\switch(),case,break`
   - 循环语句`for (statement0;statement1;statement2)`
      - for(c = getchar(）；getchar() != '#';c = getchar()) putchar(c);输入12345#输出13
<a name="ypISs"></a>
## 书本知识点：
> 可能考的定义性和概念性的知识点，以及书上需要注意的易错点。

- C程序由函数构成。
- 程序设计语言必须具备数据表达和流程控制的功能。
- C语言中标识符由字母、数字、下划线构成，第一个字符不可以是数字；C语言中，标识符中英文字母的大小写形式是有区别的。
- C语言生成的目标代码质量高，运行效率高。
- C语言是编译型语言，移植性比较不好。
- else 和 if 匹配原则：else 与最靠近它的，没有别的else匹配的if 相匹配。(与缩进无关，但是易错）
   - 改变配对：
      - 使用大括号，构造复合语句；
      - 增加空的else。
- C程序中定义的变量，代表内存中的一个存储单元。
- 编译程序 首先要对 源程序 进行 [**词法分析**](https://zh.wikipedia.org/wiki/%E8%AF%8D%E6%B3%95%E5%88%86%E6%9E%90)，然后进行 [**语法分析**](https://zh.wikipedia.org/wiki/%E8%AF%AD%E6%B3%95%E5%88%86%E6%9E%90) 和 **语义分析**
- 编写程序  **->**  编译生成二进制obj目标程序文件  **->**  **与库函数进行连接**，形成exe可执行文件。
- 函数
   - 函数的实参可以是常量，变量和表达式，其作用是把常量，变量或者表达式的值传递给形参；形参必须是变量，用于接受实参传过来的值。实参与形参一一对应，数量应相同，顺序应一致，类型尽量保持一致
   - return 语句只能返回一个值。
   - 在不返回结果的函数`void`不能省略；否则，函数类型被默认定义为`int`

<a name="JY9Lt"></a>
## 书本笔记
> 自己不熟悉了解必须记忆的知识点

> - 随机数：
> 
`#include <time.h>`
> `srand(time(0));//设定随机数的产生与系统始终相关联`
> `randnumber = rand()%100 + 1;//计算机随机产生一个1~100的随机数`

- 局部变量与全局变量
   - C语言中把定义在函数内部（包括main函数）以及复合语句{}的变量称为局部变量，有效作用范围局限于函数内部或者复合语句内；局部变量一般定义在函数或者复合语句的开始处，标准C规定其不能定义在中间位置。
   - 定义在函数外而不属于任何函数的变量称为全局变量。作用范围从定义开始到程序所在文件的结束，对作用范围内的所有函数都起作用。一般（也可定义在其他函数外部地方）定义在程序的最前面，即第一个函数的前面。
   - 函数的局部变量与全局变量同名时，在该函数中全局变量不起作用，而由局部变量起作用。
- 变量生存周期与静态局部变量
   - 自动变量：函数调用时，系统自动为其局部变量分配内存；一旦函数调用结束（不一定是整个程序运行结束），所有分配给局部变量的单元由系统自动回收。
   - 静态局部变量: 生存周期会持续到程序结束，一旦含有静态局部变量的函数被再次调用，则静态局部变量会被重新激活，上一次函数调用后的值仍旧保存，可供本次调用继续使用。（赋初值只在函数第一次调用时起作用，若未赋初值，系统自动赋为0）
- 逻辑表达式
   - 逻辑运算符
   - 逻辑表达式：用逻辑符将关系表达式或逻辑量连接起来的式子。`!(x == 2)`是逻辑表达式，`!x == 2`是关系表达式，等价于`(!x) == 2`此时该式的逻辑值恒为0.
> - 数组
>    - 定义类型名指定数组中每个元素的类型；数组名是数组变量的名称，是一个合法的标识符；数组长度是一个整型常量表达式，设定数组的大小。数组长度是一个常量。定义数组之后，系统根据数组中元素的类型及个数在内存中分配了一段连续的存储单元用于存放数组的各个元素。
>    - 数组名是一个地址常量，存放数组内存空间的首地址。
>    - 定义数组时，方括号内是常量表达式，代表数组长度，它可以包括常量和符号常量，但不能包括变量。而引用数组元素时，方括号内是表达式，代表下标，可以是变量，下标的合理取值范围是[0，数组长度-1]。
>    - 定义二维数组时，不能省略列长度。


> - 指针

   - 指针变量可以进行加减运算，例如p++、p+i、p-=i。指针变量的加减运算并不是简单的加上或减去一个整数，而是跟指针指向的数据类型有关。
   - 给指针变量赋值时，要将一份数据的地址赋给它，不能直接赋给一个整数，例如int *p = 1000;是没有意义的，使用过程中一般会导致程序崩溃。但是`int *p = 0`是将指针初始化为空指针，0是ASCII字符NULL的值。
   - 使用指针变量之前一定要初始化，否则就不能确定指针指向哪里，如果它指向的内存没有使用权限，程序就崩溃了。对于暂时没有指向的指针，建议赋值NULL。
   - 两个指针变量可以相减。如果两个指针变量指向同一个数组中的某个元素，那么相减的结果就是两个指针之间的元素个数。
   - 数组也是有类型的，数组名的本意是表示一组类型相同的数据。在定义数组时，或者和 sizeof、& 运算符一起使用时数组名才表示整个数组，表达式中的数组名会被转换为一个指向数组首地址的指针。
- <br />
<a name="wIwcD"></a>
## 实验
<a name="tpLm1"></a>
### 技巧性的编程片段

-   统计字符时读入并舍弃换行符
```c
#include <stdio.h>
int main()
{
   int n;
    scanf("%d",&n);
    getchar();//读入并舍弃换行符；若无此步操作，则'\n'会被当做第一个输入的ch
    for (int i = 0; i < n ; i++)
    {
    	ch = getchar();
        if (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            letter ++;
        }
        else if(ch >='0' && ch <= '9')
        {
            digit ++;
        }
        else 
        {
            other ++;
        }
    }
    
    printf("letter = %d,",letter);
    printf(" digit = %d,",digit);
    printf(" other = %d",other);
    return 0;
}
```

- 输入30，输出30.00 。❌实际输出了0.00，原因在于`scanf("%lf",x)`。
```c
double x;   
scanf("x=%lf", &x);  
printf("%.2f", x);   

```

- 循环
   - 循环内局部变量的初始化
```c
int i, sum;
for (i = 1; i <= 10; i++){
    sum = 0;//sum = 0初始化在for循环内部，则每次循环开始的sum值均为0。
    sum = sum + i;
}
```

   - 对于循环中的判断条件和改变对象，要注意在循环体内是否被改变。
   - 不要随意改变判断循环条件的值
```c
for(num = 1; num <= 100; num++){ 
    s = 0;
    do{
       s = s + num % 10;
       num = num / 10;
    }while(num != 0);//循环完毕后num为0
    printf("%d\n", s); 
}

```

   - 未进入循环的其他特殊情况
```c
int isprime(int n)
{
    if(n <= 1)
    {
        return 0;
    }
    else if(n == 2)
    {
    	return 1;
    }
    else //i是从i= 2 开始的，当 n < 2还要另外判断
    {
        for(int i = 2; i <= sqrt(n) + 1; i++)
        {
            if(n % i == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}
```

- if-else结构
```c
mynumber = 38;
scanf ("%d", &yournumber); 
if(yournumber == mynumber){ 
    printf("Right");
}
if(yournumber > mynumber ){   //不是else if与前面的if不构成分支结构
    printf("Big");
}else{ 
    printf("Small");//输入38，输出RightSmall
}
```

- 使用一些标记变量flag表示真假有无状态
```c
#include <stdio.h>//输出21世纪截止某个年份的闰年
int main()
{
    int n;
    int flag = 1;
    scanf("%d",&n);
    if(n > 2000 && n <= 2100)
    {
        for (int i = 2001; i <= n; i++)
        {
            if ( (i % 4 == 0 && i % 100 != 0)||i % 400 == 0)
            {
                printf("%d\n",i);
                flag = 0;
            }
        }
        if (flag)
            printf("None");
        /*for (int j = 2001; j<= n; j++)
        {
            if( (j % 4 == 0 && j % 100 != 0)||j % 400 == 0)
            {
                break;
            }
            if(j == n)
                printf("None\n");
        }*/ //若没有闰年则输出None,这种写法有点麻烦
    }
    else
    {
        printf("Invalid year!\n");
    }
    return 0;
}
```

- 统计单词个数：本题目要求编写程序统计一行字符中单词的个数。所谓“单词”是指连续不含空格的字符串，各单词之间用空格分隔，空格数可以是多个。
   - 测试点有多个：开始输入空格，空格连续多个，结尾 . 后面添加空格
```c
//原始办法，只是根据特殊情况分开讨论
#include <stdio.h>
int main()
{
    char ch;
    int count = 0;
    while((ch = getchar()) == ' ');//开始时如果多个空格
    if(ch == '\n')
        printf("0 ");//开始时输入\n
    while(ch != '\n')
    {
        while(ch != ' '&& ch != '\n')//最后结束的那段单词
        {
            count ++;
            ch = getchar();
        }
        printf("%d ",count);
        count = 0;
        if(ch != '\n')
        {
            while(( ch = getchar()) == ' ');//当有多个空格时使用while循环把空格只读入
        }
    }
    printf("\n");
    return 0;
}
//我的改进还是有点奇怪 思路仍旧关注的是' '的个数
s#include<stdio.h>
int main()
{
    char ch;
    int word = 0;
    int count = 0;
    while((ch = getchar()) != '\n')
    {
        if(word == 1) //' '之前为单词
        {
            if(ch == ' ')
            {
                count ++;//前面为单词的空格数量增加
                word = 0;//Word为0，表示无新单词
            }
        }
        if(ch != ' ')
        {
            word = 1;   //表示为单词
        }
    }
    printf("%d",count + word);//计算单词数量如果结尾为' ' 则不加1，若结尾为普通字符则加1
    return 0;
}
//教材解答 思路关注的是遇到新单词个数
#include <stdio.h>
int main()
{
    int cnt = 0, word = 0;//cnt单词个数，Word是新单词标识，初值为0，表示还未遇到新单词
    char ch;
    while((ch = getchar()) != '\n')
    {
        if (ch == ' ')
        {
            word = 0;     //word赋0，表示还未遇到新单词
        }
        else if (word == 0)//读入非空格且word为0 ，为单词的首字符
        {
            word = 1;      //word赋1，表示遇到新单词
            cnt ++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
```

- 求一个整数的逆序数
```c
int reverse( int number)
{
    int rev = 0;
    int sign = 1;
    if(number < 0)
    {
        sign = -1;
        number = - number;
    }
    else if(number == 0)
    {
        return 0;
    }
    else 
    
    //原本的思路 还有一种奇怪的思路把数字的各位数字分别依次输出，但是个位为0不易处理

   /* {
     int p = 1;
    int sum = 0;
    int  t = number;
    while(t > 10)
    {
        t = t / 10;
        p = p * 10;//通过p可以求出number的位数
    }
    int m = 1;
    while(number != 0)
    {
        t = number / p;//此时的t为number从高到低的各位数字
        sum = sum + m * t;//最高位数字变为个位，从高到低位数增加的表达式这种方法可以用来求数的各位数正序输出
        m = m * 10; 
        number = number % p; 
        p = p / 10;
    }
    return sign * sum;
}*/
        while( number != 0)
        {
            rev = rev * 10 + number % 10;//这步表达很关键最低位数字一直随着rev乘10所占位增高
            number = number / 10;
        }
    }
    return sign * rev;
}
```

- 顺序输出整数的各位数字
```c
int digit, number, pow, t_number; 
scanf ("%d", &number);
t_number = number;
pow = 1;
while (t_number>10)
{
    pow = pow*10;
    t_number = t_number / 10;       
}  
while ( pow >= 1 ) 
{
    digit = number/pow;
    number = number%pow;
    pow = pow/10;
    printf ("%d ", digit);
}
printf ("\n");
```

- 统计单词的长度
```c
#include <stdio.h>
int main()
{
    char ch;
    int count = 0;
    while((ch = getchar()) == ' ');//开始时如果多个空格
    if(ch == '\n')
        printf("0 ");//开始时输入\n
    while(ch != '\n')
    {
        while(ch != ' '&& ch != '\n')//最后结束的那段单词
        {
            count ++;
            ch = getchar();
        }
        printf("%d ",count);
        count = 0;
        if(ch != '\n')
        {
            while(( ch = getchar()) == ' ');//当有多个空格时使用while循环把空格只读入
        }
    }
    printf("\n");
    return 0;
}
这道题需要注意的地方很多
```

- 字符串：
   - 结束处添上`'\0'`;
 ```c
 while((a[i] = getchar())!= '\0')
       {i ++;}
  ```
- 数组
   - 注意是从0开始计数，当结果与数组的序数有关如月份时，注意转换。可以将第0个元素设为0，后面使用数组不引用。
<a name="bdW9A"></a>
### 编程错题
```c
/*函数search在字符串s中查找子串t，返回子串t在s中的首地址。若未找到，则返回NULL。*/
char *search( char *s, char *t)
{
    while (*s != '\0' )
    {
        char *p = m;//需要t在s中的首地址
        char *temp = t;//如果没有此步，在第一次进入if语句中，指针t的值改变，只关注了s中指针的移动
        if(*temp == *p )
        {
            char *q = p;
            while(*temp != '\0' && *p != '\0' )
            {
                if(*p != *temp)
                {
                    break;
                }
                p ++;
                temp ++;
            }
            if(*temp == '\0')
            {
                return q;
            }
        }
        s ++;
    }
    return NULL;
}
```
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 80
int main()
{
    int n = 5, index;
    /*char s[n][MAX];*/字符数组与指针
    char *s[n];
    for(int i = 0; i < n; i++)
    {
        s[i] = malloc(MAX*sizeof(char));
        scanf("%s",s[i]);
    }
    for(int i = 0; i < n; i ++)
    {
        for(int j = i; j < n; j ++)
        {
            index = i;
            if(strcmp(s[index], s[j]) < 0)
            {
                index = j;
            }
            /*char t[MAX];
            strcpy(t,s[index]);//这里不能用t = s[index];但是把 t 和s[index]都看成是指针
            strcpy(s[index], s[j]);
            strcpy(s[j], t);*/
            char *t = s[index];
            s[index] = s[j];
            s[j] = t;
        }
    }
    printf("After sorted:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%s\n",s[i]);
    }
    return 0;
}

```

