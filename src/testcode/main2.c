#define EXTERN_DLL_EXPORT __declspec(dllexport)

EXTERN_DLL_EXPORT int printf(const unsigned short *format, ...);

void print(char* str);

int main()
{
    print("FuN"); // 70 117  78
    return 0;
}

void print(char* str)
{
    char* nrStr = str;
    int i = 0;
    unsigned short l = 0;
    do{
    l = nrStr[i];
    i++;
    if(l == 117) {printf((short unsigned int*)"117\n");}
    } while(l != 0);
    printf((short unsigned int*)"Done\n");
}