// autor Greg

#include <cstdint>
#include <Arduino.h>

class Control
{
public:
    // construtor
    Control(double kp, double ki, double kd);
    virtual ~Control(){};
    // atualiza todas constantes
    void setConst(double kp, double ki, double kd);
    void setVerb(bool verb);
    /**
     * escolhemos qual modo do PID usar
     * @param
     * Erro calculado com a biblioteca linesensor
     * @param
     * mode Rotacional ou Translacional
     */
    int32_t simplePID(double kp, double ki, double kd, double Erro, int32_t limit);
    int32_t simplePD(double kp, double kd, double Erro, int32_t limit);
    // printa as configurações
    String printConfig();

private:
    uint32_t Time = 0;
    double kp = 1, kd = 1, ki = 1, k1, k2, ka, limit;
    double Erro = 0, ErroPassado = 0, Ie = 0;
    bool verb = false;
    int32_t pid, aw;
};
