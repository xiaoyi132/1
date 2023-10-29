#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int a, b, c;
//	float s, p;
//	scanf_s("%d %d %d", &a, &b, &c);
//	if ((a + b > c) && (b + c > a) && (a + c > b))
//	{
//		p = (float)(a + b + c) / 2;
//		s = sqrt(p * (p - a) * (p - b) * (p - c));
//		printf("%.2f %.2f", s, p * 2);
//	}
//	else
//		printf("Not a Valid Triangle\n");
//	return 0;
//}

//
////加油站服务
//#include<stdio.h>
//int main()
//{
//    int n, t;
//    float money;
//    char s;
//    scanf("%d %d %c", &n, &t, &s);
//    if (t == 89)
//        money = 6.17f;
//    else if (t == 92)
//        money = 5.58f;
//    else if (t == 95)
//        money = 5.96f;
//    if (s == 'a')
//        printf("%.2f", money * n * 0.95);
//    if (s == 'h')
//        printf("%.2f", money * n * 0.98);
//    return 0;
//}

//成绩评估
//#include<stdio.h>
//int main()
//{
//    int w, c, f, sum;
//    scanf("%d %d %d", &w, &c, &f);
//    sum = w + c + f;
//    if (sum <= 300 && sum >= 285)
//        printf("Gold Medal");
//    else if (sum < 285 && sum >= 270)
//        printf("Silver Medal");
//    else if (sum < 270 && sum >= 240)
//        printf("Bronze Medal");
//    if(sum < 240)
//    {
//        if(w >= 95 || c >= 95 || f >= 95)
//            printf("Honor Medal");
//        else
//            printf("No Medal");
//    }
//    return 0;
//}



//#include<stdio.h>
//int main()
//{
//    int w, c, f, sum;
//    scanf("%d %d %d", &w, &c, &f);
//    sum = w + c + f;
//    if (sum <= 300 && sum >= 285)
//        printf("Gold Medal");
//    else if (sum < 285 && sum >= 270)
//        printf("Silver Medal");
//    else if (sum < 270 && sum >= 240)
//        printf("Bronze Medal");
//    if (sum < 240)
//    {
//        if (w >= 95 || c >= 95 || f >= 95)
//            printf("Honor Medal");
//        else
//            printf("No Medal");
//    }
//    return 0;
//}




//#include<stdio.h>
//int main()
//{
//    int a, b, c;
//    scanf("%d %d %d", &a, &b, &c);
//        if ((a + b > c) && (b + c > a) && (a + c > b))
//        {
//            if (a == b && b == c)
//                printf("Equilateral Triangle");
//            else if ((a == b && a != c) || (a == c && a != b) || (c == b && a != c))
//                printf("Isosceles Triangle");
//            else
//                printf("Scalene Triangle");
//        }
//        else
//            printf("No Triangle");
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//    int a = getchar();
//    if ((a >= 65 && a <= 90) || (a <= 122 && a >= 97))
//        printf("Letter");
//    else if (a >= 48 && a <= 57)
//        printf("Digit");
//    else
//        printf("Other");
//    return 0;
//}

#include<stdio.h>
int main()
{
    double w, p;
    scanf("%lf", &w);
    if (w <= 2)
        p = 7.5;
    else
        p = (w - 2) * 1.8 + 7.5;
    printf("%.1lf", p);
    return 0;
}