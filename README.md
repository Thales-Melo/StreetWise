# StreetWise
Código em C para encontrar o caminho mais curto entre cidades


## TADs criados

• City --> Representa os nós do grafo (Imagine o grafo como sendo um conjunto de cidades conectadas por rodovias, etc...) (Escolhido também para evitar conflito de nomes, uma vez que a Lista Duplamente Encadeada já possui "nodes")

• Route --> Representa as arestas do grafo... Entre cidades se trata de um "caminho" ou "conexão"

• Graphs --> Representa o grafo

• Parent --> Estrutura utilizada no algoritmo Dijkstra para armazenar os pais de cada nó no tocante ao melhor caminho

• Path --> Representa o melhor caminho até chegar ao nó

• Dijkstra --> Algoritmo implementada para resolver o problema

• Problem --> Problema a ser resolvido


## Estruturas de Dados
Para resolver o problema, utilizei HEAP (Fila de prioridade) para manipular os e iterar sobre os nós do grafo, além de uma LISTA DUPLAMENTE ENCADEADA para armazenar as rotas (Motivo explicado no .h)
