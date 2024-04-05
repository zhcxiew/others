/*
1.编译选项:g++ super_calculator.cpp -o super_calculator -lgmp -lm
2.需要安装GMP库
3.有些时候有Bug
*/
//fuck,不想写了
//历史计算写入还有问题
#include <stdlib.h>
#include <iostream>
#include <stdio.h> //标准库
#include <gmp.h>
#include <gmpxx.h> //GMP大数库
#include <cmath>
#include <math.h> //数学库

#define BUFFER_SIZE 1024

using namespace std;
void add(); //基本运算
void sub();
void mul();
void div();
void baifen();

void jb(); //菜单
void gj();
void sj();
void tongji();
void show();
void del();

void power(); //高级
void _sqrt();
void lcm();
void gcd();
void abs();
void mod();
void lg();
void ln();
void fac();
void fenjie();

void average();
void variance();
void stadev();
void pro();
const double pi = acos(-1); //圆周率
string cmd = "clear"; //移植到windows时,请改成string cmd = "cls";
FILE *fp; //hitory.txt
FILE *w; //输入历史
int main(void){
    while(1){
    char choice;
    system(cmd.c_str());
    printf("超级计算器 Version 1.0\n\n"); //菜单
    printf("1---基本计算(+-x÷)\n");
    printf("2---高级运算(幂平方根等)\n");
    printf("3---三角函数\n");
    printf("4---概率与统计类\n");
    printf("5---查看历史记录\n");
    printf("6---清空历史记录\n");
    printf("7---退出\n");
    printf("\n");
    printf("请选择:");
    cin>>choice;
    while(choice < '1' || choice > '7'){
        printf("输入错误,请重新输入:");
        cin>>choice;
    }
    while(getchar()!='\n');
    switch(choice){ //分支处理
        case '1':jb();break;
        case '2':gj();break;
        case '3':sj();break;
        case '4':tongji();break;
        case '5':show();break;
        case '6':del();break;
        case '7':exit(0);break;
    }
    }
    return 0;
}

void add(){ //整数高精度加法ok
    system(cmd.c_str());
    mpz_t a,b,sum;
    mpz_init(a);mpz_init(b);mpz_init(sum);
    printf("请输入要进行运算的两个数:");
    gmp_scanf("%Zd%Zd",a,b);
    mpz_add(sum,a,b);
    printf("结果:");
    gmp_printf("%Zd\n",sum);

    char* aa = mpz_get_str(NULL, 10, a);
    char* bb = mpz_get_str(NULL, 10, b);
    char* ssum = mpz_get_str(NULL, 10, sum);
    w = fopen("history.txt", "a");
    fprintf(w,"%s+",aa);
    fprintf(w,"%s=",bb);
    fprintf(w,"%s\n",ssum);

    mpz_clear(a);mpz_clear(b);mpz_clear(sum);
    fclose(w);
    printf("\n");
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void sub(){ //整数高精度减法ok
    system(cmd.c_str());
    mpz_t a,b,sub;
    mpz_init(a);mpz_init(b);mpz_init(sub);
    printf("请输入要进行运算的两个数:");
    gmp_scanf("%Zd%Zd",a,b);
    mpz_sub(sub,a,b);
    printf("结果:");
    gmp_printf("%Zd\n",sub);

    char* aa = mpz_get_str(NULL, 10, a);
    char* bb = mpz_get_str(NULL, 10, b);
    char* ssub = mpz_get_str(NULL, 10, sub);
    w = fopen("history.txt", "a");
    fprintf(w,"%s-",aa);
    fprintf(w,"%s=",bb);
    fprintf(w,"%s\n",ssub);
    fclose(w);

    mpz_clear(a);mpz_clear(b);mpz_clear(sub);
    printf("\n");
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void mul(){ //整数高精度乘法ok
    system(cmd.c_str());
    mpz_t a,b,mul;
    mpz_init(a);mpz_init(b);mpz_init(mul);
    printf("请输入要进行运算的两个数:");
    gmp_scanf("%Zd%Zd",a,b);
    mpz_mul(mul,a,b);
    printf("结果:");
    gmp_printf("%Zd\n",mul);

    char* aa = mpz_get_str(NULL, 10, a);
    char* bb = mpz_get_str(NULL, 10, b);
    char* mmul = mpz_get_str(NULL, 10, mul);
    w = fopen("history.txt", "a");
    fprintf(w,"%sx",aa);
    fprintf(w,"%s=",bb);
    fprintf(w,"%s\n",mmul);
    fclose(w);

    mpz_clear(a);mpz_clear(b);mpz_clear(mul);
    printf("\n");
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void div(){ //整数高精度除法 //写入历史有问题
    system(cmd.c_str());
    mpf_t a,b,div;
    mpf_init(a);mpf_init(b);mpf_init(div);
    printf("请输入要进行运算的两个数:");
    gmp_scanf("%Ff%Ff",a,b);
    if(mpf_cmp_ui(b,0) == 0){
        printf("得数:不能除以0\n");

        char* aa = mpf_get_str(NULL, NULL, 10, -1, a);
        w = fopen("history.txt","a");
        fprintf(w,"%s÷0=不能除以0\n",aa);
        fclose(w);

        mpf_clear(a);mpf_clear(b);mpf_clear(div);
        printf("请输入回车键以继续......");
        getchar();
        getchar();
    }
    mpf_div(div,a,b);
    printf("结果:");
    gmp_printf("%Ff\n",div);

    char* aa = mpf_get_str(NULL, NULL, 10, -1, a);
    char* bb = mpf_get_str(NULL, NULL, 10, -1, b);
    char* ddiv = mpf_get_str(NULL, NULL, 10, -1, div);
    w = fopen("history.txt","a");
    fprintf(w,"%s÷",aa);
    fprintf(w,"%s=",bb);
    fprintf(w,"%s\n",ddiv);
    fclose(w);
    
    mpf_clear(a);mpf_clear(b);mpf_clear(div);
    printf("\n");
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void baifen(){ //
    system(cmd.c_str());
    mpf_t a,b,bai;
    char option;
    mpf_init(a);mpf_init(b);mpf_init(bai);
    mpf_set_ui(b, 100);
    printf("1---转换为百分数\n2---转换百分数\n\n");
    printf("请输入:");
    cin>>option;
    while(option < '1' || option > '2'){
        printf("输入错误,请重新输入:");
        cin>>option;
    }
    while(getchar()!='\n');
    printf("请输入数字:");
    if(option == '1'){
        gmp_scanf("%Ff",a);
        mpf_mul(bai,a,b);
        gmp_printf("结果: %Ff%%\n\n",bai);
    }
    if(option == '2'){
        gmp_scanf("%Ff%%",a);
        mpf_div(bai,a,b);
        gmp_printf("结果: %Ff\n\n",bai);
    }
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void jb(){ //基本运算ok
    system(cmd.c_str());
    char c;
    printf("1---加法\n");
    printf("2---减法\n");
    printf("3---乘法\n");
    printf("4---除法\n");
    printf("5---百分数\n\n");
    printf("请选择:");
    cin>>c;
    while(c < '1' || c > '5'){
        printf("输入错误,请重新输入:");
        cin>>c;
    }
    while(getchar()!='\n');
    if(c=='1'){add();}
    if(c=='2'){sub();}
    if(c=='3'){mul();}
    if(c=='4'){div();}
    if(c=='5'){baifen();}
}

void gj(){ //ok
    system(cmd.c_str());
    char ch;
    printf("0---质因数分解\n");
    printf("1---幂运算\n");
    printf("2---平方根\n");
    printf("3---最小公倍数\n");
    printf("4---最大公因数\n");
    printf("5---绝对值\n");
    printf("6---取模\n");
    printf("7---对数(lg)\n");
    printf("8---对数(ln)\n");
    printf("9---阶乘\n");
    printf("\n\n");
    printf("请选择:");
    cin>>ch;
    while(ch < '0' || ch > '9'){
        printf("输入错误,请重新输入:");
        cin>>ch;
    }
    while(getchar()!='\n');
    switch(ch){
        case '1':power();break;
        case '2':_sqrt();break;
        case '3':lcm();break;
        case '4':gcd();break;
        case '5':abs();break;
        case '6':mod();break;
        case '7':lg();break;
        case '8':ln();break;
        case '9':fac();break;
        case '0':fenjie();break;
    }
}

void sj(){ //ok
    system(cmd.c_str());
    char cho;
    double num,rad;
    printf("1---sin\n");
    printf("2---cos\n");
    printf("3---tan\n");
    printf("4---asin\n"); //反正弦
    printf("5---acos\n"); //反余弦
    printf("6---atan\n\n"); //反正切函数主值
    printf("请选择:");
    cin>>cho;
    while(cho < '1' || cho > '6'){
        printf("输入错误,请重新输入:");
        cin>>cho;
    }
    while(getchar()!='\n');
    printf("\n\n");
    if(cho=='1'){
        printf("请输入:");
        cin>>num;
        rad = num * (pi / 180.0);
        printf("得数:%lf\n\n", sin(rad));
        w = fopen("history.txt", "a");
        fprintf(w,"sin(%lf)=%lf\n", num, sin(rad));
        fclose(w);
    }
    if(cho=='2'){
        printf("请输入:");
        cin>>num;
        rad = num * (pi / 180.0);
        printf("得数:%lf\n\n", cos(rad));
        w = fopen("history.txt", "a");
        fprintf(w,"cos(%lf)=%lf\n", num, cos(rad));
        fclose(w);
    }
    if(cho=='3'){
        printf("请输入:");
        cin>>num;
        rad = num * (pi / 180.0);
        if(num==90){ //tan(90)时，tan(90)=sin(90)/cos(90)=1/0，特例输出inf
            printf("得数:inf\n\n");
            w = fopen("history.txt", "a");
            fprintf(w,"tan(90)=inf\n");
            fclose(w);
            goto aaa;
        }
        printf("得数:%lf\n\n", tan(rad));
        w = fopen("history.txt", "a");
        fprintf(w,"tan(%lf)=%lf\n", num, tan(rad));
        fclose(w);
    }
    if(cho=='4'){
        printf("请输入:");
        cin>>num;
        while(num < -1 || num > 1){
            printf("输入无效,请重新输入:");
            cin>>num;
        }
        printf("得数:%lf度\n\n", asin(num)*180/pi);
        w = fopen("history.txt", "a");
        fprintf(w,"asin(%lf)=%lf度\n", num, asin(num)*180/pi);
        fclose(w);
    }
    if(cho=='5'){
        printf("请输入:");
        cin>>num;
        while(num < -1 || num > 1){
            printf("输入无效,请重新输入:");
            cin>>num;
        }
        printf("得数:%lf度\n\n", acos(num)*180/pi);
        w = fopen("history.txt", "a");
        fprintf(w,"acos(%lf)=%lf度\n", num, acos(num)*180/pi);
        fclose(w);
    }
    if(cho=='6'){
        printf("请输入:");
        cin>>num;
        printf("得数:%lf度\n\n", atan(num)*180/pi);
        w = fopen("history.txt", "a");
        fprintf(w,"atan(%lf)=%lf度\n", num, atan(num)*180/pi);
        fclose(w);
    }
    aaa:
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void tongji(){ //ok
    system(cmd.c_str());
    char option;
    printf("1---平均数\n");
    printf("2---方差\n");
    printf("3---标准差\n");
    printf("4---概率\n");
    printf("\n\n");
    printf("请选择:");
    cin>>option;
    while(option < '1' || option > '4'){
        printf("输入无效,请重新输入:");
        cin>>option;
    }
    while(getchar()!='\n');
    switch(option){
        case '1':average();break;
        case '2':variance();break;
        case '3':stadev();break;
        case '4':pro();break;
    }
}

void power(){ //
    system(cmd.c_str());
    mpz_t a,power;
    mpf_t powera,aa,one;
    int b;
    mpz_init(a);mpz_init(power);mpf_init(aa);mpf_init(powera);mpf_init(one);
    printf("请输入要进行运算的两个数(指数和底数):");
    scanf("%d",&b);
    if(b < 0){
        b = abs(b);
        gmp_scanf("%Ff",aa);
        mpf_pow_ui(powera,aa,b);
        mpf_set_ui(one, 1);
        mpf_div(powera,one,powera);
        gmp_printf("%Ff\n\n",powera);
        goto clear;
    }
    gmp_scanf("%Zd",a);
    mpz_pow_ui(power,a,b);
    gmp_printf("%Zd\n\n",power);
    clear:
    mpz_clear(a);mpz_clear(power);mpf_clear(aa);mpf_clear(powera);mpf_clear(one);
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void _sqrt(){ //
    system(cmd.c_str());
    mpf_t a,sqrt;
    mpf_init(a);mpf_init(sqrt);
    printf("请输入要进行运算的数:");
    gmp_scanf("%Ff",a);
    if(mpf_cmp_ui(a,0) < 0){ //负数平方根特例
        mpf_abs(a,a);
        mpf_sqrt(sqrt,a);
        gmp_printf("%Ff i\n\n",sqrt);
        mpf_clear(a);mpf_clear(sqrt);
        printf("请输入回车键以继续......");
        getchar();
        goto aa;
    }
    mpf_sqrt(sqrt,a);
    gmp_printf("%Ff\n\n",sqrt);
    mpf_clear(a);mpf_clear(sqrt);
    printf("请输入回车键以继续......");
    getchar();
    aa:
    getchar();
}

void lcm(){ //ok
    system(cmd.c_str());
    mpz_t a,b,gcd,lcm;
    mpz_init(a);mpz_init(b);mpz_init(gcd);mpz_init(lcm);
    printf("请输入要进行运算的两个数(除0外自然数):");
    gmp_scanf("%Zd%Zd",a,b);
    while(mpz_cmp_ui(a,0) == 0 || mpz_cmp_ui(b,0) == 0){
        printf("输入无效,请重新输入:");
        gmp_scanf("%Zd%Zd",a,b);
    }
    mpz_gcd(gcd,a,b);
    mpz_mul(lcm,a,b);
    mpz_tdiv_q(lcm,lcm,gcd); //lcm = a * b / gcd
    gmp_printf("%Zd\n\n",lcm);
    w = fopen("history.txt","a");
    char* aa = mpz_get_str(NULL, 10, a);
    char* bb = mpz_get_str(NULL, 10, b);
    char* llcm = mpz_get_str(NULL, 10, lcm);
    fprintf(w,"lcm(%s,", aa);
    fprintf(w, "%s)=", bb);
    fprintf(w, "%s\n", llcm);
    fclose(w);
    mpz_clear(a);mpz_clear(b);mpz_clear(gcd);mpz_clear(lcm);
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void gcd(){ //ok
    system(cmd.c_str());
    mpz_t a,b,gcd;
    mpz_init(a);mpz_init(b);mpz_init(gcd);
    printf("请输入要进行运算的两个数(除0外自然数):");
    gmp_scanf("%Zd%Zd",a,b);
    while(mpz_cmp_ui(a,0) == 0 || mpz_cmp_ui(b,0) == 0){
        printf("输入无效,请重新输入:");
        gmp_scanf("%Zd%Zd",a,b);
    }
    mpz_gcd(gcd,a,b);
    gmp_printf("%Zd\n\n",gcd);
    w = fopen("history.txt","a");
    char* aa = mpz_get_str(NULL, 10, a);
    char* bb = mpz_get_str(NULL, 10, b);
    char* ggcd = mpz_get_str(NULL, 10, gcd);
    fprintf(w,"gcd(%s,", aa);
    fprintf(w, "%s)=", bb);
    fprintf(w, "%s\n", ggcd);
    fclose(w);
    mpz_clear(a);mpz_clear(b);mpz_clear(gcd);
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void abs(){ //
    system(cmd.c_str());
    mpf_t a,i,abs;
    mpf_init(a);mpf_init(i);mpf_init(abs);
    printf("请输入实数部:");
    gmp_scanf("%Ff",a);
    printf("请输入虚数部:");
    gmp_scanf("%Ff",i);
    mpf_mul(a,a,a);
    mpf_mul(i,i,i);
    mpf_add(a,a,i);
    mpf_sqrt(abs,a);
    gmp_printf("%Ff\n\n",abs);
    mpf_clear(a);mpf_clear(i);mpf_clear(abs);
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void mod(){ //ok
    system(cmd.c_str());
    mpz_t a,b,mod;
    mpz_init(a);mpz_init(b);mpz_init(mod);
    printf("请输入被除数和除数(整数):");
    gmp_scanf("%Zd%Zd",a,b);
    mpz_mod(mod,a,b);
    gmp_printf("余数: %Zd\n\n",mod);
    w = fopen("history.txt","a");
    char* aa = mpz_get_str(NULL, 10, a);
    char* bb = mpz_get_str(NULL, 10, b);
    char* mmod = mpz_get_str(NULL, 10, mod);
    fprintf(w,"%s mod ", aa);
    fprintf(w, "%s=", bb);
    fprintf(w, "%s\n", mmod);
    fclose(w);
    mpz_clear(a);mpz_clear(b);mpz_clear(mod);
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void lg(){ //ok
    system(cmd.c_str());
    double input; //double浮点数数据可能会存在部分问题
    printf("请输入数:");
    cin>>input;
    printf("lg(%lf) = %lf\n\n",input,log10(input));
    w = fopen("history.txt","a");
    fprintf(w,"lg(%lf) = %lf\n",input,log10(input));
    fclose(w);
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void ln(){ //ok
    system(cmd.c_str());
    double input;
    printf("请输入数:");
    cin>>input;
    printf("ln(%lf) = %lf\n\n",input,log(input));
    w = fopen("history.txt","a");
    fprintf(w,"ln(%lf) = %lf\n",input,log(input));
    fclose(w);
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void fac(){ //ok
    system(cmd.c_str());
    long long int input;
    mpz_t fac;
    mpz_init(fac);
    mpz_set_ui(fac, 1);
    printf("请输入要计算的数字:");
    scanf("%lld",&input);
    while(input < 0){
        printf("输入无效,请重新输入:");
        scanf("%lld",&input);
    }
    if(input == 0){
        printf("1\n");
        w = fopen("history.txt", "a");
        fprintf(w, "0!=1\n");
        fclose(w);
        mpz_clear(fac);
        printf("请输入回车键以继续......");
        getchar();getchar();
        main();
    }
    else{
        for(long long int i = input;i > 0;i -= 1){
            mpz_mul_ui(fac,fac,i);
        }
    }
    gmp_printf("%Zd\n\n",fac);
    w = fopen("history.txt", "a");
    char* ffac = mpz_get_str(NULL, 10, fac);
    fprintf(w, "%lld!=", input);
    fprintf(w, "%s\n", ffac);
    fclose(w);
    mpz_clear(fac);
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void average(){ //ok
    system(cmd.c_str());
    long long int sum = 0;
    int num,t_num;
    printf("请输入要输入几个数:");
    scanf("%d",&num);
    while(num < 1){
        printf("数字太小了,请重新输入:");
        cin>>num;
    }
    printf("请输入数:");
    for(int i = 0;i < num;i++){
        cin>>t_num;
        sum += t_num;
    }
    printf("%lf\n\n",double(sum/double(num)));
    w = fopen("history.txt", "a");
    fprintf(w, "平均数是%lf\n", double(sum/double(num)));
    fclose(w);
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void variance(){ //ok
    system(cmd.c_str());
    double a[10000],aver = 0,v = 0;
    int num;
    printf("请输入要输入几个数:");
    scanf("%d",&num);
    while(num < 1 || num > 10000){
        printf("数字太大/太小了,请重新输入:");
        cin>>num;
    }
    printf("请输入数:");
    for(int i = 0;i < num;i++){
        cin>>a[i];
        aver += a[i];
    }
    aver = aver / num;
    for(int i = 0;i < num;i++){
        if(a[i] < aver) v = v + (aver - a[i]) * (aver - a[i]);
        if(a[i] > aver) v = v + (a[i] - aver) * (a[i] - aver);
    }
    v = v / num;
    printf("%lf\n\n",v);
    w = fopen("history.txt", "a");
    fprintf(w, "方差是%lf\n", v);
    fclose(w);
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void stadev(){ //ok
    system(cmd.c_str());
    double a[10000],aver = 0,v = 0;
    int num;
    printf("请输入要输入几个数:");
    scanf("%d",&num);
    while(num < 1 || num > 10000){
        printf("数字太大/太小了,请重新输入:");
        cin>>num;
    }
    printf("请输入数:");
    for(int i = 0;i < num;i++){
        cin>>a[i];
        aver += a[i];
    }
    aver = aver / num;
    for(int i = 0;i < num;i++){
        if(a[i] < aver) v = v + (aver - a[i]) * (aver - a[i]);
        if(a[i] > aver) v = v + (a[i] - aver) * (a[i] - aver);
    }
    v = v / num;
    printf("%lf\n\n",sqrt(v));
    w = fopen("history.txt", "a");
    fprintf(w, "标准差是%lf\n", sqrt(v));
    fclose(w);
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void pro(){ //
    int c;
    char option;
    unsigned int countd;
    double p,pc = 1,num;
    system(cmd.c_str());
    printf("1---计算同一概率事件,多少次时至少有一次发生的概率\n2---计算同一概率事件,要多少次时,至少有一次发生的概率达到某数\n\n");
    printf("请选择:");
    cin>>option;
    while(option < '1' || option > '2'){
        printf("输入无效,请重新输入:");
        cin>>option;
    }
    while(getchar()!='\n');
    if(option=='1'){
        printf("请输入概率(小数,非百分数):");
        cin>>p;
        while(p > 1 || p < 0){
            printf("输入无效,请重新输入:");
            cin>>p;
        }
        printf("请输入次数:");
        cin>>c;
        while(c < 0){
            printf("输入无效,请重新输入:");
            cin>>c;
        }
        if(p == 0){
            printf("概率:无法达成此事件哦\n\n");
            goto a;
        }
        if(p == 1){
            printf("概率:100%%\n\n");
            goto a;
        }
        p = 1 - p;
        pc = std::pow(p,c);
        pc = 1 - pc;
        pc *= 100;
        printf("概率:%f%%\n\n",pc);
    }
    if(option=='2'){
        countd = 1;
        printf("请输入概率(小数,非百分数):");
        cin>>p;
        while(p > 1 || p < 0){
            printf("输入无效,请重新输入:");
            cin>>p;
        }
        printf("请输入要达成的概率(小数):");
        cin>>num;
        while(num > 1 || num < 0){
            printf("输入无效,请重新输入:");
            cin>>num;
        }
        if(p == 0){
            printf("次数:无法达成此事件哦\n\n");
            goto a;
        }
        if(p == 1){
            printf("次数:1次\n\n");
            goto a;
        }
        p = 1 - p;
        num = 1 - num;
        while(p > num + 0.01){ //浮点数容错
            p = p * p;
            countd += 1;
        }
        printf("次数:%d次\n\n",countd);
    }
    a:
    printf("请输入回车键以继续......");
    getchar();
    getchar();
}

void show(){ //ok
    system(cmd.c_str());
    fp = fopen("history.txt","r");
    if(fp == NULL){
        cout<<"还没有历史记录......\n";
        printf("\n请输入回车键以继续......");
        getchar();
        goto c;
    }
    char buffer[BUFFER_SIZE];
    while(fgets(buffer, BUFFER_SIZE, fp) != NULL) {  
        printf("%s", buffer);
    }
    fclose(fp);
    printf("\n请输入回车键以继续......");
    c:
    getchar();
}

void del(){ //ok
    system(cmd.c_str());
    system("rm history.txt"); //in Windows, change it to system("del history.txt");
}

void fenjie(){ //ok
    system(cmd.c_str());
	long long int n;
    cout<<"请输入要进行分解的数:";
	cin>>n;
    while(n <= 1){
        cout<<"输入的数无效,请重新输入:";
        cin>>n;
    }
    w = fopen("history.txt", "a");
    fprintf(w, "%lld 的质因数分解为 ", n);
	for(int i = 2; i <= sqrt(n); i++){
		while(n%i == 0){
			cout<<i<< " ";
            fprintf(w, "%d ", i);
			n/=i;
		}
	}
	if(n > 1){cout<<n;fprintf(w, "%lld", n);}
    fprintf(w, "\n");
    fclose(w);
    printf("\n请输入回车键以继续......");
    getchar();
    getchar();
}
