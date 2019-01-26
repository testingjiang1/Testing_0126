
#include "task.h"
#include "iwdg.h"
#include "board.h"

int main(void)
{
	// please enable this define for creating USB program
	#ifdef USE_USB_BOOTLOADER
	SCB->VTOR = 0X8040000;//-----������λ���õ�ַ��

	__asm("CPSIE I");//���ж�
	__asm("CPSIE F");//�������쳣����
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


