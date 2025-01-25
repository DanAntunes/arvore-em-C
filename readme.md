# Árvore Binária de Busca (ABB)

Este projeto implementa uma **Árvore Binária de Busca (ABB)** em linguagem C, com funcionalidades de inclusão, remoção e busca de nós. Ele utiliza um menu interativo no console para que o usuário possa explorar as operações disponíveis.

## Funcionalidades

- **Inserção de Nós:** Adiciona um novo valor à árvore na posição correta seguindo as regras da ABB.
- **Remoção de Nós:** Remove um nó específico da árvore, reorganizando a estrutura conforme necessário.
- **Busca em Pré-Ordem:** Percorre os nós da árvore na sequência: raiz, esquerda, direita.
- **Busca em Ordem:** Percorre os nós da árvore na sequência: esquerda, raiz, direita.
- **Busca em Pós-Ordem:** Percorre os nós da árvore na sequência: esquerda, direita, raiz.

## Estrutura do Código

1. **Definição de Estruturas:**
   - Estrutura `Node` que representa um nó da árvore.
   - Ponteiros para os filhos esquerdo e direito.

2. **Funções Implementadas:**
   - `criarNo`: Cria um novo nó.
   - `inserirNo`: Insere um valor na árvore.
   - `buscaPreOrdem`, `buscaEmOrdem`, `buscaPosOrdem`: Realizam percursos na árvore.
   - `encontrarMenor`: Localiza o nó com o menor valor na subárvore.
   - `removerNo`: Remove um nó específico da árvore.

3. **Menu Interativo:**
   - Apresenta opções para o usuário realizar as operações acima.
