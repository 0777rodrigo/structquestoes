#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct informacoes_aluno
{
    char nome[300];
    int matricula;
    float nota[3];
    float media;
};

char* situacao(float media)
{

    if (media >= 6)
    {
        return "Aprovado";
    }
    else
    {
        return "Reprovado";
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i, j;
    float maiornota1 = 0, maiormedia = 0, menormedia = 999, somanotas = 0;
    struct informacoes_aluno aluno[2];

    for (i = 0; i < 2; i++)
    {

        printf("digite o nome do %d aluno \n", i + 1);
        gets(aluno[i].nome);

        printf("digite a matricula do aluno %d \n", i + 1);
        scanf("%d", &aluno[i].matricula);

        for (j = 0; j < 3; j++)
        {

            printf("digite a nota %d do aluno: \n", j + 1);
            scanf("%f", &aluno[i].nota[j]);

            somanotas += aluno[i].nota[j];
        }

        aluno[i].media = somanotas / j;
        somanotas = 0;

        if (aluno[i].nota[0] > maiornota1)
        {
            maiornota1 = aluno[i].nota[0];
        }
        if (aluno[i].media > maiormedia)
        {
            maiormedia = aluno[i].media;
        }
        if (aluno[i].media < menormedia)
        {
            menormedia = aluno[i].media;
        }

        fflush(stdin);
    }

    printf("maior nota da primeira prova %2.f \n", maiornota1);
    printf("maior media geral %2.f \n", maiormedia);
    printf("menor media geral %2.f \n", menormedia);

    for (i = 0; i < 2; i++){
        printf("nome do aluno %d: %s \n", i + 1, aluno[i].nome);
        printf("matricula do aluno %d: %d \n", i + 1, aluno[i].matricula);
        printf("Media do aluno %d: %2.f. \n Situacao: %s \n", i + 1,aluno[i].media ,situacao(aluno[i].media));
    }

    return 0;
}
