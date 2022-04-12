/*
	A partir do timer0 mostre como gerar outras bases de tempo para a realização de 3 tarefas A, B e C.
	A tarefa A precisa ser executada a cada 20us, enquanto que a cada 100us e a C a cada 1ms.
*/

#include <16F877A.h>
#include "reg_16f.h"

void taferaB();
void taferaC();

void man()
{
	unsigned int8 b = 0, c = 0
	
	setup_timer_0(T0_INTERNAL);

	OPTION_REG != 0x08; // setando o bit 3 do OPTION_REG (o PSA)

	TMR0 = 156; // Proveniente do cálculo da frequência (fórmula)
	// timer0 para gerar o menor tempo (20us): 1/0,00002 = 50000 (50KHz)

	while (TRUE)
	{
		if (tmr0if)
		{
			// TMR0 = 156;
			set_timer0(get_timer0() + 156); // mais preciso
			b++;

			if (b == 5) // 100us/20us = 5
			{
				b = 0;
				taferaB();
			}

			c++;
			if (c == 50) // 1000us/20us = 50
			{
				c = 0;
				taferaC();
			}
			
			tmr0if = 0;
		}
	}
}