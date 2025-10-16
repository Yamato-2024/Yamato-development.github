---
date: 2025-10-05
---
>File对象就表示一个路径，可以是文件的路径，也可以是文件夹的路径。
>这个路径可以是存在的，也允许是不存在的。
>只能读取，[[IO流]]可读写。

# 一、构造方法
| 方法名称                                      |        方法名称         |
| :---------------------------------------- | :-----------------: |
| public File (String pathname)             | 把字符串表示的路径变成 File 对象 |
| public File (String parent, String child) |   把父级路径和子级路径进行拼接    |
| public File (File parent, String child)   |   把父级路径和子级路径进行拼接    |

# 二、常见成员方法
#### 1.判断、获取
| 方法名称                        | 说明                                                      |
|:------------------------------- |:--------------------------------------------------------- |
| public boolean isDirectory()    | 判断此路径名表示的 File 是否为文件夹                      |
| public boolean isFile()         | 判断此路径名表示的 File 是否为文件                        |
| public boolean exists()         | 判断此路径名表示的 File 是否存在                          |
| public long length()            | 返回文件的大小（单位：字节）<br>无法获取文件夹的大小      |
| public String getAbsolutePath() | 返回文件的绝对路径                                        |
| public String getPath()         | 返回定义文件时使用的路径                                  |
| public String getName()         | 返回文件的名称，带后缀<br>返回文件名+后缀，返回文件夹名称 |
| public long lastModified()      | 返回文件的最后修改时间（时间毫秒值）                      |
```java
public class FileDemo2 { 
	public static void main(String[] args) {
		//1.对一个文件的路径进行判断
        File f1 = new File("D:\\aaa\\文件.txt");
        System.out.println(f1.isDirectory());//false
        System.out.println(f1.isFile());//true
        System.out.println(f1.exists());//true
        //2.对一个文件夹的路径进行判断
        File f2 = new File("D:\\aaa\\文件夹");
        System.out.println(f2.isDirectory());//false
        System.out.println(f2.isFile());//true
        System.out.println(f2.exists());//true
        //3.对一个不存在的路径进行判断
        File f3 = new File ("D:\aaa\c.txt");
        System.out.println (f3.isDirectory ());//false
        System.out.println (f3.isFile ());//false
        System.out.println (f3.exists ());//false
	}
}
```

```java
//length返回文件的大小
File f2 = new File("D:\aaa\bbb");
long len2 = f2.length();
System.out.println(len2);//0

//getAbsolutePath 返回文件的绝对路径
File f3 = new File ("D:\aaa\a.txt");
String path1 = f3.getAbsolutePath ();
System.out.println (path1);
```

#### 2.创建、删除
| 方法名称                           | 说明                            |
| :----------------------------- | ----------------------------- |
| public boolean createNewFile() | 创建一个新的空的文件                    |
| public boolean mkdir()         | 创建单级文件夹                       |
| public boolean mkdirs()        | 创建多级文件夹（会判断是存在）               |
| public boolean delete()        | 删除文件、空文件夹<br>无法删除非空文件夹，不经过回收站 |

#### 3.获取、遍历
| 方法名称                                       | 说明                                     |
|:---------------------------------------------- |:---------------------------------------- |
| public static File[] listRoots()               | 列出可用的文件系统根                     |
| public String[] list()                         | 获取当前该路径下所有内容                 |
| public String[] list(FilenameFilter filter)    | 利用文件名过滤器获取当前该路径下所有内容 |
| ==public File[] listFiles()==                  | ==获取当前该路径下所有内容==             |
| public File[] listFiles(FileFilter filter)     | 利用文件名过滤器获取当前该路径下所有内容 |
| public File[] listFiles(FilenameFilter filter) | 利用文件名过滤器获取当前该路径下所有内容 |
##### listFiles() 方法：
>获取文件夹中所有内容，把所有内容放到数组中返回。
>
>当调用者 File 表示的路径不存在时，返回 null
>当调用者 File 表示的路径是文件时，返回 null
>当调用者 File 表示的路径是一个空文件夹时，返回一个长度为 0 的数组
>当调用者 File 表示的路径是一个有内容的文件夹时，将里面所有文件和文件夹的路径放在 File 数组中返回
>当调用者 File 表示的路径是一个有隐藏文件的文件夹时，将里面所有文件和文件夹的路径放在 File 数组中返回，包含隐藏文件
>当调用者 File 表示的路径是需要权限才能访问的文件夹时，返回 null


```java
public static void main(String[] args) {
    //1.创建File对象
    File f = new File("D:\\aaa");
    //2.listFiles方法
    //作用：获取aaa文件夹里面的所有内容，把所有的内容放到数组中返回
    File[] files = f.listFiles();
    for (File file : files) {
        //file依次表示aaa文件夹里面的每一个文件或者文件夹
        System.out.println(file);
    }
}
```


# 三、练习
1. 在当前模块下的aaa文件夹中创建一个a.text文件。
```java
public static void main(String[] args) throws IOException {
    //需求：在当前模块下的aaa文件夹中创建一个a.txt文件

    //1.创建a.txt的父级路径
    File file = new File("myfile\\aaa");
    //2.创建父级路径
    //如果aaa是存在的，那么此时创建失败的。
    //如果aaa是不存在的，那么此时创建成功的。
    file.mkdirs();
    //3.拼接父级路径和子级路径
    File src = new File(file, "a.txt");
    boolean b = src.createNewFile();
    if(b){
        System.out.println("创建成功");
    }else{
        System.out.println("创建失败");
    }
}
```

2. 定义一个方法找某个文件夹中，是否有avi结尾的电影（不考虑子文件夹）。
```java
public static void main(String[] args) {
    /*需求：
        定义一个方法找某一个文件夹中，是否有以avi结尾的电影。
        （暂时不需要考虑子文件夹）
    */
    File file = new File("D:\\aaa\\bbb");
    boolean b = haveAVI(file);
    System.out.println(b);
}
/*
* 作用：用来找某一个文件夹中，是否有以avi结尾的电影
* 形参：要查找的文件夹
* 返回值：查找的结果 存在true 不存在false
* */
public static boolean haveAVI(File file){// D:\\aaa
    //1.进入aaa文件夹，而且要获取里面所有的内容
    File[] files = file.listFiles();
    //2.遍历数组获取里面的每一个元素
    for (File f : files) {
        //f：依次表示aaa文件夹里面每一个文件或者文件夹的路径
        if(f.isFile() && f.getName().endsWith(".avi")){
            return true;
        }
    }
    //3.如果循环结束之后还没有找到，直接返回false
    return false;
}
```