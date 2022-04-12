
//////////////
// EDIVÂNIA //
//   UFPI   //
//   2022   //
//////////////

/*
Fazer um código em C para fazer com que o timer0 opere como contador por borda de descida. 
A cada 10 contagens o estado do pino RA0 da porta A é invertido de estado.
*/

#include <16F877A.h>
#include "reg_16f.h"

void main()
{
	unsigned int8 cont = 0;
	
	TRISA = 0x00; // TRISA como saida

/*
	RBPU (+ significativo)
		0
	
	INTERDEG
		0
	
	T0CS - Define a fonte de clock do TIMER0:
		1 - Externa (PINO RA4/T0CKIN) - Modo contador;
	
	T0SE - Seleção da borda de transição do pino RA4/T0CKIN
		1 - transição nivel alto-baixo (transição negativa);
		
	PSA - Habilitação do prescaler (no modo CONTADOR é comum desabilitar);
		1 - Desabilitado;
	
	PS2, PS1, PS0 - Seleção do prescaler (somente no modo temporizador);
		0 (PS2)
		0 (PS1)
		0 (PS0) (- significativo)
			> 00111000
*/
	OPTION_REG = 0b00111000; // Modo contador (seta o bit 5: T0CS) > clk externo (pino RA4/T0CKIN)
	
	TMR0 = 0; // Inicializa o registro TMR0 com o valor 0.
	output_bit (pin_A0, 0); // Inicializa o valor do pino em 0
 
	while (TRUE)
	{
		cont++;

		if (cont == 10)
		{
			output_toggle (pin_A0); // Inverte o estado do pino RA0 a cada 10 pulsos/contagem
	  		cont = 0;
			TMR0 = 0;
		}
	}
}