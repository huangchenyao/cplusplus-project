�Լ�д����ĸ���C++ Project������������VS2015�±�д��  
====
##Crypt����д�˼��ֳ��ü��ܷ������кܶ໹ûд��������use C++ 11��  
###AES  
��C++ʵ�ֵ�һ��AES�����࣬Դ������\Crypt\CryptĿ¼�µ�AES.h �� AES.cpp��AES���ܶ��states��4�ַ������ֱ�Ϊ��  
+ ECBģʽ���������뱾ģʽ��Electronic codebook����ʵ��  
+ CBCģʽ������������ӣ�Cipher-block chaining��δʵ��  
+ CFBģʽ�����ķ���:Cipher feedback��δʵ��  
+ OFBģʽ�����������Output feedback��δʵ��  
Ϊ��AES����֮����õ���ʾ����Ļ�ϻ��ߴ����ļ��У�������base64���б������  

###base64  
��C++ʵ�ֵ�һ��base64�����࣬Դ������\Crypt\CryptĿ¼�µ�base64.h �� base64.cpp  
���Ը��������ܷ������б������  

    �������������Ϊstring  
    //base64����  
    string encode(string &data);  
    //base64����  
    string decode(string &base64Str);  


###MD5  
��C++ʵ�ֵ�һ��MD5�����࣬Դ������\Crypt\CryptĿ¼�µ�base64.h �� base64.cpp  

    �������������Ϊstring  
    //MD5����  
    string encrypt(string &message);  


###RSA  
��ûд  

###SHA1  
��ûд  