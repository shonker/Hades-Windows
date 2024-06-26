#ifndef _PROCESS_H
#define _PROCESS_H

typedef struct _PROCESSINFO
{
	int parentprocessid;
	int pid;
	int endprocess;
	wchar_t processpath[260 * 2];
	wchar_t commandLine[260 * 2];
	wchar_t queryprocesspath[260 * 2];
}PROCESSINFO, * PPROCESSINFO;

typedef struct _PROCESSBUFFER
{
	LIST_ENTRY			pEntry;
	ULONG				dataLength;
	char*				dataBuffer;
}PROCESSBUFFER,*P_PROCESSBUFFER;

typedef struct _PROCESSDATA
{
	KSPIN_LOCK process_lock;
	LIST_ENTRY process_pending;
}PROCESSDATA,*PPROCESSDATA;

NTSTATUS Process_Init(void);
void Process_Free(void);
void Process_Clean(void);
void Process_SetMonitor(BOOLEAN code);
void Process_SetIpsModEx(const int mods);
void Process_SetIpsMonitor(BOOLEAN code);
NTSTATUS Process_SetIpsMod(PIRP irp, PIO_STACK_LOCATION irpSp);
PROCESSBUFFER* Process_PacketAllocate(const int lens);
void Process_PacketFree(PROCESSBUFFER* packet);

PROCESSDATA* processctx_get();

#endif // !MY_PROCESS_H

