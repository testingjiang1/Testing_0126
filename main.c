
#include "task.h"
#include "iwdg.h"
#include "board.h"

int main(void)
{
	// please enable this define for creating USB program
	#ifdef USE_USB_BOOTLOADER
	SCB->VTOR = 0X8040000;//-----将程序定位到该地址处

	__asm("CPSIE I");//开中断
	__asm("CPSIE F");//开所有异常处理
	#endif
	task_op.Init_Tasks();
	#ifdef USE_WATCHDOG
	iwdg_op.Iwdg_Enable();
	#endif
	task_op.Process();
	
	while(1)
	{
		;
	}
}


