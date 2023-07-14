//猜数字游戏1.1版本
//新增功能:
//1.重复进行游戏
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
int main(void){
    int num_max=10000,num_min=0,input_num,true_num,computer_input,win,now,errors=0,cerrors=0;
    bool not_end=true,game_not_end=true;
    char replay;
    cout<<"猜数字游戏1.1\n\n";
    while(game_not_end){
        srand(time(NULL));
        true_num=(int)rand()%num_max;
        cout<<"数字范围为"<<num_min<<"~"<<num_max<<", 请输入一个数字:";
        while(not_end){
            cin>>input_num;
            cout<<"\n";
            Sleep(500);
            cout<<"您输入了数字"<<input_num<<"\n\n";
            while(input_num>num_max||input_num<num_min){
                cout<<"认真点，数字都输戳啦！重新输入一遍:";
                cin>>input_num;
                cout<<"\n\n";
            }
            if(input_num<true_num){num_min=input_num+1;errors+=1;now=0;}
            if(input_num>true_num){num_max=input_num-1;errors+=1;now=1;}
            if(input_num==true_num){win=0;break;}
            Sleep(500);
            if(now==0) cout<<"猜小了"<<","<<"现在由电脑猜数字,数字范围为"<<num_min<<"~"<<num_max<<"\n\n";
            else cout<<"猜大了"<<","<<"现在由电脑猜数字,数字范围为"<<num_min<<"~"<<num_max<<"\n\n";
            Sleep(500);
            srand(time(NULL));
            computer_input=((int)rand()%(num_max-num_min+1))+num_min;
            cout<<"电脑输入了数字"<<computer_input<<"\n\n";
            Sleep(500);
            if(computer_input<true_num){num_min=computer_input+1;cerrors+=1;now=0;}
            if(computer_input>true_num){num_max=computer_input-1;cerrors+=1;now=1;}
            if(computer_input==true_num){win=1;break;}
            if(now==0) cout<<"猜小了"<<","<<"现在由您猜数字,数字范围为"<<num_min<<"~"<<num_max<<":";
            else cout<<"猜大了"<<","<<"现在由您猜数字,数字范围为"<<num_min<<"~"<<num_max<<":";
        }
        if(win==0) cout<<"恭喜，您赢了！正确数字是"<<true_num<<endl;
        else cout<<"真可惜，您输了！正确数字是"<<true_num<<endl;
        Sleep(500);
        cout<<"您答了"<<" "<<errors<<" "<<"次"<<"\n";
        Sleep(1000);
        if(errors==0&&win==0) cout<<"达成成就:您是不是作弊了?(故意找茬)";
        if(errors==9&&win==0) cout<<"达成成就:一个十拿但九不稳的人(bushi";
        if(cerrors==0&&win==1) cout<<"达成成就:让电脑一发即中";
        if(num_min==num_max) cout<<"达成成就:标准答案成功放在面前(((";
        cout<<"\n要再玩一次吗？(y/n):";
        cin>>replay;
        if(replay=='n'){break;}
    }
    system("pause");
    return 0;
}
