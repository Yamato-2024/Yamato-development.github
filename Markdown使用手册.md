```java
public class Test {
    public static void main(String[] args) {
        System.out.println("Hello Obsidian with Java!");
    }
}
```
# Typora Markdown使用手册

## 一、标题

//# +文字（ctrl+01234）

这是第一行（Shift+Enter小换行）
这是第二行

这是第二行



## 二、文字

### 1.字体

粗体：**用双星号包裹**（Ctrl+b）

删除线：双飘号包裹（Shift+Alt+5）

下划线：<u>对u标签包裹</u>（Ctrl+u）

斜体：*单星号包裹*（Ctrl+L）

高亮：==双等号包裹==

1\*2\*3\*4\\*5

### 2.上下标

X\^2\^	=>	X^2^ 

H\~2~O 	=>	H~2~O



## 三、列表

### 1.无序列表

- \- + 空格 
- 111
  - 按Tab升级
    - 或Ctrl+左右中括号升降（回车退出）

### 2.有序列表

1. hhh
2. 数字+.+空格

### 3.测试

1. 这是一个测试

2. 来试验一下

   - 1

     - 2

     3

   - 4

3. 非常好

   1. Tab或Ctrl+回车

### 4.任务列表

- [x] 背单词

- [ ] 早起

\- [ ] 背单词



## 四、区块显示

> 右箭头>+空格
>
> 对喽
>
> > 接着往下
> >
> > >  实验
> >
> > > 先回车回退再>就可以分块



## 五、代码显示

### 1、行内代码（Ctrl+Shift+\`/鼠标选中区域+`）

``用`包裹``

`printf()`

### 2、代码块

> ```java
> ​```三次点
>     相当优雅
> ```
>
> ```java
> import ...
> ```



## 六、链接（Ctrl+左键 跳转）

> [CS自学指南](https://csdiy.wiki/ "https://csdiy.wiki/")
>
> [CS自学指南](https://csdiy.wiki/)
>
> https://csdiy.wiki/
>
> 如下：
>
> ```
> [CS自学指南](https://csdiy.wiki/ "https://csdiy.wiki/")
> [CS自学指南](https://csdiy.wiki/)
> https://csdiy.wiki/
> ```

> 快捷键Ctrl+K

> 当然也可以跳转文档标题（需要复制Lambda语法）：
>
> [标题1](##一、标题) 
>
> ```
> [标题1](##一、标题) 
> ```



## 七、脚注（像链接一样跳转）

> 便捷的对文字进行说明

> 像这样[^就可以了]
>
> ```
> 像这样[^就可以了]
> ```

> 这样更高级[^①]
>
> [^①]:光标放上去试试<br>注意脚注保证一致!
>
> ```
> 这样更高级[^①]
> [^①]:光标放上去试试<br>注意脚注保证一致!
> ```



## 八、图片

> 众所周知，有图有真相

> <img src="../../CS_Photo/演示用图.png" alt="不显示的文字" title="是不是非常实用" style="zoom:67%;" align="left"/>

> 代码：
>
> ```
> ![不显示的文字](../../CS_Photo/演示用图.png "是不是非常实用" style="zoom:67%;" align="left"/>
> ```

> 快捷键：Ctrl+Shift+L
>
> 可以在”格式—图像—复制/移动所有图片“到进行图片归纳



## 九、表格	

>推荐使用快捷键：Ctrl+T
>
>|   快捷键    |          |
>| :---------: | :------: |
>| Ctrl+Enter  |  加一行  |
>| Ctrl+Shift  | 删除一行 |
>| Shift+Enter |   换行   |

