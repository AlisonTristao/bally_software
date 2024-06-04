// autor Greg

#include <cstdint>
#include <Arduino.h>

typedef enum
{
    ROTACIONAL,
    TRANSLACIONAL
} modos;

typedef enum
{
    LEFT,
    RIGHT
} motors;

class Control
{
public:
    // construtor
    Control(double kp, double ki, double kd);
    ~Control();
    // atualiza todas constantes
    void setConst(double kp, double ki, double kd);
    void setConstPiMotors(double kp, double ki);
    void setVerb(bool verb);
    /**
     * escolhemos qual modo do PID usar
     * @param
     * Erro calculado com a biblioteca linesensor
     * @param
     * mode Rotacional ou Translacional
     */
    int32_t simplePID(double kp, double ki, double kd, double Erro, int32_t limit);
    int32_t simplePD(double kp, double kd, int32_t Erro, int32_t limit);
    // printa as configurações
    void printConfig();

private:
    int32_t simplePD1(double kp, double kd, int32_t Erro, int32_t limit);
    int32_t simplePD2(double kp, double kd, int32_t Erro, int32_t limit);
    int32_t rightPI(double kp, double ki, double Erro, int32_t limit);
    int32_t leftPI(double kp, double ki, double Erro, int32_t limit);
    uint32_t Time = 0;
    double kp = 1, kd = 1, ki = 1, k1, k2, ka;
    double Erro = 0, ErroPassado = 0, Ie = 0;
    bool verb = false;
    int32_t pid, aw;
};
