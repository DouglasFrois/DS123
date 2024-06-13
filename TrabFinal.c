#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_NOME_TURMA 25
#define MAX_NOME_ALUNO 40
#define MAX_AULAS 30
#define MAX_AVALIACOES 5
#define MAX_ALUNOS 40
#define MAX_TURMAS 10

typedef struct {
    char nomeAluno[MAX_NOME_ALUNO + 1];
    float notas[MAX_AVALIACOES];
    float notaProvaFinal;
    int presencas[MAX_AULAS];
} Aluno;

typedef struct {
    char nomeTurma[MAX_NOME_TURMA + 1];
    int numAulas;
    int chamadasRealizadas;
    int numAvaliacoesTurma;
    int avaliacoesRealizadas;
    int provaFinalRealizada;
    Aluno alunos[MAX_ALUNOS];
} Turma;

int cadastrarTurma(Turma *turmas, int numTurmas);
void editarTurma(Turma *turmas, int numTurmas);
int excluirTurma(Turma *turmas, int numTurmas);
int matricularAluno(Turma *turmas, int numTurmas);
void editarAluno(Turma *turmas, int numTurmas);
void excluirAluno(Turma *turmas, int numTurmas);
void fazerChamada(Turma *turmas, int numTurmas);
void registrarAvaliacoes(Turma *turmas, int numTurmas);
void verificarDesempenho(Turma *turmas, int numTurmas);
void carregarDados(Turma *turmas, int *numTurmas);
void salvarDados(Turma *turmas, int numTurmas);

int main() {
	
setlocale(LC_ALL, "Portuguese");

int numTurmas;
Turma turmas[MAX_TURMAS];

carregarDados(turmas, &numTurmas);

int opcao1;
do {
	opcao1 = -1;
	printf("\n");
    printf("Menu inicial:\n");
    printf("1. Turmas\n");
    printf("2. Alunos\n");
    printf("3. Chamada\n");
    printf("4. Avalia��es\n");
    printf("5. Desempenho\n");
    printf("0. Sair\n");
    printf("Escolha uma op��o: ");
    scanf("%d", &opcao1);
    fflush(stdin);
    switch (opcao1) {
    case 1: {
        int opcao2;
        do {
        	opcao2 = -1;
        	printf("\n");
            printf("1. Criar turma\n");
            printf("2. Editar turma\n");
            printf("3. Excluir turma\n");
            printf("0. Voltar\n");
            printf("Escolha uma op��o: ");
            if(opcao2 != 0) {
                scanf("%d", &opcao2);
                fflush(stdin);
            }
            switch (opcao2) {
            case 1:
            	numTurmas = cadastrarTurma(turmas, numTurmas);
                break;
            case 2:
                editarTurma(turmas, numTurmas);
                break;
            case 3:
                numTurmas = excluirTurma(turmas, numTurmas);
                break;
            case 0:
                break;
            default:
                printf("Op��o inv�lida. Por favor, tente novamente.\n");
                opcao2 = -1;
            }
        } while (opcao2 != 0);
        break;
    }
    case 2: {
        int opcao3;
        do {
        	opcao3 = -1;
        	printf("\n");
            printf("1. Matricular aluno\n");
            printf("2. Editar aluno\n");
            printf("3. Excluir aluno\n");
            printf("0. Voltar\n");
            printf("Escolha uma op��o: ");
            if(opcao3 != 0) {
                scanf("%d", &opcao3);
                fflush(stdin);
            }
            switch (opcao3) {
            case 1:
                numTurmas = matricularAluno(turmas, numTurmas);
                break;
            case 2:
                editarAluno(turmas, numTurmas);
                break;
            case 3:
                excluirAluno(turmas, numTurmas);
                break;
            case 0:
                break;
            default:
                printf("Op��o inv�lida. Por favor, tente novamente.\n");
                opcao3 = -1;
            }
        } while (opcao3 != 0);
        break;
    }
    case 3:
        fazerChamada(turmas, numTurmas);
        break;
    case 4:
        registrarAvaliacoes(turmas, numTurmas);
        break;
    case 5:
        verificarDesempenho(turmas, numTurmas);
        break;
    case 0:
        break;
    default:
        printf("Op��o inv�lida. Por favor, tente novamente.\n");
    }
} while (opcao1 != 0);

return 0;
}

int cadastrarTurma(Turma *turmas, int numTurmas) {
	printf("\n");
    if (numTurmas >= MAX_TURMAS) {
        printf("N�mero m�ximo de turmas atingido.\n");
        return numTurmas;
    }
    char nomeTurma[25];
    printf("Digite o nome da turma: ");
    fgets(nomeTurma, 25, stdin);
    nomeTurma[strcspn(nomeTurma, "\n")] = 0;
    char *token = strtok(nomeTurma, " ");
    char nomeSemEspacos[25] = "";
    while (token != NULL) {
        strcat(nomeSemEspacos, token);
        token = strtok(NULL, " ");
    }
    fflush(stdin);
    for (int i = 0; i < numTurmas; i++) {
        if (strcmp(turmas[i].nomeTurma, nomeSemEspacos) == 0) {
            printf("J� existe uma turma com o nome '%s'.\n", nomeSemEspacos);
            return numTurmas;
        }
    }
    strcpy(turmas[numTurmas].nomeTurma, nomeSemEspacos);
    printf("Digite o n�mero de aulas: ");
    scanf("%d", &(turmas[numTurmas].numAulas));
    fflush(stdin);
    printf("Digite o n�mero de avalia��es: ");
    scanf("%d", &(turmas[numTurmas].numAvaliacoesTurma));
    fflush(stdin);
    if (turmas[numTurmas].numAvaliacoesTurma > MAX_AVALIACOES) {
        printf("N�mero m�ximo de avalia��es excedido. O n�mero de avalia��es foi definido para %d.\n", MAX_AVALIACOES);
        turmas[numTurmas].numAvaliacoesTurma = MAX_AVALIACOES;
    }
    printf("Turma '%s' cadastrada com sucesso!\n", turmas[numTurmas].nomeTurma);
    numTurmas++;
    salvarDados(turmas, numTurmas);
    return numTurmas;
}

void editarTurma(Turma *turmas, int numTurmas) {
	printf("\n");
    if (numTurmas == 0) {
        printf("Nenhuma turma para editar.\n");
        return;
    }
    printf("Turmas cadastradas:\n");
    for (int i = 0; i < numTurmas; i++) {
        printf("%d. %s\n", i + 1, turmas[i].nomeTurma);
    }
    printf("Digite o n�mero da turma para editar: ");
    int numTurma;
    scanf("%d", &numTurma);
    fflush(stdin);
    numTurma--;
    if (numTurma >= 0 && numTurma < numTurmas) {
        printf("Voc� est� editando a turma: %s\n", turmas[numTurma].nomeTurma);
        char nomeTurma[25];
    	printf("Digite o nome da turma: ");
    	fgets(nomeTurma, 25, stdin);
    	nomeTurma[strcspn(nomeTurma, "\n")] = 0;
        char *token = strtok(nomeTurma, " ");
        char nomeSemEspacos[25] = "";
        while (token != NULL) {
            strcat(nomeSemEspacos, token);
            token = strtok(NULL, " ");
        }

        fflush(stdin);
        for (int i = 0; i < numTurmas; i++) {
            if (i != numTurma && strcmp(turmas[i].nomeTurma, nomeSemEspacos) == 0) {
                printf("J� existe uma turma com o nome '%s'.\n", nomeSemEspacos);
                return;
            }
        }
        strcpy(turmas[numTurma].nomeTurma, nomeSemEspacos);
        printf("Digite o novo n�mero de aulas: ");
        scanf("%d", &(turmas[numTurma].numAulas));
        fflush(stdin);
        printf("Digite o novo n�mero de avalia��es: ");
        scanf("%d", &(turmas[numTurma].numAvaliacoesTurma));
        fflush(stdin);
        printf("Turma '%s' atualizada com sucesso!\n", turmas[numTurma].nomeTurma);
    } else {
        printf("N�mero de turma inv�lido.\n");
    }
    salvarDados(turmas, numTurmas);
}

int excluirTurma(Turma *turmas, int numTurmas) {
	printf("\n");
    if (numTurmas == 0) {
        printf("Nenhuma turma para excluir.\n");
        return numTurmas;
    }
    printf("Turmas cadastradas:\n");
    for (int i = 0; i < numTurmas; i++) {
        printf("%d. %s\n", i + 1, turmas[i].nomeTurma);
    }
    printf("Digite o n�mero da turma para excluir: ");
    int numTurma;
    scanf("%d", &numTurma);
    fflush(stdin);
    numTurma--;
    if (numTurma >= 0 && numTurma < numTurmas) {
        printf("Tem certeza que deseja excluir? Digite 1 para sim, 0 para n�o.\n", turmas[numTurma].nomeTurma);
        int confirma;
		scanf("%d", &confirma);
		fflush(stdin);
		if (confirma == 1) {
		    for (int i = numTurma; i < numTurmas - 1; i++) {
            	turmas[i] = turmas[i + 1];
        	}
        	printf("Turma '%s' exclu�da com sucesso!\n", turmas[numTurma].nomeTurma);
        	numTurmas--;
    	}
    } else {
        printf("N�mero de turma inv�lido.\n");
    }
    salvarDados(turmas, numTurmas);
    return numTurmas;
}

int matricularAluno(Turma *turmas, int numTurmas) {
	printf("\n");
    if (numTurmas == 0) {
        printf("Nenhuma turma para matricular aluno.\n");
        return numTurmas;
    }
    int indicesTurmas[MAX_TURMAS];
    for (int i = 0; i < numTurmas; i++) {
        indicesTurmas[i] = i;
    }
    for (int i = 0; i < numTurmas - 1; i++) {
        for (int j = i + 1; j < numTurmas; j++) {
            if (strcmp(turmas[indicesTurmas[i]].nomeTurma, turmas[indicesTurmas[j]].nomeTurma) > 0) {
                int temp = indicesTurmas[i];
                indicesTurmas[i] = indicesTurmas[j];
                indicesTurmas[j] = temp;
            }
        }
    }
    printf("Turmas cadastradas:\n");
    for (int i = 0; i < numTurmas; i++) {
        printf("%d. %s\n", i + 1, turmas[indicesTurmas[i]].nomeTurma);
    }
    printf("Digite o n�mero da turma para matricular o aluno: ");
    int numTurma;
    scanf("%d", &numTurma);
    fflush(stdin);
    numTurma--;
    if (numTurma >= 0 && numTurma < numTurmas) {
        int numAlunos = 0;
        for (int i = 0; i < MAX_ALUNOS; i++) {
            if (strcmp(turmas[numTurma].alunos[i].nomeAluno, "") != 0) {
                numAlunos++;
            }
        }
        if (numAlunos >= MAX_ALUNOS) {
            printf("N�mero m�ximo de alunos na turma '%s' atingido.\n", turmas[numTurma].nomeTurma);
            return numTurmas;
        }
        char nomeAluno[40];
        printf("Digite o nome do aluno: ");
        fgets(nomeAluno, 40, stdin);
        nomeAluno[strcspn(nomeAluno, "\n")] = 0;
        char *token = strtok(nomeAluno, " ");
        char nomeSemEspacos[40] = "";
        while (token != NULL) {
            strcat(nomeSemEspacos, token);
            token = strtok(NULL, " ");
        }
        fflush(stdin);
        for (int i = 0; i < MAX_ALUNOS; i++) {
            if (strcmp(turmas[numTurma].alunos[i].nomeAluno, nomeSemEspacos) == 0) {
                printf("J� existe um aluno com o nome '%s' na turma '%s'.\n", nomeSemEspacos, turmas[numTurma].nomeTurma);
                return numTurmas;
            }
        }
        strcpy(turmas[numTurma].alunos[numAlunos].nomeAluno, nomeSemEspacos);
        printf("Aluno '%s' matriculado com sucesso na turma '%s'!\n", turmas[numTurma].alunos[numAlunos].nomeAluno, turmas[numTurma].nomeTurma);
    } else {
        printf("N�mero de turma inv�lido.\n");
    }
    salvarDados(turmas, numTurmas);
    return numTurmas;
}

void editarAluno(Turma *turmas, int numTurmas) {
	printf("\n");
    if (numTurmas == 0) {
        printf("Nenhuma turma para editar aluno.\n");
        return;
    }
    printf("Turmas cadastradas:\n");
    for (int i = 0; i < numTurmas; i++) {
        printf("%d. %s\n", i + 1, turmas[i].nomeTurma);
    }
    printf("Digite o n�mero da turma: ");
    int numTurma;
    scanf("%d", &numTurma);
    fflush(stdin);
    numTurma--;
    if (numTurma >= 0 && numTurma < numTurmas) {
        int numAlunos = 0;
        for (int i = 0; i < MAX_ALUNOS; i++) {
            if (strcmp(turmas[numTurma].alunos[i].nomeAluno, "") != 0) {
                numAlunos++;
            }
        }
        if (numAlunos == 0) {
            printf("N�o h� alunos matriculados na turma '%s'.\n", turmas[numTurma].nomeTurma);
            return;
        }
        printf("Alunos matriculados na turma '%s':\n", turmas[numTurma].nomeTurma);
        for (int i = 0; i < numAlunos; i++) {
            printf("%d. %s\n", i + 1, turmas[numTurma].alunos[i].nomeAluno);
        }
        printf("Digite o n�mero do aluno para editar: ");
        int numAluno;
        scanf("%d", &numAluno);
        fflush(stdin);
        numAluno--;
        if (numAluno >= 0 && numAluno < numAlunos) {
            printf("Voc� est� editando o aluno: %s\n", turmas[numTurma].alunos[numAluno].nomeAluno);
            char nomeAluno[40];
            printf("Digite o novo nome do aluno: ");
            fgets(nomeAluno, 40, stdin);
            nomeAluno[strcspn(nomeAluno, "\n")] = 0;
            char *token = strtok(nomeAluno, " ");
            char nomeSemEspacos[40] = "";
            while (token != NULL) {
                strcat(nomeSemEspacos, token);
                token = strtok(NULL, " ");
            }

            fflush(stdin);
            for (int i = 0; i < numAlunos; i++) {
                if (i != numAluno && strcmp(turmas[numTurma].alunos[i].nomeAluno, nomeSemEspacos) == 0) {
                    printf("J� existe um aluno com o nome '%s' na turma '%s'.\n", nomeSemEspacos, turmas[numTurma].nomeTurma);
                    return;
                }
            }
            strcpy(turmas[numTurma].alunos[numAluno].nomeAluno, nomeSemEspacos);
            printf("Aluno atualizado com sucesso!\n");
        } else {
            printf("N�mero de aluno inv�lido.\n");
        }
    } else {
        printf("N�mero de turma inv�lido.\n");
    }
    salvarDados(turmas, numTurmas);
}

void excluirAluno(Turma *turmas, int numTurmas) {
	printf("\n");
    if (numTurmas == 0) {
        printf("Nenhuma turma para excluir alunos.\n");
        return;
    }
    printf("Turmas cadastradas:\n");
    for (int i = 0; i < numTurmas; i++) {
        printf("%d. %s\n", i + 1, turmas[i].nomeTurma);
    }
    printf("Digite o n�mero da turma: ");
    int numTurma;
    scanf("%d", &numTurma);
    fflush(stdin);
    numTurma--;
    if (numTurma >= 0 && numTurma < numTurmas) {
        int numAlunosNaTurma = 0;
        for (int i = 0; i < MAX_ALUNOS; i++) {
            if (strcmp(turmas[numTurma].alunos[i].nomeAluno, "") != 0) {
                numAlunosNaTurma++;
            }
        }
        if (numAlunosNaTurma == 0) {
            printf("Nenhum aluno matriculado na turma '%s'.\n", turmas[numTurma].nomeTurma);
            return;
        }
        printf("Alunos matriculados na turma '%s':\n", turmas[numTurma].nomeTurma);
        for (int i = 0; i < MAX_ALUNOS; i++) {
            if (strcmp(turmas[numTurma].alunos[i].nomeAluno, "") != 0) {
                printf("%d. %s\n", i + 1, turmas[numTurma].alunos[i].nomeAluno);
            }
        }
        printf("Digite o n�mero do aluno para excluir: ");
        int numAluno;
        scanf("%d", &numAluno);
        fflush(stdin);
        numAluno--;
        if (numAluno >= 0 && numAluno < MAX_ALUNOS && strcmp(turmas[numTurma].alunos[numAluno].nomeAluno, "") != 0) {
            printf("Tem certeza que deseja excluir? Digite 1 para sim, 0 para n�o.\n", turmas[numTurma].nomeTurma);
        	int confirma;
			scanf("%d", &confirma);
			fflush(stdin);
			if (confirma == 1) {
                for (int i = numAluno; i < MAX_ALUNOS - 1; i++) {
                    turmas[numTurma].alunos[i] = turmas[numTurma].alunos[i + 1];
                }
                memset(&turmas[numTurma].alunos[MAX_ALUNOS - 1], 0, sizeof(Aluno));

                printf("Aluno exclu�do com sucesso!\n");
            } else {
                printf("Exclus�o do aluno cancelada.\n");
            }
        } else {
            printf("N�mero de aluno inv�lido.\n");
        }
    } else {
        printf("N�mero de turma inv�lido.\n");
    }
    salvarDados(turmas, numTurmas);
}

void fazerChamada(Turma *turmas, int numTurmas) {
	printf("\n");
    if (numTurmas == 0) {
        printf("Nenhuma turma para fazer chamada.\n");
        return;
    }
	int indices[MAX_TURMAS];
    for (int i = 0; i < numTurmas; i++) {
        indices[i] = i;
    }
    for (int i = 0; i < numTurmas - 1; i++) {
        for (int j = i + 1; j < numTurmas; j++) {
            if (strcmp(turmas[indices[i]].nomeTurma, turmas[indices[j]].nomeTurma) > 0) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }
    printf("Turmas cadastradas:\n");
    for (int i = 0; i < numTurmas; i++) {
        printf("%d. %s\n", i + 1, turmas[indices[i]].nomeTurma);
    }
    printf("Digite o n�mero da turma: ");
    int numTurma;
    scanf("%d", &numTurma);
    fflush(stdin);
    numTurma--;

    if (numTurma < 0 || numTurma >= numTurmas) {
        printf("N�mero de turma inv�lido. Por favor, digite um n�mero entre 1 e %d.\n", numTurmas);
        return;
    }

    if (turmas[numTurma].chamadasRealizadas >= turmas[numTurma].numAulas) {
        printf("Todas as chamadas para esta turma j� foram registradas. N�o h� mais aulas para registrar chamadas.\n");
        return;
    } else {
        printf("N�mero de turma inv�lido.\n");
        return;
    }

    int indicesTurmas[MAX_TURMAS];
    for (int i = 0; i < numTurmas; i++) {
        indicesTurmas[i] = i;
    }
    for (int i = 0; i < numTurmas - 1; i++) {
        for (int j = i + 1; j < numTurmas; j++) {
            if (strcmp(turmas[indicesTurmas[i]].nomeTurma, turmas[indicesTurmas[j]].nomeTurma) > 0) {
                int temp = indicesTurmas[i];
                indicesTurmas[i] = indicesTurmas[j];
                indicesTurmas[j] = temp;
            }
        }
    }
    printf("Turmas cadastradas:\n");
    for (int i = 0; i < numTurmas; i++) {
        printf("%d. %s\n", i + 1, turmas[indicesTurmas[i]].nomeTurma);
    }

    int numAlunosNaTurma = 0;
    for (int i = 0; i < MAX_ALUNOS; i++) {
        if (strcmp(turmas[numTurma].alunos[i].nomeAluno, "") != 0) {
            numAlunosNaTurma++;
        }
    }
    if (numAlunosNaTurma == 0) {
        printf("Nenhum aluno matriculado na turma '%s'.\n", turmas[numTurma].nomeTurma);
        return;
    }

    int numAula = turmas[numTurma].chamadasRealizadas;
    printf("Aula atual: %d de %d\n", numAula + 1, turmas[numTurma].numAulas);

    int indicesAlunos[MAX_ALUNOS];
    for (int i = 0; i < MAX_ALUNOS; i++) {
        indicesAlunos[i] = i;
    }
    for (int i = 0; i < MAX_ALUNOS - 1; i++) {
        for (int j = i + 1; j < MAX_ALUNOS; j++) {
            if (strcmp(turmas[numTurma].alunos[indicesAlunos[i]].nomeAluno, turmas[numTurma].alunos[indicesAlunos[j]].nomeAluno) > 0) {
                int temp = indicesAlunos[i];
                indicesAlunos[i] = indicesAlunos[j];
                indicesAlunos[j] = temp;
            }
        }
    }
    for (int i = 0; i < MAX_ALUNOS; i++) {
        if (strcmp(turmas[numTurma].alunos[indicesAlunos[i]].nomeAluno, "") != 0) {
            printf("Aluno: %s\n", turmas[numTurma].alunos[indicesAlunos[i]].nomeAluno);
            printf("Digite 1 para presente e 0 para ausente: ");
            int presenca;
            scanf("%d", &presenca);
            fflush(stdin);
            turmas[numTurma].alunos[indicesAlunos[i]].presencas[turmas[numTurma].chamadasRealizadas] = presenca;
        }
    }
    turmas[numTurma].chamadasRealizadas++;

    salvarDados(turmas, numTurmas);
}

void registrarAvaliacoes(Turma *turmas, int numTurmas) {
	printf("\n");
    if (numTurmas == 0) {
        printf("Nenhuma turma para registrar avalia��es.\n");
        return;
    }
    int indices[MAX_TURMAS];
    for (int i = 0; i < numTurmas; i++) {
        indices[i] = i;
    }
    for (int i = 0; i < numTurmas - 1; i++) {
        for (int j = i + 1; j < numTurmas; j++) {
            if (strcmp(turmas[indices[i]].nomeTurma, turmas[indices[j]].nomeTurma) > 0) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }
    printf("Turmas cadastradas:\n");
    for (int i = 0; i < numTurmas; i++) {
        printf("%d. %s\n", i + 1, turmas[indices[i]].nomeTurma);
    }
    printf("Digite o n�mero da turma: ");
    int numTurma;
    scanf("%d", &numTurma);
    fflush(stdin);
    numTurma--;
    if (numTurma >= 0 && numTurma < numTurmas) {
        if (turmas[numTurma].provaFinalRealizada) {
            printf("A prova final j� foi realizada para a turma '%s'. N�o � poss�vel registrar novas avalia��es.\n", turmas[numTurma].nomeTurma);
            return;
        }
        if (turmas[numTurma].avaliacoesRealizadas >= MAX_AVALIACOES) {
            printf("N�mero m�ximo de avalia��es atingido para a turma '%s'.\n", turmas[numTurma].nomeTurma);
            return;
        }
	}
    int numAlunosNaTurma = 0;
    for (int i = 0; i < MAX_ALUNOS; i++) {
        if (strcmp(turmas[numTurma].alunos[i].nomeAluno, "") != 0) {
            numAlunosNaTurma++;
        }
    }
    if (numAlunosNaTurma == 0) {
        printf("Nenhum aluno matriculado na turma '%s'.\n", turmas[numTurma].nomeTurma);
        return;
    }
    if (numTurma >= 0 && numTurma < numTurmas) {
        if (turmas[numTurma].chamadasRealizadas == 0) {
            printf("Nenhuma chamada foi realizada para a turma '%s'. N�o � poss�vel registrar avalia��es.\n", turmas[numTurma].nomeTurma);
            return;
        }
        int numAvaliacao = turmas[numTurma].avaliacoesRealizadas;

        if (numAvaliacao < turmas[numTurma].numAvaliacoesTurma) {
            printf("Avalia��o %d de %d\n", numAvaliacao + 1, turmas[numTurma].numAvaliacoesTurma);
            for (int i = 0; i < MAX_ALUNOS; i++) {
                if (strcmp(turmas[numTurma].alunos[i].nomeAluno, "") != 0) {
                    printf("Aluno: %s\n", turmas[numTurma].alunos[i].nomeAluno);
                    printf("Digite a nota do aluno (0 a 10): ");
                    scanf("%f", &turmas[numTurma].alunos[i].notas[numAvaliacao]);
                    fflush(stdin);
                }
            }
            turmas[numTurma].avaliacoesRealizadas++;
        } else {
            printf("Todas as avalia��es foram realizadas. Registrando notas da prova final para alunos em recupera��o.\n");
            for (int i = 0; i < MAX_ALUNOS; i++) {
                if (strcmp(turmas[numTurma].alunos[i].nomeAluno, "") != 0) {
                    float mediaNotas = 0;
                    for (int j = 0; j < turmas[numTurma].numAvaliacoesTurma; j++) {
                        mediaNotas += turmas[numTurma].alunos[i].notas[j];
                    }
                    mediaNotas /= turmas[numTurma].numAvaliacoesTurma;
                    if (mediaNotas >= 4 && mediaNotas < 7) {
                        printf("Aluno: %s\n", turmas[numTurma].alunos[i].nomeAluno);
                        printf("Digite a nota da prova final (0 a 10): ");
                        scanf("%f", &turmas[numTurma].alunos[i].notaProvaFinal);
                        fflush(stdin);
                    }
                }
            }
            turmas[numTurma].provaFinalRealizada = 1;
        }
    } else {
        printf("N�mero de turma inv�lido.\n");
    }
    salvarDados(turmas, numTurmas);
}

void verificarDesempenho(Turma *turmas, int numTurmas) {
    printf("\n");
	if (numTurmas == 0) {
        printf("Nenhuma turma para verificar desempenho.\n");
        return;
    }
    int indicesTurmas[MAX_TURMAS];
    for (int i = 0; i < numTurmas; i++) {
        indicesTurmas[i] = i;
    }
    for (int i = 0; i < numTurmas - 1; i++) {
        for (int j = i + 1; j < numTurmas; j++) {
            if (strcmp(turmas[indicesTurmas[i]].nomeTurma, turmas[indicesTurmas[j]].nomeTurma) > 0) {
                int temp = indicesTurmas[i];
                indicesTurmas[i] = indicesTurmas[j];
                indicesTurmas[j] = temp;
            }
        }
    }
    printf("Turmas cadastradas:\n");
    for (int i = 0; i < numTurmas; i++) {
        printf("%d. %s\n", i + 1, turmas[indicesTurmas[i]].nomeTurma);
    }
    printf("Digite o n�mero da turma: ");
    int numTurma;
    scanf("%d", &numTurma);
    fflush(stdin);
    numTurma--;
    int numAlunosNaTurma = 0;
    if (numTurma >= 0 && numTurma < numTurmas) {
    	for (int i = 0; i < MAX_ALUNOS; i++) {
            if (strcmp(turmas[numTurma].alunos[i].nomeAluno, "") != 0) {
                numAlunosNaTurma++;
            }
        }
        if (numAlunosNaTurma == 0) {
            printf("Nenhum aluno matriculado na turma '%s'.\n", turmas[numTurma].nomeTurma);
            return;
        }
        printf("\n");
        printf(">>>>>>>> Nome da turma: %-25s, Chamadas: %2d/%2d, Avalia��es: %d/%d, Prova final realizada? %s <<<<<<<<<\n\n",
               turmas[numTurma].nomeTurma,
               turmas[numTurma].chamadasRealizadas,
               turmas[numTurma].numAulas,
               turmas[numTurma].avaliacoesRealizadas,
               turmas[numTurma].numAvaliacoesTurma,
               turmas[numTurma].provaFinalRealizada ? "Sim" : "N�o");
        printf("Nome do aluno                              Presen�as     -----------Notas-----------   Final  M�dia   Status\n");
        int aprovados = 0, reprovadosPorFalta = 0, emRecuperacao = 0, reprovadosPorNota = 0;
        for (int i = 0; i < MAX_ALUNOS; i++) {
            if (strcmp(turmas[numTurma].alunos[i].nomeAluno, "") != 0) {
                printf("%-42s", turmas[numTurma].alunos[i].nomeAluno);
                int totalPresencas = 0;
                for (int j = 0; j < turmas[numTurma].numAulas; j++) {
                    totalPresencas += turmas[numTurma].alunos[i].presencas[j];
                }
                printf("%2d (%5.1f%%)    ", totalPresencas, (float)totalPresencas / turmas[numTurma].numAulas * 100);
                float somaNotas = 0;
                for (int j = 0; j < 5; j++) {
                    if (j < turmas[numTurma].numAvaliacoesTurma) {
                        printf("%-4.1f%s  ", turmas[numTurma].alunos[i].notas[j], turmas[numTurma].avaliacoesRealizadas ? "" : "");
                        somaNotas += turmas[numTurma].alunos[i].notas[j];
                    } else {
                        printf("      ");
                    }
                }
                printf("%-4.1f%s  ", turmas[numTurma].alunos[i].notaProvaFinal, turmas[numTurma].provaFinalRealizada ? "" : "");
                float mediaNotas = somaNotas / turmas[numTurma].numAvaliacoesTurma;
                float mediaFinal = mediaNotas;
                if (totalPresencas < turmas[numTurma].numAulas * 0.75) {
                printf("         Reprovado por falta\n");
                reprovadosPorFalta++;
            } else if (mediaNotas < 4) {
                printf("%4.1f  ", mediaNotas);
                printf("   Reprovado por nota\n");
                reprovadosPorNota++;
            } else if (mediaNotas < 7) {
                if (turmas[numTurma].provaFinalRealizada == 0) {
                    printf("%4.1f  ", mediaNotas);
                    printf("   Em recupera��o\n");
                    emRecuperacao++;
                } else {
                    mediaFinal = (mediaNotas + turmas[numTurma].alunos[i].notaProvaFinal) / 2;
                    printf("%4.1f  ", mediaFinal);
                    if (mediaFinal >= 7) {
                        printf("   Aprovado\n");
                        aprovados++;
                    } else {
                        printf("   Reprovado\n");
                        reprovadosPorNota++;
                    }
                }
            } else {
                printf("%4.1f  ", mediaNotas);
                printf("   Aprovado\n");
                aprovados++;
            }
        }
    }
        printf("\n");
		printf(">>>> Aprovados: %d (%.2f%%)  ", aprovados, (float)aprovados / numAlunosNaTurma * 100);
        printf("Reprovados por falta: %d (%.2f%%)  ", reprovadosPorFalta, (float)reprovadosPorFalta / numAlunosNaTurma * 100);
    	printf("Reprovados por nota: %d (%.2f%%)  ", reprovadosPorNota, (float)reprovadosPorNota / numAlunosNaTurma * 100);
        printf("Recupera��o: %d (%.2f%%) <<<<\n", emRecuperacao, (float)emRecuperacao / numAlunosNaTurma * 100);
    } else {
        printf("N�mero de turma inv�lido.\n");
    }
}

void salvarDados(Turma *turmas, int numTurmas) {
    FILE *file = fopen("dados.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    for (int i = 0; i < numTurmas; i++) {
        fprintf(file, "%-25s %02d %02d %1d %1d %1d ", turmas[i].nomeTurma, turmas[i].numAulas, turmas[i].chamadasRealizadas, turmas[i].numAvaliacoesTurma, turmas[i].avaliacoesRealizadas, turmas[i].provaFinalRealizada);
        for (int j = 0; j < MAX_ALUNOS; j++) {
            if (strcmp(turmas[i].alunos[j].nomeAluno, "") != 0) {
                fprintf(file, "%-40s ", turmas[i].alunos[j].nomeAluno);
                for (int k = 0; k < MAX_AVALIACOES; k++) {
                    fprintf(file, "%05.1f ", turmas[i].alunos[j].notas[k]);
                }
                fprintf(file, "%05.1f ", turmas[i].alunos[j].notaProvaFinal);
                for (int k = 0; k < MAX_AULAS; k++) {
                    fprintf(file, "%1d ", turmas[i].alunos[j].presencas[k]);
                }
            }
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void carregarDados(Turma *turmas, int *numTurmas) {
    FILE *file = fopen("dados.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }
    *numTurmas = 0;
    char linha[1024];
    while (fgets(linha, sizeof(linha), file)) {
        char *token = strtok(linha, " ");
        if (token != NULL && sscanf(token, "%25s", turmas[*numTurmas].nomeTurma) == 1) {
            token = strtok(NULL, " ");
            if (token != NULL && sscanf(token, "%2d", &turmas[*numTurmas].numAulas) == 1) {
                token = strtok(NULL, " ");
                if (token != NULL && sscanf(token, "%2d", &turmas[*numTurmas].chamadasRealizadas) == 1) {
                    token = strtok(NULL, " ");
                    if (token != NULL && sscanf(token, "%1d", &turmas[*numTurmas].numAvaliacoesTurma) == 1) {
                        token = strtok(NULL, " ");
                        if (token != NULL && sscanf(token, "%1d", &turmas[*numTurmas].avaliacoesRealizadas) == 1) {
                            token = strtok(NULL, " ");
                            if (token != NULL && sscanf(token, "%1d", &turmas[*numTurmas].provaFinalRealizada) == 1) {
                                for (int i = 0; i < MAX_ALUNOS; i++) {
                                    token = strtok(NULL, " ");
                                    if (token != NULL && sscanf(token, "%40s", turmas[*numTurmas].alunos[i].nomeAluno) == 1) {
                                        for (int j = 0; j < MAX_AVALIACOES; j++) {
                                            token = strtok(NULL, " ");
                                            if (token != NULL) {
                                                sscanf(token, "%5f", &turmas[*numTurmas].alunos[i].notas[j]);
                                            }
                                        }
                                        token = strtok(NULL, " ");
                                        if (token != NULL) {
                                            sscanf(token, "%5f", &turmas[*numTurmas].alunos[i].notaProvaFinal);
                                        }
                                        for (int j = 0; j < MAX_AULAS; j++) {
                                            token = strtok(NULL, " ");
                                            if (token != NULL) {
                                                sscanf(token, "%1d", &turmas[*numTurmas].alunos[i].presencas[j]);
                                            }
                                        }
                                    } else {
                                        break;
                                    }
                                }
                                (*numTurmas)++;
                            }
                        }
                    }
                }
            }
        }
    }

    fclose(file);
}
