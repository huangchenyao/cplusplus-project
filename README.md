自己写着玩的各种C++ Project，基本都是在VS2015下编写的  
====
##Crypt里面写了几种常用加密方法，有很多还没写。。。（use C++ 11）  
###AES  
用C++实现的一个AES加密类，源代码在\Crypt\Crypt目录下的AES.h 和 AES.cpp，AES加密多个states有4种方案，分别为：  
+ ECB模式（电子密码本模式：Electronic codebook）已实现  
+ CBC模式（密码分组链接：Cipher-block chaining）未实现  
+ CFB模式（密文反馈:Cipher feedback）未实现  
+ OFB模式（输出反馈：Output feedback）未实现  
为了AES加密之后更好地显示在屏幕上或者存在文件中，可以用base64进行编码解码  

###base64  
用C++实现的一个base64编码类，源代码在\Crypt\Crypt目录下的base64.h 和 base64.cpp  
可以给其他加密方案进行编码解码  

    输入输出参数均为string  
    //base64编码  
    string encode(string &data);  
    //base64解码  
    string decode(string &base64Str);  


###MD5  
用C++实现的一个MD5加密类，源代码在\Crypt\Crypt目录下的base64.h 和 base64.cpp  

    输入输出参数均为string  
    //MD5加密  
    string encrypt(string &message);  


###RSA  
还没写  

###SHA1  
还没写  