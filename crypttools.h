#ifndef CRYPTTOOLS_H
#define CRYPTTOOLS_H
#include <iostream>
#include <string>
//#define C1 52845
//#define C2 22719

class CryptTools
{
public:
    CryptTools();

    void setKeys(int c1,int c2);

    std::string EnCrypt(std::string dst); // 加密函数（最终加密函数）

    std::string DeCrpty(std::string szText); // 解密函数(最终解密函数)

private:
    std::string  Encrypt(std::string S, unsigned short Key); // 加密函数

    std::string Decrypt(std::string S, unsigned short Key); // 解密函数

    int C1=1111;
    int C2=1111;
};

#endif // CRYPTTOOLS_H
