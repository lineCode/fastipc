#ifndef _Included_org_jwebtop_dll4csharp
#define _Included_org_jwebtop_dll4csharp
#include <string>
#include <Windows.h>

#define EXPORT __declspec(dllexport)

extern "C" {

	/*
	* �÷������ڴ���һ��fastipc�����
	* serverName	���������
	* blockSize		�������ͻ���ͨ��ʱÿ�ε�������
	* result		�������������Ƿ񴴽��ɹ���0=�ɹ�
	* return		������Server��ָ��
	*/
	EXPORT long WINAPI nCreateServer(LPTSTR serverName, int blockSize,int& result);

	EXPORT void WINAPI nAbc();
	// ����һ���ص�������csharp��ʵ�ִ˻ص�����
	typedef char*(CALLBACK *CSharpCallBack)(int msgType, char* packId, char* data);

	/*
	* �÷������ڿ���fastipc����˵Ķ�ȡ�������ɹ���������ڴ˴�
	* nativeServer	ָ������ʵ����ָ��
	* listener		��Ӧ��ȡ������ָ��
	*/
	EXPORT void WINAPI nStartRead(int nativeServer, CSharpCallBack callBack);

	/*
	* �÷������ڹر�fastipc����ˣ�ִ�к�nStartRead��������ֹͣ
	* nativeServer	ָ������ʵ����ָ��
	*/
	EXPORT void WINAPI nCloseServer(int nativeServer);

	/*
	* �÷������ڴ���һ��fastipc�ͻ���
	* serverName	�ͻ��˶�Ӧ�ķ���˵�����
	* blockSize		�������ͻ���ͨ��ʱÿ�ε�������
	* result		�������������Ƿ񴴽��ɹ���0=�ɹ�
	* return		������Client��ָ��
	*/
	EXPORT int WINAPI nCreateClient(LPTSTR serverName, int blockSize,int& result);

	/*
	* �÷���������fastipc�ͻ���д�����ݣ�����д��ɺ󣬻ᴥ������˵�����
	* nativeClient	ָ��ͻ���ʵ����ָ��
	* data			Ҫд�������
	* return		�ɹ�д������ݳ���
	*/
	EXPORT int WINAPI nWriteClient(int nativeClient, LPTSTR data);

	/*
	* �÷������ڹر�fastipc�ͻ���
	* nativeClient	ָ��ͻ���ʵ����ָ��
	*/
	EXPORT void WINAPI nCloseClient(int nativeClient);

}
#endif