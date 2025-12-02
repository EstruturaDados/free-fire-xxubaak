# 🏝️ Desafio Código da Ilha – Edição Free Fire

Este projeto é uma implementação de um sistema de inventário básico em linguagem C, projetado para simular a mochila de sobrevivência de um jogador em uma ilha misteriosa inspirada no universo Free Fire. O sistema permite cadastrar, remover e listar itens estratégicos, utilizando estruturas de dados (structs) e listas sequenciais (vetores) para gerenciar os recursos de forma eficiente.

## 📜 Descrição do Projeto

No contexto de um jogo de sobrevivência em batalha real, a gestão de recursos é determinante para a vitória. Este programa foca na implementação dessa mecânica crucial, onde o jogador precisa coletar e organizar rapidamente itens essenciais como armas, munição e kits médicos antes de enfrentar seus adversários na ilha.

O objetivo principal foi criar um sistema de console funcional e intuitivo para manipular um inventário com capacidade limitada, aplicando conceitos fundamentais de programação em C e simulando uma experiência realista de gerenciamento de recursos sob pressão.

## ✨ Funcionalidades

O sistema possui as seguintes funcionalidades implementadas no **Nível Novato**:

### 1. **Cadastro de Itens**
Permite ao sobrevivente adicionar novos itens ao inventário da mochila, informando:
- **Nome do item** (ex: AK-47, M1014, Bandagem)
- **Tipo** (ex: Arma, Munição, Kit Médico, Equipamento)
- **Quantidade** (valor numérico)

O inventário possui uma capacidade máxima de **10 itens**, simulando o limite realista de uma mochila de combate.

### 2. **Remoção de Itens**
O jogador pode remover um item específico do inventário informando seu nome exato. O sistema:
- Realiza busca pelo nome do item
- Remove o item encontrado
- Reorganiza automaticamente o espaço na mochila
- Exibe mensagem de confirmação ou erro caso o item não exista

### 3. **Listagem Completa do Inventário**
A qualquer momento, é possível visualizar uma tabela organizada e formatada com todos os itens presentes na mochila, incluindo:
- Nome do item
- Tipo/categoria
- Quantidade disponível
- Contagem total de espaços ocupados

A interface visual utiliza bordas ASCII para criar uma apresentação profissional e clara dos dados.

### 4. **Menu Interativo**
Sistema de navegação intuitivo com opções numeradas:
- Adicionar item (1)
- Remover item (2)
- Listar itens (3)
- Sair do sistema (0)

O menu é implementado com estruturas de controle `do-while` e `switch-case` para garantir fluidez na navegação.

## 📦 Estrutura de Dados

Para representar cada objeto coletado na ilha, foi utilizada uma **struct** chamada `Item`, que armazena as seguintes informações:

```c
typedef struct {
    char nome[50];
    char tipo[30];
    int quantidade;
} Item;
```

### Componentes da Estrutura:
- **nome**: String de até 50 caracteres para identificar o item
- **tipo**: String de até 30 caracteres para categorizar o item
- **quantidade**: Inteiro representando quantas unidades o jogador possui

O inventário (mochila) é implementado como um **vetor estático** desta struct, com capacidade fixa de 10 posições, simulando o espaço limitado de uma mochila real.

## 🛠️ Tecnologias Utilizadas

**Linguagem:** C (Padrão ANSI C)

**Bibliotecas Padrão:**
- `stdio.h` - Entrada e saída de dados
- `string.h` - Manipulação de strings

**Conceitos Aplicados:**
- Estruturas de dados (structs)
- Vetores estáticos
- Funções modulares
- Estruturas de controle (if, switch, do-while, for)
- Manipulação de strings
- Entrada e saída formatada

## 🎯 Objetivos de Aprendizado

Este projeto foi desenvolvido como parte do **Nível Novato** do Desafio Código da Ilha, com foco em:

✅ Praticar a criação e manipulação de estruturas (structs)  
✅ Trabalhar com vetores estáticos e indexação  
✅ Implementar operações CRUD básicas (Create, Read, Delete)  
✅ Desenvolver interfaces de console amigáveis  
✅ Aplicar boas práticas de organização de código  
✅ Utilizar estruturas de controle de fluxo  

## 📝 Observações Técnicas

- O programa não utiliza ponteiros ou alocação dinâmica nesta versão inicial
- A capacidade é limitada a 10 itens para fins didáticos
- A busca e remoção são feitas por correspondência exata do nome
- O sistema possui validações para prevenir operações em inventário vazio ou cheio

## 🏆 Conclusão

Este sistema de inventário demonstra a aplicação prática de conceitos fundamentais de programação em C, simulando uma mecânica real de jogos de sobrevivência. O projeto serve como base sólida para expansões futuras e como ferramenta de aprendizado para desenvolvimento de sistemas mais complexos.

---

**Desenvolvido para:** Desafio Código da Ilha – Edição Free Fire  
**Desenvolvedor:** Widardison Sousa
**Nível:** Novato 🌱
