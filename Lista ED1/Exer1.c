#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX_PACIENTES 50
#define HORA_MIN 7
#define HORA_MAX 19
#define MINUTOS_MAX 60
#define TEMPO_RESTANTE_MAX 720

typedef struct
{
    int hora;
    int minutos;
    int tempoRestante;
    int chave;
} Paciente;

typedef struct
{
    Paciente pacientes[TAMANHO_MAX_PACIENTES];
    int tamanho;
} FilaPacientes;

Paciente novoPaciente(unsigned int horaChegada, unsigned int minutosChegada, unsigned int tempoRestante, int chave);
void mostrarPaciente(Paciente paciente);
void criarFilaVazia(FilaPacientes *fila);
void insFila(FilaPacientes *fila, Paciente novoPaciente);
void mostrarFila(FilaPacientes fila);
int pacienteEstadoCritico(FilaPacientes fila);

int converterParaMinutos(int h, int m);

int main(int argc, char const *argv[])
{
    int numeroPacientes, horaChegada, minutosChegada, tempoRestante;
    scanf("%d", &numeroPacientes);

    FilaPacientes fila;
    criarFilaVazia(&fila);

    for (int i = 0; i < numeroPacientes; i++)
    {
        scanf("%d %d %d", &horaChegada, &minutosChegada, &tempoRestante);
        Paciente paciente = novoPaciente(horaChegada, minutosChegada, tempoRestante, (i + 1));
        insFila(&fila, paciente);
    }

    int numeroCriticos = pacienteEstadoCritico(fila);
    printf("%d\n", numeroCriticos);

    return 0;
}

Paciente novoPaciente(unsigned int horaChegada, unsigned int minutosChegada, unsigned int tempoRestante, int chave)
{
    Paciente q;
    q.hora = horaChegada;
    q.minutos = minutosChegada;
    q.tempoRestante = tempoRestante;
    q.chave = chave;
    return q;
}

void mostrarPaciente(Paciente paciente)
{
    printf("\nChave......................: %d", paciente.chave);
    printf("\nHora de chegada............: %d", paciente.hora);
    printf("\nMinuto de chegada..........: %d", paciente.minutos);
    printf("\nMinutos restantes..........: %d", paciente.tempoRestante);
}

void criarFilaVazia(FilaPacientes *fila)
{
    fila->tamanho = 0;
}

void insFila(FilaPacientes *fila, Paciente novoPaciente)
{
    if (fila->tamanho < TAMANHO_MAX_PACIENTES)
    {
        fila->pacientes[fila->tamanho] = novoPaciente;
        fila->tamanho++;
    }
    else
    {
        printf("Fila cheia, não é possível adicionar mais pacientes.\n");
    }
}

void mostrarFila(FilaPacientes fila)
{
    int i;

    if (fila.tamanho == 0)
    {
        printf("A fila está vazia\n");
    }
    else
    {
        printf("A lista possui %d elementos.\n\n", fila.tamanho);
        for (i = 0; i < fila.tamanho; i++)
        {
            printf("Paciente nº: %d\n", (i + 1));
            mostrarPaciente(fila.pacientes[i]);
            printf("\n");
        }
    }
}

int converterParaMinutos(int h, int m) {
    return (h - 7) * 60 + m;
}

int pacienteEstadoCritico(FilaPacientes fila)
{
    int numeroEmEstadoCritico = 0;
    int tempoAtual = 0; // Começa às 7:00

    for (int i = 0; i < fila.tamanho; i++)
    {
        int tempoChegada = converterParaMinutos(fila.pacientes[i].hora, fila.pacientes[i].minutos);
        int tempoCritico = tempoChegada + fila.pacientes[i].tempoRestante;

        // Se o tempo atual é menor que o tempo de chegada, atualiza o tempo atual
        if (tempoAtual < tempoChegada) {
            tempoAtual = tempoChegada;
        }

        // Verifica se o paciente atingiu a condição crítica antes de ser atendido
        if (tempoAtual > tempoCritico) {
            // O paciente atingiu a condição crítica
            numeroEmEstadoCritico++;
        }

        // O atendimento ocorre de 30 em 30 minutos
        tempoAtual += 30;
    }

    return numeroEmEstadoCritico;
}