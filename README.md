## Crypt是VS2015 Project，实现了各种加密方法
### AES
    用C++实现的一个AES加密类，源代码在\Crypt\Crypt目录下的AES.h 和 AES.cpp
    AES加密多个states有4种方案，分别为：
    -ECB模式（电子密码本模式：Electronic codebook）
    -CBC模式（密码分组链接：Cipher-block chaining）未实现
    -CFB模式（密文反馈:Cipher feedback）未实现
    -OFB模式（输出反馈：Output feedback）未实现
### base64
    只实现了编码，解码还没写