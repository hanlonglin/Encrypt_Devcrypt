#include "crypttools.h"


CryptTools::CryptTools()
{

}

//设置密匙
void CryptTools::setKeys(int c1, int c2)
{
    C1=C1_DEFAULT; //默认值
    C2=C2_DEFAULT; //默认值

    if(c1!=0)
        C1=c1;
    if(c2!=0)
        C2=c2;
    qDebug()<<"c1:"<<QString::number(c1);
    qDebug()<<"c2:"<<QString::number(c2);

}

//加密
std::string CryptTools::Encrypt(std::string S, unsigned short Key) // 加密函数
{

    S = S + "PC";
    std::string Result, str;
    size_t i, j;

    Result = S; // 初始化结果字符串
    // 依次对字符串中各字符进行操作
    for (i = 0; i < S.length(); i++)
    {
        Result.at(i) = S.at(i) ^ (Key >> 8); // 将密钥移位后与字符异或
        Key = ((unsigned char)Result.at(i) + Key)*C1 + C2; // 产生下一个密钥
    }
    S = Result; // 保存结果
    Result.clear(); // 清除结果
    for (i = 0; i < S.length(); i++) // 对加密结果进行转换
    {
        j = (unsigned char)S.at(i); // 提取字符
        // 将字符转换为两个字母保存
        str = "12"; // 设置str长度为2
        str.at(0) = 65 + j / 26;
        str.at(1) = 65 + j % 26;
        Result += str;
    }
    return Result;
}
//解密
std::string CryptTools::Decrypt(std::string S, unsigned short Key) // 解密函数
{   
    std::string Result, str;
    size_t i, j;
    for (i = 0; i < S.size() / 2; i++) // 将字符串两个字母一组进行处理
    {
        j = ((unsigned char)S.at(2 * i) - 65) * 26;
        j += (unsigned char)S.at(2 * i + 1) - 65;
        str = "1"; // 设置str长度为1
        str.at(0) = j;
        Result += str; // 追加字符，还原字符串
    }
    S = Result; // 保存中间结果
    for (i = 0; i < S.size(); i++) // 依次对字符串中各字符进行操作
    {
        Result.at(i) = (unsigned char)S.at(i) ^ (Key >> 8); // 将密钥移位后与字符异或
        Key = ((unsigned char)S.at(i) + Key)*C1 + C2; // 产生下一个密钥
    }

    Result = Result.substr(0, Result.size() - 2);
    return Result;
}
//解密2 调用上一个解密函数
std::string CryptTools::DeCrpty(std::string sSrcText)
{

    qDebug()<<"C1:"<<QString::number(C1);
    qDebug()<<"C2:"<<QString::number(C2);


    static unsigned short wordkey1 = 62153;
    static unsigned short wordkey2 = 42536;
    static unsigned short wordkey3 = 21354;

    std::string dst3 = Decrypt(sSrcText, wordkey3);
    std::string dst2 = Decrypt(dst3, wordkey2);
    std::string dst = Decrypt(dst2, wordkey1);

    return dst;
}
//加密2 调用上一个加密函数
std::string CryptTools::EnCrypt(std::string dst)
{
    qDebug()<<"C1:"<<QString::number(C1);
    qDebug()<<"C2:"<<QString::number(C2);;


    static unsigned short wordkey1 = 62153;
    static unsigned short wordkey2 = 42536;
    static unsigned short wordkey3 = 21354;
    std::string dst2 = Encrypt(dst, wordkey1);
    std::string dst3 = Encrypt(dst2, wordkey2);
    std::string sSrcText = Encrypt(dst3, wordkey3);
    char szText[4];
    //int i;
    //for (i = 0; i < sSrcText.length(); i++)
    //	szText[i] = sSrcText[i];
    //szText[i] = 0;
    return sSrcText;
}
