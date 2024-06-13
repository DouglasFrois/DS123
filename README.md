# DS123
Trabalho final da disciplina DS123-TADS-UFPR

UNIVERSIDADE FEDERAL DO PARANÁ
Setor de Educação Profissional e Tecnológica
Tecnologia em Análise e Desenvolvimento de Sistemas
Disciplina: DS123 - Linguagem de Programação 
Prof. Roberson Cesar Alves de Araujo
Discentes: Douglas Cleverson Fróis (GRR20236486) e Sally Ai Saito (GRR20236485)

Desenvolvimento de um Sistema Integrado de Gerenciamento Acadêmico

Este documento foi criado com o objetivo de fornecer uma visão detalhada e compreensível do sistema de gerenciamento acadêmico implementado em C. Ele serve como um guia para desenvolvedores, usuários e partes interessadas para entender o funcionamento interno do sistema, suas funcionalidades e a lógica por trás de sua implementação.

       1. Introdução

O projeto em questão é um sistema de gerenciamento acadêmico desenvolvido em C. O sistema é projetado para gerenciar turmas e alunos, permitindo o registro de presenças, avaliações e desempenho dos alunos.

1.1. Objetivos: O principal objetivo deste sistema é facilitar o gerenciamento de turmas e alunos, fornecendo uma plataforma onde os professores podem registrar facilmente a presença e o desempenho dos alunos. Além disso, o sistema visa melhorar a eficiência e a precisão do processo de gerenciamento acadêmico.

1.2. Delimitação do Problema: O sistema é projetado para lidar com um número máximo de turmas e alunos. Ele não é projetado para lidar com outras funcionalidades, como gerenciamento de funcionários ou finanças.

1.3 Justificativa: A necessidade de um sistema de gerenciamento eficiente é crucial em qualquer instituição educacional. Este sistema foi desenvolvido para atender a essa necessidade, permitindo que os professores se concentrem mais no ensino e menos na administração.

1.4. Método de Trabalho: O sistema foi desenvolvido usando a linguagem de programação C, aproveitando suas características de baixo nível e eficiência. O código é estruturado e organizado de maneira a facilitar a compreensão e a manutenção.

Este documento irá detalhar cada função do código, explicando seu propósito, funcionamento e como ela contribui para o objetivo geral do sistema. Esperamos que este documento seja um recurso valioso para entender e trabalhar com este sistema de gerenciamento acadêmico.

       2. Descrição Geral do Sistema

O sistema em questão é um software de gerenciamento acadêmico desenvolvido na linguagem de programação C. Ele foi projetado para facilitar a administração de turmas e alunos em um ambiente educacional.

2.1. Visão Geral
O sistema fornece uma plataforma onde os professores podem registrar a presença dos alunos, suas notas e avaliações, além de gerenciar turmas. Ele também permite a matrícula de alunos e a criação de novas turmas.

2.2. Escopo
O escopo do sistema inclui o gerenciamento de turmas, alunos, presenças e avaliações. Ele permite que os professores registrem a presença dos alunos em cada aula, insiram notas para diferentes avaliações e gerenciem o desempenho geral dos alunos.

2.3. Funções Principais
1. Gerenciamento de Turmas: Permite a criação, edição e exclusão de turmas.
2. Gerenciamento de Alunos: Permite a matrícula de alunos em turmas, bem como a edição e exclusão de alunos.
3. Registro de Presenças: Permite que os professores registrem a presença dos alunos em cada aula.
4. Registro de Avaliações: Permite que os professores registrem as notas dos alunos para diferentes avaliações.
5. Verificação de Desempenho: Fornece uma visão geral do desempenho dos alunos, incluindo presença e notas.

2.4. Envolvidos
Os principais envolvidos no sistema são os professores, que usam o sistema para gerenciar suas turmas e alunos, e os alunos, que são gerenciados pelo sistema. Além disso, os desenvolvedores do sistema também são um grupo envolvido importante, pois são responsáveis pela manutenção e atualização do sistema. 

Espera-se que esta descrição geral forneça uma compreensão clara do sistema, suas funções principais e os envolvidos. A documentação subsequente fornecerá detalhes mais específicos sobre cada aspecto do sistema.

       3. Requisitos do Sistema

3.1. Requisitos Funcionais
Gerenciamento de Turmas: O sistema deve permitir a criação, edição e exclusão de turmas. Deve ser possível inserir informações relevantes para cada turma, como o nome da turma, o número de aulas, e o número de avaliações.

Gerenciamento de Alunos: O sistema deve permitir a matrícula de alunos em turmas, bem como a edição e exclusão de alunos. Deve ser possível inserir informações relevantes para cada aluno, como o nome do aluno, as notas das avaliações, e a presença nas aulas.

Registro de Presenças: O sistema deve permitir que os professores registrem a presença dos alunos em cada aula. Deve ser possível marcar cada aluno como presente ou ausente para cada aula.

Registro de Avaliações: O sistema deve permitir que os professores registrem as notas dos alunos para diferentes avaliações. Deve ser possível inserir a nota de cada aluno para cada avaliação.

Verificação de Desempenho: O sistema deve fornecer uma visão geral do desempenho dos alunos, incluindo presença e notas. Deve ser possível visualizar o desempenho de cada aluno em cada turma.

3.2. Requisitos Não-Funcionais
Desempenho: O sistema deve ser capaz de processar todas as operações de gerenciamento de turmas e alunos de maneira eficiente, mesmo com um grande número de alunos e turmas. O sistema deve responder rapidamente às ações do usuário e ser capaz de lidar com um aumento no número de turmas e alunos sem degradação significativa do desempenho.

Usabilidade: O sistema deve ser intuitivo e fácil de usar. Os usuários devem ser capazes de realizar todas as operações necessárias com um mínimo de treinamento. A interface do usuário deve ser clara e amigável, com todas as opções facilmente acessíveis. Deve ser fácil para os usuários navegarem pelo sistema e encontrar as informações ou funcionalidades que precisam. A interface do usuário deve ser consistente em todo o sistema, para que os usuários não fiquem confusos ao navegar por diferentes partes do sistema. Além disso, o sistema deve fornecer feedback adequado aos usuários, informando-os sobre o sucesso ou falha das operações realizadas.

       4. Análise e Design

O sistema é projetado como um sistema de gerenciamento acadêmico, focando especificamente no gerenciamento de turmas e alunos. Ele é escrito em C, uma linguagem de programação procedural, e usa uma interface baseada em console para interação do usuário.

Estruturas de Dados: O sistema usa duas estruturas principais, Aluno e Turma. A estrutura Aluno contém informações sobre um aluno, incluindo seu nome, notas, nota do exame final e presença. A estrutura Turma contém informações sobre uma turma, incluindo seu nome, o número de aulas, o número de avaliações e um array de estruturas Aluno representando os alunos da turma.

Funcionalidades: O sistema oferece várias funcionalidades, cada uma implementada como uma função separada. Estas incluem a criação, edição e exclusão de turmas e alunos (cadastrarTurma, editarTurma, excluirTurma, matricularAluno, editarAluno, excluirAluno), registro de presença (fazerChamada), registro de avaliações (registrarAvaliacoes), e verificação de desempenho (verificarDesempenho). A função main oferece um menu para o usuário escolher entre essas opções.

Operações de Arquivo: O sistema pode salvar e carregar dados de e para um arquivo (salvarDados, carregarDados). Isso permite que os dados persistam em várias execuções do programa. Os dados são salvos em um formato de texto simples, com os dados de cada turma e aluno escritos em uma linha separada.

Requisitos Não-Funcionais: Em termos de requisitos não-funcionais, o sistema visa eficiência e usabilidade. Ele é projetado para lidar com um grande número de alunos e turmas sem degradação significativa de desempenho. A interface do usuário é baseada em console e projetada para ser intuitiva e fácil de usar, com prompts claros e feedback.

       5. Testes

O sistema foi exaustivamente testado em todas as suas funções e foram detectadas diversas situações onde a inconsistência dos dados, tanto aqueles registrados nos arquivos e nas estruturas quanto os digitados pelo usuário, poderiam causar erros no funcionamento do sistema. Para corrigir essas falhas, foram implementadas diversas verificações para garantir a consistência dos dados.

       6. Descrição do código

6.1. Bibiotecas
stdio.h: Esta é a biblioteca padrão de entrada e saída em C. Ela fornece funções para realizar operações de entrada e saída, como printf para imprimir na tela e scanf para ler a entrada do usuário.
string.h: Esta biblioteca contém funções para manipular strings em C, como strcmp para comparar duas strings, strcat para concatenar duas strings e strtok para dividir uma string em tokens.
locale.h: Esta biblioteca é usada para configurar a localidade do programa, que afeta a formatação de dados como datas, horas e números. A função setlocale é usada para definir a localidade. No seu código, setlocale(LC_ALL, "Portuguese") é usado para definir a localidade para o português.

6.2. Estrutura de Dados
O sistema usa duas estruturas de dados principais, Aluno e Turma, para representar alunos e turmas, respectivamente. Aqui está uma descrição detalhada dessas estruturas:

Estrutura Aluno: Esta estrutura contém as seguintes informações sobre um aluno:
nomeAluno: Uma string que armazena o nome do aluno. O tamanho máximo do nome é definido pela constante MAX_NOME_ALUNO.
notas: Um array de floats que armazena as notas das avaliações do aluno. O número máximo de avaliações é definido pela constante MAX_AVALIACOES.
notaProvaFinal: Um float que armazena a nota da prova final do aluno.
presencas: Um array de inteiros que armazena a presença do aluno em cada aula. O número máximo de aulas é definido pela constante MAX_AULAS.

Estrutura Turma: Esta estrutura contém as seguintes informações sobre uma turma:
nomeTurma: Uma string que armazena o nome da turma. O tamanho máximo do nome é definido pela constante MAX_NOME_TURMA.
numAulas: Um inteiro que armazena o número de aulas da turma.
chamadasRealizadas: Um inteiro que armazena o número de chamadas realizadas na turma.
numAvaliacoesTurma: Um inteiro que armazena o número de avaliações planejadas para a turma.
avaliacoesRealizadas: Um inteiro que armazena o número de avaliações que foram realizadas na turma.
provaFinalRealizada: Um inteiro que indica se a prova final foi realizada na turma.
alunos: Um array de estruturas Aluno que armazena os alunos matriculados na turma. O número máximo de alunos é definido pela constante MAX_ALUNOS.

6.3. Função main
A função main é o ponto de entrada do programa. Ela é responsável por controlar o fluxo do programa e interagir com o usuário. Aqui está uma descrição detalhada de sua implementação:

Configuração da Localidade: A função setlocale é chamada para configurar a localidade do programa para Português. Isso afeta a formatação de dados como datas, horas e números.
Inicialização das Variáveis: As variáveis numTurmas e turmas são inicializadas. numTurmas mantém o controle do número atual de turmas, enquanto turmas é um array que armazena as informações de todas as turmas.
Carregamento dos Dados: A função carregarDados é chamada para carregar os dados das turmas e alunos de um arquivo.
Menu Principal: Um loop é iniciado para apresentar um menu ao usuário e processar a opção escolhida. O usuário pode escolher entre gerenciar turmas, alunos, fazer chamada, registrar avaliações, verificar desempenho ou sair do programa. Dependendo da escolha do usuário, a função correspondente é chamada.
Submenus: Dentro de cada opção do menu principal, existem submenus que permitem ao usuário realizar ações específicas. Por exemplo, se o usuário escolher “Turmas”, ele pode então escolher entre criar, editar ou excluir uma turma.
Loop do Menu: O menu principal é apresentado em um loop, permitindo que o usuário realize várias ações em uma única execução do programa. O loop continua até que o usuário escolha a opção “Sair”.
Término do Programa: Quando o usuário escolhe “Sair”, o programa termina e a função main retorna 0, indicando que o programa terminou com sucesso.

6.4. Demais funções
A função cadastrarTurma é usada para criar uma nova turma no sistema. Seu funcionamento compreende os seguintes passos:

    • Verificação do número de turmas: A função primeiro verifica se o número máximo de turmas já foi atingido. Se sim, ela informa ao usuário e retorna o número atual de turmas.
    • Entrada do nome da turma: A função pede ao usuário para digitar o nome da turma. Ela remove espaços do nome usando a função strtok.
    • Verificação do nome da turma: A função verifica se já existe uma turma com o mesmo nome. Se sim, ela informa ao usuário e retorna o número atual de turmas.
    • Entrada do número de aulas e avaliações: A função pede ao usuário para digitar o número de aulas e o número de avaliações para a turma.
    • Verificação do número de avaliações: Se o número de avaliações exceder o máximo permitido, a função redefine o número de avaliações para o máximo permitido e informa ao usuário.
    • Criação da turma: A função cria a nova turma, armazenando o nome da turma, o número de aulas e o número de avaliações nos campos apropriados da estrutura Turma.
    • Salvamento dos dados: A função chama salvarDados para salvar os dados atualizados em um arquivo.
    • Retorno: A função incrementa o número de turmas e retorna esse valor.

A função editarTurma é usada para editar as informações de uma turma existente no sistema. Seu funcionamento compreende os seguintes passos:

    • Verificação do número de turmas: A função primeiro verifica se existem turmas para editar. Se não houver, ela informa ao usuário e retorna.
    • Exibição das turmas cadastradas: A função exibe todas as turmas cadastradas para o usuário.
    • Seleção da turma a ser editada: A função pede ao usuário para digitar o número da turma que deseja editar.
    • Verificação do número da turma: A função verifica se o número da turma fornecido pelo usuário é válido. Se não for, ela informa ao usuário e retorna.
    • Entrada das novas informações da turma: A função pede ao usuário para digitar o novo nome da turma, o novo número de aulas e o novo número de avaliações.
    • Verificação do novo nome da turma: A função verifica se já existe uma turma com o novo nome. Se sim, ela informa ao usuário e retorna.
    • Atualização das informações da turma: A função atualiza as informações da turma com os novos dados fornecidos pelo usuário.
    • Salvamento dos dados: A função chama salvarDados para salvar os dados atualizados em um arquivo.

A função excluirTurma é usada para excluir uma turma existente do sistema. Seu funcionamento compreende os seguintes passos:

    • Verificação do número de turmas: A função primeiro verifica se existem turmas para excluir. Se não houver, ela informa ao usuário e retorna o número atual de turmas.
    • Exibição das turmas cadastradas: A função exibe todas as turmas cadastradas para o usuário.
    • Seleção da turma a ser excluída: A função pede ao usuário para digitar o número da turma que deseja excluir.
    • Verificação do número da turma: A função verifica se o número da turma fornecido pelo usuário é válido. Se não for, ela informa ao usuário e retorna.
    • Confirmação da exclusão: A função pede ao usuário para confirmar a exclusão da turma. Se o usuário confirmar, a função prossegue com a exclusão.
    • Exclusão da turma: A função exclui a turma, movendo todas as turmas subsequentes para cima no array para preencher o espaço deixado pela turma excluída. Ela então decrementa o número de turmas.
    • Salvamento dos dados: A função chama salvarDados para salvar os dados atualizados em um arquivo.
    • Retorno: A função retorna o novo número de turmas.

A função matricularAluno é usada para matricular um aluno em uma turma existente no sistema. Seu funcionamento compreende os seguintes passos:

    • Verificação do número de turmas: A função primeiro verifica se existem turmas para matricular alunos. Se não houver, ela informa ao usuário e retorna o número atual de turmas.
    • Ordenação das turmas: A função ordena as turmas em ordem alfabética.
    • Exibição das turmas cadastradas: A função exibe todas as turmas cadastradas para o usuário.
    • Seleção da turma: A função pede ao usuário para digitar o número da turma em que deseja matricular o aluno.
    • Verificação do número da turma: A função verifica se o número da turma fornecido pelo usuário é válido. Se não for, ela informa ao usuário e retorna.
    • Verificação do número de alunos na turma: A função verifica se o número máximo de alunos na turma foi atingido. Se sim, ela informa ao usuário e retorna o número atual de turmas.
    • Entrada do nome do aluno: A função pede ao usuário para digitar o nome do aluno.
    • Verificação do nome do aluno: A função verifica se já existe um aluno com o mesmo nome na turma. Se sim, ela informa ao usuário e retorna o número atual de turmas.
    • Matrícula do aluno: A função matricula o aluno na turma, armazenando o nome do aluno no campo apropriado da estrutura Aluno.
    • Salvamento dos dados: A função chama salvarDados para salvar os dados atualizados em um arquivo.
    • Retorno: A função incrementa o número de turmas e retorna esse valor.

A função editarAluno é usada para editar as informações de um aluno existente em uma turma específica. Seu funcionamento compreende os seguintes passos:


    • Verificação do número de turmas: A função primeiro verifica se existem turmas para editar alunos. Se não houver, ela informa ao usuário e retorna.
    • Exibição das turmas cadastradas: A função exibe todas as turmas cadastradas para o usuário.
    • Seleção da turma: A função pede ao usuário para digitar o número da turma que contém o aluno a ser editado.
    • Verificação do número da turma: A função verifica se o número da turma fornecido pelo usuário é válido. Se não for, ela informa ao usuário e retorna.
    • Verificação do número de alunos na turma: A função verifica se há alunos matriculados na turma selecionada. Se não houver, ela informa ao usuário e retorna.
    • Exibição dos alunos matriculados na turma: A função exibe todos os alunos matriculados na turma selecionada.
    • Seleção do aluno a ser editado: A função pede ao usuário para digitar o número do aluno que deseja editar.
    • Verificação do número do aluno: A função verifica se o número do aluno fornecido pelo usuário é válido. Se não for, ela informa ao usuário e retorna.
    • Entrada do novo nome do aluno: A função pede ao usuário para digitar o novo nome do aluno.
    • Verificação do novo nome do aluno: A função verifica se já existe um aluno com o mesmo nome na turma. Se sim, ela informa ao usuário e retorna.
    • Atualização do nome do aluno: A função atualiza o nome do aluno com o novo nome fornecido pelo usuário.
    • Salvamento dos dados: A função chama salvarDados para salvar os dados atualizados em um arquivo.

A função excluirAluno é usada para excluir um aluno de uma turma existente no sistema. Seu funcionamento compreende os seguintes passos:

    • Verificação do número de turmas: A função primeiro verifica se existem turmas para excluir alunos. Se não houver, ela informa ao usuário e retorna.
    • Exibição das turmas cadastradas: A função exibe todas as turmas cadastradas para o usuário.
    • Seleção da turma: A função pede ao usuário para digitar o número da turma que contém o aluno a ser excluído.
    • Verificação do número da turma: A função verifica se o número da turma fornecido pelo usuário é válido. Se não for, ela informa ao usuário e retorna.
    • Verificação do número de alunos na turma: A função verifica se há alunos matriculados na turma selecionada. Se não houver, ela informa ao usuário e retorna.
    • Exibição dos alunos matriculados na turma: A função exibe todos os alunos matriculados na turma selecionada.
    • Seleção do aluno a ser excluído: A função pede ao usuário para digitar o número do aluno que deseja excluir.
    • Verificação do número do aluno: A função verifica se o número do aluno fornecido pelo usuário é válido. Se não for, ela informa ao usuário e retorna.
    • Confirmação da exclusão: A função pede ao usuário para confirmar a exclusão do aluno. Se o usuário confirmar, a função prossegue com a exclusão.
    • Exclusão do aluno: A função exclui o aluno, movendo todos os alunos subsequentes para cima no array para preencher o espaço deixado pelo aluno excluído. Ela então limpa os dados do último aluno no array usando a função memset.
    • Salvamento dos dados: A função chama salvarDados para salvar os dados atualizados em um arquivo.

A função fazerChamada é usada para registrar a presença dos alunos em uma aula de uma turma específica. Seu funcionamento compreende os seguintes passos:

    • Verificação do número de turmas: A função primeiro verifica se existem turmas para fazer a chamada. Se não houver, ela informa ao usuário e retorna.
    • Exibição das turmas cadastradas: A função exibe todas as turmas cadastradas para o usuário.
    • Seleção da turma: A função pede ao usuário para digitar o número da turma em que deseja fazer a chamada.
    • Verificação do número da turma: A função verifica se o número da turma fornecido pelo usuário é válido. Se não for, ela informa ao usuário e retorna.
    • Verificação do número de chamadas realizadas: A função verifica se todas as chamadas para a turma selecionada já foram registradas. Se sim, ela informa ao usuário e retorna.
    • Verificação do número de alunos na turma: A função verifica se há alunos matriculados na turma selecionada. Se não houver, ela informa ao usuário e retorna.
    • Exibição dos alunos matriculados na turma: A função exibe todos os alunos matriculados na turma selecionada.
    • Registro da presença dos alunos: A função pede ao usuário para registrar a presença de cada aluno, digitando 1 para presente e 0 para ausente. Ela então registra a presença do aluno no campo apropriado da estrutura Aluno.
    • Atualização do número de chamadas realizadas: A função incrementa o número de chamadas realizadas para a turma.
    • Salvamento dos dados: A função chama salvarDados para salvar os dados atualizados em um arquivo.

A função registrarAvaliacoes é usada para registrar as notas dos alunos em uma turma específica. Seu funcionamento compreende os seguintes passos:

    • Verificação do número de turmas: A função primeiro verifica se existem turmas para registrar avaliações. Se não houver, ela informa ao usuário e retorna.
    • Exibição das turmas cadastradas: A função exibe todas as turmas cadastradas para o usuário.
    • Seleção da turma: A função pede ao usuário para digitar o número da turma em que deseja registrar avaliações.
    • Verificação do número da turma: A função verifica se o número da turma fornecido pelo usuário é válido. Se não for, ela informa ao usuário e retorna.
    • Verificação da prova final: A função verifica se a prova final já foi realizada para a turma selecionada. Se sim, ela informa ao usuário e retorna.
    • Verificação do número de avaliações realizadas: A função verifica se o número máximo de avaliações já foi atingido para a turma selecionada. Se sim, ela informa ao usuário e procede o registro das notas da prova final.
    • Verificação do número de alunos na turma: A função verifica se há alunos matriculados na turma selecionada. Se não houver, ela informa ao usuário e retorna.
    • Registro das notas dos alunos: A função pede ao usuário para registrar as notas de cada aluno. Se todas as avaliações já foram realizadas, ela pede ao usuário para registrar as notas da prova final para os alunos em recuperação.
    • Atualização do número de avaliações realizadas: A função incrementa o número de avaliações realizadas para a turma.
    • Salvamento dos dados: A função chama salvarDados para salvar os dados atualizados em um arquivo.

A função verificarDesempenho é usada para verificar e exibir o desempenho dos alunos em uma turma específica. Seu funcionamento compreende os seguintes passos:

    • Verificação do número de turmas: A função primeiro verifica se existem turmas para verificar o desempenho. Se não houver, ela informa ao usuário e retorna.
    • Exibição das turmas cadastradas: A função exibe todas as turmas cadastradas para o usuário.
    • Seleção da turma: A função pede ao usuário para digitar o número da turma cujo desempenho deseja verificar.
    • Verificação do número da turma: A função verifica se o número da turma fornecido pelo usuário é válido. Se não for, ela informa ao usuário e retorna.
    • Verificação do número de alunos na turma: A função verifica se há alunos matriculados na turma selecionada. Se não houver, ela informa ao usuário e retorna.
    • Exibição do desempenho dos alunos: A função exibe o desempenho de cada aluno na turma selecionada. Ela calcula a média das notas, verifica se o aluno passou ou falhou e exibe essas informações para o usuário.
    • Exibição do resumo do desempenho da turma: A função exibe um resumo do desempenho da turma, incluindo o número e a porcentagem de alunos aprovados, reprovados por falta e em recuperação.

A função salvarDados é usada para salvar os dados atuais de todas as turmas e alunos em um arquivo chamado “dados.txt”. Seu funcionamento compreende os seguintes passos:

    • Abertura do arquivo: A função tenta abrir o arquivo “dados.txt” em modo de escrita. Se o arquivo não puder ser aberto (por exemplo, se o programa não tiver permissão para escrever no arquivo), a função informa ao usuário e retorna.
    • Iteração sobre as turmas: A função itera sobre todas as turmas. Para cada turma, ela escreve várias informações no arquivo, incluindo o nome da turma, o número de aulas, o número de chamadas realizadas, o número de avaliações planejadas, o número de avaliações realizadas e se a prova final foi realizada.
    • Iteração sobre os alunos: Dentro de cada turma, a função itera sobre todos os alunos. Para cada aluno que tem um nome (ou seja, o nome do aluno não é a string vazia), a função escreve várias informações no arquivo, incluindo o nome do aluno, as notas das avaliações, a nota da prova final e a presença nas aulas.
    • Fechamento do arquivo: Depois de escrever todas as informações, a função fecha o arquivo.

A função carregarDados é usada para carregar os dados de todas as turmas e alunos de um arquivo chamado “dados.txt”. Seu funcionamento compreende os seguintes passos:

    • Abertura do arquivo: A função tenta abrir o arquivo “dados.txt” em modo de leitura. Se o arquivo não puder ser aberto (por exemplo, se o arquivo não existir), a função informa ao usuário e retorna.
    • Leitura do arquivo: A função lê o arquivo linha por linha. Cada linha representa uma turma e contém os dados da turma seguidos pelos dados de todos os alunos na turma.
    • Processamento de cada linha: Para cada linha, a função usa a função strtok para dividir a linha em tokens separados por espaços. Ela então usa a função sscanf para analisar cada token e armazenar os dados no campo apropriado da estrutura Turma ou Aluno.
    • Verificação de cada token: Se um token for analisado com sucesso, a função passa para o próximo token. Se um token não puder ser analisado (por exemplo, porque o final da linha foi atingido), a função para de processar a linha atual e passa para a próxima linha.
    • Fechamento do arquivo: Depois de todas as linhas terem sido processadas, a função fecha o arquivo.
