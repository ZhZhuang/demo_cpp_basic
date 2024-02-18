// 天地宽视-合肥相关面试题

#include <iostream>
using namespace std;


// 实现这些方法！！
class String {
public:
    String(const char *str = NULL); // 通用构造函数
    String(const String &another); // 拷贝构造函数
    ~ String(); // 析构函数
    String &operater =(const String &rhs); // 赋值函数
private:
    char *m_data; // 用于保存字符串
};

// 结构体的大小
typedef struct{
    char a;
    int b;
    char c;
}info;
typedef struct{
    char name[10];
    short *count;
    char *addr;
    info f;
}obj;

//逆序输出num，前导零不用输出
void print_reverse_int(int num){
    // 现场没有考虑到0的问题
    if(num == 0){
        printf("%d",num);
    }

    int a,b,flag;
    a=num, b=0,flag=0;
    while(a){
        b = a%10;
        a = a/10;

        if(b!=0){
            flag=1;
        }
        if(b==0&&flag==0){
            continue;
        }
        printf("%d", b);
    }
    printf("\n");
}

int main()
{
    obj x;
    char array[10];
    cout<<sizeof(info)<<endl;//12
    cout<<sizeof(obj)<<endl;//48
    cout<<sizeof(array)<<endl;

    int a[] = {1,2,3,4,5};
    int *p = (int *)(&a + 1);
    printf("%d, %d\n",*(a+1), *(p-1));

    int num = 0;
    print_reverse_int(num);

    return 0;
}
