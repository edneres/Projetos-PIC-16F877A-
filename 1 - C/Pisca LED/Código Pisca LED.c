#include <16F628a.h> // O ".h" indica que esse arquivo � um cabe�alho que con�m todas as configura��es pra se trabalhar com esse microcontrolador

#fuses XT, NOLVP, NOWDT // Bits de configura��es
						// Fus�vel do tipo XT: � a velocidade do oscilador externo (se � lenta, m�dia ou alta, no caso, m�dia
				        // NOLVP: "No Low Voltage Programe" (grava modo de grava��o em baixa tens�o, no caso, desabilitado > NO < ; com isso passa-se a ter condi��es de ultilizar o pino RB )
				        // NOWDT: "No Watch Dog TIme" >> NO - desabilita >> WDT - reinicia o c�digo a cada erro/trvamento

#use delay(clock = 4000000) // Outra diretiva com o que se quer usar de especial no c�digo
		                    // delay: sistema pra atraso, trava o c�digo em determinado momento, uma parada for�ada, com determinada frequ�ncia pra base de tempo como par�metro
							// clocl: base para o delay.
							// 4000000: frequ�ncia [do clock] do cristal externo. Frequ�ncia m�dia, tal qual o requerido anteriormente. >> Frequ�ncias m�dias -- 1MHz - 4MHz (para esse Micro)  


void main()
{
	while(TRUE)
		{
			////////////////////////
			// EFEITO PISCA-PISCA //
			////////////////////////

			output_high(pin_b0); // Liga uma sa�da em n�vel alto (poderia ser em n�vel baixo). >> pin_b0: par�metro que indica qual a sa�da 
			
			// Depois de ligado, quer-se que a sa�da fique um tempo ligada...
			delay_ms(500); // delay sempre em milissegundos (ms) ou em micro. >> 500: o tempo do delay (meio segundo)
			
			// Passado o tempo especificado, agora quer-se desligar a sa�da...
			output_low(pin_b0); 
			
			// Depois de desligado, quer-se que a sa�da fique um tempo desligada... 
			delay_ms(500);
		}
}












































