#include<stdio.h>

//int main()
//{
//	enum x {
//		RED,
//		GREEN,
//	};
//	printf("%d\n%d\n",GREEN,RED);
//	return 0;
//}

//int main()
//{
//	printf("abc\vdejhkj\tadawdas");
//	return 0;
//}

//int main()
//{
//	printf("%c\n%c",'&\130&\x63');
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	int c = a + b;
//	printf("%d\n", c);
//	
//	return 0;
//}

//int main()
//{
//	int math = 0;
//	int english = 0;
//	printf("请输入数学和英语成绩：");
//	scanf("%d %d\n, &math,&english);
//	int plus = math + english;
//	printf("你的总成绩是：%d,\n", plus);
//	if ( plus>= 120)
//	{
//		printf("yes");
//	}
//	else
//	{
//		printf("no");
//	}
//	return 0;
//  }

//int main()
//{
//	int line = 0;
//	printf("加入比特\n");
//	while (line <= 50)
//	{
//		printf("写代码：%d\n", line);
//		line++;
//		if (line > 50)
//		{
//			printf("好offer\n");
//		}
//		else
//		{
//			printf("继续加油\n");
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int line = 0;
//	printf("加入比特\n");
//	while (line <= 40)
//	{
//		printf("写代码：%d\n", line);
//		line++;
//	}
//	if (line > 50)
//	{
//		printf("好offer\n");
//	}
//	else
//	{
//		printf("继续加油\n");
//	}
//	return 0;
//}

//void print_star()
//{
//	printf("*************\n");
//}
//void print_message()
//{
//	printf("how do you do\n");
//}
//int main()
//{
//	print_star();
//	print_message();
//	print_star();
//	return 0;
//}

//int add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int n1 = 0;
//	int n2 = 0;
//	printf("请输入n1n2的值：");
//	scanf("%d %d", &n1, &n2);
//	int sum = add(n1, n2);
//	printf("两数之和为：%d", sum);
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d\n", arr[2]);
//}

//int main()
//{
//	float a = 7 / 2.0;
//	printf("%.1f\n", a);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	printf("%d\n", sizeof (22221233211));
//	return 0;
//}
//int main()
//{
//	int a = 3.14;
//	printf("%d\n", a);
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int b = 2;
//	int x = a > b ? b : a;
//	printf("%d\n",x);
//	return 0;
//}

//void text()
//{
//	static int a = 1;
//	a++;
//	printf("%d", a);
//}
//int main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		text();
//		i++;
//	}
//	int a = 5;
//	printf("%d", a);
//		return 0;
//}

//extern int a;
//int main()
//{
//	printf("%d\n", a + 1);
//	{
//		int a = 9;
//		printf("%d\n", a); 
//		return 0;
//	}
//}

//#define mun 100
//int main()
//{
//	printf("%d\n", mun);
//	int n = mun;
//	printf("%d\n", n);
//	int arr[mun] = { 0 };
//	printf("%lld\n", sizeof(mun));
//	return 0;	
//}

int main()
{
	int a = 10;
	int* p = &a;
	*p = 99;
	printf("%d\n", a);
	return 0;
}