/*
	Fa�a um programa em C para implemetar um rel�gio usando o TIMER1  
	com um cristal externo de 32768Hz.
*/

#include <16F877A.h>
#include "reg_16f.h"

void main()
{
	unsigned int8 seg = 0, min = 0, hora = 0; // 8 bits de mem�ria > essas vari�veis n�o ir�o passar de 255 (decimal) 

	/////////////////////////
	// CONFIGURA��O DO MIC //
	/////////////////////////

    setup_timer_1 (T1_EXTERNAL_SYNC | T1_DIV_BY_1); // clk externo sincronizado [ou] e sem PRESCALER (divisor de frequ�ncia)
												   // timer1 funcionando a partir do cristal externo de 32768Hz > timer1 rodando a essa freq.

	// Preciso que o timer1 estoure a sua contagem a cada 1Hz (1/f) > f�rmula da freq. externa: f = (32768 Hz) / (1 * 2^16 - x) = 1 -> x = 2^15
	
	////////////////////////////
	// INICIALIZ��O DO TIMER1 //
	////////////////////////////

	// No lugar de set_timer1(32768); o melhor � usar o registrador:
	TMR1H =0x00 ; TMR1L =0x00; // zera tudo
	TMR1H |=0x80; // esse valor corresponde ao bit mais significativo de n�vel l�gico alto > seta o bit mais significativo, equivalente a escrevermos o valor 32768
	
	// Para uma temporiza��o precisa � preciso acessar os registradores do timer1 > incluir arquivo dos registradores no c�digo(regs_16f.h) e no arquivo do projeto

    //////////////////////////////////
    // ETAPA DE EXECU��O PERMANENTE //
    //////////////////////////////////

    while (TRUE)
    {
		if (tmr1if) // Flag do timer1 > houve estouro do timer1? == Passou um segundo?
    	{
			seg++;
			output_toggle (pin_d0); // Comando do Ccsc (para o teste) > inverte o estado do pino d0 a cada 1 segundo
			
			if (seg > 59)
			{
				seg = 0;
				min++;
		
				if (min > 59)
				{
					min = 0;
					hora++;

					if (hora > 24)
						hora = 0;
				}
			}

			tmr1if = 0;
			TMR1H |=0x80;
		}

	}
}