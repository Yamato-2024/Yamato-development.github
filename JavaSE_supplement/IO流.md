---
date: 2025-10-05
---
>**存储和读取数据的解决方案**
>用于读写文件中的数据

# 一、IO流的分类
## （一）字节流
![[Pasted image 20251005204608.png]]

### 字节输出流  FileOutputStream
| 方法名称                                   | 说明             |
| -------------------------------------- | -------------- |
| void write(int b)                      | 一次写一个字节数据      |
| void write(byte[] b)                   | 一次写一个字节数组数据    |
| void write(byte[] b, int off, int len) | 一次写一个字节数组的部分数据 |
#### 1.步骤
1. 创建字节输出流对象
	- 参数是字符串表示的路径或者[[File类]]对象皆可。
	- 父级路径存在，文件不存在，则创建一个文件写入。
	- 如果文件已经存在，则会覆盖文件。
2. 写数据
	- write方法的参数是整数，但实际上写到本地文件中的是整数所对应的ASCII值。
3. 释放资源
	- 每次使用完流后必须释放资源。
```java
 public static void main(String[] args) throws IOException {
        //1.创建对象
        FileOutputStream fos = new FileOutputStream("myio\\a.txt");
        //2.写出数据
        byte[] bytes = {97, 98, 99, 100, 101};
        fos.write(bytes, 1, 2);// b c
        //3.释放资源
        fos.close();
    }
```

#### 2.换行&续写
1. 换行：
```java
//再写一个换行符就行
String wrap = "\r\n";
byte[] Enter = wrap.getBytes();
fos.write(Enter);
```
2. 续写
	- 想续写需要打开续写开关（创建对象的第二个参数）。
	- 参数为空默认为false，表示关闭续写。

---
### 字节输入流  FileInputStream
#### 1.步骤
1. 创建字节输入流对象
	- 如果文件不存在，直接报错。
2. 读取数据
	- 一次读一个字节，读出来的是数据在ASCII上对应的数字。
	- 读到末尾，read方法返回-1。
3. 释放资源
	- 每次使用完流后必须释放资源。
```java
public static void main(String[] args) throws IOException {  
    FileInputStream fis = new FileInputStream("MyIO\\1test.txt");  
    int read = fis.read();  
    System.out.println((char)read);  
    fis.close();  
}
```

#### 2.循环读取
- read：表示读取数据，而且是读取一个数据就向后移动一次指针！！！[^1]
```java
 public static void main(String[] args) throws IOException {
        //1.创建对象
        FileInputStream fis = new FileInputStream("myio\\a.txt");
        //2.循环读取
        int b;
        while ((b = fis.read()) != -1) {
            System.out.print((char) b);
        }
        //3.释放资源
        fis.close();
    }
```

#### 3.文件拷贝
|方法名称|说明|
|---|---|
|`public int read()`|一次读一个字节数据（慢）|
|`public int read(byte[] buffer)`|一次读一个字节数组数据|
- 核心思想：边读取边写入
- 大文件copy：
	1. 一次读取一个字节数组的数据，读取会尽可能把数组装满，数组越长读取越快。
	2. 返回值：本次读取到多少个字节数据。
```java
public static void main(String[] args) throws IOException {  
    long strat = System.currentTimeMillis();  
  
    FileInputStream fis = new FileInputStream("E:\\...\\水门无运镜60帧.mp4");  
    FileOutputStream fos = new FileOutputStream("E:\\...\\copyplus.mp4");  
    //核心思想：边读边写  
    int len;  
    byte[] bytes = new byte[1024*1024*5]; //5Mb  
    while((len = fis.read(bytes)) != -1){ //一次读取5Mb个字节  
        fos.write(bytes, 0, len); //只写入与读取长度相同的字节数  
    }    
    fos.close();  
    fis.close();  //先开的后关闭
  
    long end = System.currentTimeMillis();  
    System.out.println("复制完毕，耗时：" + (end - strat) + "毫秒");  
}
```

---
## （二）字符集
### 常用字符集
#### 1. ASCII字符集
#### 2.GBK字符集
- 包含全部中日韩汉字，以及BIG5编码中的全部汉字Windows默认使用（系统显示ANSI）
- 规则：
	1. 汉字两个字节存储
	2. 高位字节二进制一定以“1”开头（区别英文字符），高位字节转成十进制后是个负数
#### 3.Unicode字符集
- 国际标准字符集（万国码）。
- 基于Unicode字符集的UTF-8编码规则：
	1. 各个语言用1~4个字节保存
	2. 英文占一个字节，二进制第一位为0
	3. 中文占三个字节，二进制第一位为1，第一个字节转化成十进制是负数

---

### 为什么会有乱码？
- 读取数据时未读取完整个汉字or编码和解码方式不统一
- 如何不产生乱码：
	1. 不用字节流读取文本文件（读时不同码表乱码，拷贝使用统一码表不会乱码）
	2. 编码和解码时使用同一个码表，同一个编码方式

---

### 编码和解码的实现
==IDEA默认UTF-8==
#### 1. Java 中编码的方法
| String 类中的方法                                 | 说明         |
| -------------------------------------------- | ---------- |
| `public byte[] getBytes()`                   | 使用默认方式进行编码 |
| `public byte[] getBytes(String charsetName)` | 使用指定方式进行编码 |
#### 2. Java 中解码的方法
| String 类中的方法                               | 说明         |
| ------------------------------------------ | ---------- |
| `String(byte[] bytes)`                     | 使用默认方式进行解码 |
| `String(byte[] bytes, String charsetName)` | 使用指定方式进行解码 |
```java
public class EncodingDecodingDemo {
    public static void main(String[] args) {
        //1.编码
        String str = "ai你哟";
        byte[] bytes1 = str.getBytes();
        System.out.println(java.util.Arrays.toString(bytes1));//数组长度6

        byte[] bytes2 = str.getBytes("GBK");
        System.out.println(java.util.Arrays.toString(bytes2));//数组长度8

        //2.解码
        String str2 = new String(bytes1);
        System.out.println(str2);//正常输出

        String str3 = new String(bytes1, "GBK");
        System.out.println(str3);//输出乱码
    }
}
```

---

## （三）字符流
==字符流 = 字节流 + 字符集==
适用于对纯文本进行读写操作
### 字符输入流  FileReader
- 一次读一个字节，遇到中文时，一次读多个字节
#### 1.创建字符输入流对象
|构造方法|说明|
|---|---|
|`public FileReader(File file)`|创建字符输入流关联本地文件|
|`public FileReader(String pathname)`|创建字符输入流关联本地文件|
**细节**：文件不存在直接报错

#### 2.读取数据
|成员方法|说明|
|---|---|
|`public int read()`|读取数据，读到末尾返回`-1`|
|`public int read(char[] buffer)`|读取多个数据，读到末尾返回`-1`|
**细节 1**：按字节进行读取，遇到中文，一次读多个字节，读取后解码，返回一个整数。
**细节 2**：读到文件末尾了，`read`方法返回`-1`。
```java
public static void main(String[] args) {
        FileReader fr = null;
        try {
            // 1.创建对象并关联本地文件
            fr = new FileReader("myio\\a.txt");
            // 2.读取数据 read()
            // 字符流的底层也是字节流，默认也是一个字节一个字节的读取的。
            // 如果遇到中文就会一次读取多个，GBK一次读两个字节，UTF-8一次读三个字节

            // read() 细节：
            // 1.read():默认也是一个字节一个字节的读取的,如果遇到中文就会一次读取多个
            // 2.在读取之后，方法的底层还会进行解码并转成十进制。
            // 最终把这个十进制作为返回值
            // 这个十进制的数据也表示在字符集上的数字
            // 英文：文件里面二进制数据 0110 0001
            //      read方法进行读取，解码并转成十进制97
            // 中文：文件里面的二进制数据 11100110 10110001 10001001
            //      read方法进行读取，解码并转成十进制27721

            // 我想看到中文汉字，就是把这些十进制数据，再进行强转就可以了
            int ch;
            while ((ch = fr.read()) != -1) {
                System.out.print((char) ch);
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            // 3.释放资源
            if (fr != null) {
                try {
                    fr.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
```
- 读取多个数据类似[[#3.文件拷贝]]
- 带参read(...)：读取、解码、强转三部合并了，将强转后的字符放到数组中，无序额外强转

#### 3.释放资源
|成员方法|说明|
|---|---|
|`public int close()`|释放资源 / 关流|

---

### 字符输出流  FileWriter
#### 1.步骤
###### a. 创建字符输出流对象
| 构造方法                                                 | 说明               |
| ---------------------------------------------------- | ---------------- |
| `public FileWriter(File file)`                       | 创建字符输出流关联本地文件    |
| `public FileWriter(String pathname)`                 | 创建字符输出流关联本地文件    |
| `public FileWriter(File file, boolean append)`       | 创建字符输出流关联本地文件，续写 |
| `public FileWriter(String pathname, boolean append)` | 创建字符输出流关联本地文件，续写 |
- 细节 1：参数是字符串表示的路径或者`File`对象都是可以的。
- 细节 2：如果文件不存在会创建一个新的文件，但要保证父级路径是存在的。
- 细节 3：如果文件已经存在，则会清空文件，若不想清空可打开续写开关。
###### b. 写数据
|成员方法|说明|
|---|---|
|`void write(int c)`|写出一个字符|
|`void write(String str)`|写出一个字符串|
|`void write(String str, int off, int len)`|写出一个字符串的一部分|
|`void write(char[] cbuf)`|写出一个字符数组|
|`void write(char[] cbuf, int off, int len)`|写出字符数组的一部分|
- 细节：若`write`方法的参数是整数，实际上写到本地文件中的是该整数在字符集上对应的字符。
###### c. 释放资源

---




[^1]: printlin自带换行，print不换行
