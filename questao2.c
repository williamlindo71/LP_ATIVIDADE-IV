#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Aluno {
    char nome[500];
    char dataNascimento[500];
    float nota1;
    float nota2;
    float media;
};


float calcularMedia(struct Aluno aluno) {
    return (aluno.nota1 + aluno.nota2) / 2;
}


void Aprovação(struct Aluno aluno) {
    if (aluno.media >= 7) {
        printf("%s está APROVADO!\n", aluno.nome);
    } else {
        printf("%s está REPROVADO!\n", aluno.nome);
    }
}

void main() {
    setlocale(LC_ALL, "portuguese");
    struct Aluno alunos[5]; 

    
    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do aluno %d:\n", i + 1);
        scanf("%s", alunos[i].nome);
        
        printf("Digite a data de nascimento:\n");
        scanf("%s", alunos[i].dataNascimento);
        
        printf("Digite a nota 1:\n");
        scanf("%f", &alunos[i].nota1);
        
        printf("Digite a nota 2:\n");
        scanf("%f", &alunos[i].nota2);

        
        alunos[i].media = calcularMedia(alunos[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("Média de %s: %.2f\n", alunos[i].nome, alunos[i].media);
        Aprovação(alunos[i]);
    }

   
}