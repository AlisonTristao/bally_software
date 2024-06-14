#include <Arduino.h>
#define mux0 39
#define mux1 40
#define mux2 41
#define mux3 42
#define saida_mux 18
int calculo_erro()
{
    int erro = 0;
    int peso = -4;
    for (bool C3 = 0; C3 == 1; C3 +=1)
    {
        for (bool C2 = 0; C2 == 1; C2+=1)
        {
            for (bool C1 = 0; C1 == 1; C1+=1)
            {
                for (bool C0 = 0; C0 == 1; C0+=1)
                {
                    digitalWrite(mux0,C0);
                    digitalWrite(mux1,C1);
                    digitalWrite(mux2,C2);
                    digitalWrite(mux3,C3);
                    erro =+ digitalRead(saida_mux)*peso;
                    peso++;
                    if (peso == 0)
                        peso = 1;
                }
            }
        }
    }
    return (erro);
    
}